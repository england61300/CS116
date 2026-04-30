/*
    FILE: 09_Lab4_Dynamic_Memory_Deep_Copy_Study_Notes.cpp
    TOPIC: Fixing classes that use dynamic memory.

    This file covers:
        - GoodArray
        - GradeBook
        - Patient

    Main idea:
    Each class owns a dynamic array.
    That means each class needs safe copying and cleanup.

    Rule of Three:
        If a class needs a destructor, it probably also needs:
            1. copy constructor
            2. copy assignment operator
*/

#include <iostream>
#include <string>
using namespace std;

class GoodArray {
private:
    int size;
    int* data;

public:
    GoodArray(int s) : size(s) {
        data = new int[size] {0};
    }

    ~GoodArray() {
        delete[] data;
    }

    GoodArray(const GoodArray& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    GoodArray& operator=(const GoodArray& other) {
        if (this != &other) {
            delete[] data;

            size = other.size;
            data = new int[size];

            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    void setAll(int value) {
        for (int i = 0; i < size; i++) {
            data[i] = value;
        }
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

class GradeBook {
private:
    int studentCount;
    int* grades;

public:
    GradeBook(int count) : studentCount(count) {
        grades = new int[studentCount] {0};
    }

    GradeBook(const GradeBook& other) : studentCount(other.studentCount) {
        grades = new int[studentCount];
        for (int i = 0; i < studentCount; i++) {
            grades[i] = other.grades[i];
        }
    }

    ~GradeBook() {
        delete[] grades;
    }

    GradeBook& operator=(const GradeBook& other) {
        if (this != &other) {
            delete[] grades;

            studentCount = other.studentCount;
            grades = new int[studentCount];

            for (int i = 0; i < studentCount; i++) {
                grades[i] = other.grades[i];
            }
        }
        return *this;
    }

    void setAllGrades(int value) {
        for (int i = 0; i < studentCount; i++) {
            grades[i] = value;
        }
    }

    void setGrade(int index, int value) {
        if (index >= 0 && index < studentCount) {
            grades[index] = value;
        }
    }

    void printGrades() const {
        for (int i = 0; i < studentCount; i++) {
            cout << grades[i] << " ";
        }
        cout << endl;
    }
};

class Patient {
private:
    string name;
    int numTests;
    double* testResults;

public:
    Patient() : name("Unknown"), numTests(0), testResults(nullptr) {}

    Patient(string n, int t) : name(n), numTests(t) {
        testResults = new double[numTests] {0.0};
    }

    Patient(const Patient& other) : name(other.name), numTests(other.numTests) {
        if (numTests > 0) {
            testResults = new double[numTests];
            for (int i = 0; i < numTests; i++) {
                testResults[i] = other.testResults[i];
            }
        }
        else {
            testResults = nullptr;
        }
    }

    ~Patient() {
        delete[] testResults;
    }

    Patient& operator=(const Patient& other) {
        if (this != &other) {
            delete[] testResults;

            name = other.name;
            numTests = other.numTests;

            if (numTests > 0) {
                testResults = new double[numTests];
                for (int i = 0; i < numTests; i++) {
                    testResults[i] = other.testResults[i];
                }
            }
            else {
                testResults = nullptr;
            }
        }
        return *this;
    }

    void setTestResult(int index, double value) {
        if (index >= 0 && index < numTests) {
            testResults[index] = value;
        }
    }

    void print() const {
        cout << "Patient: " << name << " | Results: ";
        for (int i = 0; i < numTests; i++) {
            cout << testResults[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "Part 1 GoodArray output:\n";
    GoodArray a1(5);
    a1.setAll(10);
    GoodArray a2 = a1;
    a2.setAll(20);
    a1.print();
    a2.print();

    cout << "\nPart 2 GradeBook output:\n";
    GradeBook g1(5);
    g1.setAllGrades(80);
    GradeBook g2 = g1;
    g2.setGrade(0, 100);
    g1.printGrades();
    g2.printGrades();

    cout << "\nPart 3 Patient output:\n";
    Patient p1("Mary", 3);
    p1.setTestResult(0, 98.5);
    p1.setTestResult(1, 87.2);
    p1.setTestResult(2, 91.0);

    Patient p2 = p1;
    p2.setTestResult(1, 50.0);

    p1.print();
    p2.print();

    return 0;
}
