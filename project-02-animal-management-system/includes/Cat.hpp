#ifndef CAT_HPP
#define CAT_HPP

#include <string_view>

#include "Animal.hpp"

class Cat : public Animal {
  public:
    explicit Cat(std::string_view cat_name, int cat_age, std::string_view cat_species);

    void make_sound() const override;
    void make_action() const override;
};

#endif