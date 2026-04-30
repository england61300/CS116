# C++ Copy/Paste Snippet Bank

# 1. Basic Program

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello!" << endl;
    return 0;
}
```

**What it is for:**  
Starting any C++ program.

**Change this:**  
Change the text inside `cout`.

**Expand it by:**  
Adding variables, input, functions, or classes.

---

# 2. Print Something

```cpp
cout << "Message here" << endl;
```

**What it is for:**  
Displays output on the screen.

**Change this:**  
Replace `"Message here"`.

**Expand it by:**  

```cpp
cout << "Score: " << score << endl;
```

---

# 3. User Input

```cpp
int number;

cout << "Enter a number: ";
cin >> number;
```

**What it is for:**  
Gets a value from the user.

**Change this:**  
Change `int number` to another type.

```cpp
double price;
string name;
```

**Expand it by:**  
Ask for multiple values.

---

# 4. Full Line Input

```cpp
string text;

cout << "Enter text: ";
getline(cin, text);
```

**What it is for:**  
Gets a full line, including spaces.

**Change this:**  
Rename `text`.

**Expand it by:**  
Use after `cin.ignore()` if you used `cin >>` before it.

---

# 5. If / Else

```cpp
if (number > 0) {
    cout << "Positive" << endl;
}
else {
    cout << "Zero or negative" << endl;
}
```

**What it is for:**  
Makes a decision.

**Change this:**  
Change the condition.

**Expand it by:**  
Adding `else if`.

---

# 6. Else If Chain

```cpp
if (score >= 90) {
    cout << "A" << endl;
}
else if (score >= 80) {
    cout << "B" << endl;
}
else {
    cout << "Below B" << endl;
}
```

**What it is for:**  
Checks several possible conditions.

**Change this:**  
Change the score ranges.

**Expand it by:**  
Add more `else if` blocks.

---

# 7. Switch Statement

```cpp
switch (choice) {
case 1:
    cout << "Option 1" << endl;
    break;
case 2:
    cout << "Option 2" << endl;
    break;
default:
    cout << "Invalid" << endl;
}
```

**What it is for:**  
Handles menu choices.

**Change this:**  
Change the case numbers and actions.

**Expand it by:**  
Add more `case` sections.

---

# 8. Menu Loop

```cpp
int choice;

do {
    cout << "1. Start" << endl;
    cout << "2. Exit" << endl;
    cin >> choice;

    if (choice == 1) {
        cout << "Starting..." << endl;
    }

} while (choice != 2);
```

**What it is for:**  
Repeats a menu until the user exits.

**Change this:**  
Change the exit number.

**Expand it by:**  
Use a `switch` inside the loop.

---

# 9. For Loop

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

**What it is for:**  
Repeats a known number of times.

**Change this:**  
Change `5` to the amount you need.

**Expand it by:**  
Use `i` as an array index.

---

# 10. While Loop

```cpp
int x = 0;

while (x < 5) {
    cout << x << endl;
    x++;
}
```

**What it is for:**  
Repeats while a condition is true.

**Change this:**  
Change `x < 5`.

**Expand it by:**  
Use it for validation.

---

# 11. Input Validation

```cpp
while (number < 0) {
    cout << "Enter a positive number: ";
    cin >> number;
}
```

**What it is for:**  
Forces the user to enter valid input.

**Change this:**  
Change the condition.

**Expand it by:**  

```cpp
while (number < 1 || number > 10)
```

---

# 12. Function With Return

```cpp
int doubleNumber(int x) {
    return x * 2;
}
```

**What it is for:**  
Calculates and returns a value.

**Change this:**  
Change the return type, name, and formula.

**Expand it by:**  
Add more parameters.

---

# 13. Void Function

```cpp
void sayHello() {
    cout << "Hello!" << endl;
}
```

**What it is for:**  
Runs code without returning a value.

**Change this:**  
Change the function name and message.

**Expand it by:**  
Add parameters.

```cpp
void sayHello(string name)
```

---

# 14. Function Prototype

```cpp
void showMessage();

int main() {
    showMessage();
    return 0;
}

void showMessage() {
    cout << "Hi" << endl;
}
```

**What it is for:**  
Lets you put functions after `main()`.

**Change this:**  
Prototype and function header must match.

**Expand it by:**  
Add more prototypes above `main()`.

---

# 15. Array

```cpp
int nums[3] = {10, 20, 30};
```

**What it is for:**  
Stores multiple values of the same type.

**Change this:**  
Change size and values.

**Expand it by:**  
Loop through it.

---

# 16. Print Array

```cpp
for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
}
```

**What it is for:**  
Displays all array values.

**Change this:**  
Change `arr` and `size`.

**Expand it by:**  
Print each value on a new line.

---

# 17. Sum Array

```cpp
int total = 0;

