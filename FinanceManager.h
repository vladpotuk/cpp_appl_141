#ifndef FINANCE_MANAGER_H
#define FINANCE_MANAGER_H

#include "Wallet.h"
#include "Expense.h"
#include <vector>
#include <map>
#include <string>

class FinanceManager {
private:
    std::vector<Wallet> wallets;
    std::vector<Expense> expenses;

public:
    void addWallet(Wallet wallet);
    void addExpense(Expense expense);
    double calculateWeeklyExpense() const;
    double calculateMonthlyExpense() const;
    std::map<std::string, double> getTop3WeeklyCategories() const;
    std::map<std::string, double> getTop3MonthlyCategories() const;
    void saveReportsToFile(std::string filename) const;
};

#endif 

