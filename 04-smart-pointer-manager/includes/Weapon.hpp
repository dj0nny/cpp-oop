#pragma once

#include <string>

class Weapon {
 private:
  std::string m_name{};
  int m_damage{};

 public:
  Weapon(const std::string&, int);

  const std::string& get_name() const;
  int get_damage() const;

  void display_status() const;
};