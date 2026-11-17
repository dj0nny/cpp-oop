#pragma once

#include <memory>
#include <vector>

#include "GameObject.hpp"

class Scene {
 private:
  std::vector<std::unique_ptr<GameObject>> m_object{};

 public:
  void add_object(std::unique_ptr<GameObject>);
  void remove_object(std::size_t);
  void display_objects() const;
};