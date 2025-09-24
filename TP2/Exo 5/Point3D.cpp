#include "Point3D.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib> // rand()
#include <ctime>   // time()

// Constructeur par défaut : valeurs aléatoires entre 0 et 100
Point3D::Point3D() {
    x = static_cast<float>(rand() % 101);
    y = static_cast<float>(rand() % 101);
    z = static_cast<float>(rand() % 101);
}

// Constructeur avec valeurs données
Point3D::Point3D(const float& newx, const float& newy, const float& newz)
    : x(newx), y(newy), z(newz) {
}

// Setters
void Point3D::setXYZ(const float& newx, const float& newy, const float& newz) {
    x = newx; y = newy; z = newz;
}
void Point3D::setX(const float& newx) { x = newx; }
void Point3D::setY(const float& newy) { y = newy; }
void Point3D::setZ(const float& newz) { z = newz; }

// Getters
float Point3D::getX() { return x; }
float Point3D::getY() { return y; }
float Point3D::getZ() { return z; }

// Affichage
void Point3D::print() {
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}

// Distance euclidienne
float Point3D::distanceTo(const Point3D& otherPoint3D) {
    float dx = x - otherPoint3D.x;
    float dy = y - otherPoint3D.y;
    float dz = z - otherPoint3D.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}
