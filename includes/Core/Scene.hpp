#pragma once

#include "Core/GameObject.hpp"
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <algorithm>

namespace BBloc {
    
    class Scene {
    public:
        Scene(const std::string& name = "Scene");
        
        // GameObject management
        std::shared_ptr<GameObject> CreateGameObject(const std::string& name = "GameObject");
        void DestroyGameObject(std::shared_ptr<GameObject> gameObject);
        
        // Lifecycle
        void Update(float deltaTime);
        void Render(sf::RenderWindow& window);
        
        // Collision checking
        void CheckCollisions();
        
        // Getters
        const std::string& GetName() const;
        const std::vector<std::shared_ptr<GameObject>>& GetGameObjects() const;
        
    private:
        std::string m_Name;
        std::vector<std::shared_ptr<GameObject>> m_GameObjects;
    };
}