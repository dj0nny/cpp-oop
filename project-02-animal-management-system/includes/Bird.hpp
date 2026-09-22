#ifndef BIRD_HPP
#define BIRD_HPP

#include <string_view>

#include "Animal.hpp"

class Bird : public Animal {
  public:
    explicit Bird(std::string_view bird_name, int bird_age, std::string_view bird_species);

    void make_sound() const override;
    void make_action() const override;
};

#endif

