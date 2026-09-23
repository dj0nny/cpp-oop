#ifndef CHECKING_ACCOUNT_HPP
#define CHECKING_ACCOUNT_HPP

#include "Account.hpp"

class CheckingAccount : public Account {
  private:
    double monthly_fee;
    double overdraft_limit;

    double deposit_fee {1.25};
    double withdraw_fee {1.50};
  public:
    explicit CheckingAccount(std::string_view account_owner, double account_balance, AccountType account_type, double account_monthly_fee, double account_overdraft_limit);
    bool deposit(double amount) override;
    bool withdraw(double amount) override;
    void process_monthly_fee();
};

#endif