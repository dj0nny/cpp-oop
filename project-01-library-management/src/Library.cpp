#include <iostream>
#include <algorithm>

#include "Book.hpp"
#include "Library.hpp"

Library::Library() {}

void Library::insert_book(const Book& book) {
  books.push_back(book);
}

void Library::show_books() const {
  if (!books.empty()) {
    for (const Book& current_book : books)
      std::cout << current_book << '\n';
  } else
    std::cout << "The are no books in the library" << "\n\n";
}

bool Library::delete_book(int book_id) {
  if (!books.empty()) {
    auto delete_item_iterator {std::find_if(books.begin(), books.end(), [book_id](const Book& current_book) {
      return book_id == current_book.get_id();
    })};

    if (delete_item_iterator != books.end()) {
      books.erase(delete_item_iterator);
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