#pragma once

#include "Math/Vector2.hpp"

namespace BBloc {
    class Rigidbody {
    public:
        Rigidbody(float mass = 1.0f, bool useGravity = true);
        
        // Physics update - called every frame
        void Update(float deltaTime);
        
        // Force application
        void ApplyForce(const Vector2& force);
        void ApplyAcceleration(const Vector2& acceleration);
        
        // Getters
        float GetMass() const;
        Vector2 GetVelocity() const;
        Vector2 GetAcceleration() const;
        Vector2 GetPosition() const;
        bool IsUsingGravity() const;
        
        // Setters
        void SetMass(float mass);
        void SetVelocity(const Vector2& velocity);
        void SetAcceleration(const Vector2& acceleration);
        void SetPosition(const Vector2& position);
        void SetUseGravity(bool useGravity);
        
        // Constants
        static constexpr float GRAVITY = 9.81f;
        
    private:
        float m_Mass;
        Vector2 m_Velocity;
        Vector2 m_Acceleration;
        Vector2 m_Position;
        Vector2 m_Force;
        bool m_UseGravity;
    };
}