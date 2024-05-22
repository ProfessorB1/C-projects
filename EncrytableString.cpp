#include <iostream>
#include <string>
using namespace std;
class EncryptableString : public string {
public:
 void encrypt() {
 for (char& c : *this) {
 if ((c >= 'a' && c <= 'z')) {
 c = (c == 'z') ? 'a' : c + 1;
 }
 else if ((c >= 'A' && c <= 'Z')) {
 c = (c == 'Z') ? 'A' : c + 1;
 }
 
 }
 }
};
int main() {
 string input;
 cout << "Enter a string: ";
 cin >> input;
 EncryptableString encryptableString = input;
 encryptableString.encrypt();
 cout << "Encrypted string: " << encryptableString << endl;
 return 0;
}
