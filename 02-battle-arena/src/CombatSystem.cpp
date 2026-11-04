#include "CombatSystem.hpp"

#include <algorithm>
#include <iostream>
#include <stdexcept>

void CombatSystem::add_character(Character* character) {
  if (character == nullptr) {
    throw std::invalid_argument{"Invalid argument value."};
  }

  auto it{find_if(m_characters.begin(), m_characters.end(), [character](Character* current_character) { return current_character == character; })};

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

  for (const auto* current_character : m_characters) {
    current_character->display_status();
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

CombatSystem::~CombatSystem() {
  for (auto* item : m_characters) {
    delete item;
  }
}