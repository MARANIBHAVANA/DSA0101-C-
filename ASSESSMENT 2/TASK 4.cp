
#include <iostream>
using namespace std;

class SavingsAccount {
private:
    int accountNumber;
    double balance;
    double transactions[10];
    int count;

public:
    SavingsAccount(int acc, double initial)
        : accountNumber(acc), balance(initial), count(0) {}

    void deposit(double amount);
    void withdraw(double amount);
    void miniStatement() const;
};

void SavingsAccount::deposit(double amount) {
    if (amount <= 0) return;

    balance += amount;

    if (count < 10) {
        transactions[count++] = amount;
    } else {
        for (int i = 1; i < 10; i++)
            transactions[i - 1] = transactions[i];

        transactions[9] = amount;
    }
}

void SavingsAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance) return;

    balance -= amount;

    if (count < 10) {
        transactions[count++] = -amount;
    } else {
        for (int i = 1; i < 10; i++)
            transactions[i - 1] = transactions[i];

        transactions[9] = -amount;
    }
}

void SavingsAccount::miniStatement() const {
    cout << "Account: " << accountNumber << '\n';
    cout << "Balance: " << balance << '\n';
    cout << "Recent transactions:\n";

    for (int i = 0; i < count; i++)
        cout << transactions[i] << '\n';
}

int main() {
    SavingsAccount account(101, 1000);

    account.deposit(500);
    account.withdraw(200);
    account.deposit(300);

    account.miniStatement();

    return 0;
}
