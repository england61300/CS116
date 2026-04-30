#include <iostream>
using namespace std;

/*
    TOPIC: Inheritance, Access Control, Constructors, Polymorphism,
           Multiple Inheritance, and the Diamond Problem

    This file is a study guide in code form.

    Main concepts:
      1. public/private/protected members
      2. public/protected/private inheritance
      3. constructor/destructor order
      4. virtual functions and runtime polymorphism
      5. parent constructor calls
      6. multiple inheritance
      7. diamond problem and virtual inheritance
*/

//===============================================================================================
// BASIC INHERITANCE
//===============================================================================================
class Animal {
private:
    int privateValue = 13;     // Only Animal can directly access this.

protected:
    int protectedValue = 19;   // Animal and derived classes can access this.

public:
    void speak() const {
        cout << "Animal speaks\n";
    }

    void eat() const {
        cout << "Animal eats animal food\n";
    }
};

class Dog : public Animal {
public:
    void showProtectedValue() const {
        // cout << privateValue << endl; // ERROR: private data is not inherited as directly accessible.
        cout << "Dog can access protectedValue: " << protectedValue << endl;
    }

    void bark() const {
        cout << "Dog barks\n";
    }

    // Function overriding:
    // Dog provides its own version of eat().
    void eat() const {
        cout << "Dog eats dog food\n";
    }

    void speak() const {
        cout << "Dog speak override: Dog barks\n";
        cout << "Calling Animal::speak() too: ";
        Animal::speak();
    }
};

//===============================================================================================
// ACCESS CONTROL IN INHERITANCE
//===============================================================================================
class Base {
public:
    int publicV;       // Accessible outside the class.

protected:
    int protectedV;    // Accessible in this class and derived classes.

private:
    int privateV;      // Accessible only inside Base.
};

class DerivedPub : public Base {
    // publicV stays public.
    // protectedV stays protected.
    // privateV is not directly accessible.
};

class DerivedProt : protected Base {
    // publicV becomes protected.
    // protectedV stays protected.
    // privateV is not directly accessible.
};

class DerivedPriv : private Base {
    // publicV becomes private.
    // protectedV becomes private.
    // privateV is not directly accessible.
};

//===============================================================================================
// CONSTRUCTOR AND DESTRUCTOR ORDER
//===============================================================================================
class BaseClass {
public:
    BaseClass() {
        cout << "BaseClass constructor runs first\n";
    }

    ~BaseClass() {
        cout << "BaseClass destructor runs last\n";
    }
};

class DerivedClass : public BaseClass {
public:
    DerivedClass() {
        cout << "DerivedClass constructor runs second\n";
    }

    ~DerivedClass() {
        cout << "DerivedClass destructor runs first\n";
    }
};

//===============================================================================================
// VIRTUAL FUNCTIONS AND RUNTIME POLYMORPHISM
//===============================================================================================
class Shape {
public:
    virtual void draw() const {
        cout << "Drawing a shape\n";
    }

    // Virtual destructor is important if deleting derived objects through base pointers.
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a circle\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a rectangle\n";
    }
};

//===============================================================================================
// CALLING A PARENT CONSTRUCTOR
//===============================================================================================
class Parent {
public:
    Parent(int x) {
        cout << "Parent constructor called with x = " << x << endl;
    }
};

class Child : public Parent {
public:
    // The initializer list calls Parent(x) before the Child constructor body runs.
    Child(int x, int y) : Parent(x) {
        cout << "Child constructor called with y = " << y << endl;
    }
};

//===============================================================================================
// MULTIPLE INHERITANCE
//===============================================================================================
class Student {
public:
    void study() const {
        cout << "Student is studying\n";
    }
};

class Kid {
public:
    void play() const {
        cout << "Child is playing\n";
    }
};

class PreTeen : public Kid, public Student {
public:
    void action() const {
        play();
        study();
    }
};

//===============================================================================================
// DIAMOND PROBLEM
//===============================================================================================
class A {
public:
    void test() const {
        cout << "A::test()\n";
    }
};

// virtual public A means B and C share one A subobject when combined in D.
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

int main() {
    cout << "================ BASIC INHERITANCE ================\n";
    Dog myDog;
    myDog.showProtectedValue();
    myDog.speak();
    myDog.bark();
    myDog.eat();

    cout << "\n================ CONSTRUCTOR / DESTRUCTOR ORDER ================\n";
    {
        DerivedClass obj;
        cout << "Object is alive inside this block.\n";
    } // obj is destroyed here.

    cout << "\n================ RUNTIME POLYMORPHISM ================\n";
    Shape* s1 = new Circle();
    Shape* s2 = new Rectangle();

    s1->draw();
    s2->draw();

    delete s1;
    delete s2;

    cout << "\n================ PARENT CONSTRUCTOR CALL ================\n";
    Child object(10, 20);

    cout << "\n================ MULTIPLE INHERITANCE ================\n";
    PreTeen pt;
    pt.action();

    cout << "\n================ DIAMOND PROBLEM FIX ================\n";
    D d;
    d.test();

    return 0;
}
