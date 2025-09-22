#include <iostream>
#include <cmath>
#include <string>
using namespace std;

static int global_count_ = 0;

class Shape {
protected:
    string color;
public:
    Shape(string c = "black") : color(c) { 
        global_count_++; 
    }
    virtual ~Shape() { global_count_--; }

    virtual float get_area() const = 0;     
    virtual void print_data() const = 0;     
};

class Rectangle : public Shape {
protected:
    float length;
    float width;
public:
    Rectangle(float l, float w, string c = "red") : Shape(c), length(l), width(w) {}
    float get_area() const override { 
        return length * width;
    }
    void print_data() const override {
        cout << "Rectangle " << color << " (" << length << "x" << width
            << ") - Aire = " << get_area() << endl;
    }
};

class Square : public Rectangle {
public:
    Square(float side, string c = "blue") : Rectangle(side, side, c) {}
    float get_area() const override { 
        return length * length; 
    }
    void print_data() const override {
        cout << "Carre " << color << " (cote = " << length
            << ") - Aire = " << get_area() << endl;
    }
};

class Circle : public Shape {
private:
    float radius;
public:
    Circle(float r, string c = "green") : Shape(c), radius(r) {}
    float get_area() const override { 
        return 3.14159f * radius * radius;
    }
    void print_data() const override {
        cout << "Cercle " << color << " (r=" << radius
            << ") - Aire = " << get_area() << endl;
    }
};

// Triangle
class Triangle : public Shape {
private:
    float side1, side2, side3;
public:
    Triangle(float a, float b, float c, string col = "yellow")
        : Shape(col), side1(a), side2(b), side3(c) {
    }

    float get_area() const override {
        float s = (side1 + side2 + side3) / 2.0f; 
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    void print_data() const override {
        cout << "Triangle " << color << " (" << side1 << ", "
            << side2 << ", " << side3 << ") - Aire = " << get_area() << endl;
    }
};

int main() {
    Rectangle r(4, 5);
    Square s(3);
    Circle c(2);
    Triangle t(3, 4, 5);

    r.print_data();
    s.print_data();
    c.print_data();
    t.print_data();

    cout << "Nombre total de formes : " << global_count_ << endl;
    return 0;
}
