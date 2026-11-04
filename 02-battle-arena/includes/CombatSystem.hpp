#pragma once

#include <vector>

#include "Character.hpp"

class CombatSystem {
 private:
  std::vector<Character*> m_characters{};

 public:
  CombatSystem(const CombatSystem&) = delete;
  CombatSystem& operator=(const CombatSystem&) = delete;
  CombatSystem(CombatSystem&&) = delete;
  CombatSystem& operator=(CombatSystem&&) = delete;

  void add_character(Character*);
  void remove_character(int);
  void display_characters() const;
  void start_battle(int, int);
  ~CombatSystem();
};