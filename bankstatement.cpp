 #include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
private:
    string name;
public:
    Person(string name) : name(name) {}

    string getName() {
        return name;
    }
};

class Account {
protected:
    Person holder;
    int idNumber;
    double balance;
public:
    Account(Person holder, int idNumber, double balance) : holder(holder), idNumber(idNumber), balance(balance) {}

    virtual double withdraw(double amount) {
        balance -= amount;
        return amount;
    }

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void interest() = 0;
};

class SavingsAcc : public Account {
public:
    SavingsAcc(Person holder, int idNumber, double balance) : Account(holder, idNumber, balance) {}

    double withdraw(double amount) override {
        if (amount < 1000) {
            balance -= amount + 50;
            return amount + 50;
        }
        else {
            balance -= amount;
            return amount;
        }
    }

    void deposit(double amount) override {
        balance += amount;
    }

    void interest() override {
        balance *= 1.0105;
    }
};

class CheckingAcc : public Account {
public:
    CheckingAcc(Person holder, int idNumber, double balance) : Account(holder, idNumber, balance) {}

    double withdraw(double amount) override {
        balance -= amount;
        return amount;
    }

    void deposit(double amount) override {
        balance += amount;
    }

    void interest() override {
        balance *= 1.0002;
    }
};

class CdAcc : public Account {
private:
    int monthsActive;
public:
    CdAcc(Person holder, int idNumber, double balance) : Account(holder, idNumber, balance), monthsActive(0) {}

    double withdraw(double amount) override {
        balance -= amount;
        return amount;
    }

    void deposit(double amount) override {
        balance += amount;
    }

    void interest() override {
        monthsActive++;
        balance *= (1 + 0.01 * monthsActive);
    }
};

class MmdaAcc : public Account {
public:
    MmdaAcc(Person holder, int idNumber, double balance) : Account(holder, idNumber, balance) {}

    double withdraw(double amount) override {
        if (amount < 10000) {
            balance -= amount + 200;
            return amount + 200;
        }
        else {
            balance -= amount;
            return amount;
        }
    }

    void deposit(double amount) override {
        balance += amount;
    }

    void interest() override {
        balance *= 1.0125;
    }
};

int main() {
    vector <Account*> accounts;
    vector <Person*> customers;

    // Create some customers
    Person* person1 = new Person("John Doe");
    Person* person2 = new Person("Jane Smith");

    // Create some accounts
    Account* account1 = new SavingsAcc(*person1, 1, 1000);
    Account* account2 = new CheckingAcc(*person1, 2, 500);
    Account* account3 = new CdAcc(*person2, 3, 2000);
    Account* account4 = new MmdaAcc(*person2, 4, 10000);

    // Add accounts to vector
    accounts.push_back(account1);
    accounts.push_back(account2);
    accounts.push_back(account3);
    accounts.push_back(account4);

    // Add customers to vector
    customers.push_back(person1);
    customers.push_back(person2);

    // Perform some operations on the accounts
    for (Account* account : accounts) {
        account->deposit(100);
        account->withdraw(200);
        account->interest();

        cout << "Account holder: " << account -> holder.getName() << endl;
        cout << "Account balance: " << account -> balance << endl;
        cout << endl;
    }

    // Clean up memory
    for (Account* account : accounts) {

        fclose (account);
    }

    for (Person* person : customers) {
        fclose (person);
    }

    return 0;
}