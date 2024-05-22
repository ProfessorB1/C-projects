//Austin Farias
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;
int main() {
 ifstream inFile("thuxley.txt");
 if (!inFile) {
 cout << "Error opening file." << endl;
 return 1;
 }
 int letterCounts[128] = { 0 }; 
 char ch;
 while (inFile.get(ch)) {
 if (isalpha(ch)) {
 letterCounts[tolower(ch)]++;
 }
 }
 cout << "Letter\tFrequency" << endl;
 for (int i = 'a'; i <= 'z'; i++) {
 cout << static_cast<char>(i) << "\t" << letterCounts[i] << endl;
 }
 inFile.close();
 return 0;
}