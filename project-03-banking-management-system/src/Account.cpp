#include "Account.hpp"

Account::Account(std::string_view account_owner, double account_balance, AccountType account_type)
  : owner {account_owner}, balance {account_balance}, type {account_type}
{}

std::string Account::get_owner() const {
  return owner;
}

double Account::get_balance() const {
  return balance;
}
 
std::string Account::get_account_type() const {
  return to_string_account_type(type);
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
  return os << account.get_owner() << ", " << account.get_balance() << ", " << account.get_account_type();
}