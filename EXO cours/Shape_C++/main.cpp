#include <cstdlib>
#include "shape.hpp"

int main()
{
    const int const_size = 3;
    Rectangle rectangle(Point2D(0, 0), Point2D(5, 10)); 
    cout << "aera Shape : " << rectangle.get_aera() << "..." << endl;
    ;
    rectangle.print_data();

    auto p_rectangle = &rectangle; // Rectangle *p_rectangle = &rectangle;
    cout << "aera Shape : " << p_rectangle->get_aera() << "..." << endl;
    ;
    p_rectangle->print_data();

    Shape *p_shape = &rectangle;
    cout << "aera Shape : " << p_shape->get_aera() << "..." << endl;
    ;
    p_shape->print_data();

    auto tab_shape = new Shape *[const_size];
    // C++ equivalent to Shape **tab_shape  = (Shape **) malloc(_SIZE_ * sizeof(Shape*)) with some additions

    tab_shape[0] = new Rectangle(Point2D(0, 0), Point2D(5, 10));
    tab_shape[1] = new Triangle(Point2D(0, 0), Point2D(5, 0), Point2D(0, 5));
    tab_shape[2] = new Circle(Point2D(2,2), 20);

    for (int i = 0; i < const_size; ++i)
    {
        cout << "aera Shape n° " << i + 1 << " " << tab_shape[i]->get_aera() << endl;
        tab_shape[i]->print_data();
    }

    for (int i = 0; i < const_size; ++i)
    {
        delete tab_shape[i];
    }
    delete[] tab_shape;

    return EXIT_SUCCESS;
}
