#include "Weapon.hpp"

#include <iostream>
#include <utility>

Weapon::Weapon(const std::string& name, int damage) : m_name{std::move(name)}, m_damage{damage} {}

const std::string& Weapon::get_name() const { return m_name; }
int Weapon::get_damage() const { return m_damage; }

void Weapon::display_status() const { std::cout << "Weapon name: " << get_name() << " |  Damager power: " << m_damage << '\n'; }
