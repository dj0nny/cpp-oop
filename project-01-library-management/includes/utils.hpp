#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <string_view>

#include "MenuActions.hpp"
#include "BookStatus.hpp"
#include "SearchMethods.hpp"
 
#include "Library.hpp"

/****** MENU MANAGEMENT ******/
int menu_selection();
void handle_menu_selection(int choice, Library& my_library);

/****** INPUT MANAGEMENT ******/
void handle_invalid_input(std::istream& is);
Book read_book();
bool valid_book_status(int book_status_code);
bool valid_search_method(int search_method_code);
int read_book_id();
std::string read_book_title();
std::string read_book_author();
int read_book_year();

/****** CASTING ******/
MenuActions to_menu_actions(int choice_code);
std::string_view to_string_rent_status(BookStatus book_status);
std::string to_lowercase_string(std::string_view s);
SearchMethods to_search_methods(int search_method_code);

/****** SEARCH FUNCTIONS ******/
std::vector<Book>::iterator search_book_by_id(int book_id, std::vector<Book>& books);
std::vector<Book>::iterator search_book_by_title(std::string_view book_title, std::vector<Book>& books);
std::vector<Book>::iterator search_book_by_author(std::string_view book_author, std::vector<Book>& books);
std::vector<Book>::iterator search_book_by_year(int book_year, std::vector<Book>& books);

#endif