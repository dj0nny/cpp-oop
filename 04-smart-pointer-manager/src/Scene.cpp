#include "Scene.hpp"

#include <cstddef>
#include <iostream>

void Scene::add_object(std::unique_ptr<GameObject> p_game_object) { m_objects.push_back(p_game_object); }

void Scene::remove_object(int index) {
  if (m_objects.empty()) {
    std::cout << "The scene is empty.";
    return;
  }

  if (index < 0 || index >= m_objects.size()) {
    std::cout << "The index is not valid" << '\n';
    return;
  }

  auto iterator_index{static_cast<std::ptrdiff_t>(index)};
  m_objects.erase(m_objects.begin() + iterator_index);

  std::cout << "Object removed from the scene." << '\n';
}

void Scene::display_objects() const {
  std::cout << "Objects currently active in the scene:" << '\n';

  for (const auto& object : m_objects) {
    object->display_status();
    std::cout << '\n';
  }
}