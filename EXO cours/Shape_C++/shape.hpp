#pragma once

#include <iostream>
#include <cmath>   
#include <iostream>
#include <string>
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
    Vecteur(float x = 0.f, float y = 0.f) : x_(x), y_(y) {}

    Vecteur(const Point2D& A, const Point2D& B) {
        x_ = B.get_x() - A.get_x();
        y_ = B.get_y() - A.get_y();
    }

    float get_x() const { return x_; }
    float get_y() const { return y_; }
    void set_x(float x) { x_ = x; }
    void set_y(float y) { y_ = y; }

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
    Point2D* points_; 
    int n_;           

public:
    // Constructeur par défaut
    Polygon() : points_(nullptr), n_(0) {}

    // constructeur de polyognes avec n points
   Polygon(const Point2D pts[], int n) : points_(nullptr), n_(n) {
        if (n_ > 0) {
            points_ = new Point2D[n_];
            for (int i = 0; i < n_; ++i) points_[i] = pts[i];
        }
    }

    //Si on veut créer un deuxième polygone
    Polygon(const Polygon& other) : points_(nullptr), n_(other.n_) {
        if (n_ > 0) {
            points_ = new Point2D[n_];
            for (int i = 0; i < n_; ++i) points_[i] = other.points_[i];
        }
    }

    // Opérateur d'affectation, permets de faire poly1 = poly2 en gros 
    Polygon& operator=(const Polygon& other) {
        if (this == &other) return *this;
        delete[] points_;
        n_ = other.n_;
        if (n_ > 0) {
            points_ = new Point2D[n_];
            for (int i = 0; i < n_; ++i) points_[i] = other.points_[i];
        }
        else {
            points_ = nullptr;
        }
        return *this;
    }

    // Si on veut supprimer un polynome, c'est comme le free en C
    ~Polygon() { delete[] points_; }

    // Calcul de l'aire  avec la formule donnée dans l'énoncé
    float area() const {
        if (n_ < 3) return 0.f;
        float sum = 0.f;
        for (int i = 0; i < n_; ++i) {
            const Point2D& p1 = points_[i];
            const Point2D& p2 = points_[(i + 1) % n_]; 
            sum += (p1.get_x() * p2.get_y()) - (p2.get_x() * p1.get_y());
        }
        return fabs(sum) / 2.f;
    }

    // Affichage
    void print() const {
        cout << "Polygon: ";
        for (int i = 0; i < n_; ++i) {
            points_[i].print();
            cout << " ";
        }
        cout << endl;
    }

};

class BankAccount {
protected:
    int number;
    string owner;
    float balance;

public:
    BankAccount(int num, string own, float bal = 0.0f)
        : number(num), owner(own), balance(bal) {
    }

    virtual ~BankAccount() {}

    void deposit(float amount) {
        balance += amount;
        cout << "Déposer un montant: " << amount << ", Nouveau solde: " << balance << endl;
    }

    virtual void withdrawal(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Retrait: " << amount << ", Nouveau solde: " << balance << endl;
        }
        else {
            cout << "Fonds insuffisant." << endl;
        }
    }

    float getBalance() const { return balance; }
    void printAccount() const {
        cout << "Compte #" << number << ", Propriétaire: " << owner
            << ", Solde: " << balance << endl;
    }
};

// Classe CheckingAccount (compte courant)
class CheckingAccount : public BankAccount {
private:
    float overdraftLimit;

public:
    CheckingAccount(int num, string own, float bal = 0.0f, float overdraft = 0.0f)
        : BankAccount(num, own, bal), overdraftLimit(overdraft) {
    }

    void withdrawal(float amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Retrait: " << amount << ", Nouveau solde: " << balance << endl;
        }
        else {
            cout << "Limite du plafond de découvert autorisée atteinte." << endl;
        }
    }

    void transfer(float amount, BankAccount& otherAccount) {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            otherAccount.deposit(amount);
            cout << "Transféré " << amount << " à un autre compte." << endl;
        }
        else {
            cout << "Transfert impossible :Limite du plafond de découvert autorisée atteinte." << endl;
        }
    }
};

// Classe SavingsAccount (compte épargne)
class SavingsAccount : public BankAccount {
private:
    float annualInterestRate;

public:
    SavingsAccount(int num, string own, float bal = 0.0f, float rate = 0.0f)
        : BankAccount(num, own, bal), annualInterestRate(rate) {
    }

    void depositAnnualInterest() {
        float interest = balance * annualInterestRate;
        balance += interest;
        cout << "Intérêt annuel déposé: " << interest
            << ", Nouveau solde: " << balance << endl;
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
