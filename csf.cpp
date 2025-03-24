// P3.1 College Fees, Calculate student fees
// By: Devin England
// 03-22-25

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    //Declare variables, int/strings
    string fName;
    string lName;
    string acRoom;
    string isGrad;
    
    int studID;
    int units;
    int unitCharge = 0;
    int roomCharge = 0;
    int foodCharge = 400;
    int matFee = 30;
    int dipFee = 0;
    int total = 0;
    
    //Prompt user for name, studID, ac y/n, units, grad y/n
    ////Name 
    cout << "Please enter your first name: ";
    cin >> fName;
    cout << "Please enter your last name: ";
    cin >> lName;
    
    ////studID + check 4 characters
    cout << "Please enter your Student ID: ";
    cin >> studID;
        if (to_string(studID).size() != 4) {
            cout << "Error: Student ID must be a 4-digit number." << endl;
            return 1;
        }
        
    ////AC
    cout << "Would you like an air-conditioned room(Yes/No)? ";
    cin >> acRoom;
        if (acRoom == "y" || acRoom == "Y" || acRoom == "yes" || acRoom == "Yes") {
            roomCharge = 250;
        }
        else{ 
            roomCharge = 200;
        }
        
    ////units + limits check
    cout << "Number of Units: ";
    cin >> units;
        if (units > 21) {
            cout << "Error: Students enrolled in more than 21 units are not allowed." << endl;
            return 1;
        }
        if (units < 12) {
            cout << "Note: You are not a full-time student." << endl;
        }
    
    ////is Grad?
    cout << "Are you graduating this semester? ";
    cin >> isGrad;
        if (isGrad == "y" || isGrad == "Y" || isGrad == "yes" || isGrad == "Yes") {
            dipFee = 35;
        }
        
    //Calculate Fees
    unitCharge = units * 90;
    total = unitCharge + roomCharge + foodCharge + matFee + dipFee;
    
    // output 
    cout << endl;
    cout << "Name: " << fName << " " << lName << endl;
    cout << "Student ID: " << studID << endl;
    cout << "Units Enrolled: " << units << endl;
    cout << "Charge for Units: $" << unitCharge << endl;
    cout << "Romm Charge: $" << roomCharge << endl;
    cout << "Food Charge: $" << foodCharge << endl;
    cout << "Matriculation Fee: $" << matFee << endl;
    if (dipFee > 0) {
        cout << "Diploma Fee: $" << dipFee << endl;
    }
    cout << endl;
    cout << "Total Fees: $" << total << endl;
    
    return 0;
}
