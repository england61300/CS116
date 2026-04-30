/*
    FILE: 04_Distance_Operator_Overloading_Full_Study_Notes.cpp
    TOPIC: Operator overloading with a distance class.

    This rewrites the larger distance operator file and fixes the scope problem.
    In the original version, several operator functions were written after return 0
    and effectively inside main(), which will not compile as intended.

    Rule:
    Member operators must be declared inside the class.
    Non-member operators, like << and >>, are usually written outside the class.
*/

#include <iostream>
using namespace std;

class Dist {
private:
    int kMeter;
    int meter;

    /*
        simplify()
        ----------
        Keeps the object in a normal form.
        Since 1000 meters = 1 kilometer:

            2 km and 1200 m should become 3 km and 200 m.

        This helper is private because it is an internal detail.
        The user of the class does not need to call it directly.
    */
    void simplify() {
        int totalMeters = (kMeter * 1000) + meter;
        kMeter = totalMeters / 1000;
        meter = totalMeters % 1000;
    }

public:
    // Constructor with default values.
    // Dist d; creates 0 km and 0 m.
    // Dist d(2, 900); creates 2 km and 900 m.
    Dist(int k = 0, int m = 0) : kMeter(k), meter(m) {
        simplify();
    }

    void setKMeter(int k) {
        kMeter = k;
        simplify();
    }

    void setMeter(int m) {
        meter = m;
        simplify();
    }

    int getMeter() const { return meter; }
    int getkMeter() const { return kMeter; }

    void print() const {
        cout << kMeter << " kilometer and " << meter << " meter" << endl;
    }

    /*
        + operator
        ----------
        Allows: d3 = d1 + d2;

        rhs means right-hand side.
        In d1 + d2:
            d1 is the left-hand side object, also called *this
            d2 is rhs
    */
    Dist operator+(const Dist& rhs) const {
        Dist result(kMeter + rhs.kMeter, meter + rhs.meter);
        return result;
    }

    /*
        > operator
        ----------
        Allows: if (d3 > d1)

        It compares kilometers first. If kilometers are equal, it compares meters.
    */
    bool operator>(const Dist& rhs) const {
        return (kMeter > rhs.kMeter) ||
               (kMeter == rhs.kMeter && meter > rhs.meter);
    }

    /*
        Prefix ++
        ----------
        Allows: ++d2;
        Prefix means increment first, then return the updated object.
    */
    Dist& operator++() {
        meter++;
        simplify();
        return *this;
    }

    /*
        Postfix ++
        -----------
        Allows: d2++;
        The unused int parameter is how C++ knows this is postfix.
        Postfix returns the old value, then changes the object.
    */
    Dist operator++(int) {
        Dist oldValue = *this;
        meter++;
        simplify();
        return oldValue;
    }

    /*
        += operator
        -----------
        Allows: d1 += 110;
        This adds meters directly to the existing object.
    */
    Dist& operator+=(int metersToAdd) {
        meter += metersToAdd;
        simplify();
        return *this;
    }

    /*
        Assignment operator
        -------------------
        Allows:
            d3 = d1;
            d4 = d3 = d2;

        C++ would generate this automatically for this class because there is no dynamic memory,
        but writing it here shows how assignment works.
    */
    Dist& operator=(const Dist& rhs) {
        if (this != &rhs) {
            kMeter = rhs.kMeter;
            meter = rhs.meter;
        }
        return *this;
    }

    /*
        Friend input operator
        ---------------------
        Allows: cin >> d3;
        It needs access to private data, so we make it a friend.
    */
    friend istream& operator>>(istream& stream, Dist& d);
};

/*
    Output operator
    ---------------
    Allows: cout << d1;
    This is not a member function because the left side is cout, not a Dist object.
*/
ostream& operator<<(ostream& stream, const Dist& d) {
    stream << d.getkMeter() << " kilometer and " << d.getMeter() << " meter";
    return stream;
}

istream& operator>>(istream& stream, Dist& d) {
    stream >> d.kMeter >> d.meter;
    d.simplify();
    return stream;
}

int main() {
    Dist d1(2, 900);
    Dist d2(1, 999);
    Dist d3;
    Dist d4;

    cout << "Initial distances:\n";
    cout << "d1: " << d1 << endl;
    cout << "d2: " << d2 << endl;

    d3 = d1 + d2;
    cout << "\nAfter d1 + d2, d3: " << d3 << endl;

    ++d2;
    cout << "After prefix ++d2, d2: " << d2 << endl;

    d2++;
    cout << "After postfix d2++, d2: " << d2 << endl;

    d1 += 110;
    cout << "After d1 += 110, d1: " << d1 << endl;

    d3 = d1;
    cout << "After d3 = d1, d3: " << d3 << endl;

    d4 = d3 = d2;
    cout << "After d4 = d3 = d2:\n";
    cout << "d3: " << d3 << endl;
    cout << "d4: " << d4 << endl;

    cout << "\nIs d3 > d1? " << ((d3 > d1) ? "Yes" : "No") << endl;

    cout << "\nEnter distance as two numbers, for example: 3 250\n";
    cout << "Enter distance (kilometers meters): ";
    cin >> d3;
    cout << "You entered: " << d3 << endl;

    return 0;
}
