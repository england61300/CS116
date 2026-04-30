#include <iostream>
using namespace std;

// MEMBER FUNCTION VERSION
class MemberTest {
private:
    double val;

public:
    MemberTest(double v = 0.0) : val(v) {}

    // prefix --
    MemberTest operator--() {
        --val;
        return MemberTest(val);
    }

    // postfix --
    MemberTest operator--(int) {
        MemberTest temp(val);
        val--;
        return temp;
    }

    // -=
    MemberTest operator-=(double d) {
        val -= d;
        return MemberTest(val);
    }

    // *=
    MemberTest operator*=(double d) {
        val *= d;
        return MemberTest(val);
    }

    // /=
    MemberTest operator/=(double d) {
        if (d != 0)
            val /= d;
        else
            cout << "Cannot divide by zero." << endl;

        return MemberTest(val);
    }

    void display() const {
        cout << val << endl;
    }
};

// FRIEND FUNCTION VERSION
class FriendTest {
private:
    double val;

public:
    FriendTest(double v = 0.0) : val(v) {}

    // friend prefix --
    friend FriendTest operator--(FriendTest& a) {
        --a.val;
        return FriendTest(a.val);
    }

    // friend postfix --
    friend FriendTest operator--(FriendTest& a, int) {
        FriendTest temp(a.val);
        a.val--;
        return temp;
    }

    // friend -=
    friend FriendTest operator-=(FriendTest& a, double d) {
        a.val -= d;
        return FriendTest(a.val);
    }

    // friend *=
    friend FriendTest operator*=(FriendTest& a, double d) {
        a.val *= d;
        return FriendTest(a.val);
    }

    // friend /=
    friend FriendTest operator/=(FriendTest& a, double d) {
        if (d != 0)
            a.val /= d;
        else
            cout << "Cannot divide by zero." << endl;

        return FriendTest(a.val);
    }

    void display() const {
        cout << val << endl;
    }
};

int main() {
    cout << "MEMBER FUNCTION VERSION" << endl;
    MemberTest m1(10.0), m2(20.0), m3(30.0), m4(40.0), m5(50.0);

    MemberTest preM = --m1;
    cout << "prefix --m1: ";
    preM.display();

    MemberTest postM = m2--;
    cout << "postfix m2--: ";
    postM.display();
    cout << "m2 after postfix: ";
    m2.display();

    m3 -= 5.0;
    cout << "m3 -= 5.0: ";
    m3.display();

    m4 *= 2.0;
    cout << "m4 *= 2.0: ";
    m4.display();

    m5 /= 5.0;
    cout << "m5 /= 5.0: ";
    m5.display();

    cout << endl;
    cout << "FRIEND FUNCTION VERSION" << endl;
    FriendTest f1(10.0), f2(20.0), f3(30.0), f4(40.0), f5(50.0);

    FriendTest preF = --f1;
    cout << "prefix --f1: ";
    preF.display();

    FriendTest postF = f2--;
    cout << "postfix f2--: ";
    postF.display();
    cout << "f2 after postfix: ";
    f2.display();

    f3 -= 5.0;
    cout << "f3 -= 5.0: ";
    f3.display();

    f4 *= 2.0;
    cout << "f4 *= 2.0: ";
    f4.display();

    f5 /= 5.0;
    cout << "f5 /= 5.0: ";
    f5.display();

    return 0;
}