// England, Devin
// Summer Job Earnings
//A program that shows you your summer job earnings after all your expenses

#include <iostream>
#include <iomanip>
using namespace std;

// Constants
const double HOURLY_RATE = 15.50;
const double TAX_RATE = 0.14;
const double CLOTHING_RATE = 0.20;
const double SCHOOL_SUPPLIES_RATE = 0.05;
const double SAVINGS_RATE = 0.25;
const int WEEKS = 5;

int main() {
    // Variables
    string initials;
    double hoursWorked[WEEKS], totalHours = 0, grossEarnings, taxes, netEarnings;
    double clothingExpense, schoolSuppliesExpense, savings, amountLeft;
    
    // User input
    cout << "Enter your initials: ";
    cin >> initials;
    
    cout << "Enter hours worked for each of the 5 weeks: \n";
    for (int i = 0; i < WEEKS; i++) {
        cout << "Week " << (i + 1) << ": ";
        cin >> hoursWorked[i];
        totalHours += hoursWorked[i];
    }
    
    // Calculations
    grossEarnings = totalHours * HOURLY_RATE;
    taxes = grossEarnings * TAX_RATE;
    netEarnings = grossEarnings - taxes;
    clothingExpense = netEarnings * CLOTHING_RATE;
    schoolSuppliesExpense = netEarnings * SCHOOL_SUPPLIES_RATE;
    amountLeft = netEarnings - (clothingExpense + schoolSuppliesExpense);
    savings = amountLeft * SAVINGS_RATE;
    amountLeft -= savings;
    
    // Output formatted report
    cout << fixed << setprecision(2);
    cout << "\nInitials " << setw(15) << initials << endl;
    cout << "Total Hours Worked " << setw(8) << totalHours << endl;
    cout << "Gross Earnings " << setw(8) << grossEarnings << endl;
    cout << "Taxes Paid " << setw(8) << taxes << endl;
    cout << "Net Earnings " << setw(8) << netEarnings << endl;
    cout << "\nExpenses" << endl;
    cout << "Clothes " << setw(8) << clothingExpense << endl;
    cout << "School Supplies " << setw(8) << schoolSuppliesExpense << endl;
    cout << "Amount Remaining " << setw(8) << amountLeft << endl;
    cout << "Savings " << setw(8) << savings << endl;
    cout << "Amount left to spend " << setw(8) << amountLeft << endl;
    
    return 0;
}
