#ifndef TICTACTOE_ALGORITHM_SYMBOL_H_
#define TICTACTOE_ALGORITHM_SYMBOL_H_

class Symbol {
 public:
  Symbol(char symbol_, int symbol_rep_) :
      symbol{symbol_}, symbol_rep{symbol_rep_} {}

  char GetSymbol() {
    return symbol;
  }

  int GetSymbolInt() {
    return symbol_rep;
  }

 private:
  char symbol;
  int symbol_rep;
};

#endif //TICTACTOE_ALGORITHM_SYMBOL_H_
