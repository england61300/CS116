#include <iostream>
using namespace std;

class Dist {
private:
    int kMeter;
    int meter;

    // Keeps meter in the range 0-999
    void normalize() {
        if (meter >= 1000) {
            kMeter += meter / 1000;
            meter = meter % 1000;
        }

        if (meter < 0) {
            int borrow = (-meter + 999) / 1000;
            kMeter -= borrow;
            meter += borrow * 1000;
        }
    }

public:
    // Default constructor
    Dist() {
        kMeter = 0;
        meter = 0;
    }

    // Parameterized constructor
    Dist(int km, int m) {
        kMeter = km;
        meter = m;
        normalize();
    }

    // Copy constructor
    Dist(const Dist& d) {
        kMeter = d.kMeter;
        meter = d.meter;
    }

    // > operator
    bool operator>(const Dist& rhs) const {
        if (kMeter > rhs.kMeter) {
            return true;
        }
        if (kMeter == rhs.kMeter && meter > rhs.meter) {
            return true;
        }
        return false;
    }

    // Prefix ++
    Dist& operator++() {
        ++meter;
        normalize();
        return *this;
    }

    // Postfix ++
    Dist operator++(int) {
        Dist temp(*this);
        meter++;
        normalize();
        return temp;
    }

    // += operator
    Dist& operator+=(int m) {
        meter += m;
        normalize();
        return *this;
    }

    // Assignment operator
    Dist& operator=(const Dist& rhs) {
        if (this != &rhs) {
            kMeter = rhs.kMeter;
            meter = rhs.meter;
        }
        return *this;
    }

    //----------------------------------------------------------
    // Friend functions
    //----------------------------------------------------------
    friend Dist operator+(const Dist& d1, const Dist& d2);
    friend istream& operator>>(istream& stream, Dist& d);
    friend ostream& operator<<(ostream& stream, const Dist& d);
};

// + operator (friend version)
Dist operator+(const Dist& d1, const Dist& d2) {
    Dist temp;
    temp.kMeter = d1.kMeter + d2.kMeter;
    temp.meter = d1.meter + d2.meter;
    temp.normalize();
    return temp;
}

// >> operator (input)
istream& operator>>(istream& stream, Dist& d) {
    stream >> d.kMeter >> d.meter;
    d.normalize();
    return stream;
}

// << operator (output)
ostream& operator<<(ostream& stream, const Dist& d) {
    stream << d.kMeter << " kmeter and " << d.meter << " meter";
    return stream;
}

//==============================================================
int main() {
    // Initial distances
    Dist d1(2, 900);
    Dist d2(1, 999);
    Dist d3, d4;

    cout << "d1 = " << d1 << endl;
    cout << "d2 = " << d2 << endl;

    //----------------------------------------------------------
    // Test + operator
    d3 = d1 + d2;
    cout << "\nAfter d3 = d1 + d2: " << d3 << endl;

    //----------------------------------------------------------
    // Test > operator
    cout << "\nIs d1 > d2? " << ((d1 > d2) ? "Yes" : "No") << endl;

    //----------------------------------------------------------
    // Test >> operator
    cout << "\nEnter distance (km meter): ";
    cin >> d3;
    cout << "You entered: " << d3 << endl;

    //----------------------------------------------------------
    // Test prefix ++
    ++d2;
    cout << "\nAfter prefix ++d2: " << d2 << endl;

    //----------------------------------------------------------
    // Test postfix ++
    d2++;
    cout << "After postfix d2++: " << d2 << endl;

    //----------------------------------------------------------
    // Test += operator
    d1 += 110;
    cout << "\nAfter d1 += 110: " << d1 << endl;

    //----------------------------------------------------------
    // Test assignment operator
    d3 = d1;
    cout << "After d3 = d1: " << d3 << endl;

    d4 = d3 = d2;
    cout << "After d4 = d3 = d2:" << endl;
    cout << "d3 = " << d3 << endl;
    cout << "d4 = " << d4 << endl;

    return 0;
}