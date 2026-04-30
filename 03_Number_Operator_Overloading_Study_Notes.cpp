/*
    FILE: 03_Number_Operator_Overloading_Study_Notes.cpp
    TOPIC: Operator overloading with a Number class.

    Big idea:
    Operator overloading lets your class use normal operators like +, -, *, /, ==, <, and >.
    Instead of writing n1.add(n2), you can write n1 + n2.
*/

#include <iostream>
#include <stdexcept> // used for runtime_error when dividing by zero

class Number {
private:
    double val;

public:
    // Constructor with a default value.
    // Number n;      creates Number with value 0.0
    // Number n(5.5); creates Number with value 5.5
    Number(double v = 0.0) : val(v) {}

    /*
        Member operator overloads
        -------------------------
        A member operator has access to this object's private data.

        For n1 - n2:
            n1 is the calling object, also called *this
            n2 is the parameter named other
    */
    Number operator-(const Number& other) const {
        return Number(val - other.val);
    }

    bool operator<(const Number& other) const {
        return val < other.val;
    }

    bool operator>=(const Number& other) const {
        return val >= other.val;
    }

    bool operator!=(const Number& other) const {
        return val != other.val;
    }

    /*
        Friend operator overloads
        -------------------------
        A friend function is not a member function, but it is allowed to access private data.
        It receives both objects as parameters.

        For n1 + n2:
            a is n1
            b is n2
    */
    friend Number operator+(const Number& a, const Number& b) {
        return Number(a.val + b.val);
    }

    friend Number operator*(const Number& a, const Number& b) {
        return Number(a.val * b.val);
    }

    friend Number operator/(const Number& a, const Number& b) {
        if (b.val == 0.0) {
            throw std::runtime_error("Cannot divide by zero.");
        }
        return Number(a.val / b.val);
    }

    friend bool operator>(const Number& a, const Number& b) {
        return a.val > b.val;
    }

    friend bool operator<=(const Number& a, const Number& b) {
        return a.val <= b.val;
    }

    friend bool operator==(const Number& a, const Number& b) {
        return a.val == b.val;
    }

    // const means display() can be called on const and non-const Number objects.
    void display() const {
        std::cout << val << std::endl;
    }
};

int main() {
    Number n1(10.5);
    Number n2(5.0);
    Number n3(10.5);

    Number sum = n1 + n2;
    Number sub = n1 - n2;
    Number mul = n1 * n2;
    Number div = n1 / n2;

    std::cout << "--- Arithmetic Tests ---\n";
    std::cout << "n1 + n2: "; sum.display();
    std::cout << "n1 - n2: "; sub.display();
    std::cout << "n1 * n2: "; mul.display();
    std::cout << "n1 / n2: "; div.display();

    std::cout << "\n--- Comparison Tests ---\n";
    std::cout << "n1 == n3? " << (n1 == n3 ? "Yes" : "No") << "\n";
    std::cout << "n1 != n2? " << (n1 != n2 ? "Yes" : "No") << "\n";
    std::cout << "n1 > n2?  " << (n1 > n2 ? "Yes" : "No") << "\n";
    std::cout << "n2 < n1?  " << (n2 < n1 ? "Yes" : "No") << "\n";
    std::cout << "n1 >= n3? " << (n1 >= n3 ? "Yes" : "No") << "\n";
    std::cout << "n2 <= n1? " << (n2 <= n1 ? "Yes" : "No") << "\n";

    return 0;
}
