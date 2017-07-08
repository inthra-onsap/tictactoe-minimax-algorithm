#ifndef TICTACTOE_ALGORITHM_BOARD_H_
#define TICTACTOE_ALGORITHM_BOARD_H_

#include "../symbol/symbol.h"

#include <iostream>
#include <string>
#include <vector>

class Board {
 public:

  Board(std::string title = "", std::string subtitle = "") :
      board_title{title}, board_subtitle{subtitle} {}

  void RenderHeader();

  void RenderSampleBoard();

  void RenderFooter(std::string text);

  void Render(Symbol human, Symbol bot, std::vector<int> state);

 private:
  std::string board_title;
  std::string board_subtitle;
};

#endif //TICTACTOE_ALGORITHM_BOARD_H_
