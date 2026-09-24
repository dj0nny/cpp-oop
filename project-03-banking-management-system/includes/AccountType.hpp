#ifndef ACCOUNT_TYPE_HPP
#define ACCOUNT_TYPE_HPP

#include <iostream>
#include <stdexcept>

enum class AccountType {
  CheckingAccount,
  InvestmentAccount,
  SavingsAccount
};

inline std::ostream& operator<<(std::ostream& os, const AccountType& type) {
  switch (type) {
    case AccountType::CheckingAccount:
      return os << "Checking account";
    case AccountType::InvestmentAccount:
      return os << "Investment account";
    case AccountType::SavingsAccount:
      return os << "Savings account";
  }

  throw std::runtime_error("Invalid account type");

}

inline std::string to_string_account_type(const AccountType& type) {
  switch (type) {
    case AccountType::CheckingAccount:
      return "Checking account";
    case AccountType::InvestmentAccount:
      return "Investment account";
    case AccountType::SavingsAccount:
      return "Savings account";
  }

  throw std::runtime_error("Invalid account type");
}


#endif