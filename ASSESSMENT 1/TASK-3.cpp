
#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int main() {
    bool peakHour = true;
    char zoneCode = 'M';
    unsigned int zoneNumber = 2;
    int farePaise = 2000;
    long long balancePaise = 100000;
    double rupees = 0.1;
    auto journeys = 3000000LL;

    constexpr int SURCHARGE = 20;

    long long fare = farePaise +
        (1LL * farePaise * SURCHARGE / 100);

    long long collection = journeys * 3000LL;

    cout << "Data Type Sizes:\n";
    cout << "bool: " << sizeof(bool) << " bytes\n";
    cout << "char: " << sizeof(char) << " bytes\n";
    cout << "int: " << sizeof(int) << " bytes\n";
    cout << "unsigned int: " << sizeof(unsigned int) << " bytes\n";
    cout << "long long: " << sizeof(long long) << " bytes\n";
    cout << "float: " << sizeof(float) << " bytes\n";
    cout << "double: " << sizeof(double) << " bytes\n";

    cout << "\nInt range: " << INT_MIN
         << " to " << INT_MAX << endl;

    cout << boolalpha;
    cout << "Peak hour: " << peakHour << endl;
    cout << "Zone code: " << zoneCode << endl;
    cout << "Zone number: " << zoneNumber << endl;

    cout << fixed << setprecision(2);
    cout << "Fare with surcharge: Rs. "
         << fare / 100.0 << endl;
    cout << "Daily collection: Rs. "
         << collection / 100.0 << endl;

    cout << setprecision(17);
    cout << "0.1 + 0.2 using double: "
         << 0.1 + 0.2 << endl;

    cout << "Exact sum in paise: "
         << 10 + 20 << " paise" << endl;

    int count = 2;
    bool discount = true;
    double result = count + 0.5 + discount;

    cout << setprecision(2);
    cout << "Mixed type result: " << result << endl;

    return 0;
}
