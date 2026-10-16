
#include <iostream>
using namespace std;

// Constants
constexpr int INNER_FARE = 1000;   // Rs. 10 in paise
constexpr int MIDDLE_FARE = 2000;  // Rs. 20 in paise
constexpr int OUTER_FARE = 3000;   // Rs. 30 in paise
constexpr int MIN_BALANCE = 5000;  // Rs. 50 in paise
constexpr int SURCHARGE_PERCENT = 20;

enum class Zone {
    Inner,
    Middle,
    Outer
};

int getFare(Zone zone) {
    switch (zone) {
        case Zone::Inner:
            return INNER_FARE;
        case Zone::Middle:
            return MIDDLE_FARE;
        case Zone::Outer:
            return OUTER_FARE;
    }
    return 0;
}

int main() {
    Zone zone = Zone::Middle;
    int balance = 10000;  // Rs. 100 in paise
    int fare = getFare(zone);
    bool peakHour = true;

    if (peakHour) {
        fare = fare + (fare * SURCHARGE_PERCENT / 100);
    }

    if (balance - fare >= MIN_BALANCE) {
        balance = balance - fare;
        cout << "Fare: Rs. " << fare / 100.0 << endl;
        cout << "Remaining balance: Rs. "
             << balance / 100.0 << endl;
        cout << "Journey allowed" << endl;
    } else {
        cout << "Insufficient balance" << endl;
    }

    return 0;
}
