#include "Physics/Collision.hpp"
#include <cassert>
#include <cmath>

using namespace BBloc;

// ===== CircleCollider Tests =====

void TestCircleColliderConstruction() {
  CircleCollider circle(Vector2(100.0f, 50.0f), 25.0f);
  assert(circle.GetCenter().x == 100.0f);
  assert(circle.GetCenter().y == 50.0f);
  assert(circle.GetRadius() == 25.0f);
}

void TestCircleColliderContains() {
  CircleCollider circle(Vector2(0.0f, 0.0f), 10.0f);

  // Point at center
  assert(circle.Contains(Vector2(0.0f, 0.0f)));

  // Point inside
  assert(circle.Contains(Vector2(5.0f, 0.0f)));

  // Point outside
  assert(!circle.Contains(Vector2(15.0f, 0.0f)));
}

void TestCircleColliderGetBounds() {
  CircleCollider circle(Vector2(0.0f, 0.0f), 20.0f);
  Vector2 bounds = circle.GetBounds();
  assert(bounds.x == 40.0f && bounds.y == 40.0f);
}

// ===== RectangleCollider Tests =====

void TestRectangleColliderConstruction() {
  RectangleCollider rect(Vector2(10.0f, 20.0f), 100.0f, 50.0f);
  assert(rect.GetPosition().x == 10.0f);
  assert(rect.GetPosition().y == 20.0f);
  assert(rect.GetWidth() == 100.0f);
  assert(rect.GetHeight() == 50.0f);
}

void TestRectangleColliderContains() {
  RectangleCollider rect(Vector2(0.0f, 0.0f), 100.0f, 100.0f);

  // Point inside
  assert(rect.Contains(Vector2(50.0f, 50.0f)));

  // Point at corner
  assert(rect.Contains(Vector2(0.0f, 0.0f)));

  // Point outside
  assert(!rect.Contains(Vector2(150.0f, 50.0f)));
}

void TestRectangleColliderGetBounds() {
  RectangleCollider rect(Vector2(0.0f, 0.0f), 80.0f, 60.0f);
  Vector2 bounds = rect.GetBounds();
  assert(bounds.x == 80.0f && bounds.y == 60.0f);
}

// ===== Circle vs Circle Collision Tests =====

void TestCircleCircleCollisionOverlapping() {
  CircleCollider c1(Vector2(0.0f, 0.0f), 10.0f);
  CircleCollider c2(Vector2(15.0f, 0.0f), 10.0f); // Overlapping

  CollisionInfo info = CollisionDetector::CheckCollision(c1, c2);

  assert(info.isColliding);
  assert(info.penetrationDepth > 0.0f);
  assert(info.normal.Length() > 0.0f);
}

void TestCircleCircleCollisionTouching() {
  CircleCollider c1(Vector2(0.0f, 0.0f), 10.0f);
  CircleCollider c2(Vector2(20.0f, 0.0f), 10.0f); // Just touching

  CollisionInfo info = CollisionDetector::CheckCollision(c1, c2);

  assert(!info.isColliding);
}

void TestCircleCircleCollisionSeparated() {
  CircleCollider c1(Vector2(0.0f, 0.0f), 10.0f);
  CircleCollider c2(Vector2(30.0f, 0.0f), 10.0f); // Separated

  CollisionInfo info = CollisionDetector::CheckCollision(c1, c2);

  assert(!info.isColliding);
}

// ===== Rectangle vs Rectangle Collision Tests =====

void TestRectRectCollisionOverlapping() {
  RectangleCollider r1(Vector2(0.0f, 0.0f), 50.0f, 50.0f);
  RectangleCollider r2(Vector2(25.0f, 25.0f), 50.0f, 50.0f); // Overlapping

  CollisionInfo info = CollisionDetector::CheckCollision(r1, r2);

  assert(info.isColliding);
  assert(info.penetrationDepth > 0.0f);
}

void TestRectRectCollisionTouching() {
  RectangleCollider r1(Vector2(0.0f, 0.0f), 50.0f, 50.0f);
  RectangleCollider r2(Vector2(50.0f, 0.0f), 50.0f, 50.0f); // Just touching

  CollisionInfo info = CollisionDetector::CheckCollision(r1, r2);

  // When just touching (edge to edge), should NOT be colliding
  assert(!info.isColliding);
}

void TestRectRectCollisionSeparated() {
  RectangleCollider r1(Vector2(0.0f, 0.0f), 50.0f, 50.0f);
  RectangleCollider r2(Vector2(60.0f, 0.0f), 50.0f, 50.0f); // Separated

  CollisionInfo info = CollisionDetector::CheckCollision(r1, r2);

  assert(!info.isColliding);
}

// ===== Circle vs Rectangle Collision Tests =====

void TestCircleRectCollisionOverlapping() {
  CircleCollider circle(Vector2(25.0f, 25.0f), 20.0f);
  RectangleCollider rect(Vector2(0.0f, 0.0f), 50.0f, 50.0f);

  CollisionInfo info = CollisionDetector::CheckCollision(circle, rect);

  assert(info.isColliding);
}

void TestCircleRectCollisionOutside() {
  CircleCollider circle(Vector2(100.0f, 100.0f), 10.0f);
  RectangleCollider rect(Vector2(0.0f, 0.0f), 50.0f, 50.0f);

  CollisionInfo info = CollisionDetector::CheckCollision(circle, rect);

  assert(!info.isColliding);
}

void TestRectCircleCollisionReverse() {
  CircleCollider circle(Vector2(25.0f, 25.0f), 20.0f);
  RectangleCollider rect(Vector2(0.0f, 0.0f), 50.0f, 50.0f);

  CollisionInfo info1 = CollisionDetector::CheckCollision(circle, rect);
  CollisionInfo info2 = CollisionDetector::CheckCollision(rect, circle);

  assert(info1.isColliding && info2.isColliding);
  // Normals should be opposite
  assert(std::abs(info1.normal.x + info2.normal.x) < 0.01f);
  assert(std::abs(info1.normal.y + info2.normal.y) < 0.01f);
}

int main() {
  // CircleCollider tests
  TestCircleColliderConstruction();
  TestCircleColliderContains();
  TestCircleColliderGetBounds();

  // RectangleCollider tests
  TestRectangleColliderConstruction();
  TestRectangleColliderContains();
  TestRectangleColliderGetBounds();

  // Circle vs Circle tests
  TestCircleCircleCollisionOverlapping();
  TestCircleCircleCollisionTouching();
  TestCircleCircleCollisionSeparated();

  // Rectangle vs Rectangle tests
  TestRectRectCollisionOverlapping();
  TestRectRectCollisionTouching();
  TestRectRectCollisionSeparated();

  // Circle vs Rectangle tests
  TestCircleRectCollisionOverlapping();
  TestCircleRectCollisionOutside();
  TestRectCircleCollisionReverse();

  return 0;
}