for (int i = 0; i < size; i++) {
    total += arr[i];
}
```

**What it is for:**  
Adds all values in an array.

**Change this:**  
Change `arr`.

**Expand it by:**  
Find average:

```cpp
double average = total / static_cast<double>(size);
```

---

# 18. Find Max

```cpp
int maxValue = arr[0];

for (int i = 1; i < size; i++) {
    if (arr[i] > maxValue) {
        maxValue = arr[i];
    }
}
```

**What it is for:**  
Finds the largest value.

**Change this:**  
Use `<` to find smallest.

**Expand it by:**  
Track index too.

---

# 19. Bubble Sort

```cpp
for (int pass = 0; pass < size - 1; pass++) {
    for (int i = 0; i < size - 1 - pass; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
}
```

**What it is for:**  
Sorts an array from smallest to largest.

**Change this:**  
Use `<` instead of `>` for largest to smallest.

**Expand it by:**  
Put it inside a function.

---

# 20. Vector

```cpp
vector<int> nums;

nums.push_back(10);
nums.push_back(20);
```

**Required include:**

```cpp
#include <vector>
```

**What it is for:**  
A resizable array.

**Change this:**  
Change the type.

```cpp
vector<string> words;
```

**Expand it by:**  
Loop through it.

---

# 21. Print Vector

```cpp
for (int value : nums) {
    cout << value << " ";
}
```

**What it is for:**  
Prints every item in a vector.

**Change this:**  
Change `int` and `nums`.

**Expand it by:**  
Use references for objects.

```cpp
for (const auto& item : items)
```

---

# 22. Search Vector

```cpp
bool found = false;

for (int value : nums) {
    if (value == target) {
        found = true;
    }
}
```

**What it is for:**  
Checks if a vector contains something.

**Change this:**  
Change the condition.

**Expand it by:**  
Print where it was found.

---

# 23. Delete From Vector

```cpp
nums.erase(nums.begin() + index);
```

**What it is for:**  
Removes one element from a vector.

**Change this:**  
Change `index`.

**Expand it by:**  
Search first, then erase.

---

# 24. Basic Class

```cpp
class Thing {
private:
    int value;

public:
    Thing() {
        value = 0;
    }
};
```

**What it is for:**  
Creates a blueprint for objects.

**Change this:**  
Change class name and data.

**Expand it by:**  
Add setters, getters, and print functions.

---

# 25. Getter and Setter

```cpp
class Thing {
private:
    int value;

public:
    void setValue(int v) {
        value = v;
    }

    int getValue() const {
        return value;
    }
};
```

**What it is for:**  
Safely reads and changes private data.

**Change this:**  
Change `value` and type.

**Expand it by:**  
Add validation inside setter.

---

# 26. Constructor

```cpp
class Thing {
private:
    int value;

public:
    Thing(int v) {
        value = v;
    }
};
```

**What it is for:**  
Sets up an object when it is created.

**Change this:**  
Change parameters and assigned values.

**Expand it by:**  
Use an initializer list.

---

# 27. Initializer List

```cpp
class Thing {
private:
    int value;

public:
    Thing(int v) : value(v) {}
};
```

**What it is for:**  
Cleaner constructor style.

**Change this:**  
Change `value(v)`.

**Expand it by:**  
Initialize multiple variables.

```cpp
Thing(int a, int b) : x(a), y(b) {}
```

---

# 28. Print Method

```cpp
void print() const {
    cout << value << endl;
}
```

**What it is for:**  
Lets an object display itself.

**Change this:**  
Change what gets printed.

**Expand it by:**  
Print multiple member variables.

---

# 29. Struct

```cpp
struct Data {
    int id;
    double amount;
};
```

**What it is for:**  
Groups simple data together.

**Change this:**  
Change fields.

**Expand it by:**  
Make an array or vector of structs.

---

# 30. Pointer

```cpp
int x = 5;
int* p = &x;

cout << *p << endl;
```

**What it is for:**  
Stores the address of a variable.

**Change this:**  
Change the type.

**Expand it by:**  
Modify the value:

```cpp
*p = 10;
```

---

# 31. Dynamic Variable

```cpp
int* p = new int;
*p = 5;

delete p;
p = nullptr;
```

**What it is for:**  
Creates one variable on the heap.

**Change this:**  
Change type.

**Expand it by:**  
Use a dynamic array.

---

# 32. Dynamic Array

```cpp
int* arr = new int[size];

delete[] arr;
arr = nullptr;
```

**What it is for:**  
Creates an array whose size is decided while the program runs.

**Change this:**  
Change type and size.

**Expand it by:**  
Fill it with a loop.

---

# 33. Rule of Three Skeleton

```cpp
class Box {
private:
    int* data;

public:
    Box() {
        data = new int(0);
    }

    ~Box() {
        delete data;
    }

    Box(const Box& other) {
        data = new int(*other.data);
    }

    Box& operator=(const Box& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }
};
```

**What it is for:**  
Use when a class owns dynamic memory.

**Change this:**  
Change the data type.

**Expand it by:**  
Use arrays with `new[]` and `delete[]`.

---

# 34. Linked List Node

```cpp
struct Node {
    int data;
    Node* next;
};
```

**What it is for:**  
Basic linked list piece.

**Change this:**  
Change `int data`.

**Expand it by:**  
Add insert/search/delete functions.

---

# 35. Make New Node

```cpp
Node* node = new Node;
node->data = 10;
node->next = nullptr;
```

**What it is for:**  
Creates a linked list node.

**Change this:**  
Change the value.

**Expand it by:**  
Attach it to a list.

---

# 36. Inheritance

```cpp
class Base {
public:
    void show() {
        cout << "Base" << endl;
    }
};

class Derived : public Base {
};
```

**What it is for:**  
Lets one class reuse another class.

**Change this:**  
Change class names.

**Expand it by:**  
Add functions to the derived class.

---

# 37. Virtual Function

```cpp
class Base {
public:
    virtual void show() {
        cout << "Base" << endl;
    }

    virtual ~Base() {}
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived" << endl;
    }
};
```

**What it is for:**  
Allows runtime polymorphism.

**Change this:**  
Change the function name and output.

**Expand it by:**  
Use a base pointer:

```cpp
Base* p = new Derived();
p->show();
delete p;
```

---

# 38. Operator +

```cpp
class Num {
private:
    int value;

public:
    Num(int v = 0) : value(v) {}

