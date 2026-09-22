#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <ostream>

#include <string>
#include <string_view>

class Animal {
  protected:
    int id;
    std::string name;
    int age;
    std::string species;

    int generate_id() const;

  public:
    explicit Animal(std::string_view animal_name, int animal_age, std::string_view animal_species);

    std::string_view get_animal_name() const;
    int get_animal_age() const;
    std::string_view get_animal_species() const;

    virtual void make_sound() const = 0;
    virtual void make_action() const = 0;

    virtual ~Animal() = default;
};

std::ostream& operator<<(std::ostream& os, const Animal* animal);

#endif