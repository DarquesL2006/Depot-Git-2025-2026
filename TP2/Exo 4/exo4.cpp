#include "Point3D.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <cmath>    
using namespace std;

Point3D::Point3D() {
	x = rand() % 101;
	y = rand() % 101;
	z = rand() % 101;
}

Point3D::Point3D(const float& newx, const float& newy, const float& newz) {
	x = newx;
	y = newy;
	z = newz;
	}

void Point3D::setXYZ(const float& newx, const float& newy, const float& newz) {
	x = newx;
	y = newy;
	z = newz;
}

void Point3D::setX(const float& newx) {
	x = newx;
}

void Point3D::setY(const float& newy) {
	x = newy;
}

void Point3D::setZ(const float& newz) {
	x = newz;
}

float Point3D::getX() {
	return x;
}

float Point3D::getY() {
	return y;
}

float Point3D::getZ() {
	return z;
}

void Point3D::print() {
	cout << x << " ";
	cout << y << " ";
	cout << z << " ";
}

float Point3D::distanceTo(const Point3D& otherPoint3D) {
	unsigned int distance = 0;

	return distance = sqrt(pow(x - otherPoint3D.x, 2) + pow(y - otherPoint3D.y, 2) + pow(z - otherPoint3D.z, 2));
}

int main(void) {
	Point3D p1;
	cout << "Point p1 (constructeur par defaut) : ";
	p1.print();

	Point3D p2(10.0f, 20.0f, 30.0f);
	cout << "Point p2 (constructeur parametres) : ";
	p2.print();

	p1.setXYZ(1.0f, 2.0f, 3.0f);
	cout << "Apres setXYZ, p1 = ";
	p1.print();

	cout << "Coordonnees de p2 -> X=" << p2.getX()
		<< ", Y=" << p2.getY()
		<< ", Z=" << p2.getZ() << endl;

	p2.setX(1.0f);
	p2.setY(2.0f);
	p2.setZ(3.0f);
	cout << "Apres setX, setY, setZ, p2 = ";
	p2.print();

	float d = p1.distanceTo(p2);
	cout << "Distance entre p1 et p2 = " << d << endl;

	return 0;
}