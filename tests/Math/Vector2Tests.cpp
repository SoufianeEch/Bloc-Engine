#include "Math/Vector2.hpp"
#include <cassert>
#include <cmath>

using namespace BBloc;

void TestVector2Construction() {
  Vector2 v1;
  assert(v1.x == 0.0f && v1.y == 0.0f);

  Vector2 v2(5.0f, 3.0f);
  assert(v2.x == 5.0f && v2.y == 3.0f);
}

void TestVector2Addition() {
  Vector2 v1(2.0f, 3.0f);
  Vector2 v2(4.0f, 1.0f);
  Vector2 result = v1 + v2;

  assert(result.x == 6.0f && result.y == 4.0f);
}

void TestVector2Subtraction() {
  Vector2 v1(5.0f, 7.0f);
  Vector2 v2(2.0f, 3.0f);
  Vector2 result = v1 - v2;

  assert(result.x == 3.0f && result.y == 4.0f);
}

void TestVector2ScalarMultiplication() {
  Vector2 v(2.0f, 3.0f);
  Vector2 result = v * 2.0f;

  assert(result.x == 4.0f && result.y == 6.0f);
}

void TestVector2Length() {
  Vector2 v(3.0f, 4.0f);
  float len = v.Length();

  assert(len == 5.0f);
}

void TestVector2Normalization() {
  Vector2 v(3.0f, 4.0f);
  Vector2 normalized = v.Normalize();

  assert(std::abs(normalized.x - 0.6f) < 0.001f);
  assert(std::abs(normalized.y - 0.8f) < 0.001f);
}

void TestVector2DotProduct() {
  Vector2 v1(2.0f, 3.0f);
  Vector2 v2(4.0f, 5.0f);
  float dot = v1.DotProduct(v2);

  assert(dot == 23.0f); // (2*4) + (3*5) = 8 + 15 = 23
}

int main() {
  TestVector2Construction();
  TestVector2Addition();
  TestVector2Subtraction();
  TestVector2ScalarMultiplication();
  TestVector2Length();
  TestVector2Normalization();
  TestVector2DotProduct();

  return 0;
}
