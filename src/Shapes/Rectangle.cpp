#include "Shapes/Rectangle.hpp"
#include  <SFML/Graphics.hpp>

namespace BBloc {
  Rectangle::Rectangle(Vector2 position, float width, float height)
    : Shape(position), width(width), height(height) {}

  void Rectangle::Render(sf::RenderWindow& window) {
    sf::RectangleShape rect(sf::Vector2f(width, height)); // TODO: replace sf::Vec by my own custom one
    rect.setPosition(position.x, position.y);
    rect.setFillColor(sf::Color::White);

    // Window Ref to runder for rendering
  }

  Vector2 Rectangle::GetBounds() const { return Vector2(width, height); }
  float Rectangle::GetWidth() const { return width; }
  float Rectangle::GetHeight() const { return height; }
}