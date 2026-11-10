#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n) : name(n) {
        cout << "Person ";
    }

    virtual ~Person() {
        cout << "~Person ";
    }
};

class Student : virtual public Person {
public:
    Student(string n) : Person(n) {
        cout << "Student ";
    }

    ~Student() {
        cout << "~Student ";
    }
};

class Staff : virtual public Person {
public:
    Staff(string n) : Person(n) {
        cout << "Staff ";
    }

    ~Staff() {
        cout << "~Staff ";
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n)
        : Person(n), Student(n), Staff(n) {
        cout << "TA ";
    }

    ~TeachingAssistant() {
        cout << "~TA ";
    }
};

int main() {
    TeachingAssistant t("Kavi");
    cout << endl;
}
