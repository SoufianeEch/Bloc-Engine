#pragma once

namespace BBloc {
  class Vector2 {
    public:
      float x;
      float y;

      // Constructor
      Vector2(float x = 0.0f, float y = 0.0f);

      // Operator
      Vector2 operator+(const Vector2& other) const;
      Vector2 operator-(const Vector2& other) const;
      Vector2 operator*(float scalar) const;

      // Methods
      float Length() const;
      Vector2 Normalize() const;
      float DotProduct(const Vector2& other) const;
  };
}