#pragma once

#include <map>
#include <SFML/Window.hpp>
#include "Math/Vector2.hpp"

namespace BBloc {
  enum class Key {
      A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
      Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
      Space, Enter, Escape,
      Left, Right, Up, Down
  };
  
  enum class MouseButton {
    Left,
    Right,
    Middle
  };
  
  class InputManager {
    public:
      InputManager();
      
      // Called every frame to update input state
      void Update();
      
      // Keyboard methods
      bool IsKeyPressed(Key key) const;
      bool IsKeyJustPressed(Key key) const;
      bool IsKeyJustReleased(Key key) const;
      
      // Mouse methods
      Vector2 GetMousePosition() const;
      bool IsMouseButtonPressed(MouseButton button) const;
      bool IsMouseButtonJustPressed(MouseButton button) const;
      bool IsMouseButtonJustReleased(MouseButton button) const;
      
      // Process events from SFML
      void HandleEvent(const sf::Event& event);
      
    private:
      // Convert SFML key into our enum
      Key ConvertSFMLKey(sf::Keyboard::Key sfmlKey) const;
      
      // Track current and previous frame state
      std::map<Key, bool> m_KeyPressed;
      std::map<Key, bool> m_KeyPressedLastFrame;
      std::map<MouseButton, bool> m_MousePressed;
      std::map<MouseButton, bool> m_MousePressedLastFrame;
      Vector2 m_MousePosition;
  };
}