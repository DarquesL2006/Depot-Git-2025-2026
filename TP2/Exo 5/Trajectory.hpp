#pragma once
#include "Point3D.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

class Trajectory {
private:
    Point3D* points;
    size_t numberOfPoints;

public:
    // constructeur
    Trajectory(size_t n);

    // destructeur
    ~Trajectory();

    // méthodes
    void print();
    Point3D& getPoint(const int& n);
    float getTotalDistance();
};
#pragma once
