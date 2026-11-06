
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>
using namespace std;

class Complex {
    double real, imag;

public:
    Complex() : real(0), imag(0) {}

    Complex(double r) : real(r), imag(0) {}

    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) const {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    Complex operator/(const Complex& c) const {
        double denominator =
            c.real * c.real + c.imag * c.imag;

        if (denominator == 0)
            throw domain_error("Division by zero impedance");

        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }

    bool operator==(const Complex& c) const {
        return fabs(real - c.real) < 1e-9 &&
               fabs(imag - c.imag) < 1e-9;
    }

    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;

        if (c.imag >= 0)
            out << " + j" << c.imag;
        else
            out << " - j" << fabs(c.imag);

        return out;
    }
};

int main() {
    try {
        const double pi = acos(-1.0);
        const double frequency = 50.0;
        const double omega = 2 * pi * frequency;

        double R = 10.0;
        double L = 0.1;
        double C = 100e-6;

        Complex Zr(R, 0);
        Complex Zl(0, omega * L);
        Complex Zc(0, -1.0 / (omega * C));

        Complex series = Zr + Zl + Zc;

        Complex one(1, 0);

        Complex parallel = one /
            (one / Zr + one / Zl + one / Zc);

        cout << fixed << setprecision(2);

        cout << "Resistor: " << Zr << endl;
        cout << "Inductor: " << Zl << endl;
        cout << "Capacitor: " << Zc << endl;

        cout << "Series impedance: " << series << endl;
        cout << "Series magnitude: "
             << series.magnitude() << endl;

        cout << "Parallel impedance: " << parallel << endl;
        cout << "Parallel magnitude: "
             << parallel.magnitude() << endl;

        Complex a(5, 3);
        Complex b(2, 1);

        cout << "Addition: " << a + b << endl;
        cout << "Subtraction: " << a - b << endl;
        cout << "Multiplication: " << a * b << endl;
        cout << "Division: " << a / b << endl;

        cout << boolalpha;
        cout << "Equality: " << (a == b) << endl;

        Complex zero(0, 0);
        Complex test = a / zero;

        cout << test << endl;
    }
    catch (const domain_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
