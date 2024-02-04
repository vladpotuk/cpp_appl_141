#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include <ctime>

class Expense {
private:
    std::string category;
    double amount;
    time_t timestamp;

public:
    Expense(std::string category, double amount, time_t timestamp);
    std::string getCategory() const;
    double getAmount() const;
    time_t getTimestamp() const;
};

#endif 

