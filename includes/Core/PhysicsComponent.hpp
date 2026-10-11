#pragma once

#include "Core/Component.hpp"
#include "Physics/Rigidbody.hpp"
#include "Physics/Collision.hpp"
#include <memory>

namespace BBloc {
    
    class PhysicsComponent : public Component {
    public:
        PhysicsComponent(float mass = 1.0f, bool useGravity = true);
        
        void Update(float deltaTime) override;
        
        Rigidbody& GetRigidbody();
        const Rigidbody& GetRigidbody() const;
        
        void SetCollider(std::shared_ptr<Collider> collider);
        std::shared_ptr<Collider> GetCollider() const;
        
    private:
        Rigidbody m_Rigidbody;
        std::shared_ptr<Collider> m_Collider;
    };
}