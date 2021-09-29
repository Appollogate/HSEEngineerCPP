//
// Created by appollogate on 9/29/21.
//

#include "BigInteger.h"

BigInteger::BigInteger(int64_t num) {
    is_negative = num < 0;
    while (num != 0) {
        ushort digit = std::abs(num % 10);
        digits.push_back(digit);
        num /= 10;
    }
}

// Utility method for checking if the passed string represents a number.
bool IsStringIntegral(const std::string &str) {
    if (str.empty()) {
        return false;
    }
    // Check first digit/sign
    if (!(str[0] >= '0' && str[0] <= '9' || str[0] == '-')) {
        return false;
    }
    for (size_t i = 1; i < str.size(); ++i) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

BigInteger::BigInteger(const std::string &str) {
    if (!IsStringIntegral(str)) {
        throw std::invalid_argument("Given string \"" + str + "\" is not an integral number.\n");
    }
    is_negative = str[0] == '-';
    int start_index = is_negative ? 1 : 0;
    for (int i = static_cast<int>(str.size() - 1); i >= start_index; --i) {
        ushort digit = str[i] - '0';
        digits.push_back(digit);
    }
}

// Copy constructor
BigInteger::BigInteger(const BigInteger &rhs) {
    digits = rhs.digits;
    is_negative = rhs.is_negative;
}

// Copy assignment operator
BigInteger &BigInteger::operator=(const BigInteger &rhs) = default;

std::string BigInteger::GetStringRepr() const {
    std::ostringstream stream;
    if (is_negative) {
        stream << "-";
    }
    for (int i = static_cast<int>(digits.size() - 1); i >= 0; --i) {
        stream << digits[i];
    }
    return stream.str();
}


BigInteger BigInteger::operator+(const BigInteger &rhs) const {
    if (this->is_negative == rhs.is_negative) { // If signs match on both arguments
        if (!this->is_negative) { // If both signs are positive (ex: 2 + 5)
            return BigInteger::abs_add(*this, rhs);
        } else { // If both signs are negative (ex: -2 + -5)
            BigInteger res = BigInteger::abs_add(*this, rhs);
            res.is_negative = true; // Sum of two negative numbers will be negative
            return res;
        }
    } else { // If signs differ, switch to subtraction
        if (!this->is_negative) { // If first sign is positive and second is negative
            if (this->abs_goe(rhs)) { // ex: 5 + -2
                return BigInteger::abs_subtract(*this, rhs);
            } else { // ex: 2 + -5
                return -BigInteger::abs_subtract(rhs, *this);
            }
        } else { // If first sign is negative and second one is positive
            if (this->abs_goe(rhs)) { // ex: -5 + 2
                return -BigInteger::abs_subtract(*this, rhs);
            } else { // ex: -2 + 5
                return BigInteger::abs_subtract(rhs, *this);
            }
        }
    }
}

BigInteger &BigInteger::operator+=(const BigInteger &rhs) {
    *this = *this + rhs;
    return *this;
}

BigInteger BigInteger::operator-(const BigInteger &rhs) const {
    if (this->is_negative == rhs.is_negative) { // If both numbers share the same sign
        if (!this->is_negative) { // If both operands are non-negative
            if (this->abs_goe(rhs)) {  // If |lhs| >= |rhs|, ex: 5 - 2
                return BigInteger::abs_subtract(*this, rhs);
            } else { // If |lhs| < |rhs|, ex: 2 - 5
                return -BigInteger::abs_subtract(rhs, *this);
            }
        } else { // If both operands are negative
            if (this->abs_goe(rhs)) { // If |lhs| >= |rhs|, ex: -5 - -2
                return -BigInteger::abs_subtract(*this, rhs);
            } else { // If |lhs| < |rhs|, ex: -2 - -5
                return BigInteger::abs_subtract(rhs, *this);
            }
        }
    } else { // If operands have opposing signs, switch to addition
        if (!this->is_negative) {// If first operand is non-negative and second one is negative, ex: 2 - -5 or 5 - -2
            return BigInteger::abs_add(*this, rhs);
        } else { // If first operand is negative and second one is not, ex: -5 - 2 or -2 - 5
            return -BigInteger::abs_add(*this, rhs);
        }
    }
}

bool BigInteger::operator<(const BigInteger &rhs) const {
    // Check the signs first
    if (this->is_negative && !rhs.is_negative) {
        return true;
    }
    if (!this->is_negative && rhs.is_negative) {
        return false;
    }
    // If signs match, check number length.
    // Consider the case where both numbers are negative.
    if (this->digits.size() < rhs.digits.size()) {
        return !this->is_negative;
    }
    if (this->digits.size() > rhs.digits.size()) {
        return this->is_negative;
    }
    // If number length is equal, start checking by digits
    for (int i = 0; i < rhs.digits.size(); ++i) {
        if (rhs.digits[i] > this->digits[i]) {
            return !this->is_negative;
        }
        if (rhs.digits[i] < this->digits[i])
            return this->is_negative;
    }
    // At this point the numbers would be equal
    return this->is_negative;
}

bool BigInteger::operator>(const BigInteger &rhs) const {
    return rhs < *this;
}

bool BigInteger::operator==(const BigInteger &rhs) const {
    return !(*this < rhs) && !(*this > rhs);
}

bool BigInteger::operator!=(const BigInteger &rhs) const {
    return !(*this == rhs);
}

bool BigInteger::operator>=(const BigInteger &rhs) const {
    return (*this > rhs) || (*this == rhs);
}

bool BigInteger::operator<=(const BigInteger &rhs) const {
    return (*this < rhs) || (*this == rhs);
}

std::ostream &operator<<(std::ostream &os, const BigInteger &bi) {
    return os << bi.GetStringRepr();
}

BigInteger BigInteger::operator-() const {
    BigInteger res(*this);
    res.is_negative = !res.is_negative;
    return res;
}

BigInteger BigInteger::operator+() const {
    return *this;
}

BigInteger BigInteger::abs_add(const BigInteger &lhs, const BigInteger &rhs) const { // |lhs| + |rhs| basically
    BigInteger res(lhs);
    res.is_negative = false; // Sum of two non-negative numbers cannot be negative
    int l_ind = 0; // Index of current digit of left operand
    int r_ind = 0; // Index of current digit of right operand
    int l_dig = 0; // Current digit in left operand
    int r_dig = 0; // Current digit in right operand
    int remainder = 0;
    while (l_ind < res.digits.size() || r_ind < rhs.digits.size() || remainder != 0) {
        l_dig = (l_ind >= res.digits.size() ? 0 : res.digits[l_ind]); // Get current digit from left operand
        r_dig = (r_ind >= rhs.digits.size() ? 0 : rhs.digits[r_ind]); // Get current digit from right operand
        if (l_ind >= res.digits.size()) { // If right number is longer than the left
            res.digits.push_back(0); // add extra digit to left number
        }
        int sum_digit =
                l_dig + r_dig + remainder; // Add 2 digits together, including possible remainder from previous sum
        res.digits[l_ind] = sum_digit % 10;
        remainder = sum_digit / 10;
        ++l_ind;
        ++r_ind;
    }
    return res;
}

BigInteger BigInteger::abs_subtract(const BigInteger &lhs, const BigInteger &rhs) const {
    // Left-side argument absolute value should always be greater than the right one
    BigInteger res(lhs);
    res.is_negative = false;
    int borrow = 0;
    int l_dig = 0;
    int r_dig = 0;
    int sub = 0;
    for (int i = 0; i < res.digits.size(); ++i) {
        l_dig = res.digits[i];
        r_dig = i >= rhs.digits.size() ? 0 : rhs.digits[i];
        sub = l_dig - r_dig - borrow; // Calculate result of subtraction for current digits
        if (sub < 0) {
            res.digits[i] = sub + 10;
            borrow = 1;
        } else {
            res.digits[i] = sub;
            borrow = 0;
        }
    }
    res.RemoveLeadingZeros();
    return res;
}

void BigInteger::RemoveLeadingZeros() {
    while (digits[digits.size() - 1] == 0) {
        digits.pop_back();
    }
}

bool BigInteger::abs_goe(const BigInteger &rhs) const {
    BigInteger left(*this);
    BigInteger right(rhs);
    // Mark both numbers as non-negative
    left.is_negative = false;
    right.is_negative = false;
    return left >= right;
}