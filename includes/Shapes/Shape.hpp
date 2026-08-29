#pragma once

#include "Math/Vector2.hpp"
#include <SFML/Graphics.hpp>

namespace BBloc {
  class Shape {
    public:
      virtual ~Shape() = default;

      // Pure virual methods
      virtual void Render(sf::RenderWindow& window) = 0;
      virtual Vector2 GetBounds() const = 0;

    protected:
      Vector2 position;
      Shape(Vector2 pos) : position(pos) {}
  };
}