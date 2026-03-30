#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

//--------------------------------------------------
// Dog class
// Demonstrates returning a REFERENCE to the object
// so you can chain function calls.
//--------------------------------------------------
class Dog {
	int age;   // each Dog object stores its own age

public:
	// Constructor: runs when a Dog object is created
	Dog(int a) : age(a) {}

	// Returns a reference to THIS same Dog object
	// This is useful for chaining, like:
	// myDog.setAge(5).setAge(6);
	Dog& setAge(int a) {
		age = a;
		return *this;   // *this means "the current object itself"
	}

	// Returns a COPY of the Dog object
	// Less common for setter functions if you want chaining efficiently
	Dog setAge2(int a) {
		age = a;
		return *this;   // returning a copy
	}

	int getAge() {
		return age;
	}
};

//--------------------------------------------------
// Cat class
// Demonstrates returning a POINTER to the object
// so you can chain with ->
//--------------------------------------------------
class Cat {
	int age;

public:
	Cat(int a) : age(a) {}

	// Returns the pointer to the current object
	// Useful for chaining like:
	// catPtr->setAge(3)->setAge(4);
	Cat* setAge(int a) {
		age = a;
		return this;   // this is a pointer to the current object
	}

	int getAge() {
		return age;
	}
};

//--------------------------------------------------
// M class
// Normal mutator methods that do work, but do not
// return anything, so chaining is not possible.
//--------------------------------------------------
class M {
private:
	int value;

public:
	M(int v) : value(v) {}

	void setValue(int v) {
		value = v;
	}

	void add(int val) {
		value += val;
	}

	void print() {
		cout << "Value: " << value << endl;
	}
};

//--------------------------------------------------
// MC class
// Same idea as M, but methods return a reference
// to allow method chaining.
//--------------------------------------------------
class MC {
private:
	int value;

public:
	MC(int v) : value(v) {}

	MC& setValue(int v) {
		value = v;
		return *this;   // return current object by reference
	}

	MC& add(int val) {
		value += val;
		return *this;
	}

	void print() {
		cout << "Value: " << value << endl;
	}
};

//--------------------------------------------------
// Rec class
// Demonstrates const member functions.
// A const function promises not to modify the object.
//--------------------------------------------------
class Rec {
private:
	int width, height;

public:
	Rec(int w, int h) : width(w), height(h) {}

	// const means this function does not change width/height
	// That is why it can be called on const objects too.
	int area() const {
		return width * height;
	}

	void setWidth(int w) {
		width = w;
	}

	int getWidth() const {
		return width;
	}
};

//--------------------------------------------------
// L class
// Demonstrates mutable.
// mutable lets a member be changed even inside const functions.
//--------------------------------------------------
class L {
private:
	int i = 0;               // normal member
	mutable int lCount;      // can still change inside const function

public:
	L() : lCount(0) {}

	// const means this function should not modify the object
	// But mutable members are the exception.
	void log() const {
		lCount++;
		cout << "Log called " << lCount << " times\n";
	}
};

//--------------------------------------------------
// V class
// Demonstrates several storage/member keywords.
// Some are older or less commonly used in modern C++,
// but they are still good to recognize.
//--------------------------------------------------
class V {
private:
	int NorVar;             // normal instance variable
	const int Constval;     // must be initialized in constructor initializer list
	mutable int mutVar = 0; // can change even in const functions
	static int statVar;     // shared by all V objects
	volatile int volaVar;   // value may change unexpectedly outside normal program flow

public:
	// Constval must be initialized here
	V(int val) : NorVar(0), Constval(val), volaVar(0) {
		statVar++;
	}

	void setValue(int v) {
		NorVar = v;
	}

	// const member function
	// Cannot change normal members here,
	// but can change mutable members.
	void inc() const {
		register int speed = 100; // old keyword; compiler usually ignores it today
		mutVar++;
	}

	static int getCount() {
		return statVar;
	}

	int getValue() {
		return volaVar;
	}
};

// Definition of static class variable
// Without this, the program will not link correctly.
int V::statVar = 0;

int main() {

	int a = 10;
	int b = 1;

	// ref is another name for a
	int& ref = a;

	// ptr stores the address of a
	int* ptr = &a;

	cout << "Initial values\n";
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	cout << "\nAddresses\n";
	cout << "&a = " << &a << endl;
	cout << "ptr = " << ptr << endl;

	// A reference is just another name for the same variable,
	// so its address is the same as a's address.
	cout << "&ref = " << &ref << " (same as &a)\n";

	// Changes a through the reference
	ref = 13;
	cout << "\nAfter ref = 13\n";
	cout << "a = " << a << endl;

	// Changes a through the pointer
	*ptr = 19;
	cout << "\nAfter *ptr = 19\n";
	cout << "a = " << a << endl;

	// Pointer can be redirected to point somewhere else
	ptr = &b;
	*ptr = 50;

	cout << "\nPointer reassigned to b\n";
	cout << "b = " << b << endl;

	// Reference does NOT rebind to b
	// This copies b's value into a
	ref = b;

	cout << "\nref = b (reference does NOT rebind)\n";
	cout << "a = " << a << endl;

	// This changes a because ref still refers to a
	ref = 100;
	cout << "\nAfter ref = 100\n";
	cout << "a = " << a << endl;

	//--------------------------------------------------
	// Dog and Cat examples
	//--------------------------------------------------
	Dog myDog(10);
	Cat myCat(9);

	Dog& dogRef = myDog;   // dogRef is another name for myDog
	Cat* catPtr = &myCat;  // catPtr stores address of myCat

	dogRef.setAge(11);
	catPtr->setAge(15);

	cout << "Dog age = " << dogRef.getAge() << endl;
	cout << "Cat age = " << catPtr->getAge() << endl;

	// setAge2 returns a COPY of the Dog
	myDog.setAge2(2);
	cout << "Dog age = " << dogRef.getAge() << endl;

	//--------------------------------------------------
	// No chaining here because methods return void
	//--------------------------------------------------
	M o(10);
	o.setValue(20);
	o.add(5);
	o.print();

	//--------------------------------------------------
	// Chaining works here because methods return MC&
	//--------------------------------------------------
	MC obj(10);
	obj.setValue(20).add(5).print();

	//--------------------------------------------------
	// const member function example
	//--------------------------------------------------
	Rec r(1, 2);
	cout << "Area: " << r.area() << endl;
	cout << "Width: " << r.getWidth() << endl;

	const Rec r1(10, 5);

	// Because area() and getWidth() are const,
	// they can be called on const objects.
	cout << "Area: " << r1.area() << endl;
	cout << "Width: " << r1.getWidth() << endl;

	// Not allowed because r1 is const
	// r1.setWidth(15);

	//--------------------------------------------------
	// mutable example
	//--------------------------------------------------
	const L logger;

	// logger is const, but log() is also const,
	// and it is allowed to modify lCount because lCount is mutable
	logger.log();
	logger.log();

	return 0;
}