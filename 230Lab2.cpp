#include <iostream>
#include <string>
using namespace std;

class Ruler {
private:
    // 1. Five private member variables
    int inches;
    double centimeters;
    string material;
    string brand;
    string barcode;

    // Static member variable
    static int objectCount;

public:
    // 2. Default constructor
    Ruler() {
        inches = 0;
        centimeters = 0.0;
        material = "Unknown";
        brand = "Unknown";
        barcode = "000000000000";
        objectCount++;
    }

    // 3. Parameterized constructor
    Ruler(int i, double c, string m, string b, string code) {
        inches = i;
        centimeters = c;
        material = m;
        brand = b;
        barcode = code;
        objectCount++;
    }

    // 4. Constructor using member initializer list
    Ruler(int i, double c, string m)
        : inches(i), centimeters(c), material(m), brand("No Brand"), barcode("No Barcode") {
        objectCount++;
    }

    // Setters
    void setInches(int i) {
        inches = i;
    }

    void setCentimeters(double c) {
        centimeters = c;
    }

    void setMaterial(string m) {
        material = m;
    }

    void setBrand(string b) {
        brand = b;
    }

    void setBarcode(string code) {
        barcode = code;
    }

    // Getters
    int getInches() const {
        return inches;
    }

    double getCentimeters() const {
        return centimeters;
    }

    string getMaterial() const {
        return material;
    }

    string getBrand() const {
        return brand;
    }

    string getBarcode() const {
        return barcode;
    }

    // 8. Print function
    void print() const {
        cout << "Inches: " << inches << endl;
        cout << "Centimeters: " << centimeters << endl;
        cout << "Material: " << material << endl;
        cout << "Brand: " << brand << endl;
        cout << "Barcode: " << barcode << endl;
    }

    // Static function
    static void showObjectCount() {
        cout << "Total Ruler objects created: " << objectCount << endl;
    }

    // 9. Friend function
    friend void compareLength(const Ruler& r);
};

// Definition of static member variable
int Ruler::objectCount = 0;

// Friend function
void compareLength(const Ruler& r) {
    cout << "\nFriend Function Output:" << endl;
    if (r.inches > 12) {
        cout << "This ruler (ruler1) is longer than 12 inches." << endl;
    }
    else {
        cout << "This ruler (ruler1) is 12 inches or shorter." << endl;
    }
}

int main() {
    // Create one object and display values
    Ruler ruler1(18, 45.0, "Metal", "Staples", "718103395755");

    cout << "Object ruler1:" << endl;
    ruler1.print();

    // Pointer to an object
    Ruler* ptr = &ruler1;
    cout << "\nAccessing ruler1 through a pointer:" << endl;
    cout << "Inches: " << ptr->getInches() << endl;
    cout << "Centimeters: " << ptr->getCentimeters() << endl;
    cout << "Material: " << ptr->getMaterial() << endl;
    cout << "Brand: " << ptr->getBrand() << endl;
    cout << "Barcode: " << ptr->getBarcode() << endl;

    // Static member and static function
    cout << endl;
    Ruler::showObjectCount();

    // Array of objects
    Ruler rulers[3] = {
        Ruler(),
        Ruler(12, 30.5, "Plastic", "Westcott", "123456789012"),
        Ruler(18, 45.0, "Metal")
    };

    cout << "\nArray of objects:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\nRuler " << i + 1 << ":" << endl;
        rulers[i].print();
    }

    // Friend function test
    compareLength(ruler1);

    return 0;
}