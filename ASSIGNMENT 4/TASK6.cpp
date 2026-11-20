#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Vehicle {
protected:
string regNo;
double dailyRate;
bool rented;
public:
Vehicle(string r, double rate)
: regNo(r), dailyRate(rate), rented(false) {}
virtual double charge(int days) const = 0;
virtual void display() const {

cout << regNo << " Rate: " << dailyRate;
}
bool rent() {
if (rented)
return false;
rented = true;
return true;
}
double returnVehicle(int days, int lateDays) {
if (!rented)
return 0;
rented = false;
return charge(days) + lateDays * dailyRate;
}
virtual ~Vehicle() = default;
};
class Bicycle : public Vehicle {
public:
Bicycle(string r, double rate)
: Vehicle(r, rate) {}
double charge(int days) const override {
return days * dailyRate;
}
void display() const override {
cout << "Bicycle ";
Vehicle::display();
cout << endl;
}
};
class TwoWheeler : public Vehicle {
protected:

double fuelLevel;
string serviceDate;
public:
TwoWheeler(string r, double rate, double fuel, string date)
: Vehicle(r, rate), fuelLevel(fuel), serviceDate(date) {}
double charge(int days) const override {
return days * dailyRate;
}
void display() const override {
cout << "TwoWheeler ";
Vehicle::display();
cout << " Fuel: " << fuelLevel
<< " Service: " << serviceDate << endl;
}
};
class Car : public Vehicle {
protected:
double fuelLevel;
string serviceDate;
int seats;
public:
Car(string r, double rate, double fuel,
string date, int s)
: Vehicle(r, rate), fuelLevel(fuel),
serviceDate(date), seats(s) {}
double charge(int days) const override {
return days * dailyRate;
}
void display() const override {
cout << "Car ";
Vehicle::display();
cout << " Seats: " << seats << endl;
}

};
class ElectricCar : public Car {
double batteryCapacity;
double chargeLevel;
double ratePerKWh;
public:
ElectricCar(string r, double rate, double fuel,
string date, int seats,
double battery, double level, double kwhRate)
: Car(r, rate, fuel, date, seats),
batteryCapacity(battery),
chargeLevel(level), ratePerKWh(kwhRate) {}
double charge(int days) const override {
return days * dailyRate +
batteryCapacity * ratePerKWh;
}
void display() const override {
cout << "ElectricCar ";
Vehicle::display();
cout << " Battery: " << batteryCapacity
<< " kWh Charge: " << chargeLevel << endl;
}
};
// New type added without changing existing classes
class ElectricBus : public Vehicle {
double batteryCapacity;
double ratePerKWh;
public:
ElectricBus(string r, double rate,
double battery, double kwhRate)
: Vehicle(r, rate),
batteryCapacity(battery), ratePerKWh(kwhRate) {}
double charge(int days) const override {

return days * dailyRate +
batteryCapacity * ratePerKWh;
}
void display() const override {
cout << "ElectricBus ";
Vehicle::display();
cout << " Battery: " << batteryCapacity << " kWh" << endl;
}
};
int main() {
vector<Vehicle*> fleet;
fleet.push_back(new Bicycle("B101", 100));
fleet.push_back(new TwoWheeler("T101", 200, 5, "2026-12-01"));
fleet.push_back(new Car("C101", 1000, 20, "2026-12-05", 5));
fleet.push_back(new ElectricCar(
"E101", 1500, 0, "2026-12-10", 5, 60, 80, 5
));
// Demonstrate renting each vehicle
for (Vehicle* v : fleet) {
if (v->rent())
cout << "Rented successfully" << endl;
}
// Return vehicles; the first has a late charge
cout << "Bicycle return: "
<< fleet[0]->returnVehicle(2, 1) << endl;
cout << "TwoWheeler return: "
<< fleet[1]->returnVehicle(2, 0) << endl;
cout << "Car return: "
<< fleet[2]->returnVehicle(2, 0) << endl;
cout << "ElectricCar return: "
<< fleet[3]->returnVehicle(2, 0) << endl;

// Add a new vehicle type
fleet.push_back(new ElectricBus("EB101", 3000, 200, 4));
cout << "New vehicle added:" << endl;
fleet[4]->display();
for (Vehicle* v : fleet)
delete v;
fleet.clear();
}
