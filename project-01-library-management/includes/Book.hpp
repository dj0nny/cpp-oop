#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <string>
#include <string_view>

#include "BookStatus.hpp"

class Book {
  private:
    int id;
    std::string title;
    std::string author;
    int year;
    BookStatus rent_status;

    int generate_book_id() const;
  public:
    explicit Book(std::string_view book_title, std::string_view book_author, int book_year, BookStatus book_rent_status);

    int get_id() const;
    std::string_view get_title() const;
    std::string_view get_author() const;
    int get_year() const;
    std::string_view get_rent_status() const;
};
  
std::ostream& operator<<(std::ostream& os, const Book& book);

#endif