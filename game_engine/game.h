#ifndef TICTACTOE_ALGORITHM_TICTACTOE_BOT_H_
#define TICTACTOE_ALGORITHM_TICTACTOE_BOT_H_

#include "../widget/symbol/symbol.h"
#include "../widget/board/board.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>

class Game {
 public:
  Game(Board board_, Symbol &human_, Symbol &robot_) : board{board_}, human_sym{human_}, robot_sym{robot_} {
    state.resize(10, 0);
  }

  void Start();

 private:
  std::vector<int> state;
  Symbol human_sym;
  Symbol robot_sym;
  Board board;

  bool IsFull();

  int FindWinner();

  int Minimax(bool is_max, int alpha, int beta);

  int FindBestMove();

  bool IsOver();

  std::vector<int> GetState();

  std::string GetResultMessage();

  bool IsValid(int pos);

  void Place(int pos, Symbol symbol);
};

#endif //TICTACTOE_ALGORITHM_TICTACTOE_BOT_H_
