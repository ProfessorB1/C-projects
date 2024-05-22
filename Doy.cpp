//Austin Farias
#include <iostream>
#include <string>
using namespace std;
class DayOfYear {
private:
 int day;
 static const int daysPerMonth[];
 static const string monthNames[];
public:
 DayOfYear(int day) : day(day) {}
 void print() const {
 int month = 0;
 while (day > daysPerMonth[month]) 
 { 
 day -= daysPerMonth[month];
 month++;
 }
 cout << monthNames[month] << " " << day << endl;
 }
 DayOfYear(const string& month, int dayOfMonth) 
 {
 int monthIndex = 0;
 while (monthIndex < 12 && monthNames[monthIndex] != month)
 {
 monthIndex++;
 }
 if (monthIndex == 12) {
 cerr << "Invalid month: " << month << endl;
 exit(1);
 }
 if (dayOfMonth < 1 || dayOfMonth > daysPerMonth[monthIndex]) 
 {
 cerr << "Invalid day of month: " << dayOfMonth << endl;
 exit(1);
 }
 day = dayOfMonth;
 for (int i = 0; i < monthIndex; i++) {
 day += daysPerMonth[i];
 }
 }
 DayOfYear& operator++() 
 {
 if (day == 365) {
 day = 1;
 }
 else {
 day++;
 }
 return *this;
 }
 DayOfYear operator++(int) 
 {
 DayOfYear temp = *this;
 ++(*this);
 return temp;
 }
 DayOfYear& operator--() 
 {
 if (day == 1) {
 day = 365;
 }
 else {
 day--;
 }
 return *this;
 }
 DayOfYear operator--(int) 
 {
 DayOfYear temp = *this;
 --(*this);
 return temp;
 }
};
const int DayOfYear::daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,
31 };
const string DayOfYear::monthNames[] = 
{
 "January", "February", "March", "April", "May", "June", "July",
 "August", "September", "October", "November", "December"
};
int main() {
 DayOfYear day1(2);
 day1.print(); 
 DayOfYear day2(32);
 day2.print(); 
 DayOfYear day3(365);
 day3.print(); 
 DayOfYear day4("March", 15);
 day4.print(); 
 DayOfYear day5("April", 31); 
 ++day1;
 day1.print(); 
 --day2;
 day2.print(); 
 return 0;
}