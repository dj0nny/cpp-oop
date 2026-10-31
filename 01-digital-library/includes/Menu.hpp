#pragma once

#include <iostream>
#include <string>

#include "Library.hpp"

void handle_invalid_input(std::istream& is);

int handle_menu();
bool handle_menu_choice(int choice, Library& library);
std::string read_isbn();

bool handle_add_book(Library& library);
bool handle_borrow_book(Library& library);
bool handle_return_book(Library& library);
const Book* handle_search_book(const Library& library);
