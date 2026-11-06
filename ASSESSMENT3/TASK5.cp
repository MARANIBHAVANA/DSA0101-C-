
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Time {
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) {
        seconds = h * 3600 + m * 60 + s;
    }

    Time& operator++() {
        ++seconds;
        return *this;
    }

    Time operator++(int) {
        Time old = *this;
        ++seconds;
        return old;
    }

    bool operator==(const Time& t) const {
        return seconds == t.seconds;
    }

    bool operator<(const Time& t) const {
        return seconds < t.seconds;
    }

    void display() const {
        int h = seconds / 3600;
        int m = (seconds % 3600) / 60;
        int s = seconds % 60;

        cout << h << ":"
             << m << ":"
             << s << endl;
    }
};

class Playlist {
    vector<string> tracks;

public:
    Playlist(vector<string> t) : tracks(t) {}

    string& operator[](int i) {
        if (i < 0 || i >= (int)tracks.size())
            throw out_of_range("Invalid playlist index");

        return tracks[i];
    }

    const string& operator[](int i) const {
        if (i < 0 || i >= (int)tracks.size())
            throw out_of_range("Invalid playlist index");

        return tracks[i];
    }
};

int main() {
    Time t(0, 0, 5);

    Time a = t++;
    Time b = ++t;

    cout << "a = ";
    a.display();

    cout << "b = ";
    b.display();

    cout << "t = ";
    t.display();

    cout << boolalpha;
    cout << "a < b: " << (a < b) << endl;
    cout << "a == b: " << (a == b) << endl;

    Playlist p({"Song A", "Song B", "Song C"});

    cout << "Track 0: " << p[0] << endl;
    cout << "Track 1: " << p[1] << endl;

    try {
        cout << p[3] << endl;
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    Time rollover(0, 59, 59);
    ++rollover;

    cout << "After rollover: ";
    rollover.display();

    return 0;
}
