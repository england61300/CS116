#include <iostream>
#include <string>
using namespace std;

/*
    TOPIC: Static Members, Constructors, Destructors, Friend Functions,
           Pointers to Objects, and Dynamic Arrays

    This file is based on the static members / Car lesson.

    IMPORTANT FIX:
    The original code tried to delete carP1, but the pointer was named carP2.
    This rewritten version uses the correct pointer name.
*/

//===============================================================================================
// STATIC MEMBERS EXAMPLE
//===============================================================================================
class S {
private:
    static int count;

public:
    S() {
        count++;
    }

    static int getCount() {
        return count;
    }
};

int S::count = 0;

//===============================================================================================
// CAR CLASS
//===============================================================================================
class Car {
private:
    string make;
    string model;
    int year;
    double price;

public:
    Car() : make("Unknown"), model("Unknown"), year(0), price(0.0) {}

    Car(string mk, string md, int y, double p)
        : make(mk), model(md), year(y), price(p) {}

    ~Car() {
        cout << "Destructor running for " << make << " " << model << endl;
    }

    void setYear(int y) { year = y; }

    int getYear() const { return year; }

    void displayCar() const {
        cout << make << " " << model << " " << year << " $" << price;
    }

    // Friend function can directly access private data.
    friend void displayNewCarsDirect(const Car& c);
};

void displayNewCarsDirect(const Car& c) {
    if (c.year >= 2000) {
        cout << c.make << " " << c.model << " " << c.year << " $" << c.price << endl;
    }
}

void displayNewCarsUsingPublicFunctions(const Car& c) {
    if (c.getYear() >= 2000) {
        c.displayCar();
        cout << endl;
    }
}

int main() {
    cout << "================ STATIC MEMBERS ================\n";
    S s1, s2, s3;
    cout << "Total S objects created: " << S::getCount() << endl;
    cout << "Same static count through object: " << s1.getCount() << endl;

    cout << "\n================ CAR OBJECTS ================\n";
    Car aCar;
    aCar.setYear(2000);
    cout << "aCar year: " << aCar.getYear() << endl;

    Car myCar("VW", "ID4", 2021, 10000);
    myCar.displayCar();
    cout << endl;

    cout << "\n================ ARRAY OF CARS ================\n";
    Car cars[2] = {
        {"MB", "E350", 1996, 5000},
        {"BMW", "328d", 2014, 7000}
    };

    cout << "All cars:\n";
    for (int i = 0; i < 2; i++) {
        cars[i].displayCar();
        cout << endl;
    }

    cout << "\nCars year >= 2000 using friend function:\n";
    for (int i = 0; i < 2; i++) {
        displayNewCarsDirect(cars[i]);
    }

    cout << "\nCars year >= 2000 using public getter/member functions:\n";
    for (int i = 0; i < 2; i++) {
        displayNewCarsUsingPublicFunctions(cars[i]);
    }

    cout << "\n================ POINTERS ================\n";
    int n1 = 10;
    int* ptr1 = &n1;
    cout << "n1 value through pointer: " << *ptr1 << endl;

    cout << "\n================ DYNAMIC OBJECT ================\n";
    Car* carP2 = new Car("MB", "E350", 1990, 500);
    cout << "Dynamic car year = " << carP2->getYear() << endl;
    delete carP2;
    carP2 = nullptr;

    cout << "\n================ DYNAMIC ARRAY OF OBJECTS ================\n";
    Car* carsP = new Car[2]{
        {"BMW", "328", 2000, 300},
        {"MB", "E350", 2001, 200}
    };

    cout << "Printing dynamic array of car years:\n";
    for (int i = 0; i < 2; i++) {
        cout << carsP[i].getYear() << " ";
    }
    cout << endl;

    delete[] carsP;
    carsP = nullptr;

    return 0;
}
