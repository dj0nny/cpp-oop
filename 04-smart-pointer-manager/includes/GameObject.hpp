#pragma once

#include <string>

class GameObject {
 private:
  std::string m_name{};

 public:
  GameObject(const std::string& name);

  const std::string& get_name() const;

  virtual void display_status() const = 0;
  virtual ~GameObject();
};