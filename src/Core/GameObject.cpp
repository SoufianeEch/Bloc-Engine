#include "Core/GameObject.hpp"
#include "Core/Transform.hpp"
#include <SFML/Graphics.hpp>

namespace BBloc {

GameObject::GameObject(const std::string &name) : m_Name(name), m_Active(true) {
  m_Transform = AddComponent<Transform>();
}

GameObject::~GameObject() {
  for (auto &component : m_Components) {
    component->OnDestroy();
  }
  m_Components.clear();
}

void GameObject::Update(float deltaTime) {
  if (!m_Active)
    return;

  for (auto &component : m_Components) {
    component->Update(deltaTime);
  }
}

void GameObject::Render(sf::RenderWindow &window) {
  if (!m_Active)
    return;

  for (auto &component : m_Components) {
    component->Render(window);
  }
}

Vector2 GameObject::GetPosition() const { return m_Transform->GetPosition(); }

void GameObject::SetPosition(const Vector2 &position) {
  m_Transform->SetPosition(position);
}

const std::string &GameObject::GetName() const { return m_Name; }

bool GameObject::IsActive() const { return m_Active; }

void GameObject::SetActive(bool active) { m_Active = active; }
} // namespace BBloc
