#include "core/Game.hpp"

int main()
{
    Game game;
    game.Run();
    return 0;
}

//raylib na raiz do projeto
//g++ -std=c++17 -o game.exe src/main.cpp src/core/Game.cpp src/entities/Player.cpp -Isrc -Iraylib/include -Lraylib/lib -lraylib -lgdi32 -lwinmm