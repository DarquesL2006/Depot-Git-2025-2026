#include <iostream>
#include <stdexcept> 
#include <compare>
#include "Fraction.hpp"  
using namespace std;

Fraction& Fraction::operator=(const Fraction& other) {
    if (this != &other) {
        this->num = other.num;
        this->den = other.den;
    }
    return *this;
}

Fraction Fraction::operator+(const Fraction& other) const {
    Fraction result;
    result.num = num * other.den + other.num * den;
    result.den = den * other.den;
    return result;
}

Fraction Fraction::operator-(const Fraction& other) const {
    Fraction result;
    result.num = num * other.den - other.num * den;
    result.den = den * other.den;
    return result;
}

Fraction Fraction::operator*(const Fraction& other) const {
    Fraction result;
    result.num = num * other.num;
    result.den = den * other.den;
    return result;
}

Fraction Fraction::operator/(const Fraction& other) const {
    Fraction result;
    result.num = num * other.den;
    result.den = den * other.num;
    return result;
}

bool Fraction::operator==(const Fraction& other){
    bool comp;
    
    if (this->num == other.num && this->den == other.den) {
        comp = true;
    }
    else {
        comp = false;
    }

    return comp;
}

void Fraction::print() {
    cout << num << "/" << den << endl;
}

Fraction::Fraction(const int& num, const int& den) : num(num), den(den) {}

Fraction Fraction::plus(const Fraction& other){
    int n = num * other.den + other.num * den;
    int d = den * other.den;

    Fraction result(n, d);
    return result;
}

void Fraction::setNum(const int& num){
    int valeur;
    cout << "Entrez un numérateur :";
    cin>> valeur;
    this->num = valeur;

}

void Fraction::setDen(const int& den) {
    int valeur;
    cout << "Entrez un dénominateur :";
    cin >> valeur;
    this->den = valeur;

}

