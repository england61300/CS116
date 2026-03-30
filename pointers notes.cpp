#include <iostream>

using namespace std;

int main() {

    // -------------------------
    // Basic variables + an array
    // -------------------------
    int x = 19;
    int y = 10;

    // An int array of size 10 (10 elements). Each element is an int.
    int num[10] = { 10,20,30,40,50,60,70,80,90,100 };

    // -------------------------
    // Pointer declarations
    // -------------------------

    // Old C-style null pointer (works, but nullptr is preferred in modern C++)
    int * ptr = NULL;

    // Modern C++ null pointer (type-safe)
    int* newPtr = nullptr;

    // Just regular ints (not pointers)
    int aa, bb;

    // IMPORTANT NOTE:
    // int *pp1, pp2;
    // pp1 is a POINTER to int
    // pp2 is a regular int (NOT a pointer)
    int *pp1, pp2;

    // Here BOTH pp3 and pp4 are pointers because each has its own *
    int* pp3, * pp4;

    // -------------------------
    // Point ptr at x
    // -------------------------
    ptr = &x;   // &x means "address of x" (where x is stored in memory)

    cout << "address of x; &x : " << &x << endl;           // prints x's address
    cout << "size of an integer in C++: " << sizeof(x) << endl; // usually 4 bytes
    cout << "value of x: " << x << endl;

    // *ptr means "dereference ptr" => go to the memory address ptr holds and read the value there
    cout << "The content of where ptr is pointing to: " << *ptr << endl;

    // -------------------------
    // Changing x THROUGH the pointer
    // -------------------------
    (*ptr)++;   // increment the value at the location ptr points to (x)
    cout << "Value of x by ptrs after ++: " << x << endl;

    // Update x using x = x * 3 + 1 (but done using pointer syntax)
    *ptr = *ptr * 3 + 1;
    cout << "Value of x after 3 times plus 1: " << x << endl;
    cout << "---------------------------------------\n";

    // Multiply x by 2 using ptr
    *ptr *= 2;

    // Now make ptr point to y instead of x
    ptr = &y;
    *ptr *= 2;  // this now changes y (because ptr points to y)

    // -------------------------
    // Array name as a pointer (kinda)
    // -------------------------
    // In most expressions, "num" decays to a pointer to its first element (&num[0])
    newPtr = num;

    cout << "value of x: " << x << endl;
    cout << "value y: " << y << endl;

    // Printing num prints the address of the first element (not the whole array)
    cout << "name of the array: " << num << endl;

    // num + 1 is the address of the second element (moves by sizeof(int) bytes)
    cout << "name of the array: " << num + 1 << endl;

    // newPtr should match num (points at first element)
    cout << "ptr to array: " << newPtr << endl;
    cout << "---------------------------------------\n";

    // Accessing array elements two ways:
    cout << "first elem of num num[0]: " << num[0] << endl;
    cout << "first elem of num *num: " << *num << endl; // *num == num[0]

    cout << "address of second elem   : " << num + 1 << endl;
    cout << "second elem of num; num[1]:   " << *(num + 1) << endl; // *(num+1) == num[1]

    // -------------------------
    // Loop through the array using a pointer
    // -------------------------
    // BUG FIX: your loop had `1++` (number one) which never changes.
    // It should be `i++`.
    for (int i = 0; i < 10; i++) {
        cout << *newPtr << endl;  // print current element
        newPtr++;                 // move pointer to next int in the array
    }

    // -------------------------
    // Dynamic memory (heap allocation)
    // -------------------------
    int* dPtr = nullptr;

    // Allocate ONE int on the heap
    dPtr = new int;

    // Store 110 into that heap int
    *dPtr = 110;

    cout << "value of the dynamic allocated memory: " << *dPtr << endl;

    // Allocate an array of 10 ints on the heap
    int* myArray = new int[10];

    // Assign values using both bracket and pointer arithmetic styles
    myArray[0] = 100;
    *(myArray + 1) = 200;

    cout << "first elem of myArray:  " << myArray[0] << endl;
    cout << "second elem of myArray:  " << *(myArray + 1) << endl;

    // Free heap memory (IMPORTANT to avoid memory leaks)
    delete dPtr;          // for single int
    delete[] myArray;     // for array allocated with new[]
    cout << "---------------------------------------\n";

    // -------------------------
    // Array of pointers (stack variables)
    // -------------------------
    int a = 10, b = 20, c = 30;

    // arr1 is an array of 3 pointers to int
    // Each pointer stores the address of a, b, c
    int* arr1[3] = { &a, &b, &c };

    cout << "Value pointed by aar1[0]: " << *arr1[0] << endl; // prints a
    cout << "Value pointed by aar1[1]: " << *arr1[1] << endl; // prints b
    cout << "Value pointed by aar1[2]: " << *arr1[2] << endl; // prints c
    cout << "---------------------------------------\n";

    // -------------------------
    // Dynamically allocated array of pointers
    // -------------------------
    int* p1 = &a;
    int* p2 = &b;
    int* p3 = &c;

    // arrOfPtr is a pointer-to-pointer (int**), and it points to a heap array of int*
    int** arrOfPtr = new int*[3];

    arrOfPtr[0] = p1;
    arrOfPtr[1] = p2;
    arrOfPtr[2] = p3;

    // Explanation:
    // (arrOfPtr + 0) is a pointer to the first pointer in the array
    // *(arrOfPtr + 0) gives the int* stored there (like p1)
    // **(arrOfPtr + 0) gives the int value p1 points to (a)
    cout << "Value at arrOfPtr[0]: " << **(arrOfPtr + 0) << endl;
    cout << "Value at arrOfPtr[1]: " << **(arrOfPtr + 1) << endl;
    cout << "Value at arrOfPtr[2]: " << **(arrOfPtr + 2) << endl;

    // Free only the array of pointers (NOT a/b/c because those are stack variables)
    delete[] arrOfPtr;
    cout << "---------------------------------------\n";

    // -------------------------
    // Array of pointers that each point to heap ints
    // -------------------------
    int* arr2[3];

    // Allocate 3 separate ints on the heap with initial values
    arr2[0] = new int(100);
    arr2[1] = new int(200);
    arr2[2] = new int(300);

    // NOTE: These print ADDRESSES (because arr2[i] is a pointer)
    cout << "First element:  " << arr2[0] << endl;
    cout << "Second element: " << arr2[1] << endl;
    cout << "Third element:  " << arr2[2] << endl;

    // If you wanted the actual numbers (100,200,300) you'd do:
    // cout << *arr2[0] << endl; etc.

    // Free each individually (because each was allocated with new int(...))
    delete arr2[0];
    delete arr2[1];
    delete arr2[2];
    cout << "---------------------------------------\n";

    // -------------------------
    // Pre-increment vs Post-increment examples (commented out)
    // -------------------------
    // x = ++y;  // pre-increment: y increases first, then assigned to x
    // x = y++;  // post-increment: y assigned to x first, then y increases
    // cout << "x= " << x << " y= " << y << endl;


}