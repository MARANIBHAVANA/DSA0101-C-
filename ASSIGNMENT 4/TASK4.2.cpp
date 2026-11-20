class Account {
public:
virtual ~Account() {
cout << "Account destructor\n";
}
};
class SeniorAccount : public Account {
double* history = new double[100];

public:
~SeniorAccount() override {
delete[] history;
cout << "SeniorAccount destructor\n";
}
};
