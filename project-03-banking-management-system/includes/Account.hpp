#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <string_view>

#include "AccountType.hpp"

class Account {
  protected:
    int id;
    std::string owner;
    double balance;
    AccountType type;
  public:
    explicit Account(std::string_view account_owner, double account_balance, AccountType account_type);

    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    
    void show_balance() const;
    void display_account_informations() const;

    virtual ~Account() = default;

};

#endif