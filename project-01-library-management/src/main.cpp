#include <iostream>
#include <stdexcept>

#include "Library.hpp"
#include "utils.hpp"

int main() {
  try {
    Library my_library;

    while (true) {
      int menu_choice {menu_selection()};
      handle_menu_selection(menu_choice, my_library);
    }

  } catch (const std::exception& error) {
    
  }

  return 0;
}