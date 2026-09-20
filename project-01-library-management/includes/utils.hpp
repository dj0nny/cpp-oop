#ifndef UTILS_H
#define UTILS_H

#include <string_view>

#include "MenuActions.hpp"
#include "BookStatus.hpp"
 
#include "Library.hpp"

/****** MENU MANAGEMENT ******/
int menu_selection();
void handle_menu_selection(int choice, Library& my_library);

/****** INPUT MANAGEMENT ******/
void handle_invalid_input(std::istream& is);
Book read_book();
bool valid_book_status(int book_status_code);
int read_book_id();

/****** CASTING ******/
MenuActions to_menu_actions(int choice_code);
std::string_view to_string_rent_status(BookStatus book_status);

#endif