    Num operator+(const Num& other) const {
        return Num(value + other.value);
    }
};
```

**What it is for:**  
Lets objects use `+`.

**Change this:**  
Change the calculation.

**Expand it by:**  
Add `-`, `*`, `/`, or comparisons.

---

# 39. Output Operator

```cpp
class Num {
private:
    int value;

public:
    Num(int v = 0) : value(v) {}

    friend ostream& operator<<(ostream& out, const Num& n);
};

ostream& operator<<(ostream& out, const Num& n) {
    out << n.value;
    return out;
}
```

**What it is for:**  
Lets you use:

```cpp
cout << object;
```

**Change this:**  
Change what `out` prints.

**Expand it by:**  
Print multiple fields.

---

# 40. File Write

```cpp
ofstream file("data.txt");

file << "Hello" << endl;

file.close();
```

**Required include:**

```cpp
#include <fstream>
```

**What it is for:**  
Writes to a file.

**Change this:**  
Change filename and output.

**Expand it by:**  
Check if file opened.

---

# 41. File Read

```cpp
ifstream file("data.txt");
string word;

while (file >> word) {
    cout << word << endl;
}

file.close();
```

**Required include:**

```cpp
#include <fstream>
```

**What it is for:**  
Reads from a file.

**Change this:**  
Change filename and variable.

**Expand it by:**  
Use `getline()` for full lines.

---

# 42. Swap

```cpp
int temp = a;
a = b;
b = temp;
```

**What it is for:**  
Swaps two values.

**Change this:**  
Use different variable names.

**Expand it by:**  
Put it inside a function.

---

# 43. Random Number

```cpp
int number = rand() % 10 + 1;
```

**Required include:**

```cpp
#include <cstdlib>
```

**What it is for:**  
Gets a random number from 1 to 10.

**Change this:**  
Change `10`.

**Expand it by:**  
Seed randomness:

```cpp
#include <ctime>
srand(time(0));
```

---

# 44. Try / Catch

```cpp
try {
    throw "Something went wrong";
}
catch (const char* message) {
    cout << message << endl;
}
```

**What it is for:**  
Handles simple errors.

**Change this:**  
Change the message.

**Expand it by:**  
Throw only when a condition fails.

---

# 45. Debug Print

```cpp
cout << "DEBUG: x = " << x << endl;
```

**What it is for:**  
Checks a variable while the program runs.

**Change this:**  
Change `x`.

**Expand it by:**  
Print multiple variables.

---

# 46. Clean Input Before getline

```cpp
cin.ignore();
```

**What it is for:**  
Clears leftover Enter key before `getline()`.

**Change this:**  
Usually do not change it.

**Expand it by:**  
More complete version:

```cpp
cin.ignore(numeric_limits<streamsize>::max(), '\n');
```

Required include:

```cpp
#include <limits>
```

---

# 47. Object Vector Programs

These snippets are useful when you have a class and want to store many objects in a `vector`.

Example idea:

```cpp
vector<Item> items;
```

That means `items` stores many `Item` objects.

---

# 48. Empty Vector Check

```cpp
if (items.empty()) {
    cout << "No items found." << endl;
    return;
}
```

**What it is for:**  
Stops a function early if the vector has nothing inside it.

**Change this:**  
Change `items` to your vector name.

**Expand it by:**  
Use a more specific message.

```cpp
cout << "No students found." << endl;
cout << "No products found." << endl;
cout << "No records found." << endl;
```

---

# 49. Add Object to Vector

```cpp
Item newItem(name, price);
items.push_back(newItem);
```

**What it is for:**  
Creates an object and stores it in a vector.

**Change this:**  
Change `Item` to your class name.  
Change `name, price` to match your constructor.

**Expand it by:**  
Create the object directly inside `push_back`.

```cpp
items.push_back(Item(name, price));
```

---

# 50. Display All Objects in Vector

```cpp
for (int i = 0; i < items.size(); i++) {
    items[i].print();
}
```

**What it is for:**  
Loops through a vector of objects and calls each object’s print function.

**Change this:**  
Change `items` to your vector name.  
Change `print()` to your class’s display function.

**Expand it by:**  
Number each item.

```cpp
for (int i = 0; i < items.size(); i++) {
    cout << "Item #" << i + 1 << endl;
    items[i].print();
}
```

---

# 51. Search Object in Vector by Getter

```cpp
bool found = false;

