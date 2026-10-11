#include "Input/InputManager.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

namespace BBloc {

  InputManager::InputManager() : m_MousePosition(0.0f, 0.0f) {
    // Initialize all keys as not pressed
    for (int i = static_cast<int>(Key::A); i <= static_cast<int>(Key::Down); ++i) {
      m_KeyPressed[static_cast<Key>(i)] = false;
      m_KeyPressedLastFrame[static_cast<Key>(i)] = false;
    }
  
    // Initialize all mouse buttons as not pressed
    m_MousePressed[MouseButton::Left] = false;
    m_MousePressed[MouseButton::Right] = false;
    m_MousePressed[MouseButton::Middle] = false;
    m_MousePressedLastFrame[MouseButton::Left] = false;
    m_MousePressedLastFrame[MouseButton::Right] = false;
    m_MousePressedLastFrame[MouseButton::Middle] = false;
  }
  
  void InputManager::Update() {
    // Store previous frame state
    m_KeyPressedLastFrame = m_KeyPressed;
    m_MousePressedLastFrame = m_MousePressed;
  
    // Update keyboard state
    for (int i = static_cast<int>(Key::A); i <= static_cast<int>(Key::Down); ++i) {
      Key key = static_cast<Key>(i);
      sf::Keyboard::Key sfmlKey = sf::Keyboard::Unknown;
  
      // Map Key enum to SFML keys
      if (key >= Key::A && key <= Key::Z) {
        sfmlKey = static_cast<sf::Keyboard::Key>(sf::Keyboard::A +
                                                (i - static_cast<int>(Key::A)));
      } else if (key >= Key::Num0 && key <= Key::Num9) {
        sfmlKey = static_cast<sf::Keyboard::Key>(sf::Keyboard::Num0 + (i - static_cast<int>(Key::Num0)));
      } else if (key == Key::Space) {
        sfmlKey = sf::Keyboard::Space;
      } else if (key == Key::Enter) {
        sfmlKey = sf::Keyboard::Enter;
      } else if (key == Key::Escape) {
        sfmlKey = sf::Keyboard::Escape;
      } else if (key == Key::Left) {
        sfmlKey = sf::Keyboard::Left;
      } else if (key == Key::Right) {
        sfmlKey = sf::Keyboard::Right;
      } else if (key == Key::Up) {
        sfmlKey = sf::Keyboard::Up;
      } else if (key == Key::Down) {
        sfmlKey = sf::Keyboard::Down;
      }
  
      m_KeyPressed[key] = sf::Keyboard::isKeyPressed(sfmlKey);
    }
  
    // Update mouse state
    m_MousePressed[MouseButton::Left] = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    m_MousePressed[MouseButton::Right] = sf::Mouse::isButtonPressed(sf::Mouse::Right);
    m_MousePressed[MouseButton::Middle] = sf::Mouse::isButtonPressed(sf::Mouse::Middle);
  
    // Update mouse position
    auto mousePos = sf::Mouse::getPosition();
    m_MousePosition = Vector2(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
  }
  
  bool InputManager::IsKeyPressed(Key key) const {
    auto it = m_KeyPressed.find(key);
    return it != m_KeyPressed.end() ? it->second : false;
  }
  
  bool InputManager::IsKeyJustPressed(Key key) const {
    bool isPressed = IsKeyPressed(key);
    auto it = m_KeyPressedLastFrame.find(key);
    bool wasPressed = it != m_KeyPressedLastFrame.end() ? it->second : false;
    return isPressed && !wasPressed;
  }
  
  bool InputManager::IsKeyJustReleased(Key key) const {
    bool isPressed = IsKeyPressed(key);
    auto it = m_KeyPressedLastFrame.find(key);
    bool wasPressed = it != m_KeyPressedLastFrame.end() ? it->second : false;
    return !isPressed && wasPressed;
  }
  
  Vector2 InputManager::GetMousePosition() const { return m_MousePosition; }
  
  bool InputManager::IsMouseButtonPressed(MouseButton button) const {
    auto it = m_MousePressed.find(button);
    return it != m_MousePressed.end() ? it->second : false;
  }
  
  bool InputManager::IsMouseButtonJustPressed(MouseButton button) const {
    bool isPressed = IsMouseButtonPressed(button);
    auto it = m_MousePressedLastFrame.find(button);
    bool wasPressed = it != m_MousePressedLastFrame.end() ? it->second : false;
    return isPressed && !wasPressed;
  }
  
  bool InputManager::IsMouseButtonJustReleased(MouseButton button) const {
    bool isPressed = IsMouseButtonPressed(button);
    auto it = m_MousePressedLastFrame.find(button);
    bool wasPressed = it != m_MousePressedLastFrame.end() ? it->second : false;
    return !isPressed && wasPressed;
  }
  
  void InputManager::HandleEvent(const sf::Event &event) {
    // For now, this is a placeholder for event-based input
    // Most of my input is handled in Update() using polling
  }
  
  Key InputManager::ConvertSFMLKey(sf::Keyboard::Key sfmlKey) const {
    // This is a helper function for converting SFML keys to our enum
    // Not used in current implementation, but useful for event handling
    if (sfmlKey >= sf::Keyboard::A && sfmlKey <= sf::Keyboard::Z) {
      return static_cast<Key>(static_cast<int>(Key::A) + (sfmlKey - sf::Keyboard::A));
    }
    return Key::A; // Default fallback
  }
}