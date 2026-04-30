/*
    FILE: 07_SafeString_Rule_Of_Three_Study_Notes.cpp
    TOPIC: Dynamic C-strings, destructor, copy constructor, and assignment operator.

    Big idea:
    This class manually manages a char array using new[] and delete[].
    When a class owns dynamic memory, it usually needs the Rule of Three:
        1. Destructor
        2. Copy constructor
        3. Copy assignment operator

    Why?
    The default copy would copy only the pointer address. Then two objects would point
    to the same memory. That causes double delete and accidental shared data.
*/

#include <iostream>
#include <cstring>

// Cross-platform helper.
// Visual Studio supports strcpy_s. Some other compilers use std::strcpy.
void copyCString(char* destination, size_t destinationSize, const char* source) {
#ifdef _MSC_VER
    strcpy_s(destination, destinationSize, source);
#else
    (void)destinationSize;
    std::strcpy(destination, source);
#endif
}

class SafeString {
private:
    char* data;

public:
    SafeString(const char* input = nullptr) {
        if (input == nullptr) {
            // Create an empty string.
            // A C-string must end with '\0'.
            data = new char[1];
            data[0] = '\0';
        }
        else {
            // strlen does not count the null terminator, so add 1.
            size_t len = std::strlen(input) + 1;
            data = new char[len];
            copyCString(data, len, input);
        }
    }

    ~SafeString() {
        delete[] data;
    }

    SafeString(const SafeString& other) {
        size_t len = std::strlen(other.data) + 1;
        data = new char[len];
        copyCString(data, len, other.data);
    }

    SafeString& operator=(const SafeString& other) {
        if (this == &other) {
            return *this;
        }

        delete[] data;

        size_t len = std::strlen(other.data) + 1;
        data = new char[len];
        copyCString(data, len, other.data);

        return *this;
    }

    void display() const {
        std::cout << "Stored String: " << data << std::endl;
    }
};

int main() {
    SafeString s1("Original Content");
    SafeString s2("New Content");

    std::cout << "Before Assignment:\n";
    s1.display();

    s1 = s2;
    std::cout << "\nAfter Assignment (s1 = s2):\n";
    s1.display();

    s1 = s1;
    std::cout << "\nAfter Self-Assignment (s1 = s1):\n";
    s1.display();

    return 0;
}
