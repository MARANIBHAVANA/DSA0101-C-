#include <iostream>
using namespace std;
class Cart {
double totalAmount;
public:

Cart(double total = 0) : totalAmount(total) {}
Cart& add(double amount) {
this->totalAmount += amount;
return *this;
}
double total() const {
return totalAmount;
}
};
int main() {
// (a) Direct object
Cart c(100);
cout << c.total() << endl;
// (b) Pointer using ->
Cart* p = &c;
cout << p->total() << endl;
// (c) Reference
Cart& r = c;
cout << r.total() << endl;
// (d) Dynamic object
Cart* d = new Cart(200);
cout << d->total() << endl;
delete d;
// Chaining using this
c.add(50).add(25);
cout << c.total() << endl;
}
