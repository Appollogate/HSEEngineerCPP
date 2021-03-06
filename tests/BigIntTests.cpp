//
// Created by appollogate on 9/29/21.
//

#include <gtest/gtest.h>
#include "../src/BigInteger.h"

TEST(BigIntTest, GreaterThanTestPos) {
    EXPECT_GT(BigInteger(2), BigInteger(1));
    EXPECT_GT(BigInteger(172), BigInteger(164));
}

TEST(BigIntTest, GreaterThanTestNeg) {
    EXPECT_GT(BigInteger(-1), BigInteger(-2));
}

TEST(BigIntTest, GreaterThanTestPosNeg) {
    EXPECT_GT(BigInteger(2), BigInteger(-1));
}

TEST(BigIntTest, LessThanTestPos) {
    EXPECT_LT(BigInteger(3), BigInteger(4));
}

TEST(BigIntTest, LessThanTestNeg) {
    EXPECT_LT(BigInteger(-4), BigInteger(-3));
}

TEST(BigIntTest, LessThanTestNegPos) {
    EXPECT_LT(BigInteger(-3), BigInteger(4));
}

TEST(BigIntTest, LessOrEqualTest) {
    EXPECT_LE(BigInteger(1), BigInteger(1));
    EXPECT_LE(BigInteger(1), BigInteger(2));
}

TEST(BigIntTest, GreaterOrEqualTest) {
    EXPECT_GE(BigInteger(4), BigInteger(4));
    EXPECT_GE(BigInteger(5), BigInteger(4));
}

TEST(BigIntTest, EqualTest) {
    EXPECT_EQ(BigInteger(4), BigInteger(4));
    EXPECT_EQ(BigInteger(-2), BigInteger(-2));
    EXPECT_EQ(BigInteger(0), BigInteger(0));
    EXPECT_EQ(BigInteger(123), BigInteger("123"));
}

TEST(BigIntTest, NotEqualTest) {
    EXPECT_NE(BigInteger(2), BigInteger(5));
    EXPECT_NE(BigInteger(4), BigInteger(-4));
}

TEST(BigIntTest, StringReprTest) {
    EXPECT_STREQ(BigInteger(256).GetStringRepr().c_str(), "256");
}

TEST(BigIntTest, AdditionTest) {
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

TEST(BigIntTest, SubtractionTest) {
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

TEST(BigIntTest, UnaryMinusTest) {
    EXPECT_EQ(-BigInteger(100), -100);
}

TEST(BigIntTest, MultiplicationTest) {
    BigInteger bi1(24);
    BigInteger bi2(58);
    BigInteger one(1);
    BigInteger zero(0);
    EXPECT_EQ(bi1 * bi2, 1392);
    EXPECT_EQ(bi2 * bi1, 1392);
    EXPECT_EQ(-bi1 * -bi2, 1392);
    EXPECT_EQ(bi1 * -bi2, -1392);
    EXPECT_EQ(bi1 * -bi2, -1392);
    EXPECT_EQ(bi1 * one, 24);
    EXPECT_EQ(one * bi1, 24);
    EXPECT_EQ(bi1 * -one, -24);
    EXPECT_EQ(-one * bi1, -24);
    EXPECT_EQ(zero * bi1, 0);
    EXPECT_EQ(bi1 * zero, 0);
}

TEST(BigIntTest, DivisionTest) {
    BigInteger bi1(5624);
    BigInteger bi2(71);
    BigInteger one(1);
    BigInteger zero(0);
    EXPECT_EQ(bi1 / bi2, 79);
    EXPECT_EQ(bi1 / -bi2, -79);
    EXPECT_EQ(-bi1 / bi2, -79);
    EXPECT_EQ(bi1 % bi2, 15);
    EXPECT_EQ(bi1 % bi2, 15);
    EXPECT_EQ(bi1 % bi2, 15);
    EXPECT_EQ(bi2 / bi1, 0);
    EXPECT_EQ(bi2 % bi1, 71);
    EXPECT_EQ(bi1 / bi1, 1);
    EXPECT_EQ(bi1 % bi1, 0);
    EXPECT_EQ(bi1 / -bi1, -1);
    EXPECT_EQ(-bi1 / bi1, -1);
    EXPECT_EQ(bi1 % -bi1, 0);
    EXPECT_EQ(-bi1 % bi1, 0);
    EXPECT_EQ(bi1 / one, bi1);
    EXPECT_EQ(bi1 % one, zero);
    EXPECT_EQ(zero / bi1, zero);
    EXPECT_EQ(zero % bi1, zero);
    EXPECT_ANY_THROW(bi1 / zero);
    EXPECT_ANY_THROW(bi1 % zero);
}