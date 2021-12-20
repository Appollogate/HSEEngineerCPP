//
// Created by appollogate on 15.10.2021.
//

#ifndef CPP_HW1_EXPRESSION_EVALUATOR_H
#define CPP_HW1_EXPRESSION_EVALUATOR_H

#include <string>
#include <string_view>
#include <sstream>
#include <array>
#include <algorithm>
#include <iostream>
#include <exception>
#include <stack>
#include <vector>
#include "BigInteger.h"

// Evaluating expressions with unary operators is not implemented... yet.
class ExpressionEvaluator {
public:
    explicit ExpressionEvaluator(std::string);

    bool IsExpressionValid();

    BigInteger Evaluate();

private:

    [[nodiscard]] static BigInteger GetValueFromRPN(const std::vector<std::string> &);

    [[nodiscard]] bool IsCharSetCorrect() const;

    [[nodiscard]] bool IsParenthesesSequenceCorrect() const;

    [[nodiscard]] bool IsMathExpressionCorrect() const;

    static bool HasGreaterOrEqualPrecedence(const char &, const char &);

/// Implements the shunting-yard algorithm
/// (see https://en.wikipedia.org/wiki/Shunting-yard_algorithm for reference)
/// to parse mathematical expressions in RPN (Reverse Polish Notation).
/// \return expression string in RPN.
    [[nodiscard]] std::vector<std::string> GetRPNRepresentation() const;

    std::string expression;

    // Not counting whitespace and digits. Corresponding checks for those two go separately.
    static constexpr const std::array<char, 7> allowed_chars = {
            '+', '-', '*', '/', '%', '(', ')'
    };
};


#endif //CPP_HW1_EXPRESSION_EVALUATOR_H
