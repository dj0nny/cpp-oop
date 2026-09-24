#ifndef INVESTMENT_ACCOUNT_HPP
#define INVESTMENT_ACCOUNT_HPP

#include "Account.hpp"
#include "InvestmentRiskLevel.hpp"

class InvestmentAccount : public Account {
  private:
    double invested_money;
    double investment_rate;
    InvestmentRiskLevel risk;

    double withdraw_tax = {0.30};
    double invest_fee {2.50};
  public:
    explicit InvestmentAccount(std::string_view account_owner, double account_balance, AccountType account_type, InvestmentRiskLevel account_investment_risk, double account_invested_money);

    bool deposit(double amount);
    bool withdraw(double amount);
    void apply_investment();
    void investment_information();

    ~InvestmentAccount() override = default;
};

#endif