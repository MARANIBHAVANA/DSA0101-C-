
#include <iostream>
using namespace std;

class SmartCard {
    double balance;

public:
    SmartCard(double b) : balance(b) {}

    void journey(int zone, bool peak, bool weekend, bool concession) {
        if (zone < 1 || zone > 3) {
            cout << "Invalid zone\n";
            return;
        }

        double fare = zone * 10;

        if (peak) fare *= 1.20;
        if (weekend) fare *= 0.80;
        if (concession) fare *= 0.90;

        if (balance - fare < 50)
            cout << "Insufficient balance\n";
        else {
            balance -= fare;
            cout << "Fare: Rs. " << fare << '\n';
            cout << "Balance: Rs. " << balance << '\n';
        }
    }
};

int main() {
    double balance;
    int zone, peak, weekend, concession;

    cout << "Enter balance: ";
    cin >> balance;

    cout << "Zone (1=Inner, 2=Middle, 3=Outer): ";
    cin >> zone;

    cout << "Peak hour (1/0): ";
    cin >> peak;

    cout << "Weekend (1/0): ";
    cin >> weekend;

    cout << "Student/Senior (1/0): ";
    cin >> concession;

    if (balance < 0) {
        cout << "Invalid balance\n";
        return 0;
    }

    SmartCard card(balance);
    card.journey(zone, peak, weekend, concession);

    return 0;
}
