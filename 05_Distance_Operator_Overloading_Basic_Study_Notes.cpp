/*
    FILE: 05_Distance_Operator_Overloading_Basic_Study_Notes.cpp
    TOPIC: Basic + and << operator overloading with a distance class.

    This is the smaller version of the distance program.
    It focuses only on:
        1. storing kilometers and meters
        2. adding two Dist objects with +
        3. printing a Dist object with <<
*/

#include <iostream>
using namespace std;

class Dist {
private:
    int kMeter;
    int meter;

    void simplify() {
        int totalMeters = kMeter * 1000 + meter;
        kMeter = totalMeters / 1000;
        meter = totalMeters % 1000;
    }

public:
    Dist(int k = 0, int m = 0) : kMeter(k), meter(m) {
        simplify();
    }

    int getMeter() const { return meter; }
    int getkMeter() const { return kMeter; }

    void print() const {
        cout << kMeter << " kilometer and " << meter << " meter" << endl;
    }

    Dist operator+(const Dist& rhs) const {
        // Add kilometers together and meters together.
        // The constructor calls simplify(), so 1100 meters becomes 1 km and 100 meters.
        return Dist(kMeter + rhs.kMeter, meter + rhs.meter);
    }
};

ostream& operator<<(ostream& stream, const Dist& d) {
    stream << d.getkMeter() << " kilometer and " << d.getMeter() << " meter";
    return stream;
}

int main() {
    Dist d1(2, 900);
    Dist d2(1, 999);
    Dist d3;

    cout << "Initial distances:\n";
    cout << "d1: " << d1 << endl;
    cout << "d2: " << d2 << endl;

    d3 = d1 + d2;
    cout << "\nAfter d1 + d2:\n";
    cout << "d3: " << d3 << endl;

    return 0;
}
