#include <iostream>
#include <iomanip>
using namespace std;

const float DOLLAR_TO_EURO = 1.06;
const float DOLLAR_TO_PESO = 9.73;
const float DOLLAR_TO_YEN = 124.35;
// Function prototypes
void convertMulti(float dollars, float& euros, float& pesos);
void convertMulti(float dollars, float& euros, float& pesos, float& yen);
float convertToYen(float dollars);
float convertToEuros(float dollars);
float convertToPesos(float dollars);
int main()
{
 float dollars;
 float euros;
 float pesos;
 float yen;
 cout << fixed << showpoint << setprecision(2);
 cout << "Please input the amount of American Dollars you want converted to euros and pesos" << endl;
 cin >> dollars;
 convertMulti(dollars, euros, pesos);
 cout << "Dollars converted to euros: " << euros << endl;
 cout << "Dollars converted to pesos: " << pesos << endl;
 cout << "Please input the amount of American Dollars you want converted to euros, pesos, and yen" << endl;
 cin >> dollars;
 convertMulti(dollars, euros, pesos, yen);
 cout << "Dollars converted to euros: " << euros << endl;
 cout << "Dollars converted to pesos: " << pesos << endl;
 cout << "Dollars converted to yen: " << yen << endl;
 cout << "Please input the amount of American Dollars you want converted to yen"
<< endl;
 cin >> dollars;
 yen = convertToYen(dollars);
 cout << "Dollars converted to yen: " << yen << endl;
 cout << "Please input the amount of American Dollars you want converted to euros" << endl;
 cin >> dollars;
 euros = convertToEuros(dollars);
 cout << "Dollars converted to euros: " << euros << endl;
 cout << "Please input the amount of American Dollars you want converted to pesos" << endl;
 cin >> dollars;
 pesos = convertToPesos(dollars);
 cout << "Dollars converted to pesos: " << pesos << endl;
 return 0;
}
void convertMulti(float dollars, float& euros, float& pesos)
{
 euros = dollars * DOLLAR_TO_EURO;
 pesos = dollars * DOLLAR_TO_PESO;
}
void convertMulti(float dollars, float& euros, float& pesos, float& yen)
{
 convertMulti(dollars, euros, pesos);
 yen = dollars * DOLLAR_TO_YEN;
}
float convertToYen(float dollars)
{
 return dollars * DOLLAR_TO_YEN;
}
float convertToEuros(float dollars)
{
 return dollars * DOLLAR_TO_EURO;
}
float convertToPesos(float dollars)
{
 return dollars * DOLLAR_TO_PESO;
}
