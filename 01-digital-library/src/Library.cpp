#include "Library.hpp"

#include <algorithm>

std::vector<Book>::iterator Library::find_iterator_by_isbn(const std::string& isbn) {
  return std::find_if(m_library_collection.begin(), m_library_collection.end(), [isbn](const Book& c_book) { return isbn == c_book.get_isbn(); });
}

bool Library::add_book(const Book& book) {
  auto match_book{[book](const Book& c_book) { return book.get_isbn() == c_book.get_isbn(); }};

  auto it{std::find_if(m_library_collection.begin(), m_library_collection.end(), match_book)};

  if (it != m_library_collection.end()) {
    return false;
  }

  m_library_collection.push_back(book);

  return true;
}

void Library::display_books() const {
  if (m_library_collection.empty()) {
    std::cout << "The library is empty.";
  } else {
    for (const auto& item : m_library_collection) {
      std::cout << item;
    }
  }
}

const Book* Library::find_book_by_isbn(const std::string& isbn) const {
  auto it{std::find_if(m_library_collection.begin(), m_library_collection.end(), [isbn](const Book& c_book) { return isbn == c_book.get_isbn(); })};

  if (it != m_library_collection.end()) {
    return &(*it);
  }

  return nullptr;
}

bool Library::borrow_book(const std::string& isbn) {
  auto it{find_iterator_by_isbn(isbn)};

  if (it != m_library_collection.end()) {
    if (it->borrow()) {
      return true;
    }
  }

  return false;
}

bool Library::return_book(const std::string& isbn) {
  auto it{find_iterator_by_isbn(isbn)};

  if (it != m_library_collection.end()) {
    if (it->return_book()) {
      return true;
    }
  }

  return false;
}