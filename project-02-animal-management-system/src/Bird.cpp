#include <iostream>

#include "Bird.hpp"

Bird::Bird(std::string_view bird_name, int bird_age, std::string_view bird_species)
  : Animal {bird_name, bird_age, bird_species}
{}

void Bird::make_sound() const {
  std::cout << "The bird " << name << " says: cip cip!" << '\n';
}

void Bird::make_action() const {
  std::cout << "The bird " << name << " files!" << '\n';
}