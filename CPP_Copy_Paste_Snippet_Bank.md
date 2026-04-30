# C++ Copy/Paste Coding Snippet Bank

Use this file as a quick reference when building future labs, assignments, notes, or projects.

Each section has:
- **Copy/Paste Code**
- **What it is for**
- **How to change it**
- **How to expand it**

---

# 1. Basic C++ Program Template

## Copy/Paste Code

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, world!" << endl;

    return 0;
}
```

## What it is for

This is the smallest normal C++ program structure.  
Every C++ program starts running inside `main()`.

## How to change it

Change the code inside `main()`.

Example:

```cpp
cout << "My program starts here!" << endl;
```

## How to expand it

Add:
- more `#include` lines at the top
- variables inside `main()`
- functions above `main()`
- classes above `main()`

---

# 2. Common Include Template

## Copy/Paste Code

```cpp
#include <iostream>   // cout, cin
#include <string>     // string
#include <vector>     // vector
#include <iomanip>    // setw, fixed, setprecision
#include <cmath>      // sqrt, pow
#include <algorithm>  // sort, find
using namespace std;
```

## What it is for

This gives you the most common libraries used in beginner/intermediate C++ assignments.

## How to change it

Only keep what you need.

Examples:
- Need `cout` and `cin`: keep `<iostream>`
- Need `string`: keep `<string>`
- Need `vector`: keep `<vector>`
- Need `sqrt`: keep `<cmath>`

## How to expand it

Add more libraries if needed:

```cpp
#include <fstream>  // file input/output
#include <limits>   // numeric_limits
```

---

# 3. Basic Input and Output

## Copy/Paste Code

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;

    return 0;
}
```

## What it is for

Use this when you need to ask the user for values.

## How to change it

Change the variable names and types.

Examples:

```cpp
double price;
string lastName;
int score;
```

## How to expand it

For full names with spaces, use `getline()`:

```cpp
string fullName;

cout << "Enter full name: ";
getline(cin, fullName);
```

If you use `cin` before `getline`, add:

```cpp
cin.ignore();
```

---

# 4. If / Else Decision

## Copy/Paste Code

```cpp
if (score >= 90) {
    cout << "A" << endl;
}
else if (score >= 80) {
    cout << "B" << endl;
}
else if (score >= 70) {
    cout << "C" << endl;
}
else {
    cout << "Needs improvement" << endl;
}
```

## What it is for

Use this when the program needs to make a decision.

## How to change it

Change:
- the variable: `score`
- the conditions: `>= 90`
- the output messages

## How to expand it

Add more `else if` sections:

```cpp
else if (score >= 60) {
    cout << "D" << endl;
}
```

---

# 5. Switch Menu

## Copy/Paste Code

```cpp
int choice;

cout << "1. Add" << endl;
cout << "2. Display" << endl;
cout << "3. Search" << endl;
cout << "4. Exit" << endl;
cout << "Enter choice: ";
cin >> choice;

switch (choice) {
case 1:
    cout << "Add selected" << endl;
    break;

case 2:
    cout << "Display selected" << endl;
    break;

case 3:
    cout << "Search selected" << endl;
    break;

case 4:
    cout << "Exiting..." << endl;
    break;

default:
    cout << "Invalid choice" << endl;
}
```

## What it is for

Use this for menu-driven programs.

## How to change it

Change:
- menu text
- case numbers
- what each case does

## How to expand it

Put the switch inside a loop so the menu repeats.

---

# 6. Repeating Menu With Do-While Loop

## Copy/Paste Code

```cpp
int choice;

do {
    cout << "\n===== MENU =====" << endl;
    cout << "1. Add" << endl;
    cout << "2. Display" << endl;
    cout << "3. Search" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Add selected" << endl;
        break;

    case 2:
        cout << "Display selected" << endl;
        break;

    case 3:
        cout << "Search selected" << endl;
        break;

    case 4:
        cout << "Goodbye!" << endl;
        break;

    default:
        cout << "Invalid choice" << endl;
    }

} while (choice != 4);
```

## What it is for

Use this when the user should keep seeing the menu until they choose Exit.

## How to change it

Change `4` to your exit option number.

Example:

```cpp
} while (choice != 5);
```

## How to expand it

Replace each `cout` inside the cases with function calls:

```cpp
case 1:
    addItem();
    break;