for (int i = 0; i < items.size(); i++) {
    if (items[i].getName() == target) {
        items[i].print();
        found = true;
    }
}

if (!found) {
    cout << "Not found." << endl;
}
```

**What it is for:**  
Searches a vector of objects using a getter function.

**Change this:**  
Change `items` to your vector name.  
Change `getName()` to the getter you need.  
Change `target` to the value you are searching for.

**Expand it by:**  
Stop after the first match.

```cpp
for (int i = 0; i < items.size(); i++) {
    if (items[i].getName() == target) {
        items[i].print();
        found = true;
        break;
    }
}
```

---

# 52. Delete Object from Vector by Getter

```cpp
for (int i = 0; i < items.size(); i++) {
    if (items[i].getName() == target) {
        items.erase(items.begin() + i);
        cout << "Deleted successfully." << endl;
        return;
    }
}

cout << "Not found." << endl;
```

**What it is for:**  
Deletes the first matching object from a vector.

**Change this:**  
Change `items` to your vector name.  
Change `getName()` to your getter.  
Change `target` to the value you want to delete.

**Expand it by:**  
Delete all matching objects by looping backward.

```cpp
for (int i = items.size() - 1; i >= 0; i--) {
    if (items[i].getName() == target) {
        items.erase(items.begin() + i);
    }
}
```

---

# 53. Function That Receives a Vector by Reference

```cpp
void addItem(vector<Item>& items) {
    string name;
    double price;

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter price: ";
    cin >> price;

    items.push_back(Item(name, price));
}
```

**What it is for:**  
Lets a function change the original vector.

**Change this:**  
Change `Item` to your class name.  
Change the input variables.

**Why the `&` matters:**  
Without `&`, the function gets a copy of the vector.  
With `&`, the function changes the real vector.

---

# 54. Function That Receives a Vector Without Changing It

```cpp
void displayItems(const vector<Item>& items) {
    for (int i = 0; i < items.size(); i++) {
        items[i].print();
    }
}
```

**What it is for:**  
Lets a function read a vector without copying it or changing it.

**Change this:**  
Change `Item` to your class name.  
Change `print()` to your display function.

**Why `const` matters:**  
`const` means the function is not allowed to change the vector.

---

# 55. Object Vector Menu Pattern

```cpp
vector<Item> items;
int choice;

do {
    cout << "1. Add item" << endl;
    cout << "2. Display items" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        addItem(items);
        break;

    case 2:
        displayItems(items);
        break;

    case 3:
        cout << "Goodbye!" << endl;
        break;

    default:
        cout << "Invalid choice." << endl;
    }

} while (choice != 3);
```

**What it is for:**  
Basic menu structure for programs that manage many objects.

**Change this:**  
Change `Item` to your class name.  
Change the menu options.  
Change the function names.

**Expand it by:**  
Add search and delete options.

```cpp
case 3:
    searchItem(items);
    break;

case 4:
    deleteItem(items);
    break;
```
