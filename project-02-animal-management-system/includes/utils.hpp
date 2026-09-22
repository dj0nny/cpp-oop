#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>

#include "AnimalsMenuActions.hpp"

/****** MENU MANAGEMENT ******/
int menu_selection();
void handle_menu_selection(int choice);

/****** HANDLE INPUT ******/
void handle_invalid_input(std::istream& is);
std::string read_animal_name();
int read_animal_age();
std::string read_animal_species();

/****** CASTING ******/
AnimalsMenuActions to_menu_actions(int choice_code);

/****** PRINT FUNCTIONS ******/
void print_animals(const std::vector<Animal*> animals);
void make_animals_sounds(const std::vector<Animal*> animals);
void make_animals_actions(const std::vector<Animal*> animals);

#endif