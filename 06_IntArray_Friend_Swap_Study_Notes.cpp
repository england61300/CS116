/*
    FILE: 06_IntArray_Friend_Swap_Study_Notes.cpp
    TOPIC: Dynamic arrays, destructor, friend function, and swapping pointers.

    Big idea:
    IntArray owns a dynamic array created with new[].
    Because it owns memory, it must release that memory with delete[].
*/

#include <iostream>
#include <algorithm> // std::swap

class IntArray {
private:
    int* data;
    int size;

public:
    IntArray(int s) : size(s) {
        // new int[size]{0} creates an array and initializes all values to 0.
        data = new int[size] {0};
    }

    ~IntArray() {
        // Every new[] should eventually have a matching delete[].
        delete[] data;
    }

    void setValue(int index, int value) {
        // Bounds check prevents writing outside the array.
        if (index >= 0 && index < size) {
            data[index] = value;
        }
    }

    void printArray() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    int findMax() const {
        if (size <= 0) {
            return -1;
        }

        int maxVal = data[0];
        for (int i = 1; i < size; ++i) {
            if (data[i] > maxVal) {
                maxVal = data[i];
            }
        }
        return maxVal;
    }

    /*
        Friend swap
        -----------
        This function can access private data and size.
        Instead of copying every array element, it swaps the pointers.

        Before:
            arr1.data -> [10, 20, 30]
            arr2.data -> [5, 50]

        After:
            arr1.data -> [5, 50]
            arr2.data -> [10, 20, 30]
    */
    friend void swap(IntArray& a, IntArray& b) {
        std::swap(a.data, b.data);
        std::swap(a.size, b.size);
    }
};

int main() {
    IntArray arr1(3);
    arr1.setValue(0, 10);
    arr1.setValue(1, 20);
    arr1.setValue(2, 30);

    IntArray arr2(2);
    arr2.setValue(0, 5);
    arr2.setValue(1, 50);

    std::cout << "Before Swap:\nArr1: ";
    arr1.printArray();
    std::cout << "Arr2: ";
    arr2.printArray();

    swap(arr1, arr2);

    std::cout << "\nAfter Swap:\nArr1: ";
    arr1.printArray();
    std::cout << "Arr2: ";
    arr2.printArray();
    std::cout << "New Max in Arr1: " << arr1.findMax() << std::endl;

    return 0;
}
