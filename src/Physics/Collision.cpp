#include "Physics/Collision.hpp"
#include <algorithm>
#include <cmath>

namespace BBloc {

// ===== CircleCollider =====

CircleCollider::CircleCollider(Vector2 center, float radius)
    : m_Center(center), m_Radius(radius) {}

bool CircleCollider::Contains(const Vector2 &point) const {
  Vector2 diff = point - m_Center;
  return diff.Length() <= m_Radius;
}

Vector2 CircleCollider::GetBounds() const {
  return Vector2(m_Radius * 2.0f, m_Radius * 2.0f);
}

Vector2 CircleCollider::GetCenter() const { return m_Center; }

float CircleCollider::GetRadius() const { return m_Radius; }

// ===== RectangleCollider =====

RectangleCollider::RectangleCollider(Vector2 position, float width,
                                     float height)
    : m_Position(position), m_Width(width), m_Height(height) {}

bool RectangleCollider::Contains(const Vector2 &point) const {
  return point.x >= m_Position.x && point.x <= m_Position.x + m_Width &&
         point.y >= m_Position.y && point.y <= m_Position.y + m_Height;
}

Vector2 RectangleCollider::GetBounds() const {
  return Vector2(m_Width, m_Height);
}

Vector2 RectangleCollider::GetPosition() const { return m_Position; }

float RectangleCollider::GetWidth() const { return m_Width; }

float RectangleCollider::GetHeight() const { return m_Height; }

// ===== CollisionDetector =====

// Circle vs Circle
CollisionInfo CollisionDetector::CheckCollision(const CircleCollider &c1,
                                                const CircleCollider &c2) {
  CollisionInfo info;

  Vector2 diff = c2.GetCenter() - c1.GetCenter();
  float distance = diff.Length();
  float minDistance = c1.GetRadius() + c2.GetRadius();

  if (distance < minDistance) {
    info.isColliding = true;

    // Contact point (midpoint between centers)
    info.contactPoint = c1.GetCenter() + (diff.Normalize() * c1.GetRadius());

    // Normal (direction from c1 to c2)
    info.normal = (distance > 0.0f) ? diff.Normalize() : Vector2(1.0f, 0.0f);

    // Penetration depth
    info.penetrationDepth = minDistance - distance;
  }

  return info;
}

// Rectangle vs Rectangle (AABB - Axis-Aligned Bounding Box)
CollisionInfo CollisionDetector::CheckCollision(const RectangleCollider &r1,
                                                const RectangleCollider &r2) {
  CollisionInfo info;

  Vector2 pos1 = r1.GetPosition();
  Vector2 pos2 = r2.GetPosition();
  float w1 = r1.GetWidth();
  float h1 = r1.GetHeight();
  float w2 = r2.GetWidth();
  float h2 = r2.GetHeight();

  // Check if rectangles overlap
  bool overlapX = pos1.x < pos2.x + w2 && pos1.x + w1 > pos2.x;
  bool overlapY = pos1.y < pos2.y + h2 && pos1.y + h1 > pos2.y;

  if (overlapX && overlapY) {
    info.isColliding = true;

    // Calculate penetration on each axis
    float overlapLeft = (pos1.x + w1) - pos2.x;
    float overlapRight = (pos2.x + w2) - pos1.x;
    float overlapTop = (pos1.y + h1) - pos2.y;
    float overlapBottom = (pos2.y + h2) - pos1.y;

    // Find minimum overlap
    float minOverlap =
        std::min({overlapLeft, overlapRight, overlapTop, overlapBottom});

    // Determine normal based on which side has minimum overlap
    if (minOverlap == overlapLeft) {
      info.normal = Vector2(-1.0f, 0.0f);
      info.penetrationDepth = overlapLeft;
    } else if (minOverlap == overlapRight) {
      info.normal = Vector2(1.0f, 0.0f);
      info.penetrationDepth = overlapRight;
    } else if (minOverlap == overlapTop) {
      info.normal = Vector2(0.0f, -1.0f);
      info.penetrationDepth = overlapTop;
    } else {
      info.normal = Vector2(0.0f, 1.0f);
      info.penetrationDepth = overlapBottom;
    }

    // Contact point (center of overlap region)
    float contactX =
        std::max(pos1.x, pos2.x) + std::min(overlapLeft, overlapRight) / 2.0f;
    float contactY =
        std::max(pos1.y, pos2.y) + std::min(overlapTop, overlapBottom) / 2.0f;
    info.contactPoint = Vector2(contactX, contactY);
  }

  return info;
}

// Circle vs Rectangle
CollisionInfo CollisionDetector::CheckCollision(const CircleCollider &circle,
                                                const RectangleCollider &rect) {
  CollisionInfo info;

  Vector2 circleCenter = circle.GetCenter();
  float radius = circle.GetRadius();

  Vector2 rectPos = rect.GetPosition();
  float rectW = rect.GetWidth();
  float rectH = rect.GetHeight();

  // Find closest point on rectangle to circle center
  float closestX =
      std::max(rectPos.x, std::min(circleCenter.x, rectPos.x + rectW));
  float closestY =
      std::max(rectPos.y, std::min(circleCenter.y, rectPos.y + rectH));

  Vector2 closestPoint(closestX, closestY);
  Vector2 diff = circleCenter - closestPoint;
  float distance = diff.Length();

  if (distance < radius) {
    info.isColliding = true;
    info.contactPoint = closestPoint;
    info.normal = (distance > 0.0f) ? diff.Normalize() : Vector2(1.0f, 0.0f);
    info.penetrationDepth = radius - distance;
  }

  return info;
}

// Rectangle vs Circle (reverse of above)
CollisionInfo CollisionDetector::CheckCollision(const RectangleCollider &rect,
                                                const CircleCollider &circle) {
  CollisionInfo info = CheckCollision(circle, rect);
  info.normal = info.normal * -1.0f; // Reverse normal
  return info;
}

} // namespace BBloc
