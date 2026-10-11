#include "Core/Sprite.hpp"
#include "Core/GameObject.hpp"
#include "Core/Transform.hpp"
#include "Shapes/Circle.hpp"
#include <SFML/Graphics.hpp>

namespace BBloc {

Sprite::Sprite(std::shared_ptr<Shape> shape) : m_Shape(shape) {}

void Sprite::Render(sf::RenderWindow &window) {
  if (!m_Shape || !m_GameObject)
    return;

  auto transform = m_GameObject->GetComponent<Transform>();
  if (!transform)
    return;

  m_Shape->Render(window);
}

std::shared_ptr<Shape> Sprite::GetShape() const { return m_Shape; }

void Sprite::SetShape(std::shared_ptr<Shape> shape) { m_Shape = shape; }
} // namespace BBloc
