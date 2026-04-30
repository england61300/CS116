/*
    FILE: 01_Vector_Study_Notes.cpp
    TOPIC: std::vector, loops, iterators, sorting, inserting, erasing, and objects in vectors.

    Big idea:
    A vector is like an array, but it can grow and shrink while the program runs.
    A normal array has a fixed size. A vector manages its own memory for you.
*/

#include <iostream>     // lets us use cout and cin
#include <vector>       // gives us std::vector
#include <algorithm>    // gives us std::sort
#include <functional>   // gives us std::greater<int>() for descending sort
#include <string>       // gives us std::string

using namespace std;

/*
    Person class
    ------------
    This class shows that vectors can store objects, not just numbers.

    private:
        The data members cannot be touched directly from main().
        This protects the object from accidental changes.

    public:
        Constructor and getters are public so other code can create
        Person objects and safely read their information.
*/
class Person {
private:
    string name;
    int age;

public:
    // Constructor: runs when we create a Person.
    // const string& avoids copying the name unnecessarily.
    Person(const string& name, int age) : name(name), age(age) {}

    // const after the function means this function promises not to change the object.
    string getName() const { return name; }
    int getAge() const { return age; }
};

/*
    getVector
    ---------
    Parameter: vector<int>& v

    The & means pass by reference.
    Without &, the function would receive a copy of the vector.
    Changing the copy would not change the original vector in main().
*/
void getVector(vector<int>& v) {
    for (auto& elem : v) {
        // auto& means elem is a reference to the actual vector element.
        // If we used auto without &, elem would be a copy.
        cout << "Enter value for vector: ";
        cin >> elem;
    }
}

/*
    printVectorByIndex
    ------------------
    Uses an index, similar to a normal array.
    v.at(i) is safer than v[i] because at() checks the index.
    If the index is invalid, at() throws an error instead of silently causing memory problems.
*/
void printVectorByIndex(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
}

