#include "Player.hpp"

#include <iostream>

Player::Player(const std::string& name) : GameObject(name) {}

void Player::equip(const std::shared_ptr<Weapon> p_weapon) { m_weapon = p_weapon; }
void Player::unequip() { m_weapon = nullptr; }
void Player::display_status() const {
  std::cout << "Enemy name: " << get_name() << '\n';
  std::cout << "Weapon equipped details: " << '\n';

  if (m_weapon != nullptr) {
    m_weapon->display_status();
  } else {
    std::cout << "No weapon equipped." << '\n';
  }
}