/*
    Assignment:   CSCI205 Week 1 Lab
    Fraction.h - a header file for a fraction class

    Version       1.0 Beta
    Author        Dan Caruso
    Created       9/8/2021
*/

#ifndef FRACTION_H
#define FRACTION_H
using namespace std;

class Fraction {
    private:
        int num;
        int den;

    public:
        // Constructors
        Fraction(int top, int bottom);
        Fraction(int top);
        Fraction();

        // Setters
        void setFraction(int top, int bottom);

        // Getters
        int getNumerator();
        int getDenominator();

        // Friend functions (operator overloading)
        friend Fraction operator +(const Fraction& f1, const Fraction& f2);
        friend Fraction operator -(const Fraction& f1, const Fraction& f2);
        friend Fraction operator *(const Fraction& f1, const Fraction& f2);
        friend Fraction operator /(const Fraction& f1, const Fraction& f2);
        friend Fraction operator +=(const Fraction& f1, const Fraction& f2);
        friend bool operator >(const Fraction& f1, const Fraction& f2);
        friend bool operator >=(const Fraction& f1, const Fraction& f2);
        friend bool operator <(const Fraction& f1, const Fraction& f2);
        friend bool operator <=(const Fraction& f1, const Fraction& f2);
        friend bool operator ==(const Fraction& f1, const Fraction& f2);
        friend bool operator !=(const Fraction& f1, const Fraction& f2);
        friend ostream& operator <<(ostream& stream, const Fraction& fraction);
};

#endif
