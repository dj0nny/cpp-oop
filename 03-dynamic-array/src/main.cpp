
#include <exception>
#include <iostream>
#include <utility>

#include "DynamicArray.hpp"

int main() {
  try {
    // 1. Construction
    DynamicArray first{5};

    for (std::size_t i{}; i < first.size(); ++i) {
      first[i] = static_cast<int>(i * 10);
    }

    // 2. Copy constructor
    DynamicArray second{first};

    second[0] = 999;

    std::cout << "First[0]: " << first[0] << '\n';
    std::cout << "Second[0]: " << second[0] << '\n';

    // 3. Copy assignment
    DynamicArray third{2};
    third = first;

    std::cout << "Third size: " << third.size() << '\n';

    // 4. Move constructor
    DynamicArray fourth{std::move(first)};

    std::cout << "Fourth size: " << fourth.size() << '\n';
    std::cout << "First size after move: " << first.size() << '\n';

    // 5. Move assignment
    DynamicArray fifth{3};
    fifth = std::move(second);

    std::cout << "Fifth size: " << fifth.size() << '\n';
    std::cout << "Second size after move: " << second.size() << '\n';

    // 6. Self-assignment
    third = third;

    // 7. Out-of-range access
    std::cout << fourth[10] << '\n';

  } catch (const std::exception& error) {
    std::cerr << "[ERROR] " << error.what() << '\n';
  }

  return 0;
}
