#include "Character.hpp"

#include <algorithm>
#include <iostream>
#include <stdexcept>

Character::Character(const std::string& name, int health, int attack_power) : m_name{name}, m_health{health}, m_attack_power{attack_power} {
  if (m_name.empty() || health <= 0 || m_attack_power <= 0) {
    throw std::invalid_argument{"Invalid character"};
  }
}

const std::string& Character::get_name() const { return m_name; }
int Character::get_health() const { return m_health; }
int Character::get_attack_power() const { return m_attack_power; }

void Character::take_damage(int damage) {
  if (damage < 0) {
    throw std::runtime_error{"Invalid damage"};
  }

  m_health = std::max(0, m_health - damage);
}

bool Character::is_alive() const { return m_health > 0; }

void Character::display_status() const { std::cout << "Character name: " << m_name << " | Health: " << m_health << " | Attack power: " << m_attack_power << '\n'; };

Character::~Character() {}