
#include <iostream>
#include <string>
using namespace std;

struct Parcel {
    double weight;
    bool express;
    bool insured;
};

double charge(int grams) {
    return grams * 0.05;
}

double charge(double kg, bool express = false,
              bool insured = false) {
    double amount = kg * 50;

    if (express) amount += 30;
    if (insured) amount += 20;

    return amount;
}

double charge(float kg) {
    return charge(static_cast<double>(kg));
}

double charge(Parcel p) {
    return charge(p.weight, p.express, p.insured);
}

int main() {
    cout << charge(200) << '\n';
    cout << charge(2.0) << '\n';
    cout << charge(2.0f) << '\n';
    cout << charge(2.0, true) << '\n';
    cout << charge(2.0, false, true) << '\n';

    Parcel p = {3.0, true, true};
    cout << charge(p) << '\n';

    return 0;
}
