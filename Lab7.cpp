#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Contact class
class Contact {
private:
    string firstName;
    string lastName;
    string phoneNumber;
    string emailAddress;
public:
    // default constructor
    Contact() {
        firstName = "";
        lastName = "";
        phoneNumber = "";
        emailAddress = "";
    }
    // constructor w/ parameters
    Contact(string fName, string lName, string phone, string email) {
        firstName = fName;
        lastName = lName;
        phoneNumber = phone;
        emailAddress = email;
    }
    //functions
    void setFirstName(string fName) {
        firstName = fName;
    }
    void setLastName(string lName) {
        lastName = lName;
    }
    void setPhoneNumber(string phone) {
        phoneNumber = phone;
    }
    void setEmailAddress(string email) {
        emailAddress = email;
    }
    string getFirstName() const {
        return firstName;
    }
    string getLastName() const {
        return lastName;
    }
    string getPhoneNumber() const {
        return phoneNumber;
    }
    string getEmailAddress() const {
        return emailAddress;
    }
    // displays the contacts
    void displayContact() const {
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email Address: " << emailAddress << endl;
    }
};
// add new contact
void addContact(vector<Contact>& contacts) {
    string firstName;
    string lastName;
    string phoneNumber;
    string emailAddress;
    cout << "\nEnter first name: ";
    getline(cin, firstName);
    cout << "Enter last name: ";
    getline(cin, lastName);
    cout << "Enter phone number: ";
    getline(cin, phoneNumber);
    cout << "Enter email address: ";
    getline(cin, emailAddress);
    Contact newContact(firstName, lastName, phoneNumber, emailAddress);
    contacts.push_back(newContact);
    cout << "\nContact added successfully.\n";
}
// display all contacts
void displayAllContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "\nNo contacts to display.\n";
        return;
    }
    cout << "\n----- All Contacts -----\n";
    for (int i = 0; i < contacts.size(); i++) {
        cout << "\nContact #" << i + 1 << endl;
        contacts[i].displayContact();
    }
}
// search for contact by last name
void searchContactByLastName(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "\nNo contacts to search.\n";
        return;
    }
    string searchLastName;
    bool found = false;
    cout << "\nEnter last name to search: ";
    getline(cin, searchLastName);
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getLastName() == searchLastName) {
            cout << "\nContact found:\n";
            contacts[i].displayContact();
            found = true;
        }
    }
    if (!found) {
        cout << "\nNo contact found with last name: " << searchLastName << endl;
    }
}
// delete a contact by last name
void deleteContactByLastName(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "\nNo contacts to delete.\n";
        return;
    }
    string deleteLastName;
    bool found = false;
    cout << "\nEnter last name to delete: ";
    getline(cin, deleteLastName);
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getLastName() == deleteLastName) {
            contacts.erase(contacts.begin() + i);
            cout << "\nContact deleted successfully.\n";
            found = true;
            return;
        }
    }
    if (!found) {
        cout << "\nNo contact found with last name: " << deleteLastName << endl;
    }
}
int main() {
    vector<Contact> contacts;
    int choice;
    do {
        cout << "\n===== Contact Menu =====\n";
        cout << "1. Add a new contact\n";
        cout << "2. Display all contacts\n";
        cout << "3. Search for a contact by last name\n";
        cout << "4. Delete a contact by last name\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            addContact(contacts);
            break;
        case 2:
            displayAllContacts(contacts);
            break;
        case 3:
            searchContactByLastName(contacts);
            break;
        case 4:
            deleteContactByLastName(contacts);
            break;
        case 5:
            cout << "\nExiting program.\n";
            break;
        default:
            cout << "\nInvalid choice. Please enter a number from 1 to 5.\n";
        }
    } while (choice != 5);
    return 0;
}