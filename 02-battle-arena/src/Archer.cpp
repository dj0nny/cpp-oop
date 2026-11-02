#include "Archer.hpp"

#include <algorithm>
#include <iostream>
#include <stdexcept>

Archer::Archer(const std::string& name, int health, int attack_power, int arrows) : Character(name, health, attack_power), m_arrows{arrows} {
  if (m_arrows < 0 || m_arrows < s_max_arrows) {
    throw std::invalid_argument{"Invalid arrows value"};
  }
}

int Archer::get_arrows() const { return m_arrows; }

void Archer::restore_arrows(int arrows_amount) {
  if (arrows_amount < 0) {
    throw std::invalid_argument{"Invalid arrows recovery"};
  }

  m_arrows = std::min(s_max_arrows, m_arrows + arrows_amount);
}

void Archer::attack(Character& other) {
  constexpr int arrow_cost{1};

  if (m_arrows <= 0) {
    std::cout << "Attack failed! Insufficient arrows" << '\n';
    return;
  }

  other.take_damage(get_attack_power());
  m_arrows -= arrow_cost;
}