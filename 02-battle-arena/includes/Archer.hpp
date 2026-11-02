#pragma once

#include "Character.hpp"

class Archer : public Character {
 private:
  int m_arrows{};
  static constexpr int s_max_arrows{30};

 public:
  Archer(const std::string& name, int health, int attack_power, int arrows);

  int get_arrows() const;
  void restore_arrows(int);
  void attack(Character&) override;
};