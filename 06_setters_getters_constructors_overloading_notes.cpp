#include <iostream>
#include <string>
using namespace std;

/*
    TOPIC: Function Overloading, Default Arguments, Access Modifiers,
           Getters/Setters, and Constructors

    This file is a beginner class/object lesson.
*/

//===============================================================================================
// FUNCTION OVERLOADING
//===============================================================================================
int add(int x, int y) {
    return x + y;
}

int add(int x, int y, int z) {
    return x + y + z;
}

double add(double x, double y) {
    return x + y;
}

double add(int x, double y) {
    return x + y;
}

string add(string s1, string s2) {
    return s1 + s2;
}

//===============================================================================================
// DEFAULT ARGUMENTS
//===============================================================================================
void f1(int a, int b, int c = 10) {
    cout << "f1 -> " << a << " " << b << " " << c << endl;
}

void f2(int a, int b = 5, int c = 10) {
    cout << "f2 -> " << a << " " << b << " " << c << endl;
}

//===============================================================================================
// ACCESS MODIFIERS
//===============================================================================================
class ClassA {
    // In a class, members are private by default.
    int m1;

public:
    int m2;

private:
    int m3;
};

//===============================================================================================
// GETTERS AND SETTERS
//===============================================================================================
class Point {
private:
    int x;
    int y;

public:
    Point() : x(0), y(0) {}

    void setX(int n) {
        x = n;
    }

    void setY(int y) {
        // this->y means the object's member variable named y.
        // The plain y on the right side is the parameter.
        this->y = y;
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

//===============================================================================================
// CONSTRUCTORS
//===============================================================================================
class Class3 {
private:
    int x;
    double y;
    int z;
    string s;

public:
    Class3() : x(0), y(0.0), z(0), s("") {
        cout << "Inside default constructor\n";
    }

    Class3(int v) : x(v), y(0.0), z(0), s("") {}

    Class3(int v1, double v2) : x{v1}, y{v2}, z(0), s("") {}

    Class3(int v1, double v2, int v3) : x(v1), y(v2), z(v3), s("") {}

    Class3(int v1, double v2, int v3, string v4)
        : x(v1), y(v2), z(v3), s(v4) {}

    void setX(int v) { x = v; }
    int getX() const { return x; }

    void print() const {
        cout << "x = " << x << ", y = " << y << ", z = " << z << ", s = " << s << endl;
    }
};

int main() {
    cout << "================ FUNCTION OVERLOADING ================\n";
    int i = 10, j = 20;
    double d1 = 10.1, d2 = 20.1;
    string s1 = "Hello ", s2 = "C++";

    cout << "add(i, j) = " << add(i, j) << endl;
    cout << "add(i, j, 5) = " << add(i, j, 5) << endl;
    cout << "add(d1, d2) = " << add(d1, d2) << endl;
    cout << "add(i, d1) = " << add(i, d1) << endl;
    cout << "add(s1, s2) = " << add(s1, s2) << endl;

    cout << "\n================ DEFAULT ARGUMENTS ================\n";
    f1(1, 2);
    f1(1, 2, 3);
    f2(1);
    f2(1, 2);
    f2(1, 2, 3);

    cout << "\n================ ACCESS MODIFIERS ================\n";
    ClassA objA{};
    objA.m2 = 100;
    cout << "Public member m2 = " << objA.m2 << endl;
    // objA.m1 = 10; // ERROR: m1 is private.

    cout << "\n================ GETTERS AND SETTERS ================\n";
    Point p1;
    p1.setX(10);
    p1.setY(20);
    cout << "Point: x = " << p1.getX() << ", y = " << p1.getY() << endl;

    cout << "\n================ CONSTRUCTORS ================\n";
    Class3 o1;
    Class3 o2(5);
    Class3 o3(10, 15.5, 20, "Hi");
    Class3 o4(10, 15.5, 20);

    o1.setX(19);
    o1.print();
    o2.print();
    o3.print();
    o4.print();

    return 0;
}
