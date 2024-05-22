#include <iostream>
#include <string>
#define PROJECT_NAME "Salary_Project";
using namespace std;

int main(){
    int hours;
    float hourly_rate;
    float gross_pay;
    int company_name;
    string name;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter the company's name: ";
    cin >> company_name;
    cout << "Enter your hourly rate: $";
    cin >> hours;
    cout << "Enter the hours you worked in a week: $";
    cin >> hourly_rate;
    cout << "Your gross pay is $";
    gross_pay = hourly_rate * hours;
    cin >> gross_pay;
    return 0;
}