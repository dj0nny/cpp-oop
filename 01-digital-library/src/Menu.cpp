#include "Menu.hpp"

#include <limits>

int handle_menu() {
  std::cout << "===== DIGITAL LIBRARY =====" << '\n';
  std::cout << "1. Add book" << '\n';
  std::cout << "2. Display all books" << '\n';
  std::cout << "3. Search book by ISBN" << '\n';
  std::cout << "4. Borrow book" << '\n';
  std::cout << "5. Return book" << '\n';
  std::cout << "0. Exit" << "\n\n";

  while (true) {
    std::cout << "Select an option: ";
    int choice{};
    std::cin >> choice;

    if (std::cin.fail()) {
      handle_invalid_input(std::cin);
      continue;
    }

    switch (choice) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
        return choice;
      default:
        std::cout << "[INVALID INPUT]" << "\n\n";
        continue;
    }
  }
}

bool handle_menu_choice(int choice, Library& library) {
  switch (choice) {
    case 1:
      if (handle_add_book(library)) {
        std::cout << "Book inserted successfully!";
      } else {
        std::cout << "The book already exists";
      }
      break;
    case 2:
      library.display_books();
      break;
    case 3: {
      auto found_book{handle_search_book(library)};

      if (found_book != nullptr) {
        std::cout << *found_book;
      } else {
        std::cout << "No book matching this ISBN";
      }
      break;
    }
    case 4:
      if (handle_borrow_book(library)) {
        std::cout << "Borrow succeed!";
      } else {
        std::cout << "Cannot borrow the book";
      }
      break;
    case 5:
      if (handle_return_book(library)) {
        std::cout << "Return succeed!";
      } else {
        std::cout << "Cannot return the book";
      }
      break;
    case 0:
      std::cout << "See you soon!";
      return true;
    default:
      std::cout << "Invalid choice";
  }

  std::cout << "\n\n";

  return false;
}

std::string read_isbn() {
  std::string isbn{};
  std::cout << "Enter the book ISBN: ";
  std::cin >> isbn;

  return isbn;
}

void handle_invalid_input(std::istream& is) {
  is.clear();
  is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "[INVALID INPUT]" << "\n\n";
}

bool handle_add_book(Library& library) {
  std::string title{};
  std::cout << "Enter the book title: ";
  std::getline(std::cin >> std::ws, title);

  std::string author{};
  std::cout << "Enter the book author: ";
  std::getline(std::cin >> std::ws, author);

  std::string isbn{};
  std::cout << "Enter the book ISBN: ";
  std::cin >> isbn;

  bool is_available{};

  while (true) {
    std::cout << "Enter the book availability (0 = not available, 1 = available): ";
    std::cin >> is_available;

    if (std::cin.fail()) {
      handle_invalid_input(std::cin);
      continue;
    }

    break;
  }

  if (library.add_book(Book{title, author, isbn, is_available})) {
    return true;
  }

  return false;
}

const Book* handle_search_book(const Library& library) { return library.find_book_by_isbn(read_isbn()); }

bool handle_borrow_book(Library& library) { return library.borrow_book(read_isbn()); }

bool handle_return_book(Library& library) { return library.return_book(read_isbn()); }