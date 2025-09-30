#include <cstdlib>
#include "shape.hpp"
#include <cmath>

int main()
{
   /* const int const_size = 3;
    Rectangle rectangle(Point2D(0, 0), Point2D(5, 10)); 
    cout << "aera Shape : " << rectangle.get_aera() << "..." << endl;
    ;
    rectangle.print_data();

    auto p_rectangle = &rectangle; 
    cout << "aera Shape : " << p_rectangle->get_aera() << "..." << endl;
    ;
    p_rectangle->print_data();

    Shape *p_shape = &rectangle;
    cout << "aera Shape : " << p_shape->get_aera() << "..." << endl;
    ;
    p_shape->print_data();

    auto tab_shape = new Shape *[const_size];

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
    delete[] tab_shape;*/

    //exo 2/3
    Point2D A(1, 2), B(4, 6);
    Vecteur v1(A, B);

    Vecteur v2(3, -1);
    Vecteur v3 = v1 + v2;
    Vecteur v4 = v3 * 2.0f;

    cout << "v1 = "; v1.print(); cout << endl;
    cout << "v2 = "; v2.print(); cout << endl;
    cout << "v3 = "; v3.print(); cout << endl;
    cout << "v4 = "; v4.print(); cout << endl;

    std::cout << "v1 == v2 ? " << (v1 == v2 ? "oui" : "non") << std::endl;

    //exo 4
    Point2D triangle[] = { {0,0}, {4,0}, {0,3} };
    int triN = sizeof(triangle) / sizeof(triangle[0]);
    Polygon polyTriangle(triangle, triN);
    polyTriangle.print();
    cout << "Aire du triangle = " << polyTriangle.area() << endl;

    Point2D carre[] = { {0,0}, {0,2}, {2,2}, {2,0} };
    int carN = sizeof(carre) / sizeof(carre[0]);
    Polygon polyCarre(carre, carN);
    polyCarre.print();
    cout << "Aire du carre = " << polyCarre.area() << endl;

    Point2D rectangle[] = { {0,0}, {0,3}, {5,3}, {5,0} };
    int rectN = sizeof(rectangle) / sizeof(rectangle[0]);
    Polygon polyRectangle(rectangle, rectN);
    polyRectangle.print();
    cout << "Aire du rectangle = " << polyRectangle.area() << endl;

    //Exo 5
        BankAccount b1(1, "Alice", 1000.0f);
        CheckingAccount c1(2, "Bob", 500.0f, 200.0f);
        SavingsAccount s1(3, "Charlie", 2000.0f, 0.05f);

        b1.printAccount();
        c1.printAccount();
        s1.printAccount();

        cout << "\n--- Tests dépots ---" << endl;
        b1.deposit(200);
        c1.deposit(100);
        s1.deposit(500);

        cout << "\n--- Tests retraits ---" << endl;
        b1.withdrawal(50);
        c1.withdrawal(600); 
        s1.withdrawal(3000);

        cout << "\n--- Tests transfères ---" << endl;
        c1.transfer(50, b1);

        cout << "\n--- Testing intérêt annuel---" << endl;
        s1.depositAnnualInterest();

    return EXIT_SUCCESS;
}
