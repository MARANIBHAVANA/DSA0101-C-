
#include <iostream>
#include <cstring>
using namespace std;

class Text {
    char* data;

public:
    Text(const char* s = "") {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    Text(const Text& t) {
        data = new char[strlen(t.data) + 1];
        strcpy(data, t.data);
    }

    Text& operator=(const Text& t) {
        if (this != &t) {
            char* temp = new char[strlen(t.data) + 1];
            strcpy(temp, t.data);

            delete[] data;
            data = temp;
        }

        return *this;
    }

    Text operator+(const Text& t) const {
        size_t len = strlen(data) + strlen(t.data);
        char* temp = new char[len + 1];

        strcpy(temp, data);
        strcat(temp, t.data);

        Text result(temp);
        delete[] temp;

        return result;
    }

    Text& operator+=(const Text& t) {
        *this = *this + t;
        return *this;
    }

    bool operator==(const Text& t) const {
        return strcmp(data, t.data) == 0;
    }

    bool operator!=(const Text& t) const {
        return !(*this == t);
    }

    friend ostream& operator<<(ostream& out, const Text& t) {
        out << t.data;
        return out;
    }

    ~Text() {
        delete[] data;
    }
};

int main() {
    Text a("Hello");
    Text b(" World");
    Text c(" C++");

    Text result = a + b + c;

    cout << "Combined: " << result << endl;

    Text empty;
    cout << "Empty: [" << empty << "]" << endl;

    Text copy = result;
    cout << "Copy: " << copy << endl;

    cout << boolalpha;
    cout << "Equal: " << (result == copy) << endl;

    cout << "Not equal: " << (a != b) << endl;

    a = a;
    cout << "Self assignment: " << a << endl;

    return 0;
}
