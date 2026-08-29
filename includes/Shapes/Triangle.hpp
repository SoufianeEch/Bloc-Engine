#pragma once

#include "Shapes/Shape.hpp"

namespace BBloc {
  class Triangle : public Shape {
    public:
      Triangle(Vector2 position, Vector2 p1, Vector2 p2, Vector2 p3);
  
      void Render(sf::RenderWindow& window) override;
      Vector2 GetBounds() const override;
  
      void SetScale(float scale);
      float GetScale() const;

    private:
      Vector2 points[3];
      float scale;
  };
}