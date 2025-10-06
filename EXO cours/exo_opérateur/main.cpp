#include <iostream>
#include <stdexcept> 
#include <compare>
#include "Fraction.hpp"  
using namespace std;

int main() {
	Fraction f1(1, 2);
	Fraction f2(3, 4);

	f1.print();
	f2.print();

	//f1 = f2;
	//cout << "Affectation de f1 a f2"<<endl;
	//f1.print(); 
	//f2.print();

	Fraction result1 = f1 + f2;

	cout << "Addition de 1/2 et 3/4"<<endl;
	result1.print();

	Fraction result2 = f1 - f2;

	cout << "soustraction de 1/2 et 3/4" << endl;
	result2.print();

	Fraction result3 = f1 * f2;

	cout << "Multiplication de 1/2 et 3/4" << endl;
	result3.print();

	Fraction result4 = f1 / f2;

	cout << "Division de 1/2 et 3/4" << endl;
	result4.print();

	//	f1 = f2;
	//cout << "Affectation de f1 a f2"<<endl;
	//f1.print(); 
	//f2.print();

	cout << "Comparaison f1 et f2 :" << endl;
	if (f1 == f2) {
		cout << "Les deux fractions sont egales." << endl;
	}
	else {
		cout << "Les deux fractions sont differentes." << endl;
	}

}