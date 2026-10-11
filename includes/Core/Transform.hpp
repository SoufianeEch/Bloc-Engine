#pragma once

#include "Core/Component.hpp"
#include "Math/Vector2.hpp"

namespace BBloc {
    
    class Transform : public Component {
    public:
        Transform(Vector2 position = Vector2(0.0f, 0.0f), 
                  float rotation = 0.0f, 
                  Vector2 scale = Vector2(1.0f, 1.0f));
        
        // Getters
        Vector2 GetPosition() const;
        float GetRotation() const;
        Vector2 GetScale() const;
        
        // Setters
        void SetPosition(const Vector2& position);
        void SetRotation(float rotation);
        void SetScale(const Vector2& scale);
        
        // Utilities
        void Translate(const Vector2& offset);
        void Rotate(float angle);
        
    private:
        Vector2 m_Position;
        float m_Rotation;
        Vector2 m_Scale;
    };
}