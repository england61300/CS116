#include<iostream>
using namespace std;

//==============================================================
// 1) Basic Inheritance
//==============================================================

// Animal = base class
class Animal {
private:
	int pv = 13;   // private: only accessible inside Animal

protected:
	int pt = 19;   // protected: accessible inside Animal and derived classes

public:
	void speak() {
		cout << "Animal speaks\n";
	}

	void eat() {
		cout << "Animal eats Animal food\n";
	}
};

// Dog = derived class inheriting publicly from Animal
class Dog : public Animal {
public:
	void f() {
		// Can access pt because pt is protected in Animal
		cout << pt << endl;
	}

	void bark() {
		cout << "Dog barks\n";
	}

	// This hides Animal::eat()
	void eat() {
		cout << "Dogs eat Dog food\n";
	}

	void speak() {
		// This hides Animal::speak()
		cout << "Dog barks" << endl;

		// Explicitly call base class version
		Animal::speak();
	}
};

/*
NOTES:
- Inheritance lets a derived class reuse members of a base class.
- Dog inherits from Animal, so Dog gets access to Animal's public and protected members.
- Dog CANNOT directly access Animal's private member pv.
- Dog CAN access Animal's protected member pt.
- Dog defines its own eat() and speak(), which hide the base class versions.
- Animal::speak() is called inside Dog::speak() using the scope resolution operator.
*/


//==============================================================
// 2) Access Specifiers in Inheritance
//==============================================================

class Base {
public:
	int publicV;

protected:
	int protectedV;

private:
	int privateV;
};

class DerivedPub : public Base {
	// publicV remains public
	// protectedV remains protected
	// privateV is NOT accessible
};

class DerivedProt : protected Base {
	// publicV becomes protected
	// protectedV remains protected
	// privateV is NOT accessible
};

class DerivedPriv : private Base {
	// publicV becomes private
	// protectedV becomes private
	// privateV is NOT accessible
};

/*
NOTES:
Inheritance mode changes how inherited members are exposed in the derived class.

1) public inheritance
   - public members stay public
   - protected members stay protected

2) protected inheritance
   - public members become protected
   - protected members stay protected

3) private inheritance
   - public members become private
   - protected members become private

Important:
- private members of the base class are never directly accessible in the derived class.
*/


//==============================================================
// 3) Constructor and Destructor Order
//==============================================================

class BaseClass {
public:
	BaseClass() {
		cout << "in BaseClass constructor" << endl;
	}

	~BaseClass() {
		cout << "in BaseClass constructor" << endl;   // typo in original code
	}
};

class DerivedClass : public BaseClass {
public:
	DerivedClass() {
		cout << "in DerivedClass constructor" << endl;
	}

	~DerivedClass() {
		cout << "in DerivedClass constructor" << endl; // typo in original code
	}
};

/*
NOTES:
- When an object of DerivedClass is created:
  1) BaseClass constructor runs first
  2) DerivedClass constructor runs second

- When the object is destroyed:
  1) DerivedClass destructor runs first
  2) BaseClass destructor runs second

Important:
- Your destructor messages are mislabeled in the code.
- They should probably say:
	"in BaseClass destructor"
	"in DerivedClass destructor"
*/


//==============================================================
// 4) Runtime Polymorphism / Virtual Functions
//==============================================================

class Shape {
public:
	virtual void draw() {
		cout << "Drawning a shape\n";
	}
};

class Circle : public Shape {
public:
	void draw() override {
		cout << "Drawing a circle\n";
	}
};

class Rectangle : public Shape {
public:
	void draw() {
		cout << "Drawing a rectangle\n";
	}
};

class Parent {
public:
	Parent(int x) {
		cout << "Parent constructor called with x = " << x << endl;
	}
};

class Child : public Parent {
public:
	Child(int x, int y) : Parent(x) {
		cout << "Child constructor called with y = " << y << endl;
	}
};
class Student {
public:
	void study() {
		cout << "student is stying\n";
	}
};
class Childeren {
public:
	void play() {
		cout << "child is playing\n";
	}
};
class PreTeens : public Childeren, public Student {
public: 
	void action() {
		play();
		study();
	}
};

class A {
public:
	void test() {
		cout << "A::test()\n";
	}
};

class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};


/*
==============================================================
Polymorphism (means "many forms")

Compile-time (Static Polymorphism)
1) Function Overloading
2) Operator Overloading
3) Templates (function and class templates)

Runtime Polymorphism (Dynamic Polymorphism)
- Achieved using inheritance + virtual functions (function overriding)
- The function that gets called depends on the object's actual type

Virtual function
- A function declared in a base class that is meant to be
  overridden in derived classes
==============================================================

NOTES FOR THIS CODE:
- Shape has a virtual function draw().
- Circle overrides draw().
- Rectangle also overrides draw().

Why virtual matters:
- When using a base class pointer (Shape*) to point to derived objects,
  the correct draw() function is chosen at runtime.

Example:
	Shape* s1 = new Circle();
	Shape* s2 = new Rectangle();

	s1->draw();   // calls Circle::draw()
	s2->draw();   // calls Rectangle::draw()

- This is runtime polymorphism.
- The decision is based on the actual object type, not just the pointer type.
*/


int main() {
	Dog myDog;
	myDog.f();
	myDog.speak();
	myDog.bark();
	myDog.eat();
	cout << endl;

	DerivedClass obj;
	cout << endl;

	Shape* s1 = new Circle();
	Shape* s2 = new Rectangle();

	s1->draw();
	s2->draw();

	delete s1;
	delete s2;

	Child Object(20, 30);

	PreTeens pt;
	pt.action();

	D d;
	d.test(); 

	return 0;
}