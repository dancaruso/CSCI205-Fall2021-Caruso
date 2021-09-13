/*
    Assignment:   CSCI205 Week 1 Lab
    Fraction.cpp - an implementation file for a fraction class header

    Version       1.0 Beta
    Author        Dan Caruso
    Created       9/8/2021
*/

#include <iostream>
#include <typeinfo>
#include <vector>
#include "Fraction.h"
using namespace std;

// GCD helper function - processes the GCD of two integers
int gcd(int m, int n) {
    while (m%n != 0) {
        int oldm = m;
        int oldn = n;

        m = oldn;
        n = oldm%oldn;
    }
    return n;
}

// Constructor
Fraction::Fraction(int top, int bottom) {
    std::string tname = typeid(top).name();
    std::string bname = typeid(bottom).name();
    if ((tname != "i") || (bname != "i")) {\
        cout << "Error - either the numerator or denominator is a non-integer" << endl;
    }

    int common = gcd(abs(top), abs(bottom));
    if (bottom < 0) {
        setFraction(((top * -1)/common), ((bottom * -1)/common));
    }
    else {
        setFraction(top/common, bottom/common);
    }
}    

// setFraction - sets numerator and denominator of a fraction object, reducing them based on their shared GCD
void Fraction::setFraction(int top, int bottom) {
    num = top;
    den = bottom;
}

// getNumerator() - returns the numerator of a fraction object
int Fraction::getNumerator() {
    return num;
}

// getDenominator() - returns the denominator of a fraction object
int Fraction::getDenominator() {
    return den;
}

// Operator overloading
Fraction operator +(const Fraction& f1, const Fraction& f2) {
    int newnum = f1.num*f2.den + f1.den*f2.num;
    int newden = f1.den*f2.den;
    return Fraction(newnum,newden);
}

Fraction operator -(const Fraction& f1, const Fraction& f2) {
    int newnum = f1.num*f2.den - f1.den*f2.num;
    int newden = f1.den*f2.den;
    return Fraction(newnum,newden);
}

Fraction operator *(const Fraction& f1, const Fraction& f2) {
    int newnum = f1.num*f2.num;
    int newden = f1.den*f2.den;
    return Fraction(newnum, newden);
}

Fraction operator /(const Fraction& f1, const Fraction& f2) {
    int newnum = f1.num*f2.den;
    int newden = f1.den*f2.num;
    return Fraction(newnum, newden);
}

Fraction operator +=(const Fraction& f1, const Fraction& f2) {
    return (f1 + f2);
}

bool operator >(const Fraction& f1, const Fraction& f2) {
    int firstnum = f1.num*f2.den;
    int secondnum = f2.num*f1.den;
    return firstnum > secondnum;
}

bool operator >=(const Fraction& f1, const Fraction& f2) {
    int firstnum = f1.num*f2.den;
    int secondnum = f2.num*f1.den;
    return firstnum >= secondnum;
}

bool operator <(const Fraction& f1, const Fraction& f2) {
    int firstnum = f1.num*f2.den;
    int secondnum = f2.num*f1.den;
    return firstnum < secondnum;
}

bool operator <=(const Fraction& f1, const Fraction& f2) {
    int firstnum = f1.num*f2.den;
    int secondnum = f2.num*f1.den;
    return firstnum <= secondnum;
}

bool operator ==(const Fraction& f1, const Fraction& f2) {
    int firstnum = f1.num*f2.den;
    int secondnum = f2.num*f1.den;
    return firstnum==secondnum;
}

bool operator !=(const Fraction& f1, const Fraction& f2) {
    int firstnum = f1.num*f2.den;
    int secondnum = f2.num*f1.den;
    return firstnum!=secondnum;
}

ostream& operator <<(ostream& stream, const Fraction& fraction) {
    stream << fraction.num << "/" << fraction.den;
    return stream;
}
