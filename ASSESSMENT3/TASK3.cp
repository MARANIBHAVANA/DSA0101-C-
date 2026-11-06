
#include <iostream>
using namespace std;

class Event {
    int rows, seats;
    char** seatMap;
    int booked;

public:
    Event(int r, int s)
        : rows(r), seats(s), seatMap(nullptr), booked(0) {

        cout << "Event created" << endl;

        if (rows > 0 && seats > 0) {
            seatMap = new char*[rows];

            for (int i = 0; i < rows; i++) {
                seatMap[i] = new char[seats];

                for (int j = 0; j < seats; j++)
                    seatMap[i][j] = 'O';
            }
        }
    }

    void book(int r, int s) {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seats &&
            seatMap[r][s] == 'O') {

            seatMap[r][s] = 'X';
            booked++;
            cout << "Seat booked" << endl;
        } else {
            cout << "Booking failed" << endl;
        }
    }

    void cancel(int r, int s) {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seats &&
            seatMap[r][s] == 'X') {

            seatMap[r][s] = 'O';
            booked--;
            cout << "Booking cancelled" << endl;
        }
    }

    ~Event() {
        if (seatMap != nullptr) {
            for (int i = 0; i < rows; i++)
                delete[] seatMap[i];

            delete[] seatMap;
        }

        cout << "Event closed. Booked seats: "
             << booked << endl;
    }
};

int main() {
    cout << "Stack object:" << endl;
    Event e1(2, 3);
    e1.book(0, 1);
    e1.book(1, 2);

    cout << "\nHeap object:" << endl;
    Event* e2 = new Event(3, 4);
    e2->book(0, 0);
    delete e2;

    cout << "\nBlock object:" << endl;
    {
        Event e3(2, 2);
        e3.book(1, 1);
    }

    cout << "\nZero row event:" << endl;
    Event e4(0, 5);

    return 0;
}
