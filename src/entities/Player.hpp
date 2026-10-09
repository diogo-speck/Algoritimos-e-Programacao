#pragma once

#include <raylib.h>

class Player
{
public:
    Player();

    void Reset(Vector2 startPosition);
    void Update(float deltaTime);
    void Draw() const;

    Rectangle GetBounds() const;
    void ClampToBounds(Rectangle bounds);
    void ResolveCollision(Rectangle obstacle);

private:
    Vector2 position{0.0f, 0.0f};
    Vector2 size{32.0f, 32.0f};
    float speed = 260.0f;

    Vector2 GetMovementInput() const;
};