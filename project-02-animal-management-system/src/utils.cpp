#include <limits>
#include <vector>

#include "Animal.hpp"

#include "utils.hpp"
#include "AnimalsMenuActions.hpp"

int menu_selection() {
  std::cout << "╔══════════════════════════════════════╗\n";
  std::cout << "║          ANIMALS MANAGER             ║\n";
  std::cout << "║══════════════════════════════════════║\n";
  std::cout << "║ 1. Add a dog                         ║\n";
  std::cout << "║ 2. Add a cat                         ║\n";
  std::cout << "║ 3. Add a bird                        ║\n";
  std::cout << "║ 4. Print animals                     ║\n";
  std::cout << "║ 5. Print animals sounds              ║\n";
  std::cout << "║ 0. Exit                              ║\n";
  std::cout << "╚══════════════════════════════════════╝\n\n";
  
  while (true) {
    std::cout << "Enter an operation: ";
    int choice {};
    std::cin >> choice;

    if (std::cin.fail()) {
      handle_invalid_input(std::cin);
      continue;
    }

    return choice;
  }
}

void handle_invalid_input(std::istream& is) {
  is.clear();
  is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "Invalid input" << "\n\n";
}

std::string read_animal_name() {
  std::cout << "Enter the animal name: ";
  std::string animal_name {};
  std::getline(std::cin >> std::ws, animal_name);

  return animal_name;
}

int read_animal_age() {
  int animal_age {};

  while (true) {
    std::cout << "Enter the animal age: ";
    std::cin >> animal_age;

    if (std::cin.fail()) {
      handle_invalid_input(std::cin);
      continue;
    }

    return animal_age;
  }
}

std::string read_animal_species() {
  std::cout << "Enter the animal species: ";
  std::string animal_species {};
  std::getline(std::cin >> std::ws, animal_species);

  return animal_species;
}

AnimalsMenuActions to_menu_actions(int choice_code) {
  return static_cast<AnimalsMenuActions>(choice_code);
}

void print_animals(const std::vector<Animal*> animals) {
  if (!animals.empty()) 
    for (const Animal* current_animals : animals)
      std::cout << current_animals << '\n';
  else
    std::cout << "The animals collection is empty.";

  std::cout << '\n';
}

void make_animals_sounds(const std::vector<Animal*> animals) {
  if (!animals.empty())
    for (const Animal* current_animal : animals)
      current_animal->make_sound();
  else
    std::cout << "The animals collection is empty.";

  std::cout << '\n';
}

void make_animals_actions(const std::vector<Animal*> animals) {
  if (!animals.empty())
    for (const Animal* current_animal : animals)
      current_animal->make_action();
  else
    std::cout << "The animals collection is empty.";

  std::cout << '\n';
}