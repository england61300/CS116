/*
    FILE: 08_Account_Polymorphism_Friend_Function_Study_Notes.cpp
    TOPIC: Inheritance, virtual functions, polymorphism, virtual destructors, and friend functions.

    Main ideas:
    1. Account is the base class.
    2. SavingsAccount is a derived class.
    3. virtual deposit() allows a base pointer to call the derived version.
    4. transfer() is a friend function so it can access balance directly.
*/

#include <iostream>
#include <iomanip>

class Account {
protected:
    // protected means derived classes can access it, but main() cannot.
    double balance;

public:
    Account(double initialBalance) : balance(initialBalance) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    virtual void display() const {
        std::cout << "Account Balance: $"
                  << std::fixed << std::setprecision(2)
                  << balance << std::endl;
    }

    /*
        Virtual destructor
        ------------------
        Important when deleting a derived object through a base pointer.
        Example:
            Account* ptr = new SavingsAccount(500);
            delete ptr;
    */
    virtual ~Account() {}

    friend void transfer(Account& from, Account& to, double amount);
};

class SavingsAccount : public Account {
private:
    double interestRate = 0.02;

public:
    SavingsAccount(double initialBalance) : Account(initialBalance) {}

    /*
        override
        --------
        Tells the compiler this function is meant to replace a virtual base-class function.
        If the function signature does not match, the compiler warns us.
    */
    void deposit(double amount) override {
        if (amount > 0) {
            double bonus = amount * interestRate;
            balance += amount + bonus;
            std::cout << "[Savings] Deposited $" << amount
                      << " plus $" << bonus << " interest bonus.\n";
        }
    }
};

void transfer(Account& from, Account& to, double amount) {
    if (amount > 0 && from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        std::cout << "[Transfer] Successfully moved $" << amount << " between accounts.\n";
    }
    else {
        std::cout << "[Transfer] Error: Insufficient funds or invalid amount.\n";
    }
}

int main() {
    Account* myAccount = new SavingsAccount(500.00);
    Account basicAccount(200.00);

    std::cout << "Initial States:\n";
    myAccount->display();
    basicAccount.display();
    std::cout << "-----------------------------------\n";

    // Because deposit is virtual, this calls SavingsAccount::deposit().
    myAccount->deposit(100.00);

    // Dereference pointer with *myAccount because transfer wants an Account reference.
    transfer(*myAccount, basicAccount, 50.00);

    std::cout << "-----------------------------------\n";
    std::cout << "Final States:\n";
    myAccount->display();
    basicAccount.display();

    delete myAccount;
    return 0;
}
