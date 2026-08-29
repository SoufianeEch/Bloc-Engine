#pragma once

#include "Shapes/Shape.hpp"

namespace BBloc {
  class Line : public Shape {
    public:
      Line(Vector2 startPoint, Vector2 endPoint, float thickness);

      void Render(sf::RenderWindow& window) override;
      Vector2 GetBounds() const override;

      float GetLength() const;
      float GetThickness() const;

    private:
      Vector2 endPoint;
      float thickness;
  };
}