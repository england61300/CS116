#include <iostream>
#include <string>
using namespace std;

/*
    TOPIC: Classes and Objects

    This example uses a Katana class to demonstrate:
      - private member variables
      - constructors
      - member initializer lists
      - setters and getters
      - static member variables
      - static member functions
      - pointers to objects
      - arrays of objects
      - friend functions

    Big idea:
    A class is a blueprint. An object is an actual thing made from that blueprint.
*/

class Katana {
private:
    double length;
    double width;
    string material;
    string shape;
    bool isPolished;

    // Static member variable:
    // This belongs to the class itself, not to one specific Katana object.
    // All Katana objects share the same katanaCount.
    static int katanaCount;

public:
    // Default constructor
    // Runs when we create: Katana sword;
    Katana()
        : length(70.0), width(3.2), material("Iron"), shape("Shinogi-zukuri"), isPolished(false) {
        katanaCount++;
    }

    // Parameterized constructor
    // Lets the user choose every starting value.
    Katana(double l, double w, string m, string s, bool p)
        : length(l), width(w), material(m), shape(s), isPolished(p) {
        katanaCount++;
    }

    // Constructor using a member initializer list with partial custom values.
    // The user gives length and width. The rest get default values.
    Katana(double l, double w)
        : length(l), width(w), material("Iron"), shape("Shinogi-zukuri"), isPolished(true) {
        katanaCount++;
    }

    // Setters modify private data safely through public functions.
    void setLength(double l) { length = l; }
    void setWidth(double w) { width = w; }
    void setMaterial(const string& m) { material = m; }
    void setShape(const string& s) { shape = s; }
    void setIsPolished(bool p) { isPolished = p; }

    // Getters return private data.
    // Marked const because they do not modify the object.
    double getLength() const { return length; }
    double getWidth() const { return width; }
    string getMaterial() const { return material; }
    string getShape() const { return shape; }
    bool getIsPolished() const { return isPolished; }

    // Static function:
    // Can be called using Katana::showTotalKatanas().
    // It can access static data, but it cannot directly access non-static members
    // because it is not tied to one object.
    static void showTotalKatanas() {
        cout << "Total Katanas Forged: " << katanaCount << endl;
    }

    void printDetails() const {
        cout << "Blade Details -> Material: " << material
             << ", Shape: " << shape
             << ", Dimensions: " << length << " x " << width
             << ", Polished: " << (isPolished ? "Yes" : "No") << endl;
    }

    // Friend function declaration.
    // polishSword is not a member function, but it can access private data.
    friend void polishSword(Katana& k);
};

// Static variables must be defined outside the class exactly once.
int Katana::katanaCount = 0;

void polishSword(Katana& k) {
    cout << "\n[Friend Function] Polishing the " << k.material << " " << k.shape << "...\n";
    k.isPolished = true;
    cout << "The blade now has a mirror finish.\n";
}

int main() {
    cout << "--- Object 1 Display ---\n";
    Katana sword1(72.5, 3.0, "Iron", "Shinogi-zukuri", false);
    sword1.printDetails();

    cout << "\n--- Display via Pointer ---\n";
    Katana* swordPtr = &sword1;
    // Use -> when calling a member through a pointer.
    swordPtr->printDetails();

    cout << "\n--- Static Data ---\n";
    Katana::showTotalKatanas();

    cout << "\n--- Array of Objects ---\n";
    Katana armory[2] = {
        Katana(60.0, 2.5),
        Katana()
    };

    for (int i = 0; i < 2; i++) {
        armory[i].printDetails();
    }

    cout << "\n--- Friend Function Test ---\n";
    polishSword(sword1);
    cout << "After friend function update:\n";
    sword1.printDetails();

    cout << "\n--- Final Static Count ---\n";
    Katana::showTotalKatanas();

    return 0;
}
