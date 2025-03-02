#include <iostream>
using namespace std;

int main() {
    double celsius, fahrenheit;

    // Input
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;

    // Processing
    fahrenheit = (celsius * 9 / 5) + 32;

    // Output
    cout << "The temperature in Fahrenheit is: " << fahrenheit << endl;

    return 0;
}
