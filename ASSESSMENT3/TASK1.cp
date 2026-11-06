
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book {
private:
    string title;
    int copies;

public:
    Book() : Book("", 0) {}

    explicit Book(string t) : Book(t, 0) {}

    Book(string t, int c) : title(t), copies(c) {
        if (c < 0) {
            throw invalid_argument("Copies cannot be negative");
        }
    }

    void display() const {
        cout << "Title: " << title
             << ", Copies: " << copies << endl;
    }
};

int main() {
    try {
        Book b1;
        Book b2("C++ Programming");
        Book b3("Data Structures", 10);

        b1.display();
        b2.display();
        b3.display();

        Book b4("Invalid Book", -5);
        b4.display();
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