```

---

# 7. For Loop

## Copy/Paste Code

```cpp
for (int i = 0; i < 10; i++) {
    cout << i << endl;
}
```

## What it is for

Use this when you know how many times you want to repeat something.

## How to change it

Change:
- starting value: `int i = 0`
- stopping condition: `i < 10`
- update: `i++`

## How to expand it

Count from 1 to 10:

```cpp
for (int i = 1; i <= 10; i++) {
    cout << i << endl;
}
```

Count backward:

```cpp
for (int i = 10; i >= 1; i--) {
    cout << i << endl;
}
```

---

# 8. While Loop

## Copy/Paste Code

```cpp
int count = 0;

while (count < 5) {
    cout << "Count: " << count << endl;
    count++;
}
```

## What it is for

Use this when you want to repeat while a condition is true.

## How to change it

Change the condition:

```cpp
while (choice != 0)
```

## How to expand it

Use it for input validation:

```cpp
while (age < 0) {
    cout << "Age cannot be negative. Enter again: ";
    cin >> age;
}
```

---

# 9. Input Validation Loop

## Copy/Paste Code

```cpp
int age;

cout << "Enter age: ";
cin >> age;

while (age < 0) {
    cout << "Invalid age. Enter age again: ";
    cin >> age;
}
```

## What it is for

Use this when user input must follow a rule.

## How to change it

Change the condition.

Examples:

```cpp
while (score < 0 || score > 100)
while (choice < 1 || choice > 5)
while (price < 0)
```

## How to expand it

For multiple rules:

```cpp
while (units < 0 || units > 21) {
    cout << "Units must be between 0 and 21: ";
    cin >> units;
}
```

---

# 10. Function Template

## Copy/Paste Code

```cpp
int add(int a, int b) {
    return a + b;
}
```

## What it is for

Use this to move reusable code outside of `main()`.

## How to change it

Change:
- return type: `int`
- function name: `add`
- parameters: `int a, int b`
- return calculation

## How to expand it

Example with no return value:

```cpp
void printLine() {
    cout << "----------------" << endl;
}
```

Example with a `double` return:

```cpp
double average(double a, double b) {
    return (a + b) / 2.0;
}
```

---

# 11. Function Prototype

## Copy/Paste Code

```cpp
#include <iostream>
using namespace std;

// Function prototype
int add(int a, int b);

int main() {
    cout << add(5, 3) << endl;
    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}
