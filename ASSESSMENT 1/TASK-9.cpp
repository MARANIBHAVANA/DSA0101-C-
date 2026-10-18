
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int main() {
    double fare;

    while (true) {
        cout << "Enter fare: ";

        if (cin >> fare && fare >= 0)
            break;

        cout << "Invalid input. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << fixed << setprecision(2);
    cout << "Fare: Rs " << fare << endl;
    return 0;
}
