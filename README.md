Base para a GameJam


git clone --branch gameJam --single-branch https://github.com/diogo-speck/Algoritimos-e-Programacao.git gameJam

plataforma, puzzle, exploração ou combate?
Delta time: GetFrameTime() para que o movimento não dependa da taxa de quadros.
Colisões: CheckCollisionRecs() e retângulos da raylib. Não criar um motor de física.
Estados: enum class para menu, jogo, pausa e resultado, em vez de espalhar vários booleanos pelo projeto.