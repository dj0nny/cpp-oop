#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
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

    std::string get_owner() const;
    double get_balance() const;
    std::string get_account_type() const;

    virtual ~Account() = default;

};

std::ostream& operator<<(std::ostream& os, const Account& account);

#endif