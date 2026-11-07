#include "CombatSystem.hpp"

#include <algorithm>
#include <iostream>
#include <stdexcept>

void CombatSystem::add_character(Character* character) {
  if (character == nullptr) {
    throw std::invalid_argument{"Invalid pointer."};
  }

  auto it = std::find(m_characters.begin(), m_characters.end(), character);

  if (it != m_characters.end()) {
    throw std::invalid_argument{"Invalid argument value, the character already exists."};
  }

  m_characters.push_back(character);
}

void CombatSystem::display_characters() const {
  std::cout << "List of characters in the arena:" << '\n';

  if (m_characters.empty()) {
    std::cout << "There are no characters in the arena." << '\n';
    return;
  }

  for (std::size_t idx{0}; idx < m_characters.size(); ++idx) {
    std::cout << "ID: " << idx << " | ";
    m_characters[idx]->display_status();
  }
}

void CombatSystem::remove_character(int index) {
  if (m_characters.empty()) {
    std::cout << "There are no characters in the arena." << '\n';
    return;
  }

  if (index < 0) {
    throw std::out_of_range{"Index underflows 0."};
  }

  if (static_cast<std::size_t>(index) >= m_characters.size()) {
    throw std::out_of_range{"Index overflows the vector size."};
  }

  delete m_characters[static_cast<std::size_t>(index)];
  m_characters.erase(m_characters.begin() + static_cast<std::size_t>(index));

  std::cout << "Character erased from the arena." << '\n';
}

void CombatSystem::start_battle(int first_index, int second_index) {
  if ((first_index < 0 || second_index < 0)) {
    throw std::out_of_range{"One of the indexes underflows 0."};
  }

  if (static_cast<std::size_t>(first_index) >= m_characters.size() || static_cast<std::size_t>(second_index) >= m_characters.size()) {
    throw std::out_of_range{"One of the indexes overflows the vector size."};
  }

  Character* first_character = m_characters[static_cast<std::size_t>(first_index)];
  Character* second_character = m_characters[static_cast<std::size_t>(second_index)];

  if (!first_character->is_alive() || !second_character->is_alive()) {
    std::cout << "A dead character cannot combat in the arena.";
    return;
  }

  if (first_character == second_character) {
    std::cout << "You cannot choose the same character for a battle";
    return;
  }

  first_character->attack(*second_character);

  if (second_character->is_alive()) {
    second_character->attack(*first_character);
  }

  first_character->display_status();
  second_character->display_status();
}

CombatSystem::~CombatSystem() {
  for (auto* item : m_characters) {
    delete item;
  }
}