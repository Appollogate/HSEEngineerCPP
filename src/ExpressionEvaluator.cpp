//
// Created by appollogate on 15.10.2021.
//

#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator(const std::string_view &s) : expression(s) {}

bool ExpressionEvaluator::IsExpressionValid() {
    if (!IsCharSetCorrect()){
        std::cerr << "\nERROR: Expression \"" << expression << "\" contains illegal symbols.\n"
                     "Legal symbols include digits, spaces, certain math operators (+, -, *, /, %) "
                     "and round parentheses. All other symbols are illegal.\n";
        return false;
    }
    if (!IsParenthesesSequenceCorrect()){
        std::cerr << "\nERROR: Expression \"" << expression << "\" contains invalid parenthesis sequence.\n";
        return false;
    }
    if (!IsMathExpressionCorrect()){
        std::cerr << "\nERROR: Given math expression \"" << expression << "\" has wrong format.\n";
        return false;
    }
    return true;
}

bool ExpressionEvaluator::IsCharSetCorrect() {
    return std::all_of(expression.begin(), expression.end(), [](char c) {
        return std::find(allowed_chars.begin(), allowed_chars.end(), c) != allowed_chars.end()
               || std::isspace(c) || std::isdigit(c);
    });
}

bool ExpressionEvaluator::IsParenthesesSequenceCorrect() {
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

bool ExpressionEvaluator::IsMathExpressionCorrect() {
    // Assume the expression doesn't contain unary operators.
    enum ReadSymbol {
        NO_SYMBOL, OPEN_PAR, CLOSE_PAR, OPERATOR, DIGIT
    };
    bool read_space = false;
    ReadSymbol last_read = ReadSymbol::NO_SYMBOL;
    for (char c: expression) {
        if (std::isdigit(c)) { // Case 1: last read char was a digit
            if (last_read == ReadSymbol::NO_SYMBOL || last_read == ReadSymbol::OPERATOR || last_read == ReadSymbol::OPEN_PAR ||
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
            if (last_read == ReadSymbol::NO_SYMBOL || last_read == ReadSymbol::OPEN_PAR || last_read == ReadSymbol::OPERATOR) {
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


