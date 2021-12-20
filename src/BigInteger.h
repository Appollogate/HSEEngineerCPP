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
#include <algorithm>


class BigInteger {
public:
    BigInteger();

    BigInteger(int64_t);

    BigInteger(const std::string &);

    BigInteger(const BigInteger &); // Copy constructor

    BigInteger &operator=(const BigInteger &); // Copy assignment operator

    BigInteger operator+(const BigInteger &) const;

    BigInteger &operator+=(const BigInteger &);

    BigInteger operator-(const BigInteger &) const;

    BigInteger &operator-=(const BigInteger &);

    BigInteger operator*(const BigInteger &) const;

    BigInteger &operator*=(const BigInteger &);

    BigInteger operator/(const BigInteger &) const;

    BigInteger &operator/=(const BigInteger &);

    BigInteger operator%(const BigInteger &) const;

    BigInteger &operator%=(const BigInteger &);

    bool operator<(const BigInteger &) const;

    bool operator>(const BigInteger &) const;

    bool operator<=(const BigInteger &) const;

    bool operator>=(const BigInteger &) const;

    bool operator==(const BigInteger &) const;

    bool operator!=(const BigInteger &) const;

    BigInteger operator+() const;

    BigInteger operator-() const;

    [[nodiscard]] std::string GetStringRepr() const;

    friend std::ostream &operator<<(std::ostream &, const BigInteger &);

    static BigInteger getResultFromOperation(const BigInteger &, const BigInteger &, const std::string &);

private:
    void add(const BigInteger &);

    void subtract(const BigInteger &);

    [[nodiscard]] std::pair<BigInteger, BigInteger> divide(const BigInteger &) const;

    void RemoveLeadingZeros();

    [[nodiscard]] BigInteger SelectClosestByFront(const BigInteger &, int div_len) const;

    [[nodiscard]] int GetMultiplier(const BigInteger &) const;

    [[nodiscard]] bool abs_goe(const BigInteger &) const; // Absolute Greater or Equal

    [[nodiscard]] bool is_zero() const;

    std::vector<ushort> digits;
    bool is_negative;
};

#endif //CPP_HW1_BIGINTEGER_H
