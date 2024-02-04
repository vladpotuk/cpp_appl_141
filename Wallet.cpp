#include "Wallet.h"

Wallet::Wallet(std::string name, double balance) : name(name), balance(balance) {}

void Wallet::deposit(double amount) {
    balance += amount;
}

bool Wallet::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

double Wallet::getBalance() const {
    return balance;
}

std::string Wallet::getName() const {
    return name;
}
