#pragma once

#include "Math/Vector2.hpp"

namespace BBloc {

struct CollisionInfo {
  bool isColliding;
  Vector2 contactPoint;
  Vector2 normal;
  float penetrationDepth;

  CollisionInfo()
      : isColliding(false), contactPoint(0.0f, 0.0f), normal(0.0f, 0.0f),
        penetrationDepth(0.0f) {}
};

class Collider {
public:
  virtual ~Collider() = default;

  virtual bool Contains(const Vector2 &point) const = 0;
  virtual Vector2 GetBounds() const = 0;
};

class CircleCollider : public Collider {
public:
  CircleCollider(Vector2 center, float radius);

  bool Contains(const Vector2 &point) const override;
  Vector2 GetBounds() const override;

  Vector2 GetCenter() const;
  float GetRadius() const;

private:
  Vector2 m_Center;
  float m_Radius;
};

class RectangleCollider : public Collider {
public:
  RectangleCollider(Vector2 position, float width, float height);

  bool Contains(const Vector2 &point) const override;
  Vector2 GetBounds() const override;

  Vector2 GetPosition() const;
  float GetWidth() const;
  float GetHeight() const;

private:
  Vector2 m_Position;
  float m_Width;
  float m_Height;
};

class CollisionDetector {
public:
  // Circle vs Circle
  static CollisionInfo CheckCollision(const CircleCollider &c1,
                                      const CircleCollider &c2);

  // Rectangle vs Rectangle
  static CollisionInfo CheckCollision(const RectangleCollider &r1,
                                      const RectangleCollider &r2);

  // Circle vs Rectangle
  static CollisionInfo CheckCollision(const CircleCollider &circle,
                                      const RectangleCollider &rect);
  static CollisionInfo CheckCollision(const RectangleCollider &rect,
                                      const CircleCollider &circle);
};
} // namespace BBloc
