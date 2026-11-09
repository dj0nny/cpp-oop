#pragma once

#include "Character.hpp"

class Mage : public Character {
 private:
  int m_mana{};
  static constexpr int s_max_mana{100};

 public:
  Mage(const std::string& name, int health, int attack_power, int mana);

  int get_mana() const;

  void restore_mana(int);
  void attack(Character&) override;
  ~Mage() override;
};