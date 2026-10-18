
#include <iostream>
using namespace std;

enum Zone { Inner, Middle, Outer };

int fare(Zone z, int hour) {
    int base;

    switch (z) {
        case Inner:  base = 1000; break;
        case Middle: base = 2000; break;
        case Outer:  base = 3000; break;
        default: return -1;
    }

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    if (peak)
        base += base * 20 / 100;

    return base;
}

int main() {
    int zones[] = {Inner, Middle, Outer, Inner, Outer};
    int hours[] = {7, 8, 10, 17, 20};

    int total = 0;

    for (int i = 0; i < 5; i++) {
        int f = fare((Zone)zones[i], hours[i]);

        if (f == -1)
            cout << "Invalid zone\n";
        else {
            cout << "Fare: Rs " << f / 100 << "."
                 << (f % 100 < 10 ? "0" : "") << f % 100 << '\n';
            total += f;
        }
    }

    cout << "Total: Rs " << total / 100 << "."
         << (total % 100 < 10 ? "0" : "") << total % 100 << '\n';

    return 0;
}
