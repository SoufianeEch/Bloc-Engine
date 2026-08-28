#pragma once

#include <SFML/Graphics.hpp>
#include <string>

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

    private:
        sf::RenderWindow m_Window;
        bool m_IsRunning{true};
    };
}