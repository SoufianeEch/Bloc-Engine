#include "Core/GameObject.hpp"
#include "Core/PhysicsComponent.hpp"
#include "Core/Scene.hpp"
#include "Core/Sprite.hpp"
#include "Core/Transform.hpp"
#include "Physics/Collision.hpp"
#include "Shapes/Circle.hpp"
#include "Shapes/Rectangle.hpp"
#include <cassert>

using namespace BBloc;

void TestApplicationSceneCreation() {
  auto scene = std::make_shared<Scene>("TestScene");
  assert(scene->GetName() == "TestScene");
  assert(scene->GetGameObjects().size() == 0);
}

void TestSpawnGameObject() {
  auto scene = std::make_shared<Scene>("TestScene");
  auto obj = scene->CreateGameObject("TestObject");

  assert(obj != nullptr);
  assert(scene->GetGameObjects().size() == 1);
}

void TestSpawnMultipleObjects() {
  auto scene = std::make_shared<Scene>("TestScene");

  auto circle = std::make_shared<Circle>(Vector2(100.0f, 100.0f), 20.0f);
  auto circleObj = scene->CreateGameObject("Circle");
  circleObj->AddComponent<Sprite>(circle);

  auto rect =
      std::make_shared<Rectangle>(Vector2(200.0f, 200.0f), 50.0f, 50.0f);
  auto rectObj = scene->CreateGameObject("Rectangle");
  rectObj->AddComponent<Sprite>(rect);

  assert(scene->GetGameObjects().size() == 2);
}

void TestObjectWithPhysics()
{
    auto scene = std::make_shared<Scene>("TestScene");
    auto obj = scene->CreateGameObject("Physics Object");
    
    auto physics = obj->AddComponent<PhysicsComponent>(1.0f, true);  // Keep gravity
    obj->SetPosition(Vector2(100.0f, 100.0f));
    physics->GetRigidbody().SetVelocity(Vector2(10.0f, 0.0f));
    
    scene->Update(1.0f);
    
    Vector2 newPos = obj->GetPosition();
    assert(newPos.x > 100.0f);  // Should move right due to velocity
    assert(newPos.y > 100.0f);  // Should move down due to gravity
}

void TestSceneUpdate() {
  auto scene = std::make_shared<Scene>("TestScene");

  auto obj1 = scene->CreateGameObject("Object1");
  auto obj2 = scene->CreateGameObject("Object2");

  auto physics1 = obj1->AddComponent<PhysicsComponent>(1.0f, false);
  auto physics2 = obj2->AddComponent<PhysicsComponent>(1.0f, false);

  obj1->SetPosition(Vector2(0.0f, 0.0f));
  obj2->SetPosition(Vector2(100.0f, 100.0f));

  physics1->GetRigidbody().SetVelocity(Vector2(10.0f, 0.0f));
  physics2->GetRigidbody().SetVelocity(Vector2(0.0f, 10.0f));

  scene->Update(0.5f);

  Vector2 pos1 = obj1->GetPosition();
  Vector2 pos2 = obj2->GetPosition();

  assert(pos1.x > 0.0f);
  assert(pos2.y > 100.0f);
}

void TestDestroyGameObject() {
  auto scene = std::make_shared<Scene>("TestScene");

  auto obj1 = scene->CreateGameObject("Object1");
  auto obj2 = scene->CreateGameObject("Object2");

  assert(scene->GetGameObjects().size() == 2);

  scene->DestroyGameObject(obj1);

  assert(scene->GetGameObjects().size() == 1);
}

void TestObjectCollision() {
  auto scene = std::make_shared<Scene>("TestScene");

  auto circle1 = std::make_shared<Circle>(Vector2(100.0f, 100.0f), 20.0f);
  auto obj1 = scene->CreateGameObject("Circle1");
  obj1->SetPosition(Vector2(100.0f, 100.0f));
  obj1->AddComponent<Sprite>(circle1);
  auto physics1 = obj1->AddComponent<PhysicsComponent>(1.0f, false);
  physics1->SetCollider(
      std::make_shared<CircleCollider>(Vector2(100.0f, 100.0f), 20.0f));

  auto circle2 = std::make_shared<Circle>(Vector2(110.0f, 100.0f), 20.0f);
  auto obj2 = scene->CreateGameObject("Circle2");
  obj2->SetPosition(Vector2(110.0f, 100.0f));
  obj2->AddComponent<Sprite>(circle2);
  auto physics2 = obj2->AddComponent<PhysicsComponent>(1.0f, false);
  physics2->SetCollider(
      std::make_shared<CircleCollider>(Vector2(110.0f, 100.0f), 20.0f));

  // Check collision
  auto collider1 =
      std::dynamic_pointer_cast<CircleCollider>(physics1->GetCollider());
  auto collider2 =
      std::dynamic_pointer_cast<CircleCollider>(physics2->GetCollider());

  if (collider1 && collider2) {
    CollisionInfo info =
        CollisionDetector::CheckCollision(*collider1, *collider2);
    assert(info.isColliding);
  }
}

int main() {
  TestApplicationSceneCreation();
  TestSpawnGameObject();
  TestSpawnMultipleObjects();
  TestObjectWithPhysics();
  TestSceneUpdate();
  TestDestroyGameObject();
  TestObjectCollision();

  return 0;
}
