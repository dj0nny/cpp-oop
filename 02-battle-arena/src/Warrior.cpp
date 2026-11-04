#include "Warrior.hpp"

#include <stdexcept>

Warrior::Warrior(const std::string& name, int health, int attack_power, int defense) : Character(name, health, attack_power), m_defense{defense} {
  if (m_defense < 0) {
    throw std::invalid_argument{"Invalid Warrior defense"};
  }
}

int Warrior::get_defense() const { return m_defense; }

void Warrior::take_damage(int damage) {
  if (damage < 0) {
    throw std::runtime_error{"Invalid damage"};
  }

  if (damage <= m_defense) {
    return;
  }

  if (m_defense < damage) {
    Character::take_damage(damage - m_defense);
  }
}

void Warrior::attack(Character& other) { other.take_damage(get_attack_power()); }
