#include "Physics/Rigidbody.hpp"

namespace BBloc {

  Rigidbody::Rigidbody(float mass, bool useGravity)
      : m_Mass(mass), m_Velocity(0.0f, 0.0f), m_Acceleration(0.0f, 0.0f),
        m_Position(0.0f, 0.0f), m_Force(0.0f, 0.0f), m_UseGravity(useGravity) {}
  
  void Rigidbody::Update(float deltaTime) {
    // Apply gravity if enabled
    if (m_UseGravity) {
      m_Force = m_Force + Vector2(0.0f, m_Mass * GRAVITY);
    }
  
    // Calculate acceleration from force: F = ma => a = F/m
    m_Acceleration = m_Force * (1.0f / m_Mass);
  
    // Update velocity: v = v + a*t
    m_Velocity = m_Velocity + (m_Acceleration * deltaTime);
  
    // Update position: p = p + v*t
    m_Position = m_Position + (m_Velocity * deltaTime);
  
    // Clear forces for next frame
    m_Force = Vector2(0.0f, 0.0f);
  }
  
  void Rigidbody::ApplyForce(const Vector2 &force) { m_Force = m_Force + force; }
  
  void Rigidbody::ApplyAcceleration(const Vector2 &acceleration) {
    m_Acceleration = m_Acceleration + acceleration;
  }
  
  float Rigidbody::GetMass() const { return m_Mass; }
  
  Vector2 Rigidbody::GetVelocity() const { return m_Velocity; }
  
  Vector2 Rigidbody::GetAcceleration() const { return m_Acceleration; }
  
  Vector2 Rigidbody::GetPosition() const { return m_Position; }
  
  bool Rigidbody::IsUsingGravity() const { return m_UseGravity; }
  
  void Rigidbody::SetMass(float mass) { m_Mass = mass; }
  
  void Rigidbody::SetVelocity(const Vector2 &velocity) { m_Velocity = velocity; }
  
  void Rigidbody::SetAcceleration(const Vector2 &acceleration) {
    m_Acceleration = acceleration;
  }
  
  void Rigidbody::SetPosition(const Vector2 &position) { m_Position = position; }
  
  void Rigidbody::SetUseGravity(bool useGravity) { m_UseGravity = useGravity; }

}
