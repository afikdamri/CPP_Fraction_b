#include "Fraction.hpp"
using namespace std;
#include <cmath>
#include <limits>
#include <iostream>
#include <sstream>

namespace ariel
{
    Fraction::Fraction() : numerator_(0), denominator_(1) {}

    Fraction::Fraction(int num, int den) : numerator_(num), denominator_(den)
    {
        if (den == 0)
        {
            throw invalid_argument("Denominator cannot be zero!");
        }
    }

    Fraction::Fraction(float number)
    {
        int num = static_cast<int>(number * 1000);
        int den = 1000;
        int gcd = __gcd(num, den);
        num /= gcd;
        den /= gcd;
        numerator_ = num;
        denominator_ = den;
    }

    int Fraction::getNumerator() const
    {
        return numerator_;
    }

    int Fraction::getDenominator() const
    {
        return denominator_;
    }

    Fraction floatToFraction(float number)
    {
        const int decimalPlaces = 3;
        const int scale = pow(10, decimalPlaces);

        int numerator = static_cast<int>(round(number * scale));
        int denominator = scale;

        int gcd = __gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        return Fraction(numerator, denominator);
    }

    ostream &operator<<(ostream &ostream, const Fraction &fraction)
    {
        int num = fraction.numerator_;
        int den = fraction.denominator_;

        int gcd = __gcd(num, den);
        num /= gcd;
        den /= gcd;

        if (den < 0)
        {
            num = -num;
            den = -den;
        }

        if (num < 0)
        {
            ostream << "-";
            num = -num;
        }

        if (den == 1)
        {
            ostream << num;
        }
        else
        {
            ostream << num << '/' << den;
        }

        return ostream;
    }

    istream &operator>>(istream &data, Fraction &fraction)
    {
        int numerator, denominator;
        data >> numerator >> denominator;

        if (data.fail())
        {
            throw runtime_error("Invalid input format");
        }

        if (denominator == 0)
        {
            throw runtime_error("Invalid fraction format");
        }

        if (numerator == 0)
        {
            fraction.numerator_ = 0;
            fraction.denominator_ = 1;
            return data;
        }
        int sign = (numerator < 0) != (denominator < 0) ? -1 : 1;
        numerator = abs(numerator);
        denominator = abs(denominator);
        fraction.numerator_ = sign * numerator;
        fraction.denominator_ = denominator;
        return data;
    }

