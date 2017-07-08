#include "board.h"

void Board::RenderHeader() {
  std::cout << "*************" << std::endl;
  std::cout << "* " << board_title << " *" << std::endl;
  std::cout << "*************" << std::endl;
  std::cout << board_subtitle << std::endl;
}

void Board::RenderFooter(std::string text) {
  std::cout << "***************" << std::endl;
  std::cout << "* " << text << " *" << std::endl;
  std::cout << "***************" << std::endl;
}

void Board::RenderSampleBoard() {
  std::cout << std::endl;
  std::cout << "\t\t 1 | 2 | 3\n";
  std::cout << "\t\t ---------\n";
  std::cout << "\t\t 4 | 5 | 6\n";
  std::cout << "\t\t ---------\n";
  std::cout << "\t\t 7 | 8 | 9\n";
  std::cout << std::endl;
}

void Board::Render(Symbol human, Symbol bot, std::vector<int> state) {
  char symbol;
  std::cout << std::endl;
  for (int row = 1; row <= 9; row += 3) {
    std::cout << "\t\t ";
    for (int col = 0; col < 3; ++col) {
      int pos = row + col;
      if (state[pos] != 0) {
        symbol = (state[pos] == human.GetSymbolInt()) ? human.GetSymbol() : bot.GetSymbol();
        std::cout << symbol;
      } else {
        std::cout << " ";
      }
      if (col == 0 || col == 1)
        std::cout << " | ";
    }
    if (row == 1 || row == 4)
      std::cout << "\n\t\t ---------\n";
  }
  std::cout << std::endl;
}