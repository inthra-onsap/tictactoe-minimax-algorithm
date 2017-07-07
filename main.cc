#include "game_engine/game.h"
#include "widget/board/board.h"
#include "widget/symbol/symbol.h"

#include <iostream>

using namespace std;

int main() {
  Symbol human('X', -1);
  Symbol bot('O', 1);
  Game game(human, bot);
  Board board("TicTacToe", "Choose a cell number from 1 to 9 then press Enter");
  int human_input;

  board.RenderHeader();
  board.Render(human, bot, game.GetState());
  while (!game.IsOver()) {
    cout << "Choose: ";
    cin >> human_input;
    if (game.IsValid(human_input)) {
      game.Place(human_input, human);
      game.Place(game.FindBestMove(), bot);
    } else {
      cout << "Position is not correct!" << endl;
    }
    board.Render(human, bot, game.GetState());
  }
  board.RenderFooter(game.GetResult());

  return 0;
}