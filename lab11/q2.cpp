/*
 * Name: Muhammad Abbas
 * id:23k-0068
 * purpose: a bank account system based on abstract class and inheritance
 * */
#include <iostream>

using namespace std;

//abstract base class
class Account {
protected:
    int accountNumber;
    double balance;

public:
    //Parameterized constructor with initializer list
    Account(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

    //pure virtual functions
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void calculateInterest() const = 0;

    //concrete member functions
    int getAccountNumber() const {
        return accountNumber;
    }
    double getBalance() const {
        return balance;
    }
};

//concrete subclass
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    //parameterized constructor with initializer list and base class constructor
    SavingsAccount(int accNum, double bal, double rate)
            : Account(accNum, bal), interestRate(rate) {}

    //overridden member functions
    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (balance >= amount)
            balance -= amount;
        else
            cout << "Insufficient funds!" <<endl;
    }

    void calculateInterest() const override {
        double interest = balance * interestRate / 100.0;
        cout << "Interest earned: " << interest << endl;
    }
};

//concrete subclass 2
class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    //parameterized constructor with initializer list and base class constructor
    CurrentAccount(int accNum, double bal, double limit)
            : Account(accNum, bal), overdraftLimit(limit) {}

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount)
            balance -= amount;
        else
            cout << "Transaction cannot be completed due to insufficient funds and exceeding overdraft limit!" << endl;
    }

    void calculateInterest() const override {
        cout << "No interest earned on current account." <<endl;
    }
};


int main() {
    //savings account
    SavingsAccount savings(12345, 1000, 5); // Account number, balance, interest rate
    cout << "Savings Account Details:" <<endl;
    cout << "Account Number: " << savings.getAccountNumber() <<endl;
    cout << "Initial Balance: " << savings.getBalance() << endl;
    savings.calculateInterest();
    savings.deposit(500);
    cout << "Balance after deposit: " << savings.getBalance() << endl;
    savings.withdraw(200);
    cout << "Balance after withdrawal: " << savings.getBalance() << endl;
    savings.calculateInterest();

    //current account
    CurrentAccount current(54321, 2000, 500); // Account number, balance, overdraft limit
    cout << "\nCurrent Account Details:" << endl;
    cout << "Account Number: " << current.getAccountNumber() << endl;
    cout << "Initial Balance: " << current.getBalance() << endl;
    current.calculateInterest();
    current.deposit(300);
    cout << "Balance after deposit: " << current.getBalance() << endl;
    current.withdraw(2500);
    cout << "Balance after withdrawal: " << current.getBalance() << endl;
    current.calculateInterest();

    return 0;
}


