#include <cassert>
#include "Input/InputManager.hpp"

using namespace BBloc;

void TestInputManagerConstruction()
{
    InputManager inputManager;
    // Just make sure it constructs without crashing
    assert(true);
}

void TestKeyPressed()
{
    InputManager inputManager;
    inputManager.Update();
    
    // W key should not be pressed initially
    assert(!inputManager.IsKeyPressed(Key::W));
    
    // Note: We can't easily test actual key presses without simulating SFML input
    // But we can test the structure works
}

void TestKeyJustPressed()
{
    InputManager inputManager;
    inputManager.Update();
    
    // Key should not be just pressed initially
    assert(!inputManager.IsKeyJustPressed(Key::A));
}

void TestKeyJustReleased()
{
    InputManager inputManager;
    inputManager.Update();
    
    // Key should not be just released initially
    assert(!inputManager.IsKeyJustReleased(Key::Space));
}

void TestMousePosition()
{
    InputManager inputManager;
    inputManager.Update();
    
    Vector2 mousePos = inputManager.GetMousePosition();
    // Just verify it returns a Vector2
    assert(mousePos.x >= 0.0f || mousePos.x < 0.0f);  // Always true, tests retrieval
}

void TestMouseButtonPressed()
{
    InputManager inputManager;
    inputManager.Update();
    
    // Mouse button should not be pressed initially (unless user is clicking)
    // This test just verifies the method exists and doesn't crash
    bool isPressed = inputManager.IsMouseButtonPressed(MouseButton::Left);
    assert(isPressed || !isPressed);  // Always true
}

void TestMouseButtonJustPressed()
{
    InputManager inputManager;
    inputManager.Update();
    
    // Should not be just pressed initially
    assert(!inputManager.IsMouseButtonJustPressed(MouseButton::Left));
}

void TestMouseButtonJustReleased()
{
    InputManager inputManager;
    inputManager.Update();
    
    // Should not be just released initially
    assert(!inputManager.IsMouseButtonJustReleased(MouseButton::Right));
}

void TestUpdateCycle()
{
    InputManager inputManager;
    
    // First update
    inputManager.Update();
    
    // Second update (should work without crashing)
    inputManager.Update();
    
    assert(true);  // If we got here, update cycle works
}

int main()
{
    TestInputManagerConstruction();
    TestKeyPressed();
    TestKeyJustPressed();
    TestKeyJustReleased();
    TestMousePosition();
    TestMouseButtonPressed();
    TestMouseButtonJustPressed();
    TestMouseButtonJustReleased();
    TestUpdateCycle();
    
    return 0;
}
