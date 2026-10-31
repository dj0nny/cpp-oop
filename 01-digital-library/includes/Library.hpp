#pragma once

#include <vector>

#include "Book.hpp"

class Library {
 private:
  std::vector<Book> m_library_collection{};

  std::vector<Book>::iterator find_iterator_by_isbn(const std::string& isbn);

 public:
  Library() = default;

  bool add_book(const Book& book);
  void display_books() const;
  const Book* find_book_by_isbn(const std::string& isbn) const;
  bool borrow_book(const std::string& isbn);
  bool return_book(const std::string& isbn);
};