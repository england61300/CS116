#include <iostream>
using namespace std;

int main() {
    double width, length, area, perimeter;

    // Input
    cout << "Enter the width of the rectangle: ";
    cin >> width;
    cout << "Enter the length of the rectangle: ";
    cin >> length;

    // Processing
    area = width * length;
    perimeter = 2 * (width + length);

    // Output
    cout << "The area of the rectangle is: " << area << endl;
    cout << "The perimeter of the rectangle is: " << perimeter << endl;

    return 0;
}
