#include "CheckingAccount.hpp"

CheckingAccount::CheckingAccount(std::string_view account_owner, double account_balance, AccountType account_type, double account_monthly_fee = 5.00, double account_overdraft_limit = -1000)
  : Account {account_owner, account_balance, account_type}, monthly_fee {account_monthly_fee}, overdraft_limit {account_overdraft_limit}
{}

bool CheckingAccount::deposit(double amount) {
  const double net_deposit {amount - deposit_fee};

  if (net_deposit > 0) {
    balance += net_deposit;
    return true;
  }

  return false;
}

bool CheckingAccount::withdraw(double amount) {
  const double net_withdraw {amount - deposit_fee};

  if (net_withdraw > 0 && (((balance - amount) >= overdraft_limit))) {
    balance -= net_withdraw;
    return true;
  }

  return false;
}

void CheckingAccount::process_monthly_fee() {
  balance -= monthly_fee;
}