```

## What it is for

Use this when the function is written after `main()`.

## How to change it

The prototype and function definition must match.

This:

```cpp
int add(int a, int b);
```

Must match this:

```cpp
int add(int a, int b) {
```

## How to expand it

Add more prototypes above `main()`:

```cpp
void displayMenu();
double calculateTotal(double price, int quantity);
```

---

# 12. Array Input and Print

## Copy/Paste Code

```cpp
const int SIZE = 5;
int numbers[SIZE];

for (int i = 0; i < SIZE; i++) {
    cout << "Enter number " << i + 1 << ": ";
    cin >> numbers[i];
}

cout << "Numbers: ";
for (int i = 0; i < SIZE; i++) {
    cout << numbers[i] << " ";
}
cout << endl;
```

## What it is for

Use this when you need to store a fixed number of values.

## How to change it

Change `SIZE`.

Example:

```cpp
const int SIZE = 10;
```

Change type:

```cpp
double grades[SIZE];
```

## How to expand it

Find total:

```cpp
int total = 0;

for (int i = 0; i < SIZE; i++) {
    total += numbers[i];
}
```

---

# 13. Find Largest Value in Array

## Copy/Paste Code

```cpp
int maxValue = numbers[0];

for (int i = 1; i < SIZE; i++) {
    if (numbers[i] > maxValue) {
        maxValue = numbers[i];
    }
}

cout << "Largest value: " << maxValue << endl;
```

## What it is for

Use this to find the biggest number in an array.

## How to change it

For smallest value, change `>` to `<`:

```cpp
if (numbers[i] < minValue)
```

## How to expand it

Track the index too:

```cpp
int maxIndex = 0;

for (int i = 1; i < SIZE; i++) {
    if (numbers[i] > numbers[maxIndex]) {
        maxIndex = i;
    }
}
```

---

# 14. Bubble Sort

## Copy/Paste Code

```cpp
for (int pass = 0; pass < SIZE - 1; pass++) {
    for (int i = 0; i < SIZE - 1 - pass; i++) {
        if (numbers[i] > numbers[i + 1]) {
            int temp = numbers[i];
            numbers[i] = numbers[i + 1];
            numbers[i + 1] = temp;
        }
    }
}
```

## What it is for

Bubble sort sorts an array from smallest to largest.

It compares neighboring values and swaps them if they are in the wrong order.

## How to change it

For descending order, change:

```cpp
if (numbers[i] > numbers[i + 1])
```

to:

```cpp
if (numbers[i] < numbers[i + 1])
```

## How to expand it

Print after every pass:

```cpp
for (int j = 0; j < SIZE; j++) {
    cout << numbers[j] << " ";
}
cout << endl;
```

---

# 15. Vector Basics

## Copy/Paste Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }

    return 0;
}
```

## What it is for

A vector is like a resizable array.

Use it when you do not know how many items you will need.

## How to change it

Change the type:

```cpp
vector<string> names;
vector<double> grades;
```

## How to expand it

Use `.at()` for safer access:

```cpp
cout << numbers.at(0);
```

---

# 16. Vector Add / Search / Delete

## Copy/Paste Code

```cpp
vector<string> names;

names.push_back("Mary");
names.push_back("John");
names.push_back("Alex");

// Search
string target = "John";
bool found = false;

for (int i = 0; i < names.size(); i++) {
    if (names[i] == target) {
        cout << "Found at index " << i << endl;
        found = true;
    }
}

if (!found) {
    cout << "Not found" << endl;
}

// Delete first match
for (int i = 0; i < names.size(); i++) {
    if (names[i] == target) {
        names.erase(names.begin() + i);
        break;
    }
}
```

## What it is for

Use this for simple list programs like contacts, inventory, names, grades, etc.

## How to change it

Change:
- `vector<string>` to another vector type
- `target`
- the search condition

## How to expand it

For class objects:

```cpp
if (contacts[i].getLastName() == target)
```

---

# 17. Range-Based For Loop

## Copy/Paste Code

```cpp
for (int value : numbers) {
    cout << value << " ";
}
```

## What it is for

Use this to loop through every value in an array or vector.

## How to change it

For strings:

```cpp
for (string name : names) {
    cout << name << endl;
}
```

## How to expand it

Use reference if you want to modify values:

```cpp
for (int& value : numbers) {
    value *= 2;
}
```

Use const reference to avoid copying objects:

```cpp
for (const Contact& c : contacts) {
    c.displayContact();
}
```

---

# 18. Basic Class Template

## Copy/Paste Code

```cpp
class Student {
private:
    string name;
    int age;

public:
    Student() {
        name = "";
        age = 0;
    }

    Student(string n, int a) {
        name = n;
        age = a;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};
```

## What it is for

Use this when you need to create objects with data and behavior.

## How to change it

Change:
- class name: `Student`
- private variables
- constructor parameters
- display output

## How to expand it

Add getters and setters.

---

# 19. Getters and Setters

## Copy/Paste Code

```cpp
class Student {
private:
    string name;
    int age;

public:
    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }
};
```

## What it is for

Getters and setters protect private data.

You change private variables through public functions instead of touching them directly.

## How to change it

For each private variable, usually make:
- one setter
- one getter

## How to expand it

Add validation inside setters:

```cpp
void setAge(int a) {
    if (a >= 0) {
        age = a;
    }
}
```

---

# 20. Constructor With Initializer List

## Copy/Paste Code

```cpp
class Student {
private:
    string name;
    int age;

public:
    Student(string n, int a) : name(n), age(a) {
    }
};
```

## What it is for

Initializer lists are the cleaner C++ way to set member variables in constructors.

## How to change it

Match each member variable with the parameter:

```cpp
ClassName(type parameter) : member(parameter) {}
```

## How to expand it

Add default values:

```cpp
Student() : name("Unknown"), age(0) {}
```

---

# 21. Class With Print Function

## Copy/Paste Code

```cpp
class Item {
private:
    string name;
    double price;

public:
    Item(string n, double p) : name(n), price(p) {}

    void print() const {
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
    }
};
```

## What it is for

Use this when each object should know how to display itself.

## How to change it

Change:
- class name
- member variables
- constructor
- print output

## How to expand it

Add formatting:

```cpp
cout << fixed << setprecision(2);
```

---

# 22. Static Member Counter

## Copy/Paste Code

```cpp
class Student {
private:
    string name;
    static int count;

public:
    Student(string n = "") : name(n) {
        count++;
    }

    static int getCount() {
        return count;
    }
};

int Student::count = 0;
```

## What it is for

Static variables belong to the class, not one object.

Use this to count how many objects were created.

## How to change it

Change:
- class name
- `count` name if needed

## How to expand it

Print count:

```cpp
cout << "Students created: " << Student::getCount() << endl;
```

---

# 23. Friend Function

## Copy/Paste Code

```cpp
class Box {
private:
    double width;

public:
    Box(double w) : width(w) {}

    friend void printWidth(const Box& b);
};

void printWidth(const Box& b) {
    cout << "Width: " << b.width << endl;
}
```

## What it is for

A friend function can access private data of a class.

Use carefully. It breaks normal privacy rules.

## How to change it

Change:
- class name
- private variable
- friend function name

## How to expand it

Use friend functions for operators:

```cpp
friend ostream& operator<<(ostream& out, const Box& b);
```

---

# 24. Struct Template

## Copy/Paste Code

```cpp
struct Student {
    int id;
    double gpa;
};
```

## What it is for

A struct is a simple way to group related data.

By default, struct members are public.

## How to change it

Add fields:

```cpp
string name;
int age;
```

## How to expand it

Create and use one:

```cpp
Student s;
s.id = 1234;
s.gpa = 3.5;
```

---

# 25. Pointer Basics

## Copy/Paste Code

```cpp
int x = 10;
int* ptr = &x;

cout << "Address of x: " << &x << endl;
cout << "Value of x: " << x << endl;
cout << "Value through pointer: " << *ptr << endl;

*ptr = 20;

cout << "New value of x: " << x << endl;
```

## What it is for

Pointers store memory addresses.

`&x` means address of `x`.  
`*ptr` means value at the address inside `ptr`.

## How to change it

Change the type:

```cpp
double* ptr;
string* ptr;
```

## How to expand it

Use pointers with arrays and dynamic memory.

---

# 26. Dynamic Single Variable

## Copy/Paste Code

```cpp
int* ptr = new int;

*ptr = 100;

cout << *ptr << endl;

delete ptr;
ptr = nullptr;
```

## What it is for

Use this to create one value on the heap.

## How to change it

Change type:

```cpp
double* ptr = new double;
string* ptr = new string;
```

## How to expand it

Always set pointer to `nullptr` after deleting it.

---

# 27. Dynamic Array

## Copy/Paste Code

```cpp
int size;

cout << "Enter size: ";
cin >> size;

int* arr = new int[size];

for (int i = 0; i < size; i++) {
    arr[i] = 0;
}

for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
}

delete[] arr;
arr = nullptr;
```

## What it is for

Use this when the user decides the array size at runtime.

## How to change it

Change type:

```cpp
double* arr = new double[size];
```

## How to expand it

Ask the user to fill it:

```cpp
cin >> arr[i];
```

---

# 28. Rule of Three Class

## Copy/Paste Code

```cpp
class IntArray {
private:
    int size;
    int* data;

public:
    IntArray(int s) : size(s) {
        data = new int[size] {0};
    }

    ~IntArray() {
        delete[] data;
    }

    IntArray(const IntArray& other) : size(other.size) {
        data = new int[size];

        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    IntArray& operator=(const IntArray& other) {
        if (this != &other) {
            delete[] data;

            size = other.size;
            data = new int[size];

            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }

        return *this;
    }
};
```

## What it is for

Use this when a class owns dynamic memory.

Rule of Three:
1. Destructor
2. Copy constructor
3. Copy assignment operator

## How to change it

Change:
- class name
- data type
- variable names

## How to expand it

Add functions:

```cpp
void setValue(int index, int value);
void print() const;
```

---

# 29. Linked List Node

## Copy/Paste Code

```cpp
struct Node {
    int data;
    Node* next;
};
```

## What it is for

This is the basic building block of a linked list.

Each node stores:
- data
- a pointer to the next node

## How to change it

Change `int data` to another type:

```cpp
Student data;
string data;
```

## How to expand it

Create a new node:

```cpp
Node* newNode = new Node;
newNode->data = 10;
newNode->next = nullptr;
```

---

# 30. Insert at End of Linked List

## Copy/Paste Code

```cpp
Node* insertEnd(Node* head, int value) {
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
```

## What it is for

Adds a new node to the end of a linked list.

## How to change it

If your node stores a `Student`, change:

```cpp
int value
```

to:

```cpp
Student value
```

and:

```cpp
newNode->data = value;
```

still works.

## How to expand it

Track list size with a counter variable.

---

# 31. Display Linked List

## Copy/Paste Code

```cpp
void displayList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}
```

## What it is for

Prints every value in a linked list.

## How to change it

If `data` is a struct:

```cpp
cout << current->data.id << " " << current->data.gpa << endl;
```

## How to expand it

Add an empty-list check:

```cpp
if (head == nullptr) {
    cout << "List is empty" << endl;
}
```

---

# 32. Search Linked List

## Copy/Paste Code

```cpp
bool searchList(Node* head, int target) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == target) {
            return true;
        }

        current = current->next;
    }

    return false;
}
```

## What it is for

Checks whether a value exists in a linked list.

## How to change it

If searching a struct by ID:

```cpp
if (current->data.id == target)
```

## How to expand it

Return the node instead of true/false:

```cpp
Node* searchList(Node* head, int target)
```

---

# 33. Delete Linked List Memory

## Copy/Paste Code

```cpp
void freeList(Node*& head) {
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
}
```

## What it is for

Deletes every node so you do not leak memory.

## How to change it

Usually you do not need to change this unless your node structure changes heavily.

## How to expand it

Call it before the program ends:

```cpp
freeList(head);
```

---

# 34. Basic Inheritance

## Copy/Paste Code

```cpp
class Animal {
public:
    void speak() const {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() const {
        cout << "Dog barks" << endl;
    }
};
```

## What it is for

Inheritance lets one class reuse another class.

`Dog` inherits from `Animal`.

## How to change it

Change:
- base class name
- derived class name
- functions

## How to expand it

Use protected data:

```cpp
protected:
    int age;
```

Derived classes can access protected members.

---

# 35. Virtual Function / Polymorphism

## Copy/Paste Code

```cpp
class Shape {
public:
    virtual double area() const {
        return 0.0;
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }
};
```

## What it is for

Use this when a base class pointer should call the derived class version of a function.

Example:

```cpp
Shape* s = new Circle(5.0);
cout << s->area() << endl;
delete s;
```

## How to change it

Change:
- base class
- derived class
- virtual function

## How to expand it

Add more derived classes:

```cpp
class Rectangle : public Shape
```

---

# 36. Operator Overloading: Plus Operator

## Copy/Paste Code

```cpp
class Number {
private:
    double value;

public:
    Number(double v = 0.0) : value(v) {}

    Number operator+(const Number& other) const {
        return Number(value + other.value);
    }

    void display() const {
        cout << value << endl;
    }
};
```

## What it is for

Lets objects use operators like `+`.

Example:

```cpp
Number a(5);
Number b(3);
Number c = a + b;
```

## How to change it

Change the calculation:

```cpp
return Number(value - other.value);
```

## How to expand it

Add more operators:

```cpp
operator-
operator*
operator/
operator==
operator<
```

---

# 37. Operator Overloading: Output `<<`

## Copy/Paste Code

```cpp
class Number {
private:
    double value;

public:
    Number(double v = 0.0) : value(v) {}

    friend ostream& operator<<(ostream& out, const Number& n);
};

ostream& operator<<(ostream& out, const Number& n) {
    out << n.value;
    return out;
}
```

## What it is for

Lets you print objects directly:

```cpp
cout << myNumber << endl;
```

## How to change it

Change what gets printed:

```cpp
out << "Value: " << n.value;
```

## How to expand it

Use with classes like:
- Distance
- Student
- Contact
- Item

---

# 38. String Find / Substring / Replace

## Copy/Paste Code

```cpp
string text = "Hello world";

int position = text.find("world");

if (position != string::npos) {
    cout << "Found at index: " << position << endl;
}

string part = text.substr(0, 5);
cout << part << endl;

text.replace(0, 5, "Hi");
cout << text << endl;
```

## What it is for

Use this when working with text.

## How to change it

Change:
- search word
- substring start and length
- replacement text

## How to expand it

Find first word:

```cpp
string first = text.substr(0, text.find(' '));
```

---

# 39. File Output

## Copy/Paste Code

```cpp
#include <fstream>

ofstream outFile("output.txt");

if (outFile.is_open()) {
    outFile << "Hello file!" << endl;
    outFile.close();
}
else {
    cout << "Could not open file." << endl;
}
```

## What it is for

Writes data to a file.

## How to change it

Change the filename:

```cpp
ofstream outFile("grades.txt");
```

## How to expand it

Write variables:

```cpp
outFile << name << " " << score << endl;
```

---

# 40. File Input

## Copy/Paste Code

```cpp
#include <fstream>

ifstream inFile("input.txt");

string word;

if (inFile.is_open()) {
    while (inFile >> word) {
        cout << word << endl;
    }

    inFile.close();
}
else {
    cout << "Could not open file." << endl;
}
```

## What it is for

Reads data from a file.

## How to change it

Change the filename and variable type.

Example:

```cpp
int number;
while (inFile >> number)
```

## How to expand it

Read full lines:

```cpp
string line;

while (getline(inFile, line)) {
    cout << line << endl;
}
```

---

# 41. Try/Catch Template

## Copy/Paste Code

```cpp
try {
    int age;

    cout << "Enter age: ";
    cin >> age;

    if (age < 0) {
        throw "Age cannot be negative.";
    }

    cout << "Age: " << age << endl;
}
catch (const char* message) {
    cout << "Error: " << message << endl;
}
```

## What it is for

Use this for basic exception handling.

## How to change it

Change the condition and error message.

## How to expand it

Use `runtime_error`:

```cpp
#include <stdexcept>

throw runtime_error("Something went wrong.");
```

---

# 42. Contact Class Template

## Copy/Paste Code

```cpp
class Contact {
private:
    string firstName;
    string lastName;
    string phone;
    string email;

public:
    Contact() : firstName(""), lastName(""), phone(""), email("") {}

    Contact(string first, string last, string p, string e)
        : firstName(first), lastName(last), phone(p), email(e) {}

    string getLastName() const {
        return lastName;
    }

    void display() const {
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
    }
};
```

## What it is for

Use this for contact-management assignments.

## How to change it

Add more fields:

```cpp
string address;
string birthday;
```

## How to expand it

Create a vector of contacts:

```cpp
vector<Contact> contacts;
contacts.push_back(Contact("Mary", "Smith", "555-1111", "mary@email.com"));
```

---

# 43. Class Object Vector Menu Pattern

## Copy/Paste Code

```cpp
vector<Contact> contacts;

contacts.push_back(Contact("Mary", "Smith", "555-1111", "mary@email.com"));

for (const Contact& c : contacts) {
    c.display();
}
```

## What it is for

Use this when your program stores many objects.

## How to change it

Change `Contact` to your class:

```cpp
vector<Student> students;
vector<Item> inventory;
```

## How to expand it

Search by a getter:

```cpp
if (contacts[i].getLastName() == target)
```

---

# 44. Clean Print Divider

## Copy/Paste Code

```cpp
void printDivider() {
    cout << "----------------------------------------" << endl;
}
```

## What it is for

Keeps output easier to read.

## How to change it

Change the line:

```cpp
cout << "========================================" << endl;
```

## How to expand it

Use a title:

```cpp
void printTitle(string title) {
    cout << "\n===== " << title << " =====" << endl;
}
```

---

# 45. Quick Debug Print

## Copy/Paste Code

```cpp
cout << "DEBUG: value = " << value << endl;
```

## What it is for

Use this to check what a variable is doing while your program runs.

## How to change it

Change `value` to the variable you want to inspect.

## How to expand it

Print several values:

```cpp
cout << "DEBUG: i = " << i << ", total = " << total << endl;
```

---

# 46. Safe `cin` Cleanup After Number Input

## Copy/Paste Code

```cpp
cin.ignore(numeric_limits<streamsize>::max(), '\n');
```

## Required Include

```cpp
#include <limits>
```

## What it is for

Use this after `cin >> number;` before using `getline()`.

Without this, `getline()` may accidentally read the leftover newline.

## How to change it

Usually do not change it.

## How to expand it

Example:

```cpp
int age;
string name;

cin >> age;
cin.ignore(numeric_limits<streamsize>::max(), '\n');

getline(cin, name);
```

---

# 47. Search Array

## Copy/Paste Code

```cpp
bool found = false;
int target = 50;

for (int i = 0; i < SIZE; i++) {
    if (numbers[i] == target) {
        cout << "Found at index " << i << endl;
        found = true;
        break;
    }
}

if (!found) {
    cout << "Not found" << endl;
}
```

## What it is for

Use this to find a value in an array.

## How to change it

Change:
- `target`
- array name
- condition

## How to expand it

For strings:

```cpp
if (names[i] == targetName)
```

---

# 48. Delete From Array by Shifting

## Copy/Paste Code

```cpp
int deleteIndex = 2;

for (int i = deleteIndex; i < size - 1; i++) {
    numbers[i] = numbers[i + 1];
}

size--;
```

## What it is for

Use this when deleting from a normal array.

Since arrays cannot shrink, you shift everything left and reduce the logical size.

## How to change it

Change `deleteIndex`.

## How to expand it

Search first, then delete the found index.

---

# 49. Swap Function

## Copy/Paste Code

```cpp
void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
```

## What it is for

Swaps two values using references.

## How to change it

Change type:

```cpp
void swapValues(double& a, double& b)
```

## How to expand it

Use pointer version:

```cpp
void swapValues(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

---

# 50. Sorting a Vector

## Copy/Paste Code

```cpp
sort(numbers.begin(), numbers.end());
```

## Required Include

```cpp
#include <algorithm>
```

## What it is for

Sorts a vector from smallest to largest.

## How to change it

Descending order:

```cpp
sort(numbers.begin(), numbers.end(), greater<int>());
```

## How to expand it

For strings:

```cpp
sort(names.begin(), names.end());
```

---

# 51. Final Advice for Reusing Snippets

When copying a snippet into a new assignment:

1. Change the class/function/variable names first.
2. Check every type: `int`, `double`, `string`, custom class, etc.
3. Make sure required includes are at the top.
4. Make sure every `{` has a matching `}`.
5. If you use `new`, make sure you use `delete`.
6. If you use `new[]`, make sure you use `delete[]`.
7. If a class owns dynamic memory, use the Rule of Three.
8. Test one small section at a time.
9. Add debug prints when something acts weird.
10. Rename vague files like `new 2.cpp` before uploading to GitHub.
