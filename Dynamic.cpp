// Austin Farias
#include <iostream>
using namespace std;
const int MAXNAME = 10;
int main()
{
int pos;
char* name = nullptr;
int* one = nullptr;
int* two = nullptr;
int* three = nullptr;
int result;
one = new int;
two = new int;
three = new int;
name = new char[MAXNAME];
cout << "Enter your last name with exactly 10 characters." << endl;
cout << "If your name has < 10 characters, repeat last letter. " << endl
<< "Blanks at the end do not count." << endl;
for (pos = 0; pos < MAXNAME; pos++)
cin >> *(name + pos); 
cout << "Hi ";
for (pos = 0; pos < MAXNAME; pos++)
cout << *(name + pos); 
cout << endl << "Enter three integer numbers separated by blanks" << endl;
cin >> *one >> *two >> *three;
cout << "The three numbers are " << *one << ", " << *two << ", " << *three <<
endl;
result = *one + *two + *three;
cout << "The sum of the three values is " << result << endl;
delete one;
delete two;
delete three;
delete[] name;
return 0;
}