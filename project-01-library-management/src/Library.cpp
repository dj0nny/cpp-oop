#include <iostream>
#include <algorithm>

#include "Book.hpp"
#include "Library.hpp"
#include "BookStatus.hpp"
#include "SearchMethods.hpp"
#include "utils.hpp"

Library::Library() {}

void Library::insert_book(const Book& book) {
  books.push_back(book);
  std::cout << "Book added to the library." << "\n\n";
}

void Library::show_books() const {
  if (!books.empty()) {
    for (const Book& current_book : books)
      std::cout << current_book << '\n';
  } else
    std::cout << "The are no books in the library" << "\n\n";
}

void Library::search_books() {  
  if (!books.empty()) {
    int search_code {};

    while (true) {
      std::cout << "-> 1. Id" << '\n';
      std::cout << "-> 2. Title" << '\n';
      std::cout << "-> 3. Author" << '\n';
      std::cout << "-> 4. Year" << '\n';
      std::cout << "Enter search code: ";
  
      std::cin >> search_code;

      if (std::cin.fail()) {
        handle_invalid_input(std::cin);
        continue;
      }

      if (!valid_search_method(search_code)) {
        std::cout << "Invalid search method" << '\n';
        continue;
      }

      break;
    }

    auto found_book_iterator {books.end()};

    switch (to_search_methods(search_code)) {
      case SearchMethods::Id:
        found_book_iterator = search_book_by_id(read_book_id(), books);
        break;
      case SearchMethods::Title: 
        found_book_iterator = search_book_by_title(read_book_title(), books);
        break;
      case SearchMethods::Author: 
        found_book_iterator = search_book_by_author(read_book_author(), books);
        break;
      case SearchMethods::Year: 
        found_book_iterator = search_book_by_year(read_book_year(), books);
        break;
    }

    if (found_book_iterator != books.end())
      std::cout << *found_book_iterator << '\n';
    else
      std::cout << "Book not found" << "\n\n";

  } else
    std::cout << "There are no books in the library.";

};

bool Library::delete_book(int book_id) {
  if (!books.empty()) {
    auto delete_item_iterator {search_book_by_id(book_id, books)};

    if (delete_item_iterator != books.end()) {
      books.erase(delete_item_iterator);
      return true;
    }
  }

  return false;
}

bool Library::register_book_borrow(int book_id) {
  if (!books.empty()) {
    auto borrowed_book_iterator {search_book_by_id(book_id, books)};

    if (borrowed_book_iterator != books.end() && borrowed_book_iterator->get_rent_status_code() == BookStatus::Available) {
      borrowed_book_iterator->set_as_borrowed();
      return true;
    }
  }

  return false;
}

bool Library::register_book_return(int book_id) {
  if (!books.empty()) {
    auto borrowed_book_iterator {search_book_by_id(book_id, books)};

    if (borrowed_book_iterator != books.end() && borrowed_book_iterator->get_rent_status_code() == BookStatus::NotAvailable) {
      borrowed_book_iterator->set_as_not_borrowed();
      return true;
    }
  }

  return false;
}

void Library::show_books_status() {
  if (!books.empty()) {
    auto available_books_count {std::count_if(books.begin(), books.end(), [](const Book& current_book) {
      return current_book.get_rent_status() == "Available";
    })};

    auto not_available_books_count {books.size() - available_books_count};

    std::cout << "There are " << available_books_count << " available books." << '\n';
    std::cout << "There are " << not_available_books_count<< " not available books." << '\n';

    for (const Book& current_book : books)
      if (current_book.get_rent_status() == "Available")
        std::cout << current_book.get_title() <<  " - Available" << '\n';
      else 
        std::cout << current_book.get_title() <<  " - Not available" << '\n';
  } else
    std::cout << "The are no books in the libary" << "\n\n";
}