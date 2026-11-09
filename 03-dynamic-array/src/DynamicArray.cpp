#include "DynamicArray.hpp"

DynamicArray::DynamicArray(std::size_t size) : m_data{new int[size]}, m_size{size} {}

DynamicArray::~DynamicArray() { delete[] m_data; }

std::size_t DynamicArray::size() const { return m_size; }
bool DynamicArray::empty() const { return m_size == 0; }