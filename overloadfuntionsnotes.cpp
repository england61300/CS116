#include <iostream>   // lets us print to the screen with cout
#include <string>     // lets us use the string type (words/sentences)

// This line means we don't have to type std::cout, std::string, etc.
using namespace std;

// ------------------------------------------------------------
// FUNCTION OVERLOADING EXAMPLE
// "add" has the SAME name, but DIFFERENT parameter types/amounts.
// The compiler chooses the correct one based on what you pass in.
// ------------------------------------------------------------

void f1(int a, int b, int c=10) {
    cout << a << " " << b << " " << c << endl;
}
void f2(int a, int b=5, int c = 10) {
    cout << a << " " << b << " " << c << endl;
}
//void f3(int a, int b=20, int c) {
//    cout << a << " " << b << c << endl;
//}

// adds two integers
int add(int x, int y) {
    return x + y;
}

// adds three integers
int add(int x, int y, int z) {
    return x + y + z;
}

// adds two doubles (decimals)
double add(double x, double y) {
    return x + y;
}

// adds an int and a double (still returns double because of decimal)
double add(int x, double y) {
    return x + y;
}

// adds two strings (this means "combine the text")
string add(string s1, string s2) {
    return s1 + s2;
}

// ------------------------------------------------------------
// CLASSES (OBJECTS) EXAMPLE
// A "class" is like a blueprint for creating an object.
// It can store variables (members) and have functions (methods).
// ------------------------------------------------------------

class ClassA {
    // If you don't say public:, members are private by default in a class.
    int m1;        // private (only the class itself can use this)

public:
    int m2;        // public (anyone can read/write this)

private:
    int m3;        // private
};

// A simple Point class (x,y) like in a graph
class Point {
private:
    int x;   // private: can't touch directly from main()
    int y;

public:
    // "set" functions let main() change private data safely
    void setX(int n) { x = n; }

    // this->y means "the y that belongs to this object"
    // we use it because the parameter name is also y
    void setY(int y) { this->y = y; }

    // "get" functions let main() read private data safely
    int getX() { return x; }
    int getY() { return y; }
};

// A class showing different constructors (ways to build the object)
class Class3 {
private:
    int x;
    double y;
    int z;
    string s;

public:
    // Default constructor: runs when you do Class3 o1;
    Class3() {
        // If you don't assign values here, some may start "garbage".
        // (In real code, you'd usually initialize them.)
    }

    // Constructor that sets x
    Class3(int v) {
        x = v;
    }

    // Constructor using an "initializer list" (common C++ style)
    Class3(int v1, double v2) : x{ v1 }, y{ v2 } {}

    // Another constructor: sets x, y, and z (preferred way/style)
   // Class3(int v1, double v2, int v3) : x(v1), y(v2), z(v3) {}

    Class3(int v1, double v2 , int v3, string v4 = "no")
        : x(v1), y(v2), z(v3), s(v4) {}

    void setX(int v) { x = v; }
    int getX() { return x; }

    // Prints the current member values to the screen
    void print() {
        cout << " x= " << x << " y= " << y << " z= " << z << " s= " << s << endl;
    }
};

// ------------------------------------------------------------
// MAIN PROGRAM
// main() is where the program starts running.
// ------------------------------------------------------------
int main() {
    f1(1, 2, 3);
    f1(1, 2);
    f2(1, 2, 3);
    f2(1);

    // Variables (ints are whole numbers, doubles are decimals)
    int i = 10, j = 20;
    double d1 = 10.1, d2 = 20.1;

    // Strings are text
    string s1 = "Hello", s2 = " C++";

    // These calls show function overloading:
    // same function name "add", different versions chosen automatically
    cout << "add(i, j) = " << add(i, j) << endl;           // int + int
    cout << "add(i, j, 5) = " << add(i, j, 5) << endl;     // int + int + int
    cout << "add(d1, d2) = " << add(d1, d2) << endl;       // double + double
    cout << "add(i, d1) = " << add(i, d1) << endl;         // int + double
    cout << "add(s1, s2) = " << add(s1, s2) << endl;       // string + string

    cout << endl;

    // --------------------------------------------------------
    // ClassA example: public vs private
    // --------------------------------------------------------
    ClassA objA;          // make an object from the blueprint ClassA
    objA.m2 = 100;        // OK because m2 is public

    // objA.m1 = 10;      // NOT OK because m1 is private (compiler error)

    cout << "Public member m2 = " << objA.m2 << endl;

    cout << endl;

    // --------------------------------------------------------
    // Point example: use setters/getters to access private data
    // --------------------------------------------------------
    Point p1;             // create Point object
    p1.setX(10);          // set x to 10
    p1.setY(20);          // set y to 20

    cout << "Point: x = " << p1.getX() << ", y = " << p1.getY() << endl;

    cout << endl;

    // --------------------------------------------------------
    // Class3 example: constructors
    // --------------------------------------------------------
    Class3 o1;        // calls Class3() default constructor
    Class3 o2(5);     // calls Class3(int v) constructor, sets x = 5

    o2.print();       // print values (x should be 5)
    o1.setX(19);      // set o1.x to 19
    o1.print();       // print o1 values

    Class3 o3(10, 15.5, 20, "Yes");
    Class3 o4(10, 15.5, 20);

    o3.print();
    o4.print();

    return 0;
}

//===============================================================================
// CONSTRUCTORS (simple explanation)
//
// 1) A constructor is a special function with the SAME name as the class.
// 2) It does NOT return anything (not even void).
// 3) It runs automatically when you create an object.
// 4) A constructor with no inputs is called the "default constructor".
// 5) If you create constructors with inputs, and still want to do Class3 o1;
//    you must also define a default constructor yourself.
//================================================================================