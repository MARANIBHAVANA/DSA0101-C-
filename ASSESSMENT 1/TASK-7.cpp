
#include <iostream>
using namespace std;

const int MIN_BALANCE = 5000;

bool canTravel(long long balance, long long fare) {
    return balance - fare >= MIN_BALANCE;
}

int main() {
    long long balance = 10000;
    long long fare = 2000;

    if (canTravel(balance, fare)) {
        balance -= fare;
        cout << "Travel allowed\n";
    } else {
        cout << "Travel denied\n";
    }

    cout << "Balance: Rs " << balance / 100 << endl;
    return 0;
}
