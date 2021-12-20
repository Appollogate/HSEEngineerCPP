//
// Created by appollogate on 15.10.2021.
//

#include "ExpressionEvaluator.h"

#include <utility>

ExpressionEvaluator::ExpressionEvaluator(std::string s) : expression(std::move(s)) {}

BigInteger ExpressionEvaluator::Evaluate() {
    // First, check if expression is formatted correctly.
    if (!IsExpressionValid()) {
        throw std::invalid_argument("Given expression format is invalid");
    }
    // Then, parse it to reverse polish notation and evaluate the result.
    return GetValueFromRPN(GetRPNRepresentation());
}

bool ExpressionEvaluator::IsExpressionValid() {
    if (!IsCharSetCorrect()) {
        std::cerr << "\nERROR: Expression \"" << expression << "\" contains illegal symbols.\n"
                                                               "Legal symbols include digits, spaces, certain math operators (+, -, *, /, %) "
                                                               "and round parentheses. All other symbols are illegal.\n";
        return false;
    }
    if (!IsParenthesesSequenceCorrect()) {
        std::cerr << "\nERROR: Expression \"" << expression << "\" contains invalid parenthesis sequence.\n";
        return false;
    }
    if (!IsMathExpressionCorrect()) {
        std::cerr << "\nERROR: Given math expression \"" << expression << "\" has wrong format.\n";
        return false;
    }
    return true;
}

bool ExpressionEvaluator::IsCharSetCorrect() const {
    return std::all_of(expression.begin(), expression.end(), [](char c) {
        return std::find(allowed_chars.begin(), allowed_chars.end(), c) != allowed_chars.end()
               || std::isspace(c) || std::isdigit(c);
    });
}

bool ExpressionEvaluator::IsParenthesesSequenceCorrect() const {
    int open_par_count = 0;
    for (char c: expression) {
        if (c == '(') {
            ++open_par_count;
        } else if (c == ')') {
            if (open_par_count >= 1) {
                --open_par_count;
            } else {
                return false; // Means that there are no enough pairing opening parentheses
            }
        }
    }
    if (open_par_count > 0) {
        return false; // Means that there are not enough pairing closing parentheses
    }
    return true;
}

bool ExpressionEvaluator::IsMathExpressionCorrect() const {
    // Assume the expression doesn't contain unary operators.
    enum ReadSymbol {
        NO_SYMBOL, OPEN_PAR, CLOSE_PAR, OPERATOR, DIGIT
    };
    bool read_space = false;
    ReadSymbol last_read = ReadSymbol::NO_SYMBOL;
    for (char c: expression) {
        if (std::isdigit(c)) { // Case 1: last read char was a digit
            if (last_read == ReadSymbol::NO_SYMBOL || last_read == ReadSymbol::OPERATOR ||
                last_read == ReadSymbol::OPEN_PAR ||
                (last_read == ReadSymbol::DIGIT && !read_space)) {
                last_read = ReadSymbol::DIGIT; // OK
                read_space = false;
            } else {
                return false;
            }
        } else if (c == '+' || c == '-' || c == '*'
                   || c == '/' || c == '%') { // Case 2: last read char was an operator
            if (last_read == ReadSymbol::DIGIT || last_read == ReadSymbol::CLOSE_PAR) {
                last_read = ReadSymbol::OPERATOR; // OK
                read_space = false;
            } else {
                return false;
            }
        } else if (c == '(') { // Case 3: last read char was an opening parenthesis
            if (last_read == ReadSymbol::NO_SYMBOL || last_read == ReadSymbol::OPEN_PAR ||
                last_read == ReadSymbol::OPERATOR) {
                last_read = ReadSymbol::OPEN_PAR; // OK
                read_space = false;
            } else {
                return false;
            }
        } else if (c == ')') { // Case 4: last read char was a closing parenthesis
            if (last_read == ReadSymbol::CLOSE_PAR || last_read == ReadSymbol::DIGIT) {
                last_read = ReadSymbol::CLOSE_PAR; // OK
                read_space = false;
            } else {
                return false;
            }
        } else if (std::isspace(c)) { // Case 5: last read char was 'empty'
            read_space = true;
        } else {
            // If (for whatever reason) last read char didn't match any previous cases, consider it an error
            return false;
        }
    }
    return true;
}

std::vector<std::string> ExpressionEvaluator::GetRPNRepresentation() const {
    std::string curr_number;
    std::vector<std::string> result;
    std::stack<char> operator_stack;
    for (char c: expression) {
        if (std::isdigit(c)) {
            curr_number += c;
        } else {
            // After finishing reading the number (if there was one), add it to output
            if (!curr_number.empty()) {
                result.push_back(curr_number);
                curr_number.clear();
            }
            // If the next token is an operator o1 while not being a parenthesis
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
                // While there is an operator o2 other than the left parenthesis at the top of the
                // operator stack and o2 has greater or equal precedence than o1
                while (!operator_stack.empty() && operator_stack.top() != '(' &&
                       HasGreaterOrEqualPrecedence(operator_stack.top(), c)) {
                    // Pop o2 from the operator stack in the output queue
                    result.push_back({operator_stack.top()});
                    operator_stack.pop();
                }
                // Push o1 on the operator stack
                operator_stack.push(c);
            } else if (c == '(') {
                operator_stack.push(c);
            } else if (c == ')') {
                while (operator_stack.top() != '(') {
                    // Pop the operator to the output queue while it's not a left parenthesis
                    result.push_back({operator_stack.top()});
                    operator_stack.pop();
                }
                // Assert there is a left parenthesis at the top of the operator stack.
                // Pop it from the stack and discard it.
                operator_stack.pop();
            }
            // Otherwise, read character is assumed to be whitespace.
        }
    }
    // If the last expression token was a number, add it to the output
    if (!curr_number.empty()) {
        result.push_back(curr_number);
    }
    // While there are tokens left on the operator stack, pop them in the output queue
    while (!operator_stack.empty()) {
        result.push_back({operator_stack.top()});
        operator_stack.pop();
    }
    return result;
}

BigInteger ExpressionEvaluator::GetValueFromRPN(const std::vector<std::string> &tokens) {
    std::stack<BigInteger> numbers;
    for (const std::string &token: tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%") {
            // Get right operand from the stack
            BigInteger second = numbers.top();
            numbers.pop();
            // Get left operand from the stack
            BigInteger first = numbers.top();
            numbers.pop();
            BigInteger result;
            // Calculate result based on the operator
            numbers.push(BigInteger::getResultFromOperation(first, second, token));
        } else { // the token is a number
            numbers.push(BigInteger(token));
        }
    }
    return numbers.top();
}

bool ExpressionEvaluator::HasGreaterOrEqualPrecedence(const char &op1, const char &op2) {
    // All operators are left-associative. op1 and op2 are guaranteed to be one of ['+', '-', '*', '/', '%'].
    if (op1 == '+' || op1 == '-') {
        if (op2 == '*' || op2 == '/' || op2 == '%') {
            return false;
        } else { // if (op2 == '+' || op2 == '-')
            return true;
        }
    } else { // if (op1 == '*' || op2 == '/' || op2 == '%')
        return true;
    }
}


