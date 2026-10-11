#pragma once

#include "Core/Component.hpp"
#include "Shapes/Shape.hpp"
#include <memory>

namespace BBloc {
    
    class Sprite : public Component {
    public:
        Sprite(std::shared_ptr<Shape> shape);
        
        void Render(sf::RenderWindow& window) override;
        
        std::shared_ptr<Shape> GetShape() const;
        void SetShape(std::shared_ptr<Shape> shape);
        
    private:
        std::shared_ptr<Shape> m_Shape;
    };
}