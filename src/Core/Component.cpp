#include "Core/Component.hpp"
#include "Core/GameObject.hpp"

namespace BBloc {
    
    GameObject* Component::GetGameObject() const
    {
        return m_GameObject;
    }
}