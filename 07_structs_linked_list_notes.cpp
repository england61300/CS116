#include <iostream>
using namespace std;

/*
    TOPIC: Structs and a Basic Singly Linked List

    This file demonstrates:
      - struct Student
      - struct Node
      - dynamically creating nodes with new
      - inserting at the end of a linked list
      - displaying a linked list
      - searching a linked list
      - deleting all nodes to prevent memory leaks

    A linked list is made of nodes.
    Each node stores:
      1. data
      2. a pointer to the next node
*/

struct Student {
    int ID;
    double GPA;
    int programs[5];
};

struct Node {
    int data;
    Node* next;
};

Node* insert(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        return newNode;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

void display(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

bool search(Node* head, int value) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }

    return false;
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
    }
}

int main() {
    cout << "================ STRUCT EXAMPLE ================\n";

    Student st1{};
    Student students[30]{};

    st1.ID = 1234;
    st1.GPA = 3.34;
    st1.programs[0] = 100;

    cout << "ID = " << st1.ID << endl;
    cout << "GPA = " << st1.GPA << endl;

    for (int i = 0; i < 30; i++) {
        students[i].programs[2] = 100;
    }

    cout << "Program 3 for the 4th student: " << students[4].programs[2] << endl;

    cout << "\n================ LINKED LIST EXAMPLE ================\n";
    Node* myList = nullptr;

    myList = insert(myList, 1);
    myList = insert(myList, 2);
    myList = insert(myList, 3);
    myList = insert(myList, 4);

    cout << "Printing linked list: ";
    display(myList);

    int aValue = 30;
    if (search(myList, aValue)) {
        cout << aValue << " found in the linked list.\n";
    } else {
        cout << aValue << " not found in the linked list.\n";
    }

    aValue = 3;
    if (search(myList, aValue)) {
        cout << aValue << " found in the linked list.\n";
    } else {
        cout << aValue << " not found in the linked list.\n";
    }

    deleteList(myList);
    cout << "After deleteList, myList is " << (myList == nullptr ? "nullptr" : "not nullptr") << endl;

    return 0;
}
