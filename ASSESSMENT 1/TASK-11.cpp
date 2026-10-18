
#include <iostream>
using namespace std;

const int FARES[] = {1000, 2000, 3000};
const long long MIN_BALANCE = 5000;

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long b) : balance(b) {}

    bool deduct(int fare) {
        if (fare >= 0 && balance - fare >= MIN_BALANCE) {
            balance -= fare;
            return true;
        }
        return false;
    }

    long long getBalance() {
        return balance;
    }
};

int main() {
    SmartCard card(10000);
    int zone = 1;

    if (zone >= 0 && zone < 3) {
        if (card.deduct(FARES[zone]))
            cout << "Travel allowed\n";
        else
            cout << "Travel denied\n";
    }

    cout << "Balance: Rs "
         << card.getBalance() / 100 << endl;

    return 0;
}
