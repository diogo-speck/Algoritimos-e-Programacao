#include "raylib.h"

int main() {
    InitWindow(1220, 720, "Meu jogo");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
}

// estando no mesmo dir
// g++ -o teste.exe teste.cpp -Iraylib/include -Lraylib/lib -lraylib -lgdi32 -lwinmm