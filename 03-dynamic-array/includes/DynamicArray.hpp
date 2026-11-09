#pragma once

#include <cstddef>

class DynamicArray {
 private:
  int* m_data{};
  std::size_t m_size{};

 public:
  explicit DynamicArray(std::size_t);

  ~DynamicArray();

  DynamicArray(const DynamicArray&);
  DynamicArray& operator=(const DynamicArray&);

  DynamicArray(DynamicArray&&) noexcept;
  DynamicArray& operator=(DynamicArray&&) noexcept;

  int& operator[](std::size_t);
  const int& operator[](std::size_t) const;

  std::size_t size() const;
  bool empty() const;
};