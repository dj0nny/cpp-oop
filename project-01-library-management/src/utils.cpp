#include <iostream>
#include <limits>
#include <string_view>
#include <algorithm>

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
  std::cout << "║ 3. Search a book                     ║\n";
  std::cout << "║ 4. Register a rent                   ║\n";
  std::cout << "║ 5. Return a book                     ║\n";
  std::cout << "║ 6. Delete a book                     ║\n";
  std::cout << "║ 7. Show books status                 ║\n";
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
  MenuActions choice_action {to_menu_actions(choice)};

  switch (choice_action) {
    case MenuActions::AddBook:
      my_library.insert_book(read_book());
      break;
    case MenuActions::ShowBooks:
      my_library.show_books();
      break;
    case MenuActions::SearchBook: {
      my_library.search_books();
      break;
    }
    case MenuActions::RentBook: case MenuActions::ReturnBook: case MenuActions::DeleteBook: {
      int book_id {read_book_id()};

      if (choice_action == MenuActions::RentBook) {
        if (my_library.register_book_borrow(book_id))
          std::cout << "Book borrowed" << "\n\n";
        else
          std::cout << "Book already borrowed or cannot find the book" << "\n\n";
      } else if (choice_action == MenuActions::ReturnBook) {
        if (my_library.register_book_return(book_id))
          std::cout << "Book returned" << "\n\n";
        else
          std::cout << "Book already in the library or cannot find the book" << "\n\n";
      } else {
        if (my_library.delete_book(book_id))
          std::cout << "Book deleted." << "\n\n";
        else
          std::cout << "Book not found or there are books in the library." << "\n\n";
          
        break;
      }
    }
    case MenuActions::StatusBooks:
      my_library.show_books_status();
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

    if (book_year < 0) {
      std::cout << "Invalid book year" << '\n';
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

  Book new_book(book_title, book_author, book_year, book_status);

  return new_book;
}

bool valid_book_status(int book_status_code) {
  return book_status_code == 0 || book_status_code == 1;
}

bool valid_search_method(int search_method_code) {
  return search_method_code >= 1 && search_method_code <= 4;
}

int read_book_id() {
  int book_id {};
  
  while (true) {
    std::cout << "Enter the book id: ";
    std::cin >> book_id;

    if (std::cin.fail()) {
      handle_invalid_input(std::cin);
      continue;
    }

    return book_id;
  }
}

std::string read_book_title() {
  std::cout << "Enter the book title: ";
  std::string book_title {};
  std::getline(std::cin >> std::ws, book_title);

  return book_title;
}

std::string read_book_author() {
  std::cout << "Enter the book author: ";
  std::string book_author {};
  std::getline(std::cin >> std::ws, book_author);

  return book_author;
}

MenuActions to_menu_actions(int choice_code) {
  return static_cast<MenuActions>(choice_code);
}

int read_book_year() {
  int book_year {};
  
  while (true) {
    std::cout << "Enter the book year: ";
    std::cin >> book_year;

    if (std::cin.fail()) {
      handle_invalid_input(std::cin);
      continue;
    }

    return book_year;
  }
}

std::string_view to_string_rent_status(BookStatus book_status) {
  return book_status == BookStatus::NotAvailable ? "Not Available" : "Available";
}

std::string to_lowercase_string(std::string_view s) {
  std::string lowercase_string(s.length(), '\0');

  std::transform(s.begin(), s.end(), lowercase_string.begin(), [](unsigned char c) {
    return std::tolower(c);
  });

  return lowercase_string;
}

SearchMethods to_search_methods(int search_method_code) {
  return static_cast<SearchMethods>(search_method_code);
}

std::vector<Book>::iterator search_book_by_id(int book_id, std::vector<Book>& books) {
  auto find_item_iterator {std::find_if(books.begin(), books.end(), [book_id](const Book& current_book) {
    return book_id == current_book.get_id();
  })};

  return find_item_iterator;
}

std::vector<Book>::iterator search_book_by_title(std::string_view book_title, std::vector<Book>& books) {
  auto find_item_iterator {std::find_if(books.begin(), books.end(), [book_title](const Book& current_book) {
    return to_lowercase_string(book_title) == to_lowercase_string(current_book.get_title());
  })};

  return find_item_iterator;
}

std::vector<Book>::iterator search_book_by_author(std::string_view book_author, std::vector<Book>& books) {
   auto find_item_iterator {std::find_if(books.begin(), books.end(), [book_author](const Book& current_book) {
    return to_lowercase_string(book_author) == to_lowercase_string(current_book.get_author());
  })};

  return find_item_iterator;
}

std::vector<Book>::iterator search_book_by_year(int book_year, std::vector<Book>& books) {
  auto find_item_iterator {std::find_if(books.begin(), books.end(), [book_year](const Book& current_book) {
    return book_year == current_book.get_year();
  })};

  return find_item_iterator;
}