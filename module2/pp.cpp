// England, Devin
// Payroll Program
//A program to do an individuals payroll (single employee only)

#include <iostream>
#include <iomanip>
using namespace std;

// Constants for deductions
const double FEDERAL_WITHHOLDING_RATE = 0.18;
const double STATE_WITHHOLDING_RATE = 0.045;
const double HOSPITALIZATION = 25.65;
const double UNION_DUES_RATE = 0.02;

int main() {
    // Variables
    string initials;
    double hoursWorked, hourlyRate, grossPay;
    double federalWithholding, stateWithholding, unionDues, totalDeductions, netPay;
    
    // User input
    cout << "Enter employee initials: ";
    cin >> initials;
    cout << "Enter hours worked: ";
    cin >> hoursWorked;
    cout << "Enter hourly rate: ";
    cin >> hourlyRate;
    
    // Calculations
    grossPay = hoursWorked * hourlyRate;
    federalWithholding = grossPay * FEDERAL_WITHHOLDING_RATE;
    stateWithholding = grossPay * STATE_WITHHOLDING_RATE;
    unionDues = grossPay * UNION_DUES_RATE;
    totalDeductions = federalWithholding + stateWithholding + HOSPITALIZATION + unionDues;
    netPay = grossPay - totalDeductions;
    
    // Output formatted report
    cout << fixed << setprecision(2);
    cout << "\nEmployee " << initials << endl;
    cout << "Hours Worked: " << setw(8) << hoursWorked << endl;
    cout << "Hourly Rate: " << setw(8) << hourlyRate << endl;
    cout << "Total Wages: " << setw(8) << grossPay << endl;
    cout << "\nDeductions" << endl;
    cout << "Federal Withholding: " << setw(8) << federalWithholding << endl;
    cout << "State Withholding: " << setw(8) << stateWithholding << endl;
    cout << "Hospitalization: " << setw(8) << HOSPITALIZATION << endl;
    cout << "Union Dues: " << setw(8) << unionDues << endl;
    cout << "Total Deductions: " << setw(8) << totalDeductions << endl;
    cout << "Net Pay: " << setw(8) << netPay << endl;
    
    return 0;
}
