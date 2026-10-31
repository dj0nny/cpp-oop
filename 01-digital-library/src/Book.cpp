#include "Book.hpp"

#include <utility>

Book::Book(const std::string& title, const std::string& author, const std::string& isbn, bool available)
    : m_title{std::move(title)}, m_author{std::move(author)}, m_isbn{std::move(isbn)}, m_available{available} {}

const std::string& Book::get_title() const { return m_title; }

const std::string& Book::get_author() const { return m_author; }

const std::string& Book::get_isbn() const { return m_isbn; }

bool Book::get_book_availability() const { return m_available; }

bool Book::borrow() {
  if (m_available) {
    m_available = false;

    return true;
  }

  return false;
}

bool Book::return_book() {
  if (!m_available) {
    m_available = true;

    return true;
  }

  return false;
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
  os << "Title: " << book.m_title << " | Author: " << book.m_author << " | ISBN: " << book.m_isbn << " | Available: " << std::boolalpha << book.m_available << std::noboolalpha << '\n';

  return os;
}