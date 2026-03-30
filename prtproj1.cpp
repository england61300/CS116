#include <iostream>
#include <iomanip>

using namespace std;

struct Student {
	int id;
	double gpa;
};

struct Node {
	Student data;
	Node* next;
};

void reverseArray(int* arr, int size);
void swapValues(int* a, int* b);
void displayList(Node* head);
void freeList(Node*& head);
Node* insert(Node* head, Student s);
Node* searchByID(Node* head, int id);
Node* deleteByID(Node* head, int id);
double averageGPA(Node* head);
int indexOfHighestGPA(Student* students, int n);

void reverseArray(int* arr, int size) {
	int* startPtr = arr;
	int* endPtr = arr + (size - 1);

	while (startPtr < endPtr) {
		int temp = *startPtr;
		*startPtr = *endPtr;
		*endPtr = temp;

		startPtr++;
		endPtr--;
	}
}

void swapValues(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void displayList(Node* head) {
	if (head == nullptr) {
		cout << "(empty list)" << endl;
		return;
	}
	Node* temp = head;
	while (temp != nullptr) {
		cout << "ID: " << temp->data.id
			<< "  GPA: " << fixed << setprecision(2) << temp->data.gpa << endl;
		temp = temp->next;
	}
}

void freeList(Node*& head) {
	Node* temp = head;

	while (temp != nullptr) {
		Node* nextNode = temp->next;
		delete temp;
		temp = nextNode;
	}

	head = nullptr;
}

Node* insert(Node* head, Student s) {
	Node* newNode = new Node;
	newNode->data = s;
	newNode->next = nullptr;

	if (head == nullptr) {
		head = newNode;
		return head;
	}

	Node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newNode;
	return head;
}

Node* searchByID(Node* head, int id) {
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->data.id == id) return temp;
		temp = temp->next;
	}
	return nullptr;
}

Node* deleteByID(Node* head, int id) {
	if (head == nullptr) return nullptr;

	if (head->data.id == id) {
		Node* temp = head;
		head = head->next;
		delete temp;
		return head;
	}

	Node* prev = head;
	Node* temp = head->next;

	while (temp != nullptr) {
		if (temp->data.id == id) {
			prev->next = temp->next;
			delete temp;
			return head;
		}
		prev = temp;
		temp = temp->next;
	}

	return head;
}

double averageGPA(Node* head) {
	double sum = 0.0;
	int count = 0;

	Node* temp = head;
	while (temp != nullptr) {
		sum += temp->data.gpa;
		count++;
		temp = temp->next;
	}

	if (count == 0) return 0.0;
	return sum / count;
}

int indexOfHighestGPA(Student* students, int n) {
	if (n <= 0) return -1;

	int bestIndex = 0;
	for (int i = 1; i < n; i++) {
		if (students[i].gpa > students[bestIndex].gpa) {
			bestIndex = i;
		}
	}
	return bestIndex;
}

int main() {
	cout << "-----------PROBLEM 1------------" << endl;
	const int SIZE = 8;
	int* arr = new int[SIZE];

	cout << "Enter 8 integers: " << endl;

	int* inputPtr = arr;
	while (inputPtr < arr + SIZE) {
		cin >> *inputPtr;
		inputPtr++;
	}

	reverseArray(arr, SIZE);

	cout << "Reversed array: " << endl;

	int* printPtr = arr;
	while (printPtr < arr + SIZE) {
		cout << *printPtr << " ";
		printPtr++;
	}
	cout << endl;
	delete[] arr;
	arr = nullptr;

	cout << "-----------PROBLEM 2------------" << endl;
	int x, y;
	cout << "Enter 2 integers to swarp: " << endl;
	cin >> x >> y;

	cout << "Before swap x= " << x << " y= " << y << endl;
	swapValues(&x, &y);
	cout << "After swap x= " << x << " y= " << y << endl;

	cout << "-----------PROBLEM 3------------" << endl;
	int* numbers[5];

	for (int i = 0; i < 5; i++) {
		numbers[i] = new int;
		*numbers[i] = (i + 1) * 10;
	}

	for (int i = 0; i < 5; i++) {
		cout << *numbers[i] << " " << endl;
	}

	for (int i = 0; i < 5; i++) {
		delete numbers[i];
		numbers[i] = nullptr;
	}

	cout << "-----------PROBLEM 4------------" << endl;
	int n;
	cout << "How many students? ";
	cin >> n;

	if (n > 0) {
		Student* students = new Student[n];

		for (int i = 0; i < n; i++) {
			cout << "Enter student " << (i + 1) << " ID: " << endl;
			cin >> students[i].id;

			cout << "Enter student " << (i + 1) << " GPA: " << endl;
			cin >> students[i].gpa;
		}

		cout << "All students: " << endl;
		for (int i = 0; i < n; i++) {
			cout << "ID: " << students[i].id
				<< "  GPA: " << fixed << setprecision(2) << students[i].gpa << endl;
		}

		int best = indexOfHighestGPA(students, n);
		cout << "Highest GPA student: " << endl;
		cout << "ID: " << students[best].id
			<< "  GPA: " << fixed << setprecision(2) << students[best].gpa << endl;

		delete[] students;
		students = nullptr;
	}
	else {
		cout << "No students to store." << endl;
	}

	cout << "-----------PROBLEM 5------------" << endl;
	Student* studentsPtr[3];

	studentsPtr[0] = new Student;
	studentsPtr[0]->id = 101;
	studentsPtr[0]->gpa = 3.10;

	studentsPtr[1] = new Student;
	studentsPtr[1]->id = 102;
	studentsPtr[1]->gpa = 3.85;

	studentsPtr[2] = new Student;
	studentsPtr[2]->id = 103;
	studentsPtr[2]->gpa = 2.95;

	for (int i = 0; i < 3; i++) {
		cout << "ID: " << studentsPtr[i]->id
			<< "  GPA: " << fixed << setprecision(2) << studentsPtr[i]->gpa << endl;
	}

	for (int i = 0; i < 3; i++) {
		delete studentsPtr[i];
		studentsPtr[i] = nullptr;
	}

	cout << "-----------PROBLEM 6------------" << endl;
	Node* head = nullptr;

	Student s1{ 201, 3.20 };
	Student s2{ 202, 2.70 };
	Student s3{ 203, 3.95 };
	Student s4{ 204, 3.40 };

	head = insert(head, s1);
	head = insert(head, s2);
	head = insert(head, s3);
	head = insert(head, s4);

	cout << endl << "Initial list:" << endl;
	displayList(head);

	int searchId;
	cout << endl << "Enter an ID to search for: ";
	cin >> searchId;

	Node* found = searchByID(head, searchId);
	if (found != nullptr) {
		cout << "Found -> ID: " << found->data.id
			<< " GPA: " << fixed << setprecision(2) << found->data.gpa << endl;
	}
	else {
		cout << "Student ID " << searchId << " not found." << endl;
	}

	int delId;
	cout << endl << "Enter an ID to delete: ";
	cin >> delId;

	head = deleteByID(head, delId);

	cout << endl << "Updated list:" << endl;
	displayList(head);

	cout << endl << "Average GPA: " << fixed << setprecision(2) << averageGPA(head) << endl;

	freeList(head);

	return 0;
}