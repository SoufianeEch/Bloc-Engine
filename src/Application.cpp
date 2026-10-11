#include "Application.hpp"
#include "Core/GameObject.hpp"
#include "Core/Transform.hpp"
#include "Core/Sprite.hpp"
#include "Core/PhysicsComponent.hpp"
#include "Shapes/Circle.hpp"
#include "Shapes/Rectangle.hpp"
#include "Shapes/Triangle.hpp"
#include "Shapes/Line.hpp"
#include "Physics/Collision.hpp"
#include <iostream>

namespace BBloc {

Application::Application(unsigned int width, unsigned int height,
                         const std::string &title)
    : m_Window(sf::VideoMode(width, height), title) {
  m_Window.setFramerateLimit(60);
  std::cout << "[BBloc Engine] Application initialized." << std::endl;

  // Create the initial scene
  m_CurrentScene = std::make_shared<Scene>("MainScene");
  CreateTestScene();
}

Application::~Application() {
  std::cout << "[BBloc Engine] Application shut down." << std::endl;
}

void Application::Run() {
  sf::Clock clock;

  while (m_Window.isOpen() && m_IsRunning) {
    float deltaTime = clock.restart().asSeconds();

    ProcessEvents();
    Update(deltaTime);
    Render();
  }
}

void Application::ProcessEvents() {
  sf::Event event;
  while (m_Window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      m_IsRunning = false;
      m_Window.close();
    }

    m_InputManager.HandleEvent(event);
  }

  m_InputManager.Update();
}

void Application::Update(float deltaTime) {
  if (m_CurrentScene) {
    m_CurrentScene->Update(deltaTime);
    m_CurrentScene->CheckCollisions();
  }
}

void Application::Render() {
  m_Window.clear(sf::Color::Black);

  if (m_CurrentScene) {
    m_CurrentScene->Render(m_Window);
  }

  m_Window.display();
}

void Application::CreateTestScene() {
  // Create a circle
  auto circle = std::make_shared<Circle>(Vector2(200.0f, 100.0f), 25.0f);
  auto circleObj = m_CurrentScene->CreateGameObject("Circle");
  circleObj->SetPosition(Vector2(200.0f, 100.0f));
  circleObj->AddComponent<Sprite>(circle);
  auto circlePhysics = circleObj->AddComponent<PhysicsComponent>(1.0f, true);
  circlePhysics->SetCollider(
      std::make_shared<CircleCollider>(Vector2(200.0f, 100.0f), 25.0f));

  // Create a rectangle
  auto rectangle =
      std::make_shared<Rectangle>(Vector2(400.0f, 200.0f), 100.0f, 50.0f);
  auto rectObj = m_CurrentScene->CreateGameObject("Rectangle");
  rectObj->SetPosition(Vector2(400.0f, 200.0f));
  rectObj->AddComponent<Sprite>(rectangle);
  auto rectPhysics = rectObj->AddComponent<PhysicsComponent>(2.0f, false);
  rectPhysics->SetCollider(std::make_shared<RectangleCollider>(
      Vector2(400.0f, 200.0f), 100.0f, 50.0f));

  // Create a triangle
  auto triangle =
      std::make_shared<Triangle>(Vector2(600.0f, 100.0f), Vector2(0.0f, 0.0f),
                                 Vector2(50.0f, 0.0f), Vector2(25.0f, 50.0f));
  auto triObj = m_CurrentScene->CreateGameObject("Triangle");
  triObj->SetPosition(Vector2(600.0f, 100.0f));
  triObj->AddComponent<Sprite>(triangle);

  // Create a line
  auto line = std::make_shared<Line>(Vector2(100.0f, 400.0f),
                                     Vector2(700.0f, 400.0f), 5.0f);
  auto lineObj = m_CurrentScene->CreateGameObject("Line");
  lineObj->AddComponent<Sprite>(line);

  std::cout << "[BBloc Engine] Test scene created with 4 objects." << std::endl;
}
} // namespace BBloc
