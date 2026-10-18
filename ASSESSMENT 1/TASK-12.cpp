
#include <iostream>
using namespace std;

enum Zone { Inner, Middle, Outer, Airport };

const int FARES[] = {1000, 2000, 3000, 6000};

class MonthlyPass {
    int zone1, zone2;

public:
    MonthlyPass(int a, int b) : zone1(a), zone2(b) {}

    bool covers(int zone) {
        return zone == zone1 || zone == zone2;
    }
};

int fare(int zone, bool peak, bool weekend) {
    if (zone < 0 || zone > 3)
        return -1;

    int f = FARES[zone];

    if (weekend)
        f = f * 90 / 100;
    else if (peak)
        f = f * 120 / 100;

    return f;
}

int main() {
    MonthlyPass pass(Inner, Airport);

    int zone = Airport;
    bool peak = true;
    bool weekend = true;

    if (pass.covers(zone)) {
        cout << "Monthly pass: Free journey\n";
    } else {
        int f = fare(zone, peak, weekend);

        if (f == -1)
            cout << "Invalid zone\n";
        else
            cout << "Fare: Rs " << f / 100 << "."
                 << (f % 100 < 10 ? "0" : "")
                 << f % 100 << '\n';
    }

    cout << "Weekend discount and peak surcharge "
         << "are never combined.\n";

    return 0;
}
