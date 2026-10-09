#pragma once

#include "../entities/Player.hpp"
#include <raylib.h>
#include <array>

enum class GameState
{
    Menu,
    Playing,
    Paused,
    Won
};

class Game
{
public:
    Game();
    ~Game();

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    void Run();

private:
    static constexpr int ScreenWidth = 1280;
    static constexpr int ScreenHeight = 720;
    static constexpr int CollectibleCount = 5;

    GameState state = GameState::Menu;
    Player player;
    std::array<Rectangle, CollectibleCount> collectibles{};
    std::array<bool, CollectibleCount> collected{};
    int score = 0;

    void Reset();
    void Update(float deltaTime);
    void Draw() const;
    void UpdatePlaying(float deltaTime);
    void DrawArena() const;
    void DrawHud() const;
};