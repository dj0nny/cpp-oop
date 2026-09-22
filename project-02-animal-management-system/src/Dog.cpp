#include <iostream>

#include "Dog.hpp"

Dog::Dog(std::string_view dog_name, int dog_age, std::string_view dog_species)
  : Animal{dog_name, dog_age, dog_species}
{}

void Dog::make_sound() const {
  std::cout << "The dog " <<  name << " says: woof!" << '\n';
}

void Dog::make_action() const {
  std::cout << "The dog " <<  name << " walks!" << '\n';
}