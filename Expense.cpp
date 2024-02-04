#include "Expense.h"

Expense::Expense(std::string category, double amount, time_t timestamp)
    : category(category), amount(amount), timestamp(timestamp) {}

std::string Expense::getCategory() const {
    return category;
}

double Expense::getAmount() const {
    return amount;
}

time_t Expense::getTimestamp() const {
    return timestamp;
}
