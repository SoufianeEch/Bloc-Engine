#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include "Core/Scene.hpp"
#include "Input/InputManager.hpp"

namespace BBloc {
    class Application {
    public:
        Application(unsigned int width, unsigned int height, const std::string& title);
        ~Application();
        
        // Starts and runs the main engine loop
        void Run();
        
    private:
        void ProcessEvents();
        void Update(float deltaTime);
        void Render();
        void CreateTestScene();
        
    private:
        sf::RenderWindow m_Window;
        InputManager m_InputManager;
        std::shared_ptr<Scene> m_CurrentScene;
        bool m_IsRunning{true};
    };
}