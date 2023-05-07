#include "Fraction.hpp"
using namespace std;

namespace ariel
{
    Fraction::Fraction() : numerator_(0), denominator_(1) {}

    Fraction::Fraction(int num, int den) : numerator_(num), denominator_(den)
    {
        if (den == 0)
        {
            throw std::invalid_argument("Denominator cannot be zero!");
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

    ostream &operator<<(ostream &ostream, const Fraction &fraction)
    {
        ostream << fraction.numerator_ << "/" << fraction.denominator_;
        return ostream;
    }

    istream &operator>>(istream &data, Fraction &fraction)
    {
        int num, den;
        char slash;
        data >> num >> slash >> den;
        fraction = Fraction(num, den);
        return data;
    }

    Fraction Fraction::operator+(const Fraction &fraction) const
    {
        int num = fraction.numerator_ * denominator_ + numerator_ * fraction.denominator_;
        int den = fraction.denominator_ * denominator_;
        int gcd = 1;
        for (int i = 1; i <= std::min(num, den); ++i)
        {
            if (num % i == 0 && den % i == 0)
            {
                gcd = i;
            }
        }
        return Fraction(num / gcd, den / gcd);
    }

    Fraction operator+(const Fraction &fraction, const float &number)
    {
        int num = fraction.getNumerator() + (number * fraction.getDenominator());
        int den = fraction.getDenominator();
        int gcd = 1;
        for (int i = 1; i <= std::min(num, den); ++i)
        {
            if (num % i == 0 && den % i == 0)
            {
                gcd = i;
            }
        }
        return Fraction(num / gcd, den / gcd);
    }

    Fraction operator+(const float &number, const Fraction &fraction)
    {
        int num = fraction.getNumerator() + (number * fraction.getDenominator());
        int den = fraction.getDenominator();
        int gcd = 1;
        for (int i = 1; i <= std::min(num, den); ++i)
        {
            if (num % i == 0 && den % i == 0)
            {
                gcd = i;
            }
        }
        return Fraction(num / gcd, den / gcd);
    }

    Fraction Fraction::operator-(const Fraction &fraction) const
    {
        int new_numerator = numerator_ * fraction.denominator_ - fraction.numerator_ * denominator_;
        int new_denominator = denominator_ * fraction.denominator_;
        if (new_numerator < 0 && new_denominator < 0){
            new_numerator = -new_numerator;
            new_denominator = -new_denominator;
        }
        if (new_numerator < 0 && new_denominator > 0){
            new_numerator = -new_numerator;
            new_denominator = -new_denominator;
        }
        int gcd = __gcd(new_numerator, new_denominator);
        new_numerator /= gcd;
        new_denominator /= gcd;

        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator-(const Fraction &fraction, const float &number)
    {
        float numerator_ = fraction.numerator_ - (fraction.denominator_ * number);
        return Fraction(numerator_, fraction.denominator_);
    }

    Fraction operator-(const float &number, const Fraction &fraction)
    {
        float numerator_ = fraction.numerator_ - (fraction.denominator_ * number);
        return Fraction(numerator_, fraction.denominator_);
    }

    Fraction Fraction::operator/(const Fraction &fraction) const
    {
        int num = numerator_ * fraction.denominator_;
        int den = denominator_ * fraction.numerator_;
        int gcd = __gcd(num, den);
        return Fraction(num / gcd, den / gcd);
    }

    Fraction operator/(const Fraction &fraction, const float &number)
    {
        int num = fraction.numerator_;
        int den = fraction.denominator_ * number * 1000;
        int gcd = __gcd(num, den);
        return Fraction(num / gcd, den / gcd);
    }

    Fraction operator/(const float &number, const Fraction &fraction)
    {
        int num = fraction.denominator_ * number * 1000;
        int den = fraction.numerator_;
        int gcd = __gcd(num, den);
        return Fraction(num / gcd, den / gcd);
    }

    bool Fraction::operator<(const Fraction &fraction) const
    {
        int commonDenominator_ = fraction.denominator_ * denominator_;
        int numerator_1 = fraction.numerator_ * denominator_;
        int numerator_2 = numerator_ * fraction.denominator_;

        return numerator_1 < numerator_2;
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
        return numerator_ * fraction.denominator_ > fraction.numerator_ * denominator_;
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
        int num = fraction.numerator_ * numerator_;
        int den = fraction.denominator_ * denominator_;
        int gcd = 1;
        for (int i = 1; i <= min(abs(num), abs(den)); ++i)
        {
            if (num % i == 0 && den % i == 0)
            {
                gcd = i;
            }
        }
        if (num < 0 && den < 0)
        {
            num = std::abs(num);
            den = std::abs(den);
        }
        else if (den < 0)
        {
            num *= -1;
            den = std::abs(den);
        }
        return Fraction(num / gcd, den / gcd);
    }

    Fraction operator*(const float &number, const Fraction &fraction)
    {
        float num = fraction.numerator_ * number;
        float den = fraction.denominator_;
        float gcd = __gcd(static_cast<int>(num), static_cast<int>(den));
        return Fraction(num / gcd, den / gcd);
    }

    Fraction operator*(const Fraction &fraction, const float &number)
    {
        float num = fraction.numerator_ * number;
        return Fraction(num, fraction.denominator_);
    }

    bool Fraction::operator<=(const Fraction &fraction) const
    {
        return (numerator_ * fraction.denominator_) <= (fraction.numerator_ * denominator_);
    }

    bool operator<=(const Fraction &fraction, const float &number)
    {
        float result = static_cast<float>(fraction.numerator_) / fraction.denominator_;
        return result <= number;
    }

    bool operator<=(const float &number, const Fraction &fraction)
    {
        float result = number / static_cast<float>(fraction.denominator_);
        return result <= static_cast<float>(fraction.numerator_) / fraction.denominator_;
    }

    bool Fraction::operator>=(const Fraction &fraction) const
    {
        return (numerator_ * fraction.denominator_) >= (fraction.numerator_ * denominator_);
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
        int gcd1 = __gcd(numerator_, denominator_);
        int gcd2 = __gcd(fraction.numerator_, fraction.denominator_);

        int num1 = numerator_ / gcd1;
        int den1 = denominator_ / gcd1;
        int num2 = fraction.numerator_ / gcd2;
        int den2 = fraction.denominator_ / gcd2;
        return (num1 == num2) && (den1 == den2);
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