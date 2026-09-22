#include "Animal.hpp"

int Animal::generate_id() const {
  static int id {};

  return ++id;
}

Animal::Animal(std::string_view animal_name, int animal_age, std::string_view animal_species)
  : id {generate_id()}, name {animal_name}, age {animal_age}, species {animal_species}
  {}


std::string_view Animal::get_animal_name() const {
  return name;
}

int Animal::get_animal_age() const {
  return age;
}

std::string_view Animal::get_animal_species() const {
  return species;
}

std::ostream& operator<<(std::ostream& os, const Animal* animal) {
  return os << animal->get_animal_name() << ", " << animal->get_animal_age() << ", " << animal->get_animal_species();
}