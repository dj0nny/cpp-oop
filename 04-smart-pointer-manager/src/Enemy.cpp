
#include "Enemy.hpp"

#include <iostream>

Enemy::Enemy(const std::string& name, int health, int attack_power) : GameObject(name), m_health{health}, m_attack_power{attack_power} {}

void Enemy::take_damage(int damage) {
  if (m_health > 0) {
    m_health -= damage;
  }
}

void Enemy::display_status() const { std::cout << "Enemy name: " << get_name() << " |  Health: " << m_health << " | Attack power: " << m_attack_power << '\n'; }