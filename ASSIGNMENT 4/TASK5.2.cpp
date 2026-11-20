#include <iostream>
using namespace std;
class Cart {
double amount;
public:
Cart(double a) : amount(a) {}
double total() const {
return amount;
}
};
int main() {
Cart a(100), b(250), c(180);

Cart* carts[] = {&a, &b, &c};
Cart* highest = carts[0];
for (int i = 1; i < 3; i++) {
if (carts[i]->total() > highest->total())
highest = carts[i];
}
cout << "Highest total: " << highest->total() << endl;
}
