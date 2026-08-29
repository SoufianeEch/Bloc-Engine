#include "Math/Vector2.hpp"
#include <cmath>

namespace BBloc {
  // Constructor
  Vector2::Vector2(float x, float y) : x(x), y(y) {}

  // Operation
  Vector2 Vector2::operator+(const Vector2& other) const {
    return Vector2(x + other.x, y + other.y);
  }
  Vector2 Vector2::operator-(const Vector2& other) const {
    return Vector2(x - other.x, y - other.y);
  }
  Vector2 Vector2::operator*(float scalar) const {
    return Vector2(x * scalar, y * scalar);
  }

  // Methods
  float Vector2::Length() const { return std::sqrt(x * x + y * y); }
  Vector2 Vector2::Normalize() const {
    float len = Length();
    if (len == 0.0f) return Vector2(0.0f, 0.0f);
    return Vector2(x / len, y / len);
  }
  float Vector2::DotProduct(const Vector2& other) const {
    return x * other.x + y * other.y;
  }
};