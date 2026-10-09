#include "entities/Player.hpp"

#include <cmath>

namespace
{
    constexpr Color PlayerColor{90, 210, 170, 255};
}

Player::Player() = default;

void Player::Reset(Vector2 startPosition)
{
    position = startPosition;
}

Vector2 Player::GetMovementInput() const
{
    Vector2 input{0.0f, 0.0f};

    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        input.x -= 1.0f;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
        input.x += 1.0f;
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
        input.y -= 1.0f;
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
        input.y += 1.0f;

    // Normalizar evita que mover na diagonal seja mais rápido.
    const float length = std::sqrt(input.x * input.x + input.y * input.y);
    if (length > 0.0f)
    {
        input.x /= length;
        input.y /= length;
    }

    return input;
}

void Player::Update(float deltaTime)
{
    const Vector2 input = GetMovementInput();
    position.x += input.x * speed * deltaTime;
    position.y += input.y * speed * deltaTime;
}

void Player::Draw() const
{
    DrawRectangleRec(GetBounds(), PlayerColor);
    DrawRectangleLinesEx(GetBounds(), 2.0f, RAYWHITE);
}

Rectangle Player::GetBounds() const
{
    return {position.x, position.y, size.x, size.y};
}

void Player::ClampToBounds(Rectangle bounds)
{
    if (position.x < bounds.x)
        position.x = bounds.x;
    if (position.y < bounds.y)
        position.y = bounds.y;
    if (position.x + size.x > bounds.x + bounds.width)
        position.x = bounds.x + bounds.width - size.x;
    if (position.y + size.y > bounds.y + bounds.height)
        position.y = bounds.y + bounds.height - size.y;
}

void Player::ResolveCollision(Rectangle obstacle)
{
    const Rectangle playerBounds = GetBounds();

    if (!CheckCollisionRecs(playerBounds, obstacle))
        return;

    const float overlapLeft = playerBounds.x + playerBounds.width - obstacle.x;
    const float overlapRight = obstacle.x + obstacle.width - playerBounds.x;
    const float overlapTop = playerBounds.y + playerBounds.height - obstacle.y;
    const float overlapBottom = obstacle.y + obstacle.height - playerBounds.y;

    const float minX = (overlapLeft < overlapRight) ? overlapLeft : -overlapRight;
    const float minY = (overlapTop < overlapBottom) ? overlapTop : -overlapBottom;

    // Corrige pelo menor eixo de penetração. Adequado para este protótipo simples.
    if (std::abs(minX) < std::abs(minY))
        position.x -= minX;
    else
        position.y -= minY;
}