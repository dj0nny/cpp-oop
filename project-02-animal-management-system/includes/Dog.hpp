#ifndef DOG_HPP
#define DOG_HPP

#include <string_view>

#include "Animal.hpp"

class Dog : public Animal {
  public:
    explicit Dog(std::string_view dog_name, int dog_age, std::string_view dog_species);

  void make_sound() const override;
  void make_action() const override;
};

#endif