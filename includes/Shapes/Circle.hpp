#pragma once

#include "Shapes/Shape.hpp"

namespace BBloc {
  class Circle : public Shape {
    public:
      Circle(Vector2 position, float radius);

      void Render(sf::RenderWindow& window) override;
      Vector2 GetBounds() const override;

      float GetRadius() const;

    private:
      float radius;
  };
}