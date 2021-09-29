//
// Created by appollogate on 9/29/21.
//

#ifndef CPP_HW1_BIGINTEGER_H
#define CPP_HW1_BIGINTEGER_H

#include <vector>
#include <string>
#include <utility>
#include <exception>
#include <sstream>


class BigInteger {
public:
    BigInteger(int64_t);

    BigInteger(const std::string &);

    BigInteger(const BigInteger &); // Copy constructor

    BigInteger &operator=(const BigInteger &); // Copy assignment operator

    BigInteger operator+(const BigInteger &) const;

    BigInteger& operator+=(const BigInteger &);

    BigInteger operator-(const BigInteger &) const;

    bool operator<(const BigInteger &) const;

    bool operator>(const BigInteger &) const;

    bool operator<=(const BigInteger &) const;

    bool operator>=(const BigInteger &) const;

    bool operator==(const BigInteger &) const;

    bool operator!=(const BigInteger &) const;

    BigInteger operator+() const;

    BigInteger operator-() const;

    [[nodiscard]] std::string GetStringRepr() const;

private:
    BigInteger abs_add(const BigInteger &, const BigInteger &) const;

    BigInteger abs_subtract(const BigInteger &, const BigInteger &) const;

    [[nodiscard]] bool abs_goe(const BigInteger &) const; // Absolute Greater or Equal

    void RemoveLeadingZeros();

    std::vector<ushort> digits;
    bool is_negative;
};

#endif //CPP_HW1_BIGINTEGER_H
