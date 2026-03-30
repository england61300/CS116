#include <iostream>
#include <string>

using namespace std;

//===============================================================
// 1. STATIC MEMBERS
//
// - A *static data member* belongs to the class itself (one shared copy),
//   not to each individual object.
// - A *static member function* can be called without an object.
// - Static members are often used for counters, shared configuration, etc.
//===============================================================

class S {
private:
    // Shared among ALL S objects.
    // NOTE: This must be *defined* once outside the class too (see below).
    static int count;

public:
    // Constructor runs every time an S object is created.
    S() { count++; }

    // Static member function: no "this" pointer, can be called like S::getCount()
    static int getCount() {
        return count;
    }
};

// IMPORTANT: definition of the static member (usually in a .cpp file).
// Without this, you'd get a linker error.
int S::count = 0;

//===============================================================
// 2. A CLASS WITH CONSTRUCTORS, DESTRUCTOR, CONST FUNCTIONS, FRIENDS
//===============================================================

class Car {
private:
    // Private means only member functions (and friends) can access them directly.
    string make;
    string model;
    int year = 0;       // default member initializer
    double price = 0;   // default member initializer

public:
    // Default constructor: creates an "empty" car (make/model empty strings, year=0, price=0)
    Car() {}

    // Parameterized constructor:
    // The colon section is a "member initializer list" (preferred for initializing members).
    Car(string mk, string md, int y, double p)
        : make(mk), model(md), year(y), price(p) {
    }

    // Destructor: runs automatically when an object is destroyed.
    // - Stack objects: destroyed when they go out of scope.
    // - Heap objects (created with new): destroyed when you call delete.
    ~Car() {
        cout << "In destructor for " << make << " " << model << endl;
    }

    // Setter: changes year
    void setYear(int y) { year = y; }

    // Getter marked const: promises not to modify the object.
    int getYear() const { return year; }

    // Also const because it only prints; doesn't change members.
    void displayCar() const;
    //void displayCar() const {
    //    cout << make << " " << model << " " << year << " " << price;
    //}

    // FRIEND FUNCTIONS:
    // These are NOT member functions, but they are allowed to access private members.
    // Use sparingly; often getters/setters are cleaner.
    friend void dispNewCars(const Car& c);
    friend void dispNewCars2(const Car& c);

};

void Car::displayCar() const {
    cout << make << " " << model << " " << year << " " << price;
}

// Friend function can access c.make/c.model/etc. even though they're private.
void dispNewCars(const Car& c) {
    if (c.year >= 2000)
        cout << c.make << " " << c.model << " " << c.year << " " << c.price << endl;
}

// Friend function that reuses a public member function instead of direct access.
void dispNewCars2(const Car& c) {
    if (c.year >= 2000)
        c.displayCar(); // prints but doesn't automatically add a newline
}

int main() {

    //===========================================================
    // STATIC MEMBER DEMO
    //===========================================================

    // Creating 3 objects calls S() three times, incrementing count.
    S s1, s2, s3;

    // Calling a static function via the class name (common style).
    cout << "Total objects created: " << S::getCount() << endl;

    // You *can* call static functions through an object too,
    // but it's still the same shared count.
    cout << "Total objects created: " << s1.getCount() << endl;

    //===========================================================
    // BASIC Car USAGE
    //===========================================================

    Car aCar;                // default constructor
    aCar.setYear(2000);      // setter
    cout << "aCar year = " << aCar.getYear() << endl;  // getter

    Car myCar("VW", "ID4", 2021, 10000); // parameterized constructor
    myCar.displayCar();
    cout << endl;

    //===========================================================
    // ARRAY OF OBJECTS (stack allocated)
    //===========================================================

    // This creates 2 Car objects in an array on the stack.
    Car cars[2] = { {"MB","E350",1996,5000}, {"BMW0", "328d", 2014, 7000} };

    cout << "\nAll cars: " << endl;
    for (int i = 0; i < 2; i++) {
        cars[i].displayCar();
        cout << endl;
    }

    //===========================================================
    // FRIEND FUNCTIONS
    //===========================================================

    cout << "\nNew cars (year >= 2000) via friend function:" << endl;
    for (int i = 0; i < 2; i++) {
        dispNewCars(cars[i]); // prints only if year >= 2000
    }

    cout << "\nNew Cars via friend function using member display: " << endl;
    for (int i = 0; i < 2; i++) {
        dispNewCars2(cars[i]); // prints only if year >= 2000
        cout << endl;          // add newline because dispNewCars2 doesn't
    }

    //===========================================================
    // POINTERS + DYNAMIC MEMORY
    //===========================================================

    int n1 = 10;
    int* ptr1 = &n1;  // ptr1 stores the address of n1
    // *ptr1 would give you the value at that address (10)

    // Pointer to an existing stack object:
    Car* carP1 = &myCar;

    // Use -> to call members through a pointer
    cout << "carP1 year = " << carP1->getYear() << endl;

    // Dynamic allocation: object lives on the heap until delete.
    Car* carP2 = new Car("MB", "E350", 1990, 500);
    cout << "Dynamic car year = " << carP2->getYear() << endl;

    // Dynamic array allocation: must be deleted with delete[]
    Car* carsP = new Car[2]{ {"BMW", "328",2000,300}, {"MB","E350",2001,200} };

    cout << "Printing dynamic array of cars: " << endl;
    for (int i = 0; i < 2; i++) {
        cout << carsP[i].getYear() << " ";
    }
    cout << endl;

    // Free dynamic memory (VERY IMPORTANT to avoid memory leaks).
    delete carP2;     // matches: new Car(...)
    delete[] carsP;   // matches: new Car[2]{...}

    return 0;
}