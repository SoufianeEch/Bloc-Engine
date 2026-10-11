#pragma once

#include "Core/Component.hpp"
#include "Math/Vector2.hpp"
#include <memory>
#include <vector>
#include <typeinfo>

namespace BBloc {
    
    class Transform;
    
    class GameObject {
    public:
        GameObject(const std::string& name = "GameObject");
        ~GameObject();
        
        // Component management
        template<typename T, typename... Args>
        std::shared_ptr<T> AddComponent(Args&&... args)
        {
            auto component = std::make_shared<T>(std::forward<Args>(args)...);
            component->m_GameObject = this;
            component->OnCreate();
            m_Components.push_back(component);
            return component;
        }
        
        template<typename T>
        std::shared_ptr<T> GetComponent() const
        {
            for (auto& component : m_Components) {
                auto casted = std::dynamic_pointer_cast<T>(component);
                if (casted) return casted;
            }
            return nullptr;
        }
        
        // Lifecycle
        void Update(float deltaTime);
        void Render(sf::RenderWindow& window);
        
        // Transform shortcuts
        Vector2 GetPosition() const;
        void SetPosition(const Vector2& position);
        
        // Getters
        const std::string& GetName() const;
        bool IsActive() const;
        void SetActive(bool active);
        
    private:
        std::string m_Name;
        bool m_Active;
        std::shared_ptr<Transform> m_Transform;
        std::vector<std::shared_ptr<Component>> m_Components;
    };
}