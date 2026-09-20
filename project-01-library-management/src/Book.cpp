#include <iostream>
#include <string_view>

#include "Book.hpp"
#include "utils.hpp"

Book::Book(std::string_view book_title, std::string_view book_author, int book_year, BookStatus book_rent_status)
  : id {generate_book_id()}, title {book_title}, author {book_author}, year {book_year}, rent_status {book_rent_status}
  {};

int Book::generate_book_id() const {
  static int id {0};

  return ++id;
}

int Book::get_id() const {
  return id;
}

std::string_view Book::get_title() const {
  return title;
}

std::string_view Book::get_author() const {
  return author;
}

int Book::get_year() const {
  return year;
}

std::string_view Book::get_rent_status() const {
  return to_string_rent_status(rent_status);
}

BookStatus Book::get_rent_status_code() const {
  return rent_status;
}

void Book::set_as_borrowed() {
  rent_status = BookStatus::NotAvailable;
};

void Book::set_as_not_borrowed() {
  rent_status = BookStatus::Available;
};

std::ostream& operator<<(std::ostream& os, const Book& book) {
  return os << book.get_id() << ", " << book.get_title() << ", " << book.get_author() << ", " << book.get_year() << ", " << book.get_rent_status();
}

