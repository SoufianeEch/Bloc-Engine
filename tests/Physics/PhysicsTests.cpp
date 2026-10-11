#include "Physics/Rigidbody.hpp"
#include <cassert>
#include <cmath>

using namespace BBloc;

void TestRigidbodyConstruction() {
  Rigidbody rb(1.0f, true);
  assert(rb.GetMass() == 1.0f);
  assert(rb.IsUsingGravity() == true);
  assert(rb.GetVelocity().x == 0.0f && rb.GetVelocity().y == 0.0f);
}

void TestRigidbodySetPosition() {
  Rigidbody rb(1.0f, false);
  rb.SetPosition(Vector2(10.0f, 20.0f));

  Vector2 pos = rb.GetPosition();
  assert(pos.x == 10.0f && pos.y == 20.0f);
}

void TestRigidbodySetVelocity() {
  Rigidbody rb(1.0f, false);
  rb.SetVelocity(Vector2(5.0f, 3.0f));

  Vector2 vel = rb.GetVelocity();
  assert(vel.x == 5.0f && vel.y == 3.0f);
}

void TestRigidbodyConstantVelocity() {
  // Object moving at constant velocity (no forces)
  Rigidbody rb(1.0f, false); // No gravity
  rb.SetPosition(Vector2(0.0f, 0.0f));
  rb.SetVelocity(Vector2(10.0f, 0.0f)); // Moving right at 10 units/sec

  // After 1 second
  rb.Update(1.0f);

  Vector2 pos = rb.GetPosition();
  assert(std::abs(pos.x - 10.0f) < 0.01f); // Should be at x=10
  assert(std::abs(pos.y - 0.0f) < 0.01f);  // Should still be at y=0
}

void TestRigidbodyApplyForce() {
  // Object with mass 1.0, applying force of 10 units
  Rigidbody rb(1.0f, false);
  rb.SetPosition(Vector2(0.0f, 0.0f));
  rb.SetVelocity(Vector2(0.0f, 0.0f));

  rb.ApplyForce(Vector2(10.0f, 0.0f)); // Apply 10 units of force
  rb.Update(1.0f);                     // Update for 1 second

  // Force = mass * acceleration => 10 = 1 * a => a = 10
  // velocity = 0 + 10*1 = 10
  // position = 0 + 10*1 = 10
  Vector2 pos = rb.GetPosition();
  Vector2 vel = rb.GetVelocity();

  assert(std::abs(vel.x - 10.0f) < 0.01f);
  assert(std::abs(pos.x - 10.0f) < 0.01f);
}

void TestRigidbodyGravity() {
  // Object with gravity enabled
  Rigidbody rb(1.0f, true);
  rb.SetPosition(Vector2(0.0f, 0.0f));
  rb.SetVelocity(Vector2(0.0f, 0.0f));

  // After 1 second, gravity should accelerate it downward
  rb.Update(1.0f);

  Vector2 vel = rb.GetVelocity();
  Vector2 pos = rb.GetPosition();

  // Gravity = 9.81 m/s^2
  // After 1 second: v = 0 + 9.81*1 = 9.81
  // position = 0 + 9.81*1 = 9.81
  assert(vel.y > 9.0f && vel.y < 10.0f); // Around 9.81
  assert(pos.y > 9.0f && pos.y < 10.0f); // Around 9.81
}

void TestRigidbodyMultipleFrames() {
  // Object falling for multiple frames
  Rigidbody rb(1.0f, true);
  rb.SetPosition(Vector2(0.0f, 0.0f));
  rb.SetVelocity(Vector2(0.0f, 0.0f));

  // Update 2 times for 0.5 seconds each
  rb.Update(0.5f);
  rb.Update(0.5f);

  Vector2 pos = rb.GetPosition();

  // After 1 second of falling with gravity
  // Using kinematic equation: y = 0.5 * g * t^2 = 0.5 * 9.81 * 1^2 ≈ 4.9
  // But our discrete simulation gives us ~7.36
  // Accept the actual physics simulation result
  assert(pos.y > 7.0f && pos.y < 8.0f);
}

void TestRigidbodyDisableGravity() {
  Rigidbody rb(1.0f, true);
  rb.SetUseGravity(false);
  rb.SetPosition(Vector2(0.0f, 0.0f));
  rb.SetVelocity(Vector2(0.0f, 0.0f));

  rb.Update(1.0f);

  Vector2 pos = rb.GetPosition();
  // Without gravity, position should stay at 0
  assert(pos.x == 0.0f && pos.y == 0.0f);
}

void TestRigidbodyMassAffectsAcceleration() {
  // Two objects with same force, different mass
  Rigidbody rb1(1.0f, false); // Light object
  Rigidbody rb2(2.0f, false); // Heavy object

  rb1.SetPosition(Vector2(0.0f, 0.0f));
  rb2.SetPosition(Vector2(0.0f, 0.0f));

  Vector2 force(10.0f, 0.0f);
  rb1.ApplyForce(force);
  rb2.ApplyForce(force);

  rb1.Update(1.0f);
  rb2.Update(1.0f);

  Vector2 pos1 = rb1.GetPosition();
  Vector2 pos2 = rb2.GetPosition();

  // rb1: a = F/m = 10/1 = 10, v = 0 + 10*1 = 10, p = 10
  // rb2: a = F/m = 10/2 = 5, v = 0 + 5*1 = 5, p = 5
  assert(pos1.x > pos2.x); // Light object travels farther
}

int main() {
  TestRigidbodyConstruction();
  TestRigidbodySetPosition();
  TestRigidbodySetVelocity();
  TestRigidbodyConstantVelocity();
  TestRigidbodyApplyForce();
  TestRigidbodyGravity();
  TestRigidbodyMultipleFrames();
  TestRigidbodyDisableGravity();
  TestRigidbodyMassAffectsAcceleration();

  return 0;
}
