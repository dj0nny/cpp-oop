#include <stdexcept>

#include "Book.hpp"
#include "Library.hpp"
#include "Menu.hpp"

int main() {
  try {
    Library my_library{};
    bool exit{};

    while (!exit) {
      int choice{handle_menu()};
      exit = handle_menu_choice(choice, my_library);
    }
  } catch (const std::runtime_error& error) {
    std::cerr << "[ERROR] " << error.what() << '\n';
  }
  return 0;
}