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

  void RenderHeader() {
    std::cout << "*************" << std::endl;
    std::cout << "* " << board_title << " *" << std::endl;
    std::cout << "*************" << std::endl;
    std::cout << board_subtitle << std::endl;
  }

  void RenderFooter(std::string text) {
    if (text != "Draw")
      text += " WON!";
    std::cout << "***************" << std::endl;
    std::cout << "* " << text << " *" << std::endl;
    std::cout << "***************" << std::endl;
  }

  void Render(Symbol human, Symbol bot, std::vector<int> state) {
    char symbol;
    std::cout << std::endl;
    for (int row = 1; row <= 9; row += 3) {
      std::cout << "\t\t ";
      for (int col = 0; col < 3; ++col) {
        int pos = row + col;
        if (state[pos] == 0) {
          std::cout << pos;
        } else {
          symbol = (state[pos] == human.GetSymbolInt()) ? human.GetSymbol() : bot.GetSymbol();
          std::cout << symbol;
        }
        if (col == 0 || col == 1)
          std::cout << " | ";
      }
      if (row == 1 || row == 4)
        std::cout << "\n\t\t ---------\n";
    }
    std::cout << std::endl;
  }

 private:
  std::string board_title;
  std::string board_subtitle;
};

#endif //TICTACTOE_ALGORITHM_BOARD_H_
