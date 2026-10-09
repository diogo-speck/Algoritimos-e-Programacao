#include "core/Game.hpp"

#include <string>

namespace
{
    constexpr Color BackgroundColor{24, 28, 40, 255};
    constexpr Color ArenaColor{35, 42, 58, 255};
    constexpr Color GridColor{47, 56, 74, 255};
    constexpr Color AccentColor{90, 210, 170, 255};
    constexpr Color CollectibleColor{255, 198, 82, 255};
}

Game::Game()
{
    InitWindow(ScreenWidth, ScreenHeight, "GameJamBase - raylib");
    SetTargetFPS(60);
    Reset();
}

Game::~Game()
{
    CloseWindow();
}

void Game::Run()
{
    while (!WindowShouldClose())
    {
        const float deltaTime = GetFrameTime();
        Update(deltaTime);

        BeginDrawing();
        ClearBackground(BackgroundColor);
        Draw();
        EndDrawing();
    }
}

void Game::Reset()
{
    player.Reset({ScreenWidth / 2.0f - 16.0f, ScreenHeight / 2.0f - 16.0f});
    score = 0;
    collected.fill(false);

    // Posições fixas de propósito: fáceis de entender e modificar.
    collectibles = {{
        {170.0f, 150.0f, 22.0f, 22.0f},
        {1060.0f, 160.0f, 22.0f, 22.0f},
        {220.0f, 535.0f, 22.0f, 22.0f},
        {1020.0f, 535.0f, 22.0f, 22.0f},
        {630.0f, 110.0f, 22.0f, 22.0f}
    }};
}

void Game::Update(float deltaTime)
{
    if (IsKeyPressed(KEY_R))
    {
        Reset();
        state = GameState::Playing;
        return;
    }

    switch (state)
    {
        case GameState::Menu:
            if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
                state = GameState::Playing;
            break;

        case GameState::Playing:
            if (IsKeyPressed(KEY_P))
            {
                state = GameState::Paused;
                break;
            }
            UpdatePlaying(deltaTime);
            break;

        case GameState::Paused:
            if (IsKeyPressed(KEY_P) || IsKeyPressed(KEY_ENTER))
                state = GameState::Playing;
            break;

        case GameState::Won:
            if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
            {
                Reset();
                state = GameState::Playing;
            }
            break;
    }
}

void Game::UpdatePlaying(float deltaTime)
{
    player.Update(deltaTime);

    // Limites da arena.
    player.ClampToBounds(
        {70.0f, 90.0f, static_cast<float>(ScreenWidth) - 140.0f,
         static_cast<float>(ScreenHeight) - 160.0f});

    // Um obstáculo simples no centro da arena.
    const Rectangle obstacle{560.0f, 300.0f, 160.0f, 42.0f};
    player.ResolveCollision(obstacle);

    for (int i = 0; i < CollectibleCount; ++i)
    {
        if (!collected[i] && CheckCollisionRecs(player.GetBounds(), collectibles[i]))
        {
            collected[i] = true;
            ++score;
        }
    }

    if (score == CollectibleCount)
        state = GameState::Won;
}

void Game::Draw() const
{
    DrawArena();

    if (state == GameState::Menu)
    {
        DrawRectangle(0, 0, ScreenWidth, ScreenHeight, Fade(BLACK, 0.55f));
        // Centralização simples do título.
        const int titleWidth = MeasureText("GAMEJAM BASE", 48);
        DrawText("GAMEJAM BASE", (ScreenWidth - titleWidth) / 2, 230, 48, RAYWHITE);

        const char* subtitle = "Uma base pequena para voce modificar";
        DrawText(subtitle, (ScreenWidth - MeasureText(subtitle, 22)) / 2, 300, 22, LIGHTGRAY);

        const char* prompt = "ENTER / ESPACO para jogar";
        DrawText(prompt, (ScreenWidth - MeasureText(prompt, 20)) / 2, 390, 20, AccentColor);
        return;
    }

    for (int i = 0; i < CollectibleCount; ++i)
    {
        if (!collected[i])
        {
            DrawCircle(
                static_cast<int>(collectibles[i].x + collectibles[i].width / 2),
                static_cast<int>(collectibles[i].y + collectibles[i].height / 2),
                collectibles[i].width / 2,
                CollectibleColor);
        }
    }

    // Obstáculo do protótipo.
    DrawRectangle(560, 300, 160, 42, Color{205, 105, 115, 255});
    DrawText("OBSTACULO", 577, 312, 16, RAYWHITE);

    player.Draw();
    DrawHud();

    if (state == GameState::Paused)
    {
        DrawRectangle(0, 0, ScreenWidth, ScreenHeight, Fade(BLACK, 0.6f));
        const char* title = "PAUSADO";
        DrawText(title, (ScreenWidth - MeasureText(title, 44)) / 2, 285, 44, RAYWHITE);
        const char* prompt = "Pressione P ou ENTER para continuar";
        DrawText(prompt, (ScreenWidth - MeasureText(prompt, 20)) / 2, 350, 20, LIGHTGRAY);
    }
    else if (state == GameState::Won)
    {
        DrawRectangle(0, 0, ScreenWidth, ScreenHeight, Fade(BLACK, 0.65f));
        const char* title = "VOCE COLETOU TUDO!";
        DrawText(title, (ScreenWidth - MeasureText(title, 40)) / 2, 280, 40, AccentColor);
        const char* prompt = "ENTER para jogar novamente";
        DrawText(prompt, (ScreenWidth - MeasureText(prompt, 20)) / 2, 350, 20, RAYWHITE);
    }
}

void Game::DrawArena() const
{
    DrawRectangle(70, 90, ScreenWidth - 140, ScreenHeight - 160, ArenaColor);

    for (int x = 70; x <= ScreenWidth - 70; x += 40)
        DrawLine(x, 90, x, ScreenHeight - 70, GridColor);

    for (int y = 90; y <= ScreenHeight - 70; y += 40)
        DrawLine(70, y, ScreenWidth - 70, y, GridColor);

    DrawRectangleLines(70, 90, ScreenWidth - 140, ScreenHeight - 160, Color{100, 120, 145, 255});
}

void Game::DrawHud() const
{
    DrawText(TextFormat("Pontos: %d / %d", score, CollectibleCount), 24, 22, 24, RAYWHITE);
    DrawText("WASD/setas: mover   P: pausar   R: reiniciar   ESC: sair",
             24, ScreenHeight - 35, 18, LIGHTGRAY);
}