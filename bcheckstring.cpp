#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Custom exception class for out-of-bounds exception
class BoundsException : public exception {
public:
    const char* what() const noexcept override {
        return "Out of bounds exception";
    }
};

// Derived class BCheckString from string to perform bounds checking
class BCheckString : public string {
public:
    BCheckString(const string& s) : string(s) {}

    // Override the operator[] to check for out-of-bounds access
    char operator[](int k) {
        if (k < 0 || k >= static_cast<int>(size())) {
            throw BoundsException();
        }
        return string::operator[](k);
    }
};

int main() {
    // Create an object of BCheckString
    BCheckString bString("Hello, World!");

    try {
        // Access character at position 0
        char ch1 = bString[0];
        cout << "Character at position 0: " << ch1 << endl;

        // Access character at position 13 (out of bounds)
        char ch2 = bString[13];
        cout << "Character at position 13: " << ch2 << endl;
    } catch (const BoundsException& ex) {
        // Catch and handle the out-of-bounds exception
        cout << "Exception caught: " << ex.what() << endl;
    }

    return 0;
}
