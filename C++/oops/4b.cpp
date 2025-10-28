#include <iostream>
using namespace std;

class Account {
protected:
double balance;
public:
Account(double b) {
balance = b;
}
virtual void addInterest() {
balance += 0;
}
void showBalance() {
cout << "Balance: " << balance << endl;
}
};

class Savings : public Account {
public:
Savings(double b) : Account(b) {}
void addInterest() {
balance += balance * 0.05;
}
};

class Checking : public Account {
public:
Checking(double b) : Account(b) {}
void addInterest() {
balance += balance * 0.02;
}
};

int main() {
Account* a;
Savings s(1000);
Checking c(1000);
a = &s;
a->addInterest();
a->showBalance();
a = &c;
a->addInterest();
a->showBalance();
return 0;
}
