#include "GameObject.hpp"

#include <utility>

GameObject::GameObject(const std::string& name) : m_name{std::move(name)} {}

const std::string& GameObject::get_name() const { return m_name; }

GameObject::~GameObject() {}