#include "DynamicArray.hpp"

#include <stdexcept>

DynamicArray::DynamicArray(std::size_t size) : m_data{new int[size]{}}, m_size{size} {}

DynamicArray::~DynamicArray() { delete[] m_data; }

DynamicArray::DynamicArray(const DynamicArray& other) : m_data{m_data = new int[other.m_size]}, m_size{other.m_size} {
  for (std::size_t idx{0}; idx < m_size; ++idx) {
    m_data[idx] = other.m_data[idx];
  }
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
  if (this == &other) {
    return *this;
  }

  int* temp_m_data{new int[other.m_size]};

  for (std::size_t idx{0}; idx < other.m_size; ++idx) {
    temp_m_data[idx] = other.m_data[idx];
  }

  delete[] m_data;

  m_size = other.m_size;
  m_data = temp_m_data;

  return *this;
}

DynamicArray::DynamicArray(DynamicArray&& other) noexcept : m_data{other.m_data}, m_size{other.m_size} {
  other.m_data = nullptr;
  other.m_size = 0;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& other) noexcept {
  if (this == &other) {
    return *this;
  }

  delete[] m_data;

  m_data = other.m_data;
  m_size = other.m_size;

  other.m_data = nullptr;
  other.m_size = 0;

  return *this;
}

int& DynamicArray::operator[](std::size_t index) {
  if (index >= m_size) {
    throw std::out_of_range{"The array is empty"};
  }

  return m_data[index];
}
const int& DynamicArray::operator[](std::size_t index) const {
  if (index >= m_size) {
    throw std::out_of_range{"The array is empty"};
  }

  return m_data[index];
}

std::size_t DynamicArray::size() const { return m_size; }
bool DynamicArray::empty() const { return m_size == 0; }