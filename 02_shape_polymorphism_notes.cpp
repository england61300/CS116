#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

/*
    TOPIC: Inheritance, Virtual Functions, and Polymorphism

    Goal:
    Create one base class named Shape, then create derived classes:
      - Circle
      - Rectangle
      - Triangle

    Main idea:
    A Shape pointer can point to any object that inherits from Shape.

    Example:
        Shape* s = new Circle(5.0);

    Because area(), perimeter(), and getName() are virtual, C++ waits until runtime
    to decide which version to call. This is called runtime polymorphism.
*/

const double PI = 3.14159265358979323846;

//===============================================================================================
// BASE CLASS
//===============================================================================================
class Shape {
public:
    // virtual means derived classes can override this function.
    // Returning 0.0 gives a safe default for a generic Shape.
    virtual double area() const { return 0.0; }

    virtual double perimeter() const { return 0.0; }

    virtual string getName() const { return "Shape"; }

    // A base class with virtual functions should almost always have a virtual destructor.
    // This makes sure deleting through a Shape* correctly destroys derived objects.
    virtual ~Shape() {}
};

//===============================================================================================
// DERIVED CLASS: CIRCLE
//===============================================================================================
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    string getName() const override { return "Circle"; }

    double area() const override {
        return PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * PI * radius;
    }
};

//===============================================================================================
// DERIVED CLASS: RECTANGLE
//===============================================================================================
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    string getName() const override { return "Rectangle"; }

    double area() const override {
        return length * width;
    }

    double perimeter() const override {
        return 2 * (length + width);
    }
};

//===============================================================================================
// DERIVED CLASS: TRIANGLE
//===============================================================================================
class Triangle : public Shape {
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle(double s1, double s2, double s3)
        : side1(s1), side2(s2), side3(s3) {}

    string getName() const override { return "Triangle"; }

    double area() const override {
        // Heron's formula:
        // s is the semiperimeter, meaning half of the perimeter.
        double s = (side1 + side2 + side3) / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double perimeter() const override {
        return side1 + side2 + side3;
    }
};

// Helper function keeps main cleaner.
void printShapeInfo(const Shape* shape) {
    cout << "Shape: " << shape->getName() << endl;
    cout << "Area: " << shape->area() << endl;
    cout << "Perimeter: " << shape->perimeter() << endl;

    if (shape->getName() == "Triangle") {
        cout << "Triangle area used Heron's formula.\n";
    }

    cout << "--------------------------------------------------\n";
}

int main() {
    // vector<Shape*> means the vector stores pointers to Shape.
    // Because Circle, Rectangle, and Triangle are all Shapes through inheritance,
    // all three can be stored in the same vector.
    vector<Shape*> shapes;

    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Triangle(3.0, 4.0, 5.0));

    cout << "--- Shape Calculations ---\n\n";

    for (const Shape* s : shapes) {
        printShapeInfo(s);
    }

    // Every new must have a matching delete.
    // If we do not delete these objects, the program leaks memory.
    for (Shape* s : shapes) {
        delete s;
    }

    return 0;
}
