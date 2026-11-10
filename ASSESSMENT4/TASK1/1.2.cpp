#include <iostream>
#include <string>
using namespace std;

class Staff {
protected:
    string name;
    int id;

public:
    Staff(string n, int i) : name(n), id(i) {}

    virtual double pay() const = 0;
    virtual void display() const {
        cout << name << " " << id << " ";
    }

    virtual ~Staff() = default;
};

class Professor : public Staff {
    double basic, research;

public:
    Professor(string n, int i, double b, double r)
        : Staff(n, i), basic(b), research(r) {}

    double pay() const override {
        return basic + basic * 0.42 + research;
    }
};

class LabAssistant : public Staff {
    double basic;

public:
    LabAssistant(string n, int i, double b)
        : Staff(n, i), basic(b) {}

    double pay() const override {
        return basic + basic * 0.42;
    }
};

class GuestFaculty : public Staff {
    double hours, rate;

public:
    GuestFaculty(string n, int i, double h, double r)
        : Staff(n, i), hours(h), rate(r) {}

    double pay() const override {
        return hours * rate;
    }
};

int main() {
    Professor p("Arun", 101, 50000, 5000);
    LabAssistant l("Kavi", 102, 30000);
    GuestFaculty g("Ravi", 103, 20, 1000);

    Staff* s[] = {&p, &l, &g};

    for (Staff* x : s)
        cout << x->pay() << endl;
}
