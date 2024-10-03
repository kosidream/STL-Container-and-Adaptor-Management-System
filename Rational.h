#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <algorithm>
#include <exception>
#include <string>

using namespace std;

class Rational {
private:
    int numerator; // Numerator of the rational number
    int denominator; // Denominator of the rational number

    // Helper function to compute the greatest common divisor
    int gcd(int a, int b) {
        if (a == 0 || b == 0)
            return 0;
        else if (a == b)
            return a;
        else if (a > b)
            return gcd(a - b, b);
        else
            return gcd(a, b - a);
    }

    // Helper function to normalize the rational number
    void normalize() {
        if (denominator < 0) {
            denominator *= -1;
            numerator *= -1;
        }

        int temp = gcd(abs(numerator), abs(denominator));
        numerator /= temp;
        denominator /= temp;
    }

public:
    // Custom exception class for zero denominator
    class ZeroDenominatorException : public exception {
    public:
        const char* what() const throw() {
            return "Error: Zero denominator.";
        }
    };

    // Default constructor, initializes the rational number to 0/1
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    // Constructor to initialize the rational number with numerator and denominator
    Rational(int newN, int newD) {
        numerator = newN;
        denominator = newD;
        if (denominator == 0)
            throw ZeroDenominatorException();

        normalize();
    }

    // Returns the string representation of the rational number
    string toString() {
        return to_string(numerator) + "/" + to_string(denominator);
    }

    // Getter for the numerator
    int getNumerator() const {
        return numerator;
    }

    // Setter for the numerator, also normalizes the rational number
    void setNumerator(int newN) {
        numerator = newN;
        normalize();
    }

    // Getter for the denominator
    int getDenominator() const {
        return denominator;
    }

    // Setter for the denominator, also normalizes the rational number
    void setDenominator(int newD) {
        if (newD == 0)
            throw ZeroDenominatorException();

        denominator = newD;
        normalize();
    }

    // Overloaded equality operator for Rational objects
    friend bool operator ==(const Rational& obj1, const Rational& obj2) {
        return (obj1.numerator * obj2.denominator) == (obj2.numerator * obj1.denominator);
    }

    // Overloaded less-than operator for Rational objects
    friend bool operator <(const Rational& obj1, const Rational& obj2) {
        return (obj1.numerator * obj2.denominator) < (obj2.numerator * obj1.denominator);
    }

    // Overloaded stream insertion operator for Rational objects
    friend ostream& operator <<(ostream& out, Rational obj) {
        out << obj.toString();
        return out;
    }
};

#endif // RATIONAL_H
