#include "Trajectory.hpp"

Trajectory::Trajectory(size_t n) : numberOfPoints(n) {
    points = new Point3D[numberOfPoints]; // allocation dynamique
}

Trajectory::~Trajectory() {
    delete[] points;  // libération
}

void Trajectory::print() {
    for (size_t i = 0; i < numberOfPoints; i++) {
        std::cout << "Point " << i << " : ";
        points[i].print();
    }
}

Point3D& Trajectory::getPoint(const int &n) {
    if (n < 0 || n >= (int)numberOfPoints) {
        throw std::out_of_range("Index hors limites");
    }
    return points[n];
}

float Trajectory::getTotalDistance() {
    float total = 0.0f;
    for (size_t i = 0; i < numberOfPoints - 1; i++) {
        total += points[i].distanceTo(points[i+1]);
    }
    return total;
}
