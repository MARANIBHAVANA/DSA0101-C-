
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int counts[] = {20000, 500000, 3000000};

    for (int n : counts) {
        double totalRs = 0;
        long long totalPaise = 0;

        for (int i = 0; i < n; i++) {
            totalRs += 10.01;
            totalPaise += 1001;
        }

        cout << "Journeys: " << n << '\n';
        cout << fixed << setprecision(2);
        cout << "Double total: Rs " << totalRs << '\n';
        cout << "Integer total: Rs "
             << totalPaise / 100 << "."
             << setw(2) << setfill('0') << totalPaise % 100
             << setfill(' ') << '\n';
        cout << "Difference: Rs "
             << totalRs - totalPaise / 100.0 << "\n\n";
    }

    return 0;
}
