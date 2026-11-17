#pragma once

#include <memory>

#include "GameObject.hpp"
#include "Weapon.hpp"

class Player : public GameObject {
 private:
  std::shared_ptr<Weapon> m_weapon{};

 public:
  Player(const std::string&);

  void equip(std::shared_ptr<Weapon>);
  void unequip();

  void display_status() const override;
};