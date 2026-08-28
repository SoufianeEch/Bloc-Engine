#include "Application.hpp"
#include <iostream>

namespace BBloc {

  Application::Application(unsigned int width, unsigned int height, const std::string &title) : m_Window(sf::VideoMode(width, height), title) {
    m_Window.setFramerateLimit(60); // Cap at 60 FPS
    std::cout << "[BBloc Engine] Application initialized." << std::endl;
  }
  
  Application::~Application() {
    std::cout << "[BBloc Engine] Application shut down." << std::endl;
  }
  
  void Application::Run() {
    sf::Clock clock;
  
    while (m_Window.isOpen() && m_IsRunning) {
      // Calculate time elapsed since last frame (Delta Time)
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
    }
  }

  void Application::Update(float deltaTime) {
    // Future game logic and physics updates will go here
    return;
  }
  
  void Application::Render() {
    m_Window.clear(sf::Color::Black);
  
    // Future shape rendering will go here
  
    m_Window.display();
  }
}
