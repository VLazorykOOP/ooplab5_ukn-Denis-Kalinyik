
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <random>
using namespace std;

class Quadrilateral {
protected:
    double side1;
    double side2;
    double side3;
    double side4;

public:
    Quadrilateral(double s1, double s2, double s3, double s4) {
        side1 = s1;
        side2 = s2;
        side3 = s3;
        side4 = s4;
        cout << "Quadrilateral created." << endl;
    }

    virtual double area() {
        return 0.0;
    }

    virtual double perimeter() {
        return 0.0;
    }

    virtual void print() {
        cout << "Quadrilateral with sides: " << side1 << ", " << side2 << ", " << side3 << ", " << side4 << endl;
    }

    virtual ~Quadrilateral() {
        cout << "Quadrilateral destroyed." << endl;
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(double s1, double s2) : Quadrilateral(s1, s2, s1, s2) {
        cout << "Rectangle created." << endl;
    }

    double area() override {
        return side1 * side2;
    }

    double perimeter() override {
        return 2 * (side1 + side2);
    }

    void print() override {
        cout << "Rectangle with sides: " << side1 << ", " << side2 << endl;
    }

    ~Rectangle() override {
        cout << "Rectangle destroyed." << endl;
    }
};

class Square : public Rectangle {
public:
    Square(double s) : Rectangle(s, s) {
        cout << "Square created." << endl;
    }

    double area() override {
        return side1 * side1;
    }

    double perimeter() override {
        return 4 * side1;
    }

    void print() override {
        cout << "Square with side: " << side1 << endl;
    }

    ~Square() override {
        cout << "Square destroyed." << endl;
    }
};

int main() {
    // create a vector of pointers to Quadrilateral objects
    vector<unique_ptr<Quadrilateral>> shapes;

    int choice;
    cout << "Enter 1 to input shapes from keyboard or 2 to generate random shapes: ";
    cin >> choice;

    if (choice == 1) {
        double s1, s2, s3, s4;
        cout << "Enter sides for a quadrilateral (separated by spaces): ";
        cin >> s1 >> s2 >> s3 >> s4;
        shapes.emplace_back(unique_ptr<Quadrilateral>(new Quadrilateral(s1, s2, s3, s4)));

        cout << "Enter sides for a rectangle (separated by spaces): ";
        cin >> s1 >> s2;
        shapes.emplace_back(unique_ptr<Rectangle>(new Rectangle(s1, s2)));

        cout << "Enter side for a square: ";
        cin >> s1;
        shapes.emplace_back(unique_ptr<Square>(new Square(s1)));
    }
    else if (choice == 2) {
         random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(1, 10);

        double s1 = dis(gen);
        double s2 = dis(gen);
        double s3 = dis(gen);
        double s4 = dis(gen);
        shapes.emplace_back(unique_ptr<Quadrilateral>(new Quadrilateral(s1, s2, s3, s4)));

        s1 = dis(gen);
        s2 = dis(gen);
        shapes.emplace_back(unique_ptr<Rectangle>(new Rectangle(s1, s2)));

        s1 = dis(gen);
        shapes.emplace_back(unique_ptr<Square>(new Square(s1)));
    }
    else {
        cout << "Invalid choice" << endl;
        return 1;
    }

    // print information for each shape
    for (const auto& shape : shapes) {
        shape->print();
        cout << "Area: " << shape->area() << endl;
        cout << "Perimeter: " << shape->perimeter() << endl;
        cout << endl;
    }

    return 0;
}