    Fraction Fraction::operator+(const Fraction &fraction) const
    {
        long long num = (long long)fraction.numerator_ * denominator_ + numerator_ * fraction.denominator_;
        long long den = (long long)fraction.denominator_ * denominator_;

        if (num > numeric_limits<int>::max() || num < numeric_limits<int>::min() || den > numeric_limits<int>::max() || den < numeric_limits<int>::min())
        {
            throw overflow_error("Overflow in operator+");
        }

        int new_numerator = static_cast<int>(num);
        int new_denominator = static_cast<int>(den);

        int gcd = __gcd(new_numerator, new_denominator);
        new_numerator /= gcd;
        new_denominator /= gcd;

        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator+(const Fraction &fraction, const float &number)
    {
        Fraction numberFraction = floatToFraction(number);
        int num = fraction.getNumerator() * numberFraction.getDenominator() + numberFraction.getNumerator() * fraction.getDenominator();
        int den = fraction.getDenominator() * numberFraction.getDenominator();
        int gcd = __gcd(num, den);
        return Fraction(num / gcd, den / gcd);
    }

    Fraction operator+(const float &number, const Fraction &fraction)
    {
        Fraction numberFraction = floatToFraction(number);
        int num = fraction.getNumerator() * numberFraction.getDenominator() + numberFraction.getNumerator() * fraction.getDenominator();
        int den = fraction.getDenominator() * numberFraction.getDenominator();
        int gcd = __gcd(num, den);
        return Fraction(num / gcd, den / gcd);
    }

    Fraction Fraction::operator-(const Fraction &fraction) const
    {
        long long num = (long long)numerator_ * fraction.denominator_ - (long long)fraction.numerator_ * denominator_;
        long long den = (long long)denominator_ * fraction.denominator_;

        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min() ||
            den > std::numeric_limits<int>::max() || den < std::numeric_limits<int>::min())
        {
            throw std::overflow_error("Overflow in operator-");
        }

        int new_numerator = static_cast<int>(num);
        int new_denominator = static_cast<int>(den);

        int gcd = __gcd(new_numerator, new_denominator);
        new_numerator /= gcd;
        new_denominator /= gcd;

        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator-(const float &number, const Fraction &fraction)
    {
        Fraction numberFraction = floatToFraction(number);
        int new_numerator = numberFraction.getNumerator() * fraction.getDenominator() - fraction.getNumerator() * numberFraction.getDenominator();
        int new_denominator = fraction.getDenominator() * numberFraction.getDenominator();
        int gcd = __gcd(new_numerator, new_denominator);
        return Fraction(new_numerator / gcd, new_denominator / gcd);
    }

    Fraction operator-(const Fraction &fraction, const float &number)
    {
        Fraction numberFraction = floatToFraction(number);
        int new_numerator = fraction.getNumerator() * numberFraction.getDenominator() - numberFraction.getNumerator() * fraction.getDenominator();
        int new_denominator = fraction.getDenominator() * numberFraction.getDenominator();
        int gcd = __gcd(new_numerator, new_denominator);
        return Fraction(new_numerator / gcd, new_denominator / gcd);
    }

    Fraction Fraction::operator/(const Fraction &fraction) const
    {
        if (fraction.numerator_ == 0)
        {
            throw runtime_error("Divide by zero error");
        }

        long long num = (long long)numerator_ * fraction.denominator_;
        long long den = (long long)denominator_ * fraction.numerator_;
        cout << num << " /" << den << endl;

        if ((num > numeric_limits<int>::max() && den <= numeric_limits<int>::max()) ||
            (num < numeric_limits<int>::min() && den >= numeric_limits<int>::min()) ||
            (den > numeric_limits<int>::max() && num <= numeric_limits<int>::max()) ||
            (den < numeric_limits<int>::min() && num >= numeric_limits<int>::min()))
        {
            throw overflow_error("Overflow in operator/");
        }

        int new_numerator = static_cast<int>(num);
        int new_denominator = static_cast<int>(den);

        int gcd = __gcd(new_numerator, new_denominator);
        new_numerator /= gcd;
        new_denominator /= gcd;

        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator/(const Fraction &fraction, const float &number)
    {
        if (number == 0.0)
        {
            throw runtime_error("Divide by zero error");
        }
        Fraction numberFraction = floatToFraction(number);
        int new_numerator = fraction.numerator_ * numberFraction.denominator_;
        int new_denominator = fraction.denominator_ * numberFraction.numerator_;

        int gcd = __gcd(new_numerator, new_denominator);
        new_numerator /= gcd;
        new_denominator /= gcd;

        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator/(const float &number, const Fraction &fraction)
    {
        if (fraction.numerator_ == 0)
        {
            throw runtime_error("Divide by zero error");
        }
        Fraction numberFraction = floatToFraction(number);
        int new_numerator = numberFraction.numerator_ * fraction.denominator_;
        int new_denominator = numberFraction.denominator_ * fraction.numerator_;

        int gcd = __gcd(new_numerator, new_denominator);
        new_numerator /= gcd;
        new_denominator /= gcd;

        return Fraction(new_numerator, new_denominator);
    }

    bool Fraction::operator<(const Fraction &fraction) const
    {
        int num1 = numerator_ * fraction.denominator_;
        int num2 = fraction.numerator_ * denominator_;
        return num1 < num2;
    }

    bool operator<(const float &number, const Fraction &fraction)
    {
        return number * fraction.denominator_ < fraction.numerator_;
    }

    bool operator<(const Fraction &fraction, const float &number)
    {
        return fraction.numerator_ < number * fraction.denominator_;
    }

    bool Fraction::operator>(const Fraction &fraction) const
    {
        int num1 = numerator_ * fraction.denominator_;
        int num2 = fraction.numerator_ * denominator_;
        return num1 > num2;
    }

    bool operator>(const Fraction &fraction, const float &number)
    {
        float fractionValue = (float)(fraction.getNumerator()) / fraction.getDenominator();
        return fractionValue > number;
    }

    bool operator>(const float &number, const Fraction &fraction)
    {
        float fractionValue = (float)(fraction.getNumerator()) / fraction.getDenominator();
        return number > fractionValue;
    }

    Fraction Fraction::operator*(const Fraction &fraction) const
    {
        long long num = (long long)fraction.numerator_ * numerator_;
        long long den = (long long)fraction.denominator_ * denominator_;

        if ((num > numeric_limits<int>::max() && den <= numeric_limits<int>::max()) ||
            (num < numeric_limits<int>::min() && den >= numeric_limits<int>::min()) ||
            (den > numeric_limits<int>::max() && num <= numeric_limits<int>::max()) ||
            (den < numeric_limits<int>::min() && num >= numeric_limits<int>::min()))
        {
            throw overflow_error("Overflow in operator*");
        }

        int new_numerator = static_cast<int>(num);
        int new_denominator = static_cast<int>(den);

        int gcd = __gcd(new_numerator, new_denominator);
        new_numerator /= gcd;
        new_denominator /= gcd;

        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator*(const float &number, const Fraction &fraction)
    {
        Fraction numberFraction = floatToFraction(number);
        return numberFraction * fraction;
    }

    Fraction operator*(const Fraction &fraction, const float &number)
    {
        Fraction numberFraction = floatToFraction(number);
        return fraction * numberFraction;
    }

    bool Fraction::operator<=(const Fraction &fraction) const
    {
        int num1 = numerator_ * fraction.denominator_;
        int num2 = fraction.numerator_ * denominator_;
        return num1 <= num2;
    }

    bool operator<=(const Fraction &fraction, const float &number)
    {
        Fraction fractionNumber = floatToFraction(number);
        return fraction <= fractionNumber;
    }

    bool operator<=(const float &number, const Fraction &fraction)
    {
        Fraction fractionNumber = floatToFraction(number);
        return fractionNumber <= fraction;
    }

    bool Fraction::operator>=(const Fraction &fraction) const
    {
        int num1 = numerator_ * fraction.denominator_;
        int num2 = fraction.numerator_ * denominator_;
        return num1 >= num2;
    }

    bool operator>=(const Fraction &fraction, const float &number)
    {
        float result = static_cast<float>(fraction.numerator_) / fraction.denominator_;
        return result >= number;
    }

    bool operator>=(const float &number, const Fraction &fraction)
    {
        float result = static_cast<float>(fraction.numerator_) / fraction.denominator_;
        return number >= result;
    }

    bool Fraction::operator==(const Fraction &fraction) const
    {
        int num1 = numerator_ * fraction.denominator_;
        int num2 = fraction.numerator_ * denominator_;

        if ((num1 < 0 && num2 >= 0) || (num1 >= 0 && num2 < 0))
        {
            return false;
        }
        return num1 == num2;
    }

    bool operator==(const Fraction &fraction, const float &number)
    {
        int gcd = __gcd(fraction.numerator_, fraction.denominator_);
        int num = fraction.numerator_ / gcd;
        int den = fraction.denominator_ / gcd;
        float result = static_cast<float>(num) / static_cast<float>(den);
        return result == number;
    }

    bool operator==(const float &number, const Fraction &fraction)
    {
        return fraction == number;
    }

    // Prefix
    Fraction &Fraction::operator--()
    {
        numerator_ -= denominator_;
        return *this;
    }

    // Postfix
    Fraction Fraction::operator--(int)
    {
        Fraction tmp(*this);
        --(*this);
        return tmp;
    }

    // Prefix
    Fraction &Fraction::operator++()
    {
        numerator_ += denominator_;
        return *this;
    }

    // Postfix
    Fraction Fraction::operator++(int)
    {
        Fraction tmp(*this);
        ++(*this);
        return tmp;
    }
};