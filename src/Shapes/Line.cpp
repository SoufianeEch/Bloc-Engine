#include "Shapes/Line.hpp"
#include "Math/Vector2.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

namespace BBloc {
  Line::Line(Vector2 startPoint, Vector2 endPoint, float thickness)
    : Shape(startPoint), endPoint(endPoint), thickness(thickness) {}

  void Line::Render(sf::RenderWindow& window) {
      sf::RectangleShape line(sf::Vector2f((endPoint - position).Length(), thickness));
      line.setPosition(position.x, position.y);
      
      Vector2 direction = endPoint - position;
      float angle = std::atan2(direction.y, direction.x) * 180.0f / 3.14159f;
      line.setRotation(angle);
      
      line.setFillColor(sf::Color::White);
      window.draw(line);
  }

  Vector2 Line::GetBounds() const {
    Vector2 direction = endPoint - position;
    return Vector2(std::abs(direction.x), std::abs(direction.y));
  }

  float Line::GetLength() const { return (endPoint - position).Length(); }
  float Line::GetThickness() const { return thickness; }
}