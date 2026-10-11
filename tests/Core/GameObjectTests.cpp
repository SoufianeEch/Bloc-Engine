#include "Core/GameObject.hpp"
#include "Core/PhysicsComponent.hpp"
#include "Core/Scene.hpp"
#include "Core/Sprite.hpp"
#include "Core/Transform.hpp"
#include "Shapes/Circle.hpp"
#include <cassert>

using namespace BBloc;

void TestGameObjectConstruction() {
  GameObject gameObject("TestObject");
  assert(gameObject.GetName() == "TestObject");
  assert(gameObject.IsActive());
}

void TestGameObjectTransform() {
  GameObject gameObject;
  gameObject.SetPosition(Vector2(100.0f, 50.0f));

  Vector2 pos = gameObject.GetPosition();
  assert(pos.x == 100.0f && pos.y == 50.0f);
}

void TestGameObjectAddComponent() {
  GameObject gameObject;
  auto transform = gameObject.GetComponent<Transform>();

  assert(transform != nullptr);
}

void TestGameObjectAddPhysics() {
  GameObject gameObject;
  auto physics = gameObject.AddComponent<PhysicsComponent>(2.0f, true);

  assert(physics != nullptr);
  assert(physics->GetRigidbody().GetMass() == 2.0f);
}

void TestGameObjectUpdate() {
  GameObject gameObject;
  auto physics = gameObject.AddComponent<PhysicsComponent>(1.0f, false);

  physics->GetRigidbody().SetPosition(Vector2(0.0f, 0.0f));
  physics->GetRigidbody().SetVelocity(Vector2(10.0f, 0.0f));

  gameObject.Update(1.0f);

  Vector2 pos = gameObject.GetPosition();
  assert(pos.x > 9.0f && pos.x < 11.0f); // Should have moved
}

void TestGameObjectActive() {
  GameObject gameObject;
  assert(gameObject.IsActive());

  gameObject.SetActive(false);
  assert(!gameObject.IsActive());

  gameObject.SetActive(true);
  assert(gameObject.IsActive());
}

void TestSceneCreateGameObject() {
  Scene scene("TestScene");
  auto gameObject = scene.CreateGameObject("Player");

  assert(gameObject != nullptr);
  assert(gameObject->GetName() == "Player");
  assert(scene.GetGameObjects().size() == 1);
}

void TestSceneUpdate() {
  Scene scene;
  auto gameObject = scene.CreateGameObject("Player");
  auto physics = gameObject->AddComponent<PhysicsComponent>(1.0f, false);

  physics->GetRigidbody().SetPosition(Vector2(0.0f, 0.0f));
  physics->GetRigidbody().SetVelocity(Vector2(5.0f, 0.0f));

  scene.Update(1.0f);

  Vector2 pos = gameObject->GetPosition();
  assert(pos.x > 4.0f && pos.x < 6.0f);
}

void TestSceneMultipleGameObjects() {
  Scene scene;
  auto obj1 = scene.CreateGameObject("Object1");
  auto obj2 = scene.CreateGameObject("Object2");
  auto obj3 = scene.CreateGameObject("Object3");

  assert(scene.GetGameObjects().size() == 3);
}

int main() {
  TestGameObjectConstruction();
  TestGameObjectTransform();
  TestGameObjectAddComponent();
  TestGameObjectAddPhysics();
  TestGameObjectUpdate();
  TestGameObjectActive();
  TestSceneCreateGameObject();
  TestSceneUpdate();
  TestSceneMultipleGameObjects();

  return 0;
}
