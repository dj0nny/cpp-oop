#include <iostream>
#include <limits>
#include <string_view>

#include "utils.hpp"

#include "MenuActions.hpp"
#include "BookStatus.hpp"
#include "Library.hpp"

int menu_selection() {
  std::cout << "╔══════════════════════════════════════╗\n";
  std::cout << "║            LIBARY MANAGER            ║\n";
  std::cout << "║══════════════════════════════════════║\n";
  std::cout << "║ 1. Add a book                        ║\n";
  std::cout << "║ 2. Show books collection             ║\n";
  std::cout << "║ 0. Exit                              ║\n";
  std::cout << "╚══════════════════════════════════════╝\n\n";
  
  while (true) {
    std::cout << "Enter an operation: ";
    int choice {};
    std::cin >> choice;

    if (std::cin.fail()) {
      handle_invalid_input(std::cin);
      continue;
    }

    return choice;
  }
}

void handle_menu_selection(int choice, Library& my_library) {
  switch (to_menu_actions(choice)) {
    case MenuActions::AddBook:
      my_library.insert_book(read_book());
      break;
    case MenuActions::ShowBooks:
      my_library.show_books();
      break;
    case MenuActions::Exit:
      exit(EXIT_SUCCESS);
  }
}

void handle_invalid_input(std::istream& is) {
  is.clear();
  is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "Invalid input" << "\n\n";
}

Book read_book() {
  std::cout << "Enter book title: ";
  std::string book_title {};
  std::getline(std::cin >> std::ws, book_title);

  std::cout << "Enter book author: ";
  std::string book_author {};
  std::getline(std::cin >> std::ws, book_author);
  
  int book_year {};

  while (true) {
    std::cout << "Enter book year: ";
    std::cin >> book_year;

    while (std::cin.fail()) {
      handle_invalid_input(std::cin);
      continue;
    }

    break;
  }

  BookStatus book_status {};

  while (true) {
    std::cout << "Enter book rent status (0 = Not available, 1 = Available): ";
    int book_status_code {};
    std::cin >> book_status_code;

    while (std::cin.fail()) {
      handle_invalid_input(std::cin);
      continue;
    }

    if (!valid_book_status(book_status_code)) {
      std::cout << "Invalid book status" << '\n';
      continue;
    }

    book_status = static_cast<BookStatus>(book_status_code);

    break;
  }

  Book new_book(1, book_title, book_author, book_year, book_status);

  return new_book;
}

bool valid_book_status(int book_status_code) {
  return book_status_code == 0 || book_status_code == 1;
}

MenuActions to_menu_actions(int choice_code) {
  return static_cast<MenuActions>(choice_code);
}

std::string_view to_string_rent_status(BookStatus book_status) {
  return book_status == BookStatus::NotAvailable ? "Not Available" : "Available";
}
