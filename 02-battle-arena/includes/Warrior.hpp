#pragma once

#include "Character.hpp"

class Warrior : public Character {
 private:
  int m_defense{};

 public:
  Warrior(const std::string& name, int health, int attack_power, int defense);

  int get_defense() const;

  void take_damage(int) override;
  void attack(Character&) const override;
};