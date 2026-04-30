#include <iostream>
using namespace std;

/*
    TOPIC: Pointers, Arrays, Dynamic Memory, and Pointer Arrays

    Key ideas:
      - & gives the address of a variable.
      - * dereferences a pointer, meaning it accesses the value at that address.
      - nullptr means the pointer points to nothing.
      - new allocates memory on the heap.
      - delete frees memory created with new.
      - new[] must be paired with delete[].
*/

int main() {
    cout << "================ BASIC POINTERS ================\n";

    int x = 19;
    int y = 10;
    int num[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int* ptr = nullptr;
    int* newPtr = nullptr;

    // Warning example:
    // int* pp1, pp2; means pp1 is a pointer, but pp2 is just an int.
    int* pp1 = nullptr;
    int pp2 = 0;

    // Correct way if both should be pointers:
    int* pp3 = nullptr;
    int* pp4 = nullptr;

    ptr = &x;

    cout << "address of x: " << &x << endl;
    cout << "size of integer in C++: " << sizeof(x) << endl;
    cout << "value of x: " << x << endl;
    cout << "value where ptr points: " << *ptr << endl;

    (*ptr)++;
    cout << "Value of x after (*ptr)++: " << x << endl;

    *ptr = *ptr * 3 + 1;
    cout << "Value of x after x * 3 + 1 through pointer: " << x << endl;

    *ptr *= 2;
    ptr = &y;
    *ptr *= 2;

    cout << "Value of x: " << x << endl;
    cout << "Value of y: " << y << endl;

    cout << "\n================ ARRAYS AND POINTER ARITHMETIC ================\n";
    newPtr = num;

    cout << "array name num acts like address of first element: " << num << endl;
    cout << "num + 1 is address of second element: " << num + 1 << endl;
    cout << "newPtr points to: " << newPtr << endl;

    cout << "num[0] = " << num[0] << endl;
    cout << "*num = " << *num << endl;
    cout << "*(num + 1) = " << *(num + 1) << endl;

    cout << "Printing array using pointer movement:\n";
    for (int i = 0; i < 10; i++) {
        cout << *newPtr << " ";
        newPtr++;
    }
    cout << endl;

    cout << "\n================ DYNAMIC MEMORY ================\n";
    int* dPtr = new int;
    *dPtr = 110;
    cout << "Value of dynamically allocated int: " << *dPtr << endl;

    int* myArray = new int[10]{};
    myArray[0] = 100;
    *(myArray + 1) = 200;

    cout << "first element of myArray: " << myArray[0] << endl;
    cout << "second element of myArray: " << *(myArray + 1) << endl;

    delete dPtr;
    dPtr = nullptr;

    delete[] myArray;
    myArray = nullptr;

    cout << "\n================ ARRAY OF INTEGER POINTERS ================\n";
    int a = 10, b = 20, c = 30;
    int* arr1[3] = {&a, &b, &c};

    cout << "Value pointed by arr1[0]: " << *arr1[0] << endl;
    cout << "Value pointed by arr1[1]: " << *arr1[1] << endl;
    cout << "Value pointed by arr1[2]: " << *arr1[2] << endl;

    cout << "\n================ DYNAMIC ARRAY OF POINTERS ================\n";
    int* p1 = &a;
    int* p2 = &b;
    int* p3 = &c;

    int** arrOfPtr = new int*[3];
    arrOfPtr[0] = p1;
    arrOfPtr[1] = p2;
    arrOfPtr[2] = p3;

    cout << "Value of arrOfPtr[0]: " << **(arrOfPtr + 0) << endl;
    cout << "Value of arrOfPtr[1]: " << **(arrOfPtr + 1) << endl;
    cout << "Value of arrOfPtr[2]: " << **(arrOfPtr + 2) << endl;

    delete[] arrOfPtr;
    arrOfPtr = nullptr;

    cout << "\n================ ARRAY OF POINTERS WITH DYNAMIC INTS ================\n";
    int* arr2[3];
    arr2[0] = new int(100);
    arr2[1] = new int(200);
    arr2[2] = new int(300);

    cout << "First element: " << *arr2[0] << endl;
    cout << "Second element: " << *arr2[1] << endl;
    cout << "Third element: " << *arr2[2] << endl;

    delete arr2[0];
    delete arr2[1];
    delete arr2[2];

    cout << "\n================ ARRAY OF C-STRING POINTERS ================\n";
    const char* fruits[] = {"Apple", "Orange", "Grape"};

    for (int i = 0; i < 3; i++) {
        cout << fruits[i] << endl;
    }

    // Silence unused variable warnings for demonstration-only variables.
    (void)pp1;
    (void)pp2;
    (void)pp3;
    (void)pp4;

    return 0;
}
