#pragma once

#include "Math/Vector2.hpp"
#include <SFML/Graphics.hpp>

namespace BBloc {

class GameObject; // Forward declaration

class Component {
public:
  virtual ~Component() = default;

  virtual void OnCreate() {}
  virtual void Update(float deltaTime) {}
  virtual void Render(sf::RenderWindow &window) {}
  virtual void OnDestroy() {}

  GameObject *GetGameObject() const;

protected:
  friend class GameObject;
  GameObject *m_GameObject = nullptr;
};
} // namespace BBloc
