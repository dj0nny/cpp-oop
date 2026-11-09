#include "Mage.hpp"

#include <algorithm>
#include <iostream>
#include <stdexcept>

Mage::Mage(const std::string& name, int health, int attack_power, int mana) : Character(name, health, attack_power), m_mana{mana} {
  if (m_mana < 0 || m_mana < s_max_mana) {
    throw std::invalid_argument{"Invalid mana value"};
  }
}

int Mage::get_mana() const { return m_mana; }

void Mage::restore_mana(int mana_amount) {
  if (mana_amount < 0) {
    throw std::invalid_argument{"Invalid mana recovery"};
  }

  m_mana = std::min(s_max_mana, m_mana + mana_amount);
}

void Mage::attack(Character& other) {
  constexpr int mana_cost{10};

  if (m_mana < mana_cost) {
    std::cout << "Attack failed! Insufficient mana for casting" << '\n';
    return;
  }

  other.take_damage(get_attack_power());
  m_mana -= mana_cost;
}

Mage::~Mage() {}
