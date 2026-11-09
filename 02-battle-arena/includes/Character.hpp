#pragma once

#include <string>

class Character {
 private:
  std::string m_name{};
  int m_health{};
  int m_attack_power{};

 public:
  Character(const std::string& name, int health, int attack_power);

  const std::string& get_name() const;
  int get_health() const;
  int get_attack_power() const;

  bool is_alive() const;
  void display_status() const;

  virtual void take_damage(int);
  virtual void attack(Character&) = 0;
  virtual ~Character();
};