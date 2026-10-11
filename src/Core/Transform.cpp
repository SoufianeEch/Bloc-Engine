#include "Core/Transform.hpp"

namespace BBloc {

Transform::Transform(Vector2 position, float rotation, Vector2 scale)
    : m_Position(position), m_Rotation(rotation), m_Scale(scale) {}

Vector2 Transform::GetPosition() const { return m_Position; }

float Transform::GetRotation() const { return m_Rotation; }

Vector2 Transform::GetScale() const { return m_Scale; }

void Transform::SetPosition(const Vector2 &position) { m_Position = position; }

void Transform::SetRotation(float rotation) { m_Rotation = rotation; }

void Transform::SetScale(const Vector2 &scale) { m_Scale = scale; }

void Transform::Translate(const Vector2 &offset) {
  m_Position = m_Position + offset;
}

void Transform::Rotate(float angle) { m_Rotation += angle; }
} // namespace BBloc
