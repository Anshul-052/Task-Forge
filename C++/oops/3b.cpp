#include <iostream>
using namespace std;

class Account {
int balance;
public:
Account(int b) {
balance = b;
}
void deposit(int amount) {
balance += amount;
}
void withdraw(int amount) {
if (amount <= balance)
balance -= amount;
else
cout << "Not enough balance" << endl;
}
int getBalance() {
return balance;
}
};

class Customer {
string name;
Account account;
public:
Customer(string n, int b) : account(b) {
name = n;
}
void depositMoney(int amount) {
account.deposit(amount);
}
void withdrawMoney(int amount) {
account.withdraw(amount);
}
void showBalance() {
cout << name << " Balance: " << account.getBalance() << endl;
}
};

int main() {
Customer c1("John", 1000);
c1.depositMoney(500);
c1.withdrawMoney(300);
c1.showBalance();
return 0;
}
