#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

namespace ariel
{
    class Fraction
    {
    private:
        int numerator_;
        int denominator_;

    public:
        Fraction(int num, int den);
        Fraction();
        Fraction(float number);

        int getNumerator() const;
        int getDenominator() const;

        static Fraction floatToFraction(float number);

        friend ostream &operator<<(std::ostream &ostream, const Fraction &fraction);
        friend std::istream &operator>>(std::istream &data, Fraction &fraction);

        Fraction operator+(const Fraction &fraction) const;
        friend Fraction operator+(const Fraction &fraction, const float &number);
        friend Fraction operator+(const float &number, const Fraction &fraction);

        Fraction operator-(const Fraction &fraction) const;
        friend Fraction operator-(const Fraction &fraction, const float &number);
        friend Fraction operator-(const float &number, const Fraction &fraction);

        Fraction operator/(const Fraction &fraction) const;
        friend Fraction operator/(const Fraction &fraction, const float &number);
        friend Fraction operator/(const float &number, const Fraction &fraction);

        Fraction operator*(const Fraction &fraction) const;
        friend Fraction operator*(const Fraction &fraction, const float &number);
        friend Fraction operator*(const float &number, const Fraction &fraction);

        bool operator<(const Fraction &fraction) const;
        friend bool operator<(const Fraction &fraction, const float &number);
        friend bool operator<(const float &number, const Fraction &fraction);

        bool operator>(const Fraction &fraction) const;
        friend bool operator>(const Fraction &fraction1, const float &number);
        friend bool operator>(const float &number, const Fraction &fraction);

        bool operator>=(const Fraction &fraction) const;
        friend bool operator>=(const Fraction &fraction1, const float &number);
        friend bool operator>=(const float &number, const Fraction &fraction);

        bool operator<=(const Fraction &fraction) const;
        friend bool operator<=(const Fraction &fraction1, const float &number);
        friend bool operator<=(const float &number, const Fraction &fraction);

        bool operator==(const Fraction &fraction) const;
        friend bool operator==(const Fraction &fraction1, const float &number);
        friend bool operator==(const float &number, const Fraction &fraction);

        Fraction &operator++();
        Fraction operator++(int);

        Fraction &operator--();
        Fraction operator--(int);
    };
};
