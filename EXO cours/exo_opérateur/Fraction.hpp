#include <iostream>
#include <stdexcept> 
#include <compare>
using namespace std;
#pragma once

class Fraction {
private:
	int num = 0;
	int den = 1;
public:
	Fraction(const int& num = 0, const int& den = 1);

	void print();
	Fraction plus(const Fraction& other);

	void setNum(const int& num);
	void setDen(const int& den);

	Fraction& operator=(const Fraction& other);
	Fraction operator+(const Fraction& other) const;
	Fraction operator-(const Fraction& other) const;
	Fraction operator*(const Fraction& other) const;
	Fraction operator/(const Fraction& other) const;
	bool operator==(const Fraction& other);


}; 
