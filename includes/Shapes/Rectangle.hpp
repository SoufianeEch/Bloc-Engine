#pragma once

#include "Shapes/Shape.hpp"

namespace BBloc {
  class Rectangle : public Shape {
    public:
      Rectangle(Vector2 position, float width, float height);

      void Render(sf::RenderWindow& window) override;
      Vector2 GetBounds() const override;

      float GetWidth() const;
      float GetHeight() const;

    private:
      float width;
      float height;
  };
}