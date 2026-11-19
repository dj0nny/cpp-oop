#pragma once

#include <memory>

#include "Weapon.hpp"

class WeaponObserver {
 private:
  std::weak_ptr<Weapon> m_weapon{};

 public:
  void watch(const std::shared_ptr<Weapon>&);
  void display_weapon_status() const;
  bool is_available() const;
};