#pragma once

#include "GameObject.hpp"

class Enemy : public GameObject {
 private:
  int m_health{};
  int m_attack_power{};

 public:
  Enemy(const std::string&, int, int);

  void take_damage(int);
  void display_status() const override;
};