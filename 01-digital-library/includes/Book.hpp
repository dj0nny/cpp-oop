#pragma once

#include <iostream>
#include <string>
#include <utility>

class Book {
 private:
  std::string m_title{};
  std::string m_author{};
  std::string m_isbn{};
  bool m_available{};

 public:
  Book() = default;

  Book(const std::string& title, const std::string& author, const std::string& isbn, bool available);

  const std::string& get_title() const;
  const std::string& get_author() const;
  const std::string& get_isbn() const;
  bool get_book_availability() const;

  bool borrow();
  bool return_book();
  void display_info();

  friend std::ostream& operator<<(std::ostream& os, const Book& book);
};