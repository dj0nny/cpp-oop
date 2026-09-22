#include <iostream>
#include <vector>
#include <string>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Bird.hpp"

#include "utils.hpp"

int main() {
  std::vector<Animal*> animals {};

  while (true) {
    int menu_choice {menu_selection()};
    
    switch (to_menu_actions(menu_choice)) {
      case AnimalsMenuActions::AddDog: {
        std::string dog_name {read_animal_name()};
        int dog_age {read_animal_age()};
        std::string dog_species {read_animal_species()};

        Dog* new_dog {new Dog(dog_name, dog_age, dog_species)};
        animals.push_back(new_dog);
        std::cout << "Dog added" << '\n';
        break;
      }
      case AnimalsMenuActions::AddCat: {
        std::string cat_name {read_animal_name()};
        int cat_age {read_animal_age()};
        std::string cat_species {read_animal_species()};

        Cat* new_cat {new Cat(cat_name, cat_age, cat_species)};

        animals.push_back(new_cat);
        std::cout << "Cat added" << '\n';
        break;
      }
      case AnimalsMenuActions::AddBird: {
        std::string bird_name {read_animal_name()};
        int bird_age {read_animal_age()};
        std::string bird_species {read_animal_species()};
        
        Bird* new_bird {new Bird(bird_name, bird_age, bird_species)};

        animals.push_back(new_bird);
        std::cout << "Bird added" << '\n';
        break;
      }
      case AnimalsMenuActions::PrintAnimals:
        print_animals(animals);
        break;
      case AnimalsMenuActions::MakeSounds:
        make_animals_sounds(animals);
        break;
      case AnimalsMenuActions::MakeActions:
        make_animals_actions(animals);
        break;
      case AnimalsMenuActions::Exit:
        return 0;
      default:
        std::cout << "Invalid choice" << '\n';
    }
  }
  
  return 0;
}