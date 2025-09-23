#define _USE_MATH_DEFINES // for C with VS
#include <math.h>
#include "shape.hpp"
using namespace std;

unsigned Shape::global_count_ = 0;

Shape::Shape(const Color &color) : color_(color)
{
    count_ = global_count_++;
}

Rectangle::Rectangle(const Point2D& p1, const Point2D& p2) :
    p1_(p1), p2_(p2) {}

float Rectangle::get_aera()
{
    float length_ = fabs(p2_.get_x() - p1_.get_x());
    float width_ = fabs(p2_.get_y() - p1_.get_y());
    return length_ * width_;
}

void Rectangle::print_data()
{
    cout << "Shape type : Rectangle defined by points ";
    p1_.print(); cout << " and "; p2_.print();
    cout << endl;
}

Triangle::Triangle(const Point2D& a, const Point2D& b, const Point2D& c)
    : p1_(a), p2_(b), p3_(c) {
}

float Triangle::get_aera()
{
    float a = hypot(p2_.get_x() - p1_.get_x(), p2_.get_y() - p1_.get_y());
    float b = hypot(p3_.get_x() - p2_.get_x(), p3_.get_y() - p2_.get_y());
    float c = hypot(p1_.get_x() - p3_.get_x(), p1_.get_y() - p3_.get_y());
    float s = (a + b + c) / 2.f;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

void Triangle::print_data()
{
    cout << "Shape type : Triangle with points ";
    p1_.print(); cout << ", "; p2_.print(); cout << ", "; p3_.print();
    cout << endl;
}

Circle::Circle(const Point2D &center ,const float &radius) : center(center), radius_(radius)
{
}
float Circle::get_aera()
{
    return (float)M_PI * radius_ * radius_;
}

void Circle::print_data()
{
    cout << "Shape type : Circle with center ";
    center.print(); cout << " and radius " << radius_ << endl;
}

Square::Square(const Point2D &p1,const float& side) : Rectangle(p1, Point2D(p1.get_x() + side, p1.get_y() + side)) {}

    void Square::print_data() {
        cout << "Shape type : Square with corner ";
        p1_.print(); cout << " and side length "
            << fabs(p2_.get_x() - p1_.get_x()) << endl;
    }
