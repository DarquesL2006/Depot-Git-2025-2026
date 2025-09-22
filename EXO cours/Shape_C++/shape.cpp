#define _USE_MATH_DEFINES // for C with VS
#include <math.h>
#include "shape.hpp"
using namespace std;

unsigned Shape::global_count_ = 0;

Shape::Shape(const Color &color) : color_(color)
{
    count_ = global_count_++;
}

Rectangle::Rectangle(const float &length, const float &width)
{ // or : length_(length), width_(width) {

    this->length_ = length; // or length_ = length; (see below)
    width_ = width;
}

float Rectangle::get_aera()
{
    return length_ * width_;
}

void Rectangle::print_data()
{
    cout << "Shape type : Rectangle with sides : " << length_ << " " << width_ << endl;
}

Triangle::Triangle(const float &length_side1, const float &length_side2,
                   const float &length_side3) : length_side1_(length_side1), length_side2_(length_side2), length_side3_(length_side3)
{
}

float Triangle::get_aera()
{
    float s = (length_side1_ + length_side2_ + length_side3_) / 2;
    return sqrt(s * (s - length_side1_) * (s - length_side2_) * (s - length_side3_));
}

void Triangle::print_data()
{
    cout << "Shape type : Triangle with sides : " << length_side1_ << " " << length_side2_ << " " << length_side3_ << endl;
}

Circle::Circle(const float &radius) : radius_(radius)
{
}
float Circle::get_aera()
{
    return (float)M_PI * radius_ * radius_;
}

void Circle::print_data()
{
    cout << "Shape type : Circle with radius : " << radius_ << endl;
}

Square::Square(const float& length) {
        Rectangle(length, length){}

        void printdata() {
            cout << "Shape_type : Square width side" << length << endl;
        }
