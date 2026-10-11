#include "Core/Scene.hpp"
#include "Core/PhysicsComponent.hpp"

namespace BBloc {

Scene::Scene(const std::string &name) : m_Name(name) {}

std::shared_ptr<GameObject> Scene::CreateGameObject(const std::string &name) {
  auto gameObject = std::make_shared<GameObject>(name);
  m_GameObjects.push_back(gameObject);
  return gameObject;
}

void Scene::DestroyGameObject(std::shared_ptr<GameObject> gameObject) {
  auto it = std::find(m_GameObjects.begin(), m_GameObjects.end(), gameObject);
  if (it != m_GameObjects.end()) {
    m_GameObjects.erase(it);
  }
}

void Scene::Update(float deltaTime) {
  for (auto &gameObject : m_GameObjects) {
    gameObject->Update(deltaTime);
  }
}

void Scene::Render(sf::RenderWindow &window) {
  for (auto &gameObject : m_GameObjects) {
    gameObject->Render(window);
  }
}

void Scene::CheckCollisions() {
  // Simple brute force collision checking
  for (size_t i = 0; i < m_GameObjects.size(); ++i) {
    for (size_t j = i + 1; j < m_GameObjects.size(); ++j) {
      auto physicsA = m_GameObjects[i]->GetComponent<PhysicsComponent>();
      auto physicsB = m_GameObjects[j]->GetComponent<PhysicsComponent>();

      if (physicsA && physicsB && physicsA->GetCollider() &&
          physicsB->GetCollider()) {
        // Collision would be checked here
      }
    }
  }
}

const std::string &Scene::GetName() const { return m_Name; }

const std::vector<std::shared_ptr<GameObject>> &Scene::GetGameObjects() const {
  return m_GameObjects;
}
} // namespace BBloc
