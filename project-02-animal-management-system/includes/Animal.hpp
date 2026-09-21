#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
  private:
    int id;
    std::string name;
    int age;
    std::string species;
  public:
    Animal(int animal_id, std::string animal_name, int animal_age, std::string anima_species);

    virtual void make_sound() const;
    virtual void make_action() const;

    virtual ~Animal();
};

#endif