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
    BigInteger res(*this);
    res += rhs;
    return res;
}

BigInteger &BigInteger::operator+=(const BigInteger &rhs) {
    if (this->is_negative == rhs.is_negative) { // If signs match on both arguments
        add(rhs);
    } else { // If signs differ, switch to subtraction
        subtract(rhs);
    }
    return *this;
}

BigInteger BigInteger::operator-(const BigInteger &rhs) const {
    BigInteger res(*this);
    res -= rhs;
    return res;
}

BigInteger &BigInteger::operator-=(const BigInteger &rhs) {
    if (this->is_negative == rhs.is_negative) { // If both numbers share the same sign
        subtract(rhs);
    } else { // If operands have opposing signs, switch to addition
        add(rhs);
    }
    return *this;
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
    os << bi.GetStringRepr();
    return os;
}

BigInteger BigInteger::operator-() const {
    BigInteger res(*this);
    res.is_negative = !res.is_negative;
    return res;
}

BigInteger BigInteger::operator+() const {
    return *this;
}

void BigInteger::add(const BigInteger &rhs) {
    int l_ind = 0; // Index of current digit of left operand (this)
    int r_ind = 0; // Index of current digit of right operand (rhs)
    int l_dig; // Current digit in left operand (this)
    int r_dig; // Current digit in right operand (rhs)
    int remainder = 0;
    while (l_ind < this->digits.size() || r_ind < rhs.digits.size() || remainder != 0) {
        l_dig = (l_ind >= this->digits.size() ? 0
                                              : this->digits[l_ind]); // Get current digit from left operand (this)
        r_dig = (r_ind >= rhs.digits.size() ? 0 : rhs.digits[r_ind]); // Get current digit from right operand (rhs)
        if (l_ind >= this->digits.size()) { // If right number is longer than the left
            this->digits.push_back(0); // Add extra digit to left number
        }
        int sum_digit =
                l_dig + r_dig + remainder; // Add 2 digits together, including possible remainder from previous sum
        this->digits[l_ind] = sum_digit % 10;
        remainder = sum_digit / 10;
        ++l_ind;
        ++r_ind;
    }
}

void BigInteger::subtract(const BigInteger &rhs) {
    // Determine a criteria for the resulting sign
    bool is_res_neg = is_negative && abs_goe(rhs) || !is_negative && rhs.abs_goe(*this);
    // Determine if the left argument absolute value is larger than the right one's
    bool is_lhs_bigger = abs_goe(rhs);
    // Result is always writen in *this, regardless of which operand is greater by absolute value.
    this->is_negative = is_res_neg; // Set the resulting sign
    int borrow = 0;
    int l_dig; // Current digit of left operand
    int r_dig; // Current digit of right operand
    int sub; // Current digit of result of subtraction
    for (int i = 0; i < this->digits.size(); ++i) {
        l_dig = this->digits[i];
        r_dig = i >= rhs.digits.size() ? 0 : rhs.digits[i];
        // Calculate result of subtraction for current digits
        sub = (is_lhs_bigger ?
               l_dig - r_dig - borrow :
               r_dig - l_dig - borrow);
        if (sub < 0) {
            this->digits[i] = sub + 10;
            borrow = 1;
        } else {
            this->digits[i] = sub;
            borrow = 0;
        }
    }
    RemoveLeadingZeros();
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
