#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
private:
    string name;

public:
    Person(string name) : name(name) {}

    string getName () {
        return name;
    }
};

class Account{
protected:
    Person holder;
    int idNumber;
    float balance;

public:
    Account (Person holder, int idNumber, float balance) : holder(holder), idNumber(idNumber), balance(balance) {}

    
};
