#include <exception>
#include <iostream>

#include "Archer.hpp"
#include "CombatSystem.hpp"
#include "Mage.hpp"
#include "Warrior.hpp"

int main() {
  try {
    CombatSystem combat_system{};

    combat_system.add_character(new Warrior{"Okkron", 200, 75, 50});
    combat_system.add_character(new Mage{"Alice", 75, 100, 100});
    combat_system.add_character(new Archer{"Earyn", 140, 65, 30});

    std::cout << "=== COMBAT ARENA ===\n\n";

    combat_system.display_characters();

    std::cout << "\nEnter two character indexes: ";

    int first_index{};
    int second_index{};

    if (!(std::cin >> first_index >> second_index)) {
      throw std::runtime_error{"Invalid input."};
    }

    std::cout << "\n=== BATTLE START ===\n\n";

    combat_system.start_battle(first_index, second_index);

    std::cout << "\n=== BATTLE END ===\n";

  } catch (const std::exception& error) {
    std::cerr << "[ERROR] " << error.what() << '\n';
    return 1;
  }

  return 0;
}
