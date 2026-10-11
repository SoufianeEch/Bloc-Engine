# Input Manager Requirements

InputManager handles keyboard and mouse input for the engine.

## Keyboard Input

Must support:
- Check if key is currently held down
- Detect key just pressed (this frame)
- Detect key just released (this frame)
- List of common keys (A-Z, 0-9, Space, Enter, Escape, Arrow keys)

## Mouse Input

Must support:
- Get current mouse position
- Check if mouse button is held down
- Detect mouse button just pressed
- Detect mouse button just released

## Input Update

Must update every frame to track state changes