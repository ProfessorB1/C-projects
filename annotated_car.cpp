#include <iostream>
using namespace std;

class Car {
private:
 int year;
 string make;
 int speed;
public:
 Car(int carYear, string carMake) {
 year = carYear;
 make = carMake;
 speed = 0;
 }
 int getYear() {
 return year;
 }
 string getMake() {
 return make;
 }
 int getSpeed() {
 return speed;
 }
 void accelerate() {
 speed += 5;
 }
 void brake() {
 speed -= 5;
 }
};
int main() {
 Car myCar(2023, "Toyota");
 for (int i = 0; i < 5; i++) {
 myCar.accelerate();
 cout << "Current speed: " << myCar.getSpeed() << " mph" << endl;
 }
 for (int i = 0; i < 5; i++) {
 myCar.brake();
 cout << "Current speed: " << myCar.getSpeed() << " mph" << endl;
 }
 return 0;
}