/*
    printVectorRangeBased
    ---------------------
    Range-based for loop.
    This is usually the easiest loop when you only need to read every value.

    const vector<int>& means:
    - const: do not change the vector
    - &: do not copy the whole vector
*/
void printVectorRangeBased(const vector<int>& v) {
    for (int value : v) {
        // value is a copy of each element.
        // That is fine because we only print it.
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    /*
        Different ways to create vectors
        --------------------------------
        vector<int> v1(10);
            Creates 10 integers. Since they are ints, they start at 0.

        vector<int> v2(10, 19);
            Creates 10 integers and sets each one to 19.

        vector<int> v3 = { 15, 10, 35, 20 };
            Creates a vector with specific starting values.
    */
    vector<int> v1(10);
    vector<int> v2(10, 19);
    vector<int> v3 = { 15, 10, 35, 20 };
    vector<int> v4(3);
    vector<int> v5 = { 1, 2, 3, 4, 5 };
    vector<int> v6 = { 3, 4, 5 };
    vector<int> v; // empty vector

    /*
        reserve vs resize
        -----------------
        reserve(20): gives the vector room for 20 elements, but size is still 0.
        resize(20): actually creates elements, so size becomes 20.

        size = how many real elements are currently in the vector.
        capacity = how many elements the vector can hold before it must allocate more memory.
    */
    v.reserve(20);

    // push_back adds a new element to the end of the vector.
    v.push_back(10);
    cout << "element 0 of v = " << v.at(0) << endl;

    v.push_back(20);
    v.push_back(30);

    cout << "size = " << v.size() << endl;
    printVectorByIndex(v);
    printVectorRangeBased(v);

    // resize creates more elements. New int elements become 0.
    v.resize(10);
    v.at(1) = 11;

    cout << "\nAfter resize to 10 and changing index 1:\n";
    printVectorRangeBased(v);
    cout << "size = " << v.size() << endl;
    cout << "capacity = " << v.capacity() << endl;
    cout << "front = " << v.front() << endl; // first element
    cout << "back = " << v.back() << endl;   // last element

    v.push_back(6);
    cout << "\nAfter push_back(6):\n";
    printVectorRangeBased(v);
    cout << "last element = " << v.back() << endl;

    /*
        Copying vectors
        ---------------
        vector<int> w = v;
        This makes a full copy. After copying, v and w are separate vectors.
    */
    cout << "\nv: ";
    printVectorRangeBased(v);

    vector<int> w = v;
    cout << "w: ";
    printVectorRangeBased(w);

    if (v == w) {
        cout << "v is equal to w\n";
    }

    w.push_back(13);

    if (v == w) {
        cout << "v is equal to w\n";
    }
    else {
        cout << "v is not equal to w\n";
    }

    /*
        Sorting
        -------
        sort(v3.begin(), v3.end()) sorts from smallest to largest.
        begin() points at the first element.
        end() points one position AFTER the last element.
    */
    cout << "\nOriginal v3: ";
    printVectorRangeBased(v3);

    cout << "Sorting ascending\n";
    sort(v3.begin(), v3.end());
    printVectorRangeBased(v3);

    cout << "Sorting descending\n";
    sort(v3.begin(), v3.end(), greater<int>());
    printVectorRangeBased(v3);

    /*
        insert
        ------
        insert(position, value) places a value before the chosen position.
        v.begin() is position 0.
        v.begin() + 2 is index 2.
    */
    cout << "\nBefore inserts: ";
    printVectorRangeBased(v);

    v.insert(v.begin(), 7);
    cout << "After inserting 7 at the beginning: ";
    printVectorRangeBased(v);

    v.insert(v.begin() + 2, 17);
    cout << "After inserting 17 at index 2: ";
    printVectorRangeBased(v);

    /*
        Iterators
        ---------
        An iterator acts like a pointer into the vector.
        *it means "the value the iterator is currently pointing at."
        ++it moves to the next element.
    */
    v.resize(10);
    for (size_t i = 0; i < v.size(); i++) {
        v.at(i) = 10 * static_cast<int>(i + 1);
    }

    cout << "\nReset vector to 10, 20, 30...:\n";
    printVectorRangeBased(v);

    vector<int>::iterator it1 = v.begin();
    vector<int>::iterator it2 = v.end();

    while (it1 != it2) {
        *it1 *= 2;
        ++it1;
    }

    cout << "After doubling every value with iterators:\n";
    printVectorRangeBased(v);

    /*
        auto
        ----
        auto tells C++ to figure out the variable type from the value.
        It saves typing, especially for long iterator types.
    */
    auto number = 19;       // int
    auto name = "Bob";      // const char*
    auto list = { 1, 2, 3 }; // initializer_list<int>
    (void)number;
    (void)name;
    (void)list;

    vector<int> nums = { 1, 2, 3, 4, 5 };
    for (auto n : nums) {
        // n is a copy of each int.
        (void)n;
    }

    auto insertedPosition = v.insert(v.begin() + 5, 19);
    cout << "\nInserted 19. Iterator points to: " << *insertedPosition << endl;
    printVectorRangeBased(v);

    cout << "Print using iterator loop:\n";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    /*
        erase
        -----
        erase(iterator) removes one element.
        erase(start, stop) removes a range.
        The range is [start, stop), meaning start is included but stop is not included.
    */
    cout << "\nErase element at index 2:\n";
    auto eraseOne = v.begin() + 2;
    v.erase(eraseOne);
    printVectorRangeBased(v);

    auto insertAt = v.begin() + 3;
    v.insert(insertAt, 100);
    cout << "After inserting 100 at index 3:\n";
    printVectorRangeBased(v);

    auto start = v.begin() + 1;
    auto stop = v.begin() + 3;
    v.erase(start, stop);
    cout << "After erasing indexes 1 and 2:\n";
    printVectorRangeBased(v);

    // clear removes all elements. The vector becomes size 0.
    v.clear();
    cout << "\nAfter clear(), v.size() = " << v.size() << endl;

    /*
        Vector of objects
        -----------------
        push_back(Person(...)) creates a Person, then puts it into the vector.
        emplace_back(...) builds the Person directly inside the vector.
        emplace_back is often more efficient.
    */
    vector<Person> students;
    students.push_back(Person("Mary", 19));
    students.emplace_back("Al", 20);
    students.emplace_back("Ross", 21);

    cout << "\nStudents:\n";
    for (const auto& person : students) {
        cout << "Name: " << person.getName()
             << ", Age: " << person.getAge() << endl;
    }

    return 0;
}
