#include "Shapes/Triangle.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>

namespace BBloc {
  Triangle::Triangle(Vector2 position, Vector2 p1, Vector2 p2, Vector2 p3)
    : Shape(position), scale(1.0f) {
      points[0] = p1;
      points[1] = p2;
      points[2] = p3;
    }

    void Triangle::Render(sf::RenderWindow& window) {
        sf::ConvexShape triangle(3);
        for (int i = 0; i < 3; ++i) {
            triangle.setPoint(i, sf::Vector2f(points[i].x * scale, points[i].y * scale));
        }
        triangle.setPosition(position.x, position.y);
        triangle.setFillColor(sf::Color::White);
        window.draw(triangle);
    }

  Vector2 Triangle::GetBounds() const {
    // Find max x and y for all three points
    float minX = std::min({points[0].x, points[1].x, points[2].x});
    float maxX = std::max({points[0].x, points[1].x, points[2].x});
    float maxY = std::max({points[0].y, points[1].y, points[2].y});
    float minY = std::min({points[0].x, points[1].x, points[2].x});

    float width = (maxX - minX) * scale;
    float height = (maxY - minY) * scale;
    
    return Vector2(width, height);
  }

  void Triangle::SetScale(float scale) { this->scale = scale; }

  float Triangle::GetScale() const { return scale; }
}