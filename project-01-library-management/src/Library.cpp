#include <iostream>

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