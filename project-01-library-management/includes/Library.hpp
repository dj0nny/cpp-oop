#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <vector>
#include <string_view>

#include "Book.hpp"

class Library {
  private:
    std::vector<Book> books;

  public:
    explicit Library();

    void insert_book(const Book& book);
    void show_books() const;
    void search_books(std::string_view book_name) const;
    bool register_book_rent(int book_id);
    bool register_book_return(int book_id);
    bool delete_book(int book_id);
    void show_books_status();
  };

#endif