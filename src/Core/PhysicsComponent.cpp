#include "Core/PhysicsComponent.hpp"
#include "Core/GameObject.hpp"
#include "Core/Transform.hpp"

namespace BBloc {

PhysicsComponent::PhysicsComponent(float mass, bool useGravity)
    : m_Rigidbody(mass, useGravity) {}

void PhysicsComponent::Update(float deltaTime) {
  // Sync transform position to rigidbody before update
  if (auto gameObject = GetGameObject()) {
    if (auto transform = gameObject->GetComponent<Transform>()) {
      m_Rigidbody.SetPosition(transform->GetPosition());
    }
  }

  // Update rigidbody physics
  m_Rigidbody.Update(deltaTime);

  // Sync rigidbody position back to transform
  if (auto gameObject = GetGameObject()) {
    if (auto transform = gameObject->GetComponent<Transform>()) {
      transform->SetPosition(m_Rigidbody.GetPosition());
    }
  }
}

Rigidbody &PhysicsComponent::GetRigidbody() { return m_Rigidbody; }

const Rigidbody &PhysicsComponent::GetRigidbody() const { return m_Rigidbody; }

void PhysicsComponent::SetCollider(std::shared_ptr<Collider> collider) {
  m_Collider = collider;
}

std::shared_ptr<Collider> PhysicsComponent::GetCollider() const {
  return m_Collider;
}
} // namespace BBloc
