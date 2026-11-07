#include <iostream>
#include <vector>

#include "Archer.hpp"
#include "CombatSystem.hpp"
#include "Mage.hpp"
#include "Warrior.hpp"

int main() {
  try {
    CombatSystem combat_system{};

    Warrior* okkron{new Warrior{"Okkron", 200, 75, 50}};
    Mage* alice{new Mage{"Alice", 75, 100, 100}};
    Archer* earlyn{new Archer{"Earyn", 140, 65, 30}};

    combat_system.add_character(okkron);
    combat_system.add_character(alice);
    combat_system.add_character(earlyn);

    combat_system.display_characters();

    std::cout << "\nEnter two character ids: ";
    int character_id_1{};
    int character_id_2{};
    std::cin >> character_id_1 >> character_id_2;

    combat_system.start_battle(character_id_1, character_id_2);

  } catch (const std::exception& error) {
    std::cerr << "[ERROR] " << error.what();
  }

  return 0;
}