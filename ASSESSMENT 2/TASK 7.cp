
#include <iostream>
using namespace std;

class TransactionLog {
    static const int SIZE = 10;
    double data[SIZE];
    int start;
    int count;

public:
    TransactionLog() : start(0), count(0) {}

    void add(double amount) {
        if (count < SIZE) {
            data[(start + count) % SIZE] = amount;
            count++;
        } else {
            data[start] = amount;
            start = (start + 1) % SIZE;
        }
    }

    void display() const {
        cout << "Last transactions:\n";

        for (int i = 0; i < count; i++)
            cout << data[(start + i) % SIZE] << '\n';
    }
};

int main() {
    TransactionLog log;

    for (int i = 1; i <= 12; i++)
        log.add(i * 100);

    log.display();

    return 0;
}
