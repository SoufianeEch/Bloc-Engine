#include "Shapes/Circle.hpp"
#include <SFML/Graphics.hpp>

namespace BBloc {
Circle::Circle(Vector2 position, float radius)
    : Shape(position), radius(radius) {}

void Circle::Render(sf::RenderWindow &window) {
  sf::CircleShape circle(radius);
  circle.setPosition(position.x, position.y);
  circle.setFillColor(sf::Color::White);
  window.draw(circle);
}

Vector2 Circle::GetBounds() const { return Vector2(radius * 2, radius * 2); }
float Circle::GetRadius() const { return radius; }
} // namespace BBloc
