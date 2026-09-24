#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "InvestmentAccount.hpp"

InvestmentAccount::InvestmentAccount(std::string_view account_owner, double account_balance, AccountType account_type, InvestmentRiskLevel account_investment_risk, double account_invested_money = 0.0)
  : Account {account_owner, account_balance, account_type}, invested_money {account_invested_money}, risk {account_investment_risk}
{
  if (balance > invested_money) {
    switch (risk) {
      case InvestmentRiskLevel::Low:
        investment_rate = 1.5;
        break;
      case InvestmentRiskLevel::Medium:
        investment_rate = 2.15;
        break;
      case InvestmentRiskLevel::High:
        investment_rate = 3.0;
        break; 
      default:
        throw std::runtime_error("Cannot create the investment account");
    }
  }

}


bool InvestmentAccount::deposit(double amount) {
  double net_investment {amount - invest_fee};

  if (balance >= net_investment) {
    balance -= net_investment;
    invested_money += net_investment;

    return true;
  }

  return false;
}

bool InvestmentAccount::withdraw(double amount) {
  double net_withdraw {amount + invest_fee};

  if (invested_money >= net_withdraw) {
    invested_money -= net_withdraw;
    balance += invested_money;

    return true;
  }

  return false;
}

void InvestmentAccount::apply_investment() {
  constexpr int percent {100};
  
  double decimal_investment_rate {investment_rate / percent};

  invested_money *= decimal_investment_rate;
}


void InvestmentAccount::investment_information() {
  std::cout << std::fixed << std::setprecision(2) << "Invested money: " << invested_money << "\nRisk: " << risk;
}
