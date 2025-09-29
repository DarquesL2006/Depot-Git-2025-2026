#pragma once

#include <vector>
#include <iostream>
#include <cmath>   // pour std::fabs

using namespace std;


class Point2D {
private:
    float x_;
    float y_;

public:
    Point2D(float x = 0.f, float y = 0.f) : x_(x), y_(y) {}

    float get_x() const { return x_; }
    float get_y() const { return y_; }
    void set_x(float x) { x_ = x; }
    void set_y(float y) { y_ = y; }

    void print() const {
        std::cout << "(" << x_ << ", " << y_ << ")";
    }
};

class Vecteur {
private:
    float x_;
    float y_;

public:
    // --- Constructeurs ---
    Vecteur(float x = 0.f, float y = 0.f) : x_(x), y_(y) {}

    // Construire un vecteur à partir de 2 points
    Vecteur(const Point2D& A, const Point2D& B) {
        x_ = B.get_x() - A.get_x();
        y_ = B.get_y() - A.get_y();
    }

    // --- Getters / Setters ---
    float get_x() const { return x_; }
    float get_y() const { return y_; }
    void set_x(float x) { x_ = x; }
    void set_y(float y) { y_ = y; }

    // --- Opérations ---
    Vecteur operator+(const Vecteur& v) const {
        return Vecteur(x_ + v.x_, y_ + v.y_);
    }

    Vecteur operator*(float k) const {
        return Vecteur(x_ * k, y_ * k);
    }

    bool operator==(const Vecteur& v) const {
        return (std::fabs(x_ - v.x_) < 1e-6 &&
            std::fabs(y_ - v.y_) < 1e-6);
    }

    void print() const {
        std::cout << "(" << x_ << ", " << y_ << ")";
    }
};

class Polygon {
private:
    vector<Point2D> points_;

public:
    // Constructeur
    Polygon(const vector<Point2D>& pts) : points_(pts) {}

    // Calcul de l'aire (formule de Shoelace)
    float area() const {
        int n = points_.size();
        if (n < 3) return 0.f; // pas un polygone

        float sum = 0.f;
        for (int i = 0; i < n; i++) {
            const Point2D& p1 = points_[i];
            const Point2D& p2 = points_[(i + 1) % n]; // relie au premier
            sum += (p1.get_x() * p2.get_y()) - (p2.get_x() * p1.get_y());
        }
        return fabs(sum) / 2.f;
    }

    // Affichage
    void print() const {
        cout << "Polygon: ";
        for (const auto& p : points_) {
            p.print();
            cout << " ";
        }
        cout << endl;
    }
};
enum class Color : unsigned char
{
    blue = 0,
    green = 1,
    orange = 2,
    brown = 3
};

class Shape
{
private:
    static unsigned global_count_;
    unsigned count_;
    Color color_;

public:
    Shape(const Color& color = Color::green);
    virtual float get_aera() = 0;
    virtual void print_data() = 0;
};

class Rectangle : public Shape
{
protected:
    Point2D p1_, p2_;
public:
    float get_aera();
    void print_data();
    Rectangle(const Point2D& p1, const Point2D& p2);
};

class Triangle : public Shape
{
private:
    Point2D p1_, p2_, p3_;
public:
    float get_aera();
    void print_data();
    Triangle(const Point2D& p1, const Point2D& p2,
        const Point2D& p3);
};

class Circle : public Shape
{
private:
    Point2D center;
    float radius_;
    float get_aera();

public:
    virtual void print_data();
    Circle(const Point2D& center, const float& radius);
};

class Square : public Rectangle {
public:
    Square(const Point2D& p1, const float& side);
    void print_data();
};
