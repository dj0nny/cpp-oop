#include <iostream>

#include "Cat.hpp"

Cat::Cat(std::string_view cat_name, int cat_age, std::string_view cat_species)
  : Animal {cat_name, cat_age, cat_species}
{}

void Cat::make_sound() const {
  std::cout << "The cat " << name << " says: meow!" << '\n';
}

void Cat::make_action() const {
  std::cout << "The cat " << name << " jumps!" << '\n';
}