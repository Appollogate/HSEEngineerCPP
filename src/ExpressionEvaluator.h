//
// Created by appollogate on 15.10.2021.
//

#ifndef CPP_HW1_EXPRESSION_EVALUATOR_H
#define CPP_HW1_EXPRESSION_EVALUATOR_H

#include <string_view>
#include <array>
#include <algorithm>
#include <iostream>

class ExpressionEvaluator {
public:
    explicit ExpressionEvaluator(const std::string_view &);

    bool IsExpressionValid();

private:
    bool IsCharSetCorrect();

    bool IsParenthesesSequenceCorrect();

    bool IsMathExpressionCorrect();

    std::string_view expression;

    // Not counting whitespace and digits. Corresponding checks for those two go separately.
    static constexpr const std::array<char, 7> allowed_chars = {
            '+', '-', '*', '/', '%', '(', ')'
    };
};


#endif //CPP_HW1_EXPRESSION_EVALUATOR_H
