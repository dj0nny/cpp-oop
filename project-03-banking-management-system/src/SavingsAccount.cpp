#include "SavingsAccount.hpp"

SavingsAccount::SavingsAccount(std::string_view account_owner, double account_balance, AccountType account_type, double account_interest_rate = 3.0, double account_withdrawal_limit = 2000)
  : Account {account_owner, account_balance, account_type}, interest_rate {account_interest_rate}, withdrawal_limit {account_withdrawal_limit}
{}

bool SavingsAccount::deposit(double amount) {
  const double net_deposit {amount - deposit_fee};

  if (net_deposit > 0) {
    balance += net_deposit;
    return true;
  }

  return false;
}

bool SavingsAccount::withdraw(double amount) {
  const double net_withdraw {amount - deposit_fee};

  if (net_withdraw > 0 && net_withdraw <= withdrawal_limit) {
    balance -= net_withdraw;
    return true;
  }

  return false;
}

void SavingsAccount::process_monthly_interest_rate() {
  constexpr int percent {100};
  constexpr int months {12};

  double decimal_tax_rate {interest_rate / percent};
  double monthly_tax_rate {decimal_tax_rate / months};

  balance *= monthly_tax_rate;
}