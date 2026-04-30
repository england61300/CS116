#include <iostream>
using namespace std;

/*
    TOPIC: Copy Constructors, Assignment Operators, and the Rule of Three

    This file contains two examples:

    1. Student
       - Uses only normal int data members.
       - The compiler-generated copy constructor and assignment operator would be okay.
       - A custom copy constructor is still shown so you can see the syntax.

    2. IntArray
       - Uses dynamic memory with new[].
       - This class NEEDS the Rule of Three:
           a) Destructor
           b) Copy constructor
           c) Copy assignment operator

    WHY THE RULE OF THREE MATTERS:
    If a class owns dynamic memory, copying the raw pointer only creates a shallow copy.
    A shallow copy means two objects point to the same heap array. That causes problems:
      - Changing one object may accidentally affect the other.
      - When both destructors run, both try to delete the same memory.
      - That can crash the program.

    A deep copy allocates new memory and copies the values one by one.
*/

//===============================================================================================
// STUDENT CLASS
//===============================================================================================
class Student {
private:
    int id;
    int age;

public:
    // Default constructor
    // Used when we create a Student with no starting values, like: Student s3;
    Student() : id(0), age(0) {}

    // Parameterized constructor
    // Used when we already know the id and age, like: Student s1(10, 19);
    Student(int i, int a) : id(i), age(a) {}

    // Copy constructor
    // Runs when a NEW object is created from an existing object.
    // Example: Student s2 = s1;
    // Because id and age are plain ints, this is a simple copy.
    Student(const Student& s) : id(s.id), age(s.age) {}

    // Copy assignment operator
    // Runs when an EXISTING Student is assigned another Student.
    // Example: s3 = s1;
    Student& operator=(const Student& rhs) {
        if (this != &rhs) {
            id = rhs.id;
            age = rhs.age;
        }
        return *this;
    }

    // Getters are const because they only read data.
    int getID() const { return id; }
    int getAge() const { return age; }

    // Setter lets us change age while keeping age private.
    void setAge(int a) { age = a; }

    // Member function declaration.
    void print() const;

    // Friend function declaration.
    // A friend function is NOT a member of the class, but it can access private data.
    // This is useful for special external helper functions, but should not be overused.
    friend void printFriend(const Student& s);
};

void Student::print() const {
    cout << "st_id = " << id << ", st_age = " << age << endl;
}

void printFriend(const Student& s) {
    cout << "Friend print -> id: " << s.id << ", age: " << s.age << endl;
}

//===============================================================================================
// INTARRAY CLASS - DYNAMIC MEMORY EXAMPLE
//===============================================================================================
class IntArray {
private:
    int size;
    int* arrayPtr;

public:
    // Default constructor
    // nullptr means the pointer points to nothing safely.
    IntArray() : size(0), arrayPtr(nullptr) {}

    // Parameterized constructor
    // Creates an array of size s and fills every element with value v.
    IntArray(int s, int v) : size(s), arrayPtr(nullptr) {
        if (size > 0) {
            arrayPtr = new int[size];
            setValue(v);
        }
    }

    // Copy constructor: deep copy
    // Runs when a new IntArray is created from another IntArray.
    // Example: IntArray a2 = a1;
    IntArray(const IntArray& oldArray) : size(oldArray.size), arrayPtr(nullptr) {
        if (size > 0) {
            arrayPtr = new int[size];
            for (int i = 0; i < size; i++) {
                arrayPtr[i] = oldArray.arrayPtr[i];
            }
        }
    }

    // Copy assignment operator: deep copy
    // Runs when an EXISTING IntArray is assigned another IntArray.
    // Example: a3 = a1;
    // Return type is IntArray& so chained assignment works: a = b = c;
    IntArray& operator=(const IntArray& rhs) {
        // Self-assignment check.
        // This protects code like: a1 = a1;
        if (this == &rhs) {
            return *this;
        }

        // Delete the old array before replacing it.
        // Without this, the original memory would leak.
        delete[] arrayPtr;

        // Copy size first, then allocate new memory.
        size = rhs.size;
        arrayPtr = nullptr;

        if (size > 0) {
            arrayPtr = new int[size];
            for (int i = 0; i < size; i++) {
                arrayPtr[i] = rhs.arrayPtr[i];
            }
        }

        // *this means "the current object."
        return *this;
    }

    // Destructor
    // Runs automatically when an IntArray object goes out of scope.
    // It frees the memory created with new[].
    ~IntArray() {
        delete[] arrayPtr;
    }

    void printArray() const {
        for (int i = 0; i < size; i++) {
            cout << arrayPtr[i] << " ";
        }
        cout << endl;
    }

    void setValue(int v) {
        for (int i = 0; i < size; i++) {
            arrayPtr[i] = v;
        }
    }
};

int main() {
    cout << "================ STUDENT COPY EXAMPLE ================\n";

    Student s1(10, 19);
    Student s2 = s1;       // Copy constructor

    cout << "Original s1: ";
    s1.print();
    cout << "Copied s2:   ";
    s2.print();

    cout << "\nChanging s2 age to 21. This should NOT change s1.\n";
    s2.setAge(21);
    cout << "s1: ";
    s1.print();
    cout << "s2: ";
    s2.print();

    Student s3;
    s3 = s1;               // Compiler-generated assignment is okay here because Student has no dynamic memory.
    cout << "\nAssigned s3 = s1: ";
    s3.print();

    printFriend(s1);

    cout << "\n================ INTARRAY DEEP COPY EXAMPLE ================\n";

    IntArray a1(5, 19);
    IntArray a2 = a1;      // Copy constructor

    cout << "a1: ";
    a1.printArray();
    cout << "a2: ";
    a2.printArray();

    cout << "\nChanging a2 to all 21. This should NOT change a1.\n";
    a2.setValue(21);
    cout << "a1: ";
    a1.printArray();
    cout << "a2: ";
    a2.printArray();

    IntArray a3;
    a3 = a1;               // Copy assignment operator

    cout << "\nAfter a3 = a1:\n";
    cout << "a1: ";
    a1.printArray();
    cout << "a3: ";
    a3.printArray();

    cout << "\nChanging a1 to all 13. This should NOT change a3.\n";
    a1.setValue(13);
    cout << "a1: ";
    a1.printArray();
    cout << "a3: ";
    a3.printArray();

    cout << "\nTesting chained assignment: a1 = a2 = a3;\n";
    a1 = a2 = a3;
    cout << "a1: ";
    a1.printArray();
    cout << "a2: ";
    a2.printArray();
    cout << "a3: ";
    a3.printArray();

    return 0;
}
