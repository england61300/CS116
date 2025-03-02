#include <iostream>
using namespace std;

int main() {
    double num1, num2, average, product;

    // Input
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Processing
    average = (num1 + num2) / 2;
    product = num1 * num2;

    // Output
    cout << "The average is: " << average << endl;
    cout << "The product is: " << product << endl;

    return 0;
}
