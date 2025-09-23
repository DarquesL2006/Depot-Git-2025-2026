#pragma once

#include <iostream>

using std::cout;
using std::endl;

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
    Shape(const Color &color = Color::green);
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
    Rectangle(const Point2D &p1, const Point2D &p2);
};

class Triangle : public Shape
{
private:
    Point2D p1_, p2_, p3_;
public:
    float get_aera();
    void print_data();
    Triangle(const Point2D &p1, const Point2D &p2,
        const Point2D &p3);
};

class Circle : public  Shape
{
private:
    Point2D center;
    float radius_;
    float get_aera();

public:
    virtual void print_data();
    Circle(const Point2D &center, const float &radius);
};

class Square:Rectangle {
public:
    Square(const Point2D &p1, const float &side);
    void print_data();
};
