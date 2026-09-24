#ifndef SAVINGS_ACCOUNT_HPP
#define SAVINGS_ACCOUNT_HPP

#include "Account.hpp"

class SavingsAccount : public Account {
  private:
    double interest_rate;
    double withdrawal_limit;

    double deposit_fee {0.50};
    double withdraw_fee {10};
  public:
    explicit SavingsAccount(std::string_view account_owner, double account_balance, AccountType account_type, double account_interest_rate, double account_withdrawal_limit);

    bool deposit(double amount) override;
    bool withdraw(double amount) override;
    void process_monthly_interest_rate();

    ~SavingsAccount() override = default;

};

#endif