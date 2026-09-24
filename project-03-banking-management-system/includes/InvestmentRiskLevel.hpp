#ifndef INVESTMENT_RISK_LEVEL_HPP
#define INVESTMENT_RISK_LEVEL_HPP

#include <iostream>

enum class InvestmentRiskLevel {
  Low,
  Medium,
  High
};

inline std::ostream& operator<<(std::ostream& os, const InvestmentRiskLevel& risk) {
  switch (risk) {
    case InvestmentRiskLevel::Low:
      return os << "Low";
    case InvestmentRiskLevel::Medium:
      return os << "Medium";
    case InvestmentRiskLevel::High:
      return os << "High";
  }

  throw std::runtime_error("Invalid risk level");
}

#endif