//earnings calculator
//Devin England
//Section#: 16836
//Lab 1

#include <iostream>
using namespace std;

int main() {
    int candyBarsSold;
    double earningsPerBar, totalEarnings;

    // Input
    cout << "Enter the number of candy bars sold: ";
    cin >> candyBarsSold;
    cout << "Enter the amount earned per candy bar: ";
    cin >> earningsPerBar;

    // Processing
    totalEarnings = candyBarsSold * earningsPerBar;

    // Output
    cout << "The total amount earned is: $" << totalEarnings << endl;

    return 0;
}
