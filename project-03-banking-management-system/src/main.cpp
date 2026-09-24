#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

#include "Account.hpp"
#include "CheckingAccount.hpp"
#include "SavingsAccount.hpp"
#include "InvestmentAccount.hpp"

int main() {
  try {
    std::vector<std::unique_ptr<Account>> accounts {};

    accounts.emplace_back(std::make_unique<CheckingAccount>("John", 5125.10, AccountType::CheckingAccount, 3.75, -1500));
    accounts.emplace_back(std::make_unique<SavingsAccount>("Lucy", 371774.11, AccountType::SavingsAccount, 4.25, 1500));
    accounts.emplace_back(std::make_unique<InvestmentAccount>("Patrick", 574125.97, AccountType::InvestmentAccount, InvestmentRiskLevel::High, 25000));

    for (const auto& current_account : accounts) 
      std::cout << current_account->get_owner() << '\n';

  } catch (const std::exception& error) {
    std::cerr << "Exception: " << error.what() << '\n';
  }

  return 0;
}