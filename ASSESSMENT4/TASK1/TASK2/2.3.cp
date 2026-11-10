#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int id;
    string phone;

    Person(string n = "", int i = 0, string p = "")
        : name(n), id(i), phone(p) {}
};

class Student : virtual public Person {
public:
    string programme;
    double cgpa;

    Student(string n = "", int i = 0, string p = "",
            string pr = "", double c = 0)
        : Person(n, i, p), programme(pr), cgpa(c) {}
};

class Staff : virtual public Person {
public:
    string department;
    double salary;

    Staff(string n = "", int i = 0, string p = "",
          string d = "", double s = 0)
        : Person(n, i, p), department(d), salary(s) {}
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string p)
        : Person(n, i, p),
          Student(n, i, p),
          Staff(n, i, p) {}
};

class ResearchScholar : public Student {
public:
    double fellowship;

    ResearchScholar(string n, int i, string p, double f)
        : Person(n, i, p),
          Student(n, i, p),
          fellowship(f) {}
};

int main() {
    TeachingAssistant t("Bhavana", 101, "9876543210");

    cout << t.name << endl;
    cout << t.id << endl;
}
