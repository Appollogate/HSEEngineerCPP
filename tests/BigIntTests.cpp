//
// Created by appollogate on 9/29/21.
//

#include <gtest/gtest.h>
#include "../src/BigInteger.h"

TEST(BigIntTest, GreaterThanTestPos){
    EXPECT_GT(BigInteger(2), BigInteger(1));
}

TEST(BigIntTest, GreaterThanTestNeg){
    EXPECT_GT(BigInteger(-1), BigInteger(-2));
}

TEST(BigIntTest, GreaterThanTestPosNeg){
    EXPECT_GT(BigInteger(2), BigInteger(-1));
}

TEST(BigIntTest, LessThanTestPos){
    EXPECT_LT(BigInteger(3), BigInteger(4));
}

TEST(BigIntTest, LessThanTestNeg){
    EXPECT_LT(BigInteger(-4), BigInteger(-3));
}

TEST(BigIntTest, LessThanTestNegPos){
    EXPECT_LT(BigInteger(-3), BigInteger(4));
}

TEST(BigIntTest, LessOrEqualTest){
    EXPECT_LE(BigInteger(1), BigInteger(1));
    EXPECT_LE(BigInteger(1), BigInteger(2));
}

TEST(BigIntTest, GreaterOrEqualTest){
    EXPECT_GE(BigInteger(4), BigInteger(4));
    EXPECT_GE(BigInteger(5), BigInteger(4));
}

TEST(BigIntTest, EqualTest){
    EXPECT_EQ(BigInteger(4), BigInteger(4));
    EXPECT_EQ(BigInteger(-2), BigInteger(-2));
    EXPECT_EQ(BigInteger(0), BigInteger(0));
    EXPECT_EQ(BigInteger(123), BigInteger("123"));
}

TEST(BigIntTest, NotEqualTest){
    EXPECT_NE(BigInteger(2), BigInteger(5));
    EXPECT_NE(BigInteger(4), BigInteger(-4));
}

TEST(BigIntTest, StringReprTest){
    EXPECT_STREQ(BigInteger(256).GetStringRepr().c_str(), "256");
}

TEST(BigIntTest, AdditionTest){
    BigInteger five(5);
    BigInteger two(2);
    BigInteger zero(0);
    BigInteger hundred(100);
    EXPECT_EQ(five + two, 7);
    EXPECT_EQ(-five + -two, -7);
    EXPECT_EQ(five + -two, 3);
    EXPECT_EQ(-five + two, -3);
    EXPECT_EQ(five + zero, 5);
    EXPECT_EQ(five + -zero, 5);
    EXPECT_EQ(hundred + five, 105);
    EXPECT_EQ(hundred + -five, 95);
    EXPECT_EQ(-hundred + five, -95);
    EXPECT_EQ(-hundred + -five, -105);
    EXPECT_EQ(hundred + five + two, 107);
}

TEST(BigIntTest, SubtractionTest){
    BigInteger five(5);
    BigInteger two(2);
    BigInteger zero(0);
    BigInteger hundred(100);
    EXPECT_EQ(five - two, 3);
    EXPECT_EQ(-five - -two, -3);
    EXPECT_EQ(five - -two, 7);
    EXPECT_EQ(-five - two, -7);
    EXPECT_EQ(five - zero, 5);
    EXPECT_EQ(five - -zero, 5);
    EXPECT_EQ(zero - five, -5);
    EXPECT_EQ(zero - -five, 5);
    EXPECT_EQ(two - hundred, -98);
    EXPECT_EQ(hundred - two, 98);
    EXPECT_EQ(zero - hundred, -100);
    EXPECT_EQ(-hundred + five, -95);
    EXPECT_EQ(hundred - five - two, 93);
}

TEST(BigIntTest, UnaryMinusTest){
    EXPECT_EQ(-BigInteger(100), -100);
}