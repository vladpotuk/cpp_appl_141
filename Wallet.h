#ifndef WALLET_H
#define WALLET_H

#include <string>

class Wallet {
private:
    std::string name;
    double balance;

public:
    Wallet(std::string name, double balance);
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
    std::string getName() const;
};

#endif 

