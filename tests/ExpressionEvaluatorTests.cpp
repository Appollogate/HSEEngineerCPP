//
// Created by appollogate on 19.10.2021.
//

#include <gtest/gtest.h>
#include "../src/ExpressionEvaluator.h"

TEST(EETest, CharSetCorrectness){
    EXPECT_TRUE(ExpressionEvaluator("12345 + 67890").IsExpressionValid());
    EXPECT_TRUE(ExpressionEvaluator("12345 - 67890").IsExpressionValid());
    EXPECT_TRUE(ExpressionEvaluator("12345 * 67890").IsExpressionValid());
    EXPECT_TRUE(ExpressionEvaluator("12345 / 67890").IsExpressionValid());
    EXPECT_TRUE(ExpressionEvaluator("12345 % 67890").IsExpressionValid());
    EXPECT_TRUE(ExpressionEvaluator("(12345 % 67890)").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("0x110110 + 1234L").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("CAT").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("~(^w^)~").IsExpressionValid());
}

TEST(EETest, ParenthesisCorrectness){
    EXPECT_TRUE(ExpressionEvaluator("1 + 2").IsExpressionValid());
    EXPECT_TRUE(ExpressionEvaluator("(1 + 2)").IsExpressionValid());
    EXPECT_TRUE(ExpressionEvaluator("((1 + 2))").IsExpressionValid());
    EXPECT_TRUE(ExpressionEvaluator("((1) + (2))").IsExpressionValid());
    EXPECT_TRUE(ExpressionEvaluator("((2 * (2 + 1)) + (1 + 2) - 1)").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("(1 + 2").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("1 + 2)").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("(1) + (2").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("(1 + 2))))").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("((((1 + 2)").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("((2 * (2 + 1) + (1 + 2) - 1)").IsExpressionValid());
}

TEST(EETest, MathExpressionFormatCorrectness){
    // Assume that a correct expression should not have unary + or - operators.
    EXPECT_TRUE(ExpressionEvaluator("(1 + 2) - 3 * 4 / 5 % 6").IsExpressionValid());
    EXPECT_TRUE(ExpressionEvaluator("12345").IsExpressionValid());
    EXPECT_TRUE(ExpressionEvaluator("   ").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("1 2 3 4 5").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("(1 + 2) 3 ").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("1 + -2").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("1 + ( * )").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("(1 + 2)()").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("1 (1 + 2)").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("1 - ()").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("(2 - )").IsExpressionValid());
    EXPECT_FALSE(ExpressionEvaluator("* 1").IsExpressionValid());
}

TEST(EETest, MathExpressionEvaluateTest){
    EXPECT_EQ(ExpressionEvaluator("6 + 3").Evaluate(), BigInteger("9"));
    EXPECT_EQ(ExpressionEvaluator("6 - 3").Evaluate(), BigInteger("3"));
    EXPECT_EQ(ExpressionEvaluator("6 * 3").Evaluate(), BigInteger("18"));
    EXPECT_EQ(ExpressionEvaluator("6 / 3").Evaluate(), BigInteger("2"));
    EXPECT_EQ(ExpressionEvaluator("6 % 3").Evaluate(), BigInteger("0"));
    EXPECT_EQ(ExpressionEvaluator("6 + 2 * 3").Evaluate(), BigInteger("12"));
    EXPECT_EQ(ExpressionEvaluator("(6 + 2) * 3").Evaluate(), BigInteger("24"));
    EXPECT_EQ(ExpressionEvaluator("(24 - (32 - (6 + 5 * 10)) - 18) / 3").Evaluate(), BigInteger("10"));
}