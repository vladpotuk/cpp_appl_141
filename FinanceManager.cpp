#include "FinanceManager.h"
#include <algorithm>
#include <fstream>
#include <iostream>

void FinanceManager::addWallet(Wallet wallet) {
    wallets.push_back(wallet);
}

void FinanceManager::addExpense(Expense expense) {
    expenses.push_back(expense);
}

double FinanceManager::calculateWeeklyExpense() const {
    double totalWeeklyExpense = 0.0;
    time_t currentTime = time(nullptr);
    time_t oneWeekAgo = currentTime - (7 * 24 * 3600); 

    for (const auto& expense : expenses) {
        if (expense.getTimestamp() >= oneWeekAgo) {
            totalWeeklyExpense += expense.getAmount();
        }
    }

    return totalWeeklyExpense;
}

double FinanceManager::calculateMonthlyExpense() const {
    double totalMonthlyExpense = 0.0;
    time_t currentTime = time(nullptr);
    time_t oneMonthAgo = currentTime - (30 * 24 * 3600); 

    for (const auto& expense : expenses) {
        if (expense.getTimestamp() >= oneMonthAgo) {
            totalMonthlyExpense += expense.getAmount();
        }
    }

    return totalMonthlyExpense;
}

std::map<std::string, double> FinanceManager::getTop3WeeklyCategories() const {
    std::map<std::string, double> weeklyCategoryExpenses;
    time_t currentTime = time(nullptr);
    time_t oneWeekAgo = currentTime - (7 * 24 * 3600); 

    for (const auto& expense : expenses) {
        if (expense.getTimestamp() >= oneWeekAgo) {
            weeklyCategoryExpenses[expense.getCategory()] += expense.getAmount();
        }
    }

    std::map<std::string, double> top3Categories;
    int count = 0;
    for (auto it = weeklyCategoryExpenses.rbegin(); it != weeklyCategoryExpenses.rend(); ++it) {
        top3Categories[it->first] = it->second;
        count++;
        if (count >= 3) {
            break;
        }
    }

    return top3Categories;
}

std::map<std::string, double> FinanceManager::getTop3MonthlyCategories() const {
    std::map<std::string, double> monthlyCategoryExpenses;
    time_t currentTime = time(nullptr);
    time_t oneMonthAgo = currentTime - (30 * 24 * 3600);

    for (const auto& expense : expenses) {
        if (expense.getTimestamp() >= oneMonthAgo) {
            monthlyCategoryExpenses[expense.getCategory()] += expense.getAmount();
        }
    }

    std::map<std::string, double> top3Categories;
    int count = 0;
    for (auto it = monthlyCategoryExpenses.rbegin(); it != monthlyCategoryExpenses.rend(); ++it) {
        top3Categories[it->first] = it->second;
        count++;
        if (count >= 3) {
            break;
        }
    }

    return top3Categories;
}

void FinanceManager::saveReportsToFile(std::string filename) const {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for writing!" << std::endl;
        return;
    }

    
    outputFile << "Weekly Expenses Report:" << std::endl;
    double weeklyExpense = calculateWeeklyExpense();
    outputFile << "Total Weekly Expense: $" << weeklyExpense << std::endl;

    std::map<std::string, double> top3WeeklyCategories = getTop3WeeklyCategories();
    outputFile << "Top 3 Weekly Categories:" << std::endl;
    for (const auto& pair : top3WeeklyCategories) {
        outputFile << pair.first << ": $" << pair.second << std::endl;
    }

    
    outputFile << "\nMonthly Expenses Report:" << std::endl;
    double monthlyExpense = calculateMonthlyExpense();
    outputFile << "Total Monthly Expense: $" << monthlyExpense << std::endl;

    std::map<std::string, double> top3MonthlyCategories = getTop3MonthlyCategories();
    outputFile << "Top 3 Monthly Categories:" << std::endl;
    for (const auto& pair : top3MonthlyCategories) {
        outputFile << pair.first << ": $" << pair.second << std::endl;
    }

    outputFile.close();
}
