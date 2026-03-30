#include <iostream>
#include <string> // ADDED: needed for string in Patient class
using namespace std;

// PART 1: BadArray
// Fix a Broken Class
class BadArray {
private:
    int size;
    int* data;

public:
    BadArray(int s) {
        size = s;
        data = new int[size];
    }

    // ADDED: Copy constructor (FIXES shallow copy problem)
    // Without this, a2 = a1 causes both objects to point to SAME memory
    BadArray(const BadArray& other) {
        size = other.size;
        data = new int[size]; // allocate new memory

        // copy values (deep copy)
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // ADDED: Destructor (prevents memory leak)
    ~BadArray() {
        delete[] data;
    }

    void setAll(int value) {
        for (int i = 0; i < size; i++)
            data[i] = value;
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

//----------------------------------------
// PART 2: GradeBook

class GradeBook {
private:
    int studentCount;
    int* grades;

public:
    // ADDED: Constructor (allocates memory)
    GradeBook(int count) {
        studentCount = count;
        grades = new int[studentCount];
    }

    // ADDED: Copy constructor (deep copy)
    GradeBook(const GradeBook& other) {
        studentCount = other.studentCount;
        grades = new int[studentCount];

        for (int i = 0; i < studentCount; i++) {
            grades[i] = other.grades[i];
        }
    }

    // ADDED: Destructor (frees memory)
    ~GradeBook() {
        delete[] grades;
    }

    // ADDED: Assignment operator
    GradeBook& operator=(const GradeBook& other) {
  
        if (this == &other) return *this;
        delete[] grades;
        studentCount = other.studentCount;
        grades = new int[studentCount];

        for (int i = 0; i < studentCount; i++) {
            grades[i] = other.grades[i];
        }

        return *this;
    }

    void setAllGrades(int value) {
        for (int i = 0; i < studentCount; i++)
            grades[i] = value;
    }

    void setGrade(int index, int value) {
        // ADDED: basic bounds check (prevents crash)
        if (index >= 0 && index < studentCount)
            grades[index] = value;
    }

    void printGrades() {
        for (int i = 0; i < studentCount; i++)
            cout << grades[i] << " ";
        cout << endl;
    }
};

//=============================================
// PART 3: Patient (Real-Life Example)

class Patient {
private:
    string name;
    int numTests;
    double* testResults;

public:
    // ADDED: Default constructor
    Patient() {
        name = "";
        numTests = 0;
        testResults = nullptr;
    }

    // ADDED: Constructor
    Patient(string n, int t) {
        name = n;
        numTests = t;
        testResults = new double[numTests];
    }

    // ADDED: Copy constructor (deep copy)
    Patient(const Patient& other) {
        name = other.name;
        numTests = other.numTests;

        testResults = new double[numTests];

        for (int i = 0; i < numTests; i++) {
            testResults[i] = other.testResults[i];
        }
    }

    // ADDED: Destructor
    ~Patient() {
        delete[] testResults;
    }

    // ADDED: Assignment operator
    Patient& operator=(const Patient& other) {
       
        if (this == &other) return *this;

        delete[] testResults;

        name = other.name;
        numTests = other.numTests;

        testResults = new double[numTests];

        for (int i = 0; i < numTests; i++) {
            testResults[i] = other.testResults[i];
        }

        return *this;
    }

    void setTestResult(int index, double value) {
        // ADDED: bounds check
        if (index >= 0 && index < numTests)
            testResults[index] = value;
    }

    void print() {
        cout << name << ": ";
        for (int i = 0; i < numTests; i++) {
            cout << testResults[i] << " ";
        }
        cout << endl;
    }
};

//================================================
int main() {

    // PART 1: BadArray
    BadArray a1(5);
    a1.setAll(10);
    BadArray a2 = a1;
    a2.setAll(20);

    // ADDED: print to verify fix
    a1.print(); // should stay 10s
    a2.print(); // should be 20s

    //---------------------------------------------------------

    // PART 2: GradeBook
    GradeBook g1(5);
    g1.setAllGrades(80);

    GradeBook g2 = g1;
    g2.setGrade(0, 100);

    g1.printGrades();
    g2.printGrades();

    //-------------------------------------------

    // PART 3: Patient (Real-Life Example)
    Patient p1("Mary", 3);
    p1.setTestResult(0, 98.5);
    p1.setTestResult(1, 87.2);
    p1.setTestResult(2, 91.0);

    Patient p2 = p1;
    p2.setTestResult(1, 50.0);

    p1.print();
    p2.print();
}