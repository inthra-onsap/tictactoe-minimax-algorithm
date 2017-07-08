#include "game_engine/game.h"
#include "widget/board/board.h"
#include "widget/symbol/symbol.h"

using namespace std;

int main() {
  Symbol human('x', -1);
  Symbol bot('o', 1);
  Board board("TicTacToe", "Choose a cell number from 1 to 9 then press Enter");
  Game game(board, human, bot);

  game.Start();

  return 0;
}