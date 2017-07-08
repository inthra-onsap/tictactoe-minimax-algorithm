#include "game.h"

void Game::Start() {
  int human_input;

  board.RenderHeader();
  board.RenderSampleBoard();
  while (!IsOver()) {
    std::cout << "Choose: ";
    std::cin >> human_input;
    if (IsValid(human_input)) {
      Place(human_input, human_sym);
      Place(FindBestMove(), robot_sym);
    } else {
      std::cout << "Position is not correct!" << std::endl;
    }
    board.Render(human_sym, robot_sym, GetState());
  }
  board.RenderFooter(GetResultMessage());
}

bool Game::IsFull() {
  for (int i = 1; i < state.size(); ++i)
    if (state[i] == 0)
      return false;
  return true;
};

int Game::GetWinner() {
  for (int row = 1; row < 9; row += 3)
    if (state[row] == state[row + 1] && state[row + 1] == state[row + 2] && state[row] != 0)
      return (state[row] == robot_sym.GetSymbolInt()) ? robot_sym.GetSymbolInt() : human_sym.GetSymbolInt();
  for (int col = 1; col <= 3; ++col)
    if (state[col] == state[col + 3] && state[col + 3] == state[col + 6] && state[col] != 0)
      return (state[col] == robot_sym.GetSymbolInt()) ? robot_sym.GetSymbolInt() : human_sym.GetSymbolInt();
  if (state[1] == state[5] && state[5] == state[9] && state[1] != 0)
    return (state[0] == robot_sym.GetSymbolInt()) ? robot_sym.GetSymbolInt() : human_sym.GetSymbolInt();
  if (state[3] == state[5] && state[5] == state[7] && state[3] != 0)
    return (state[3] == robot_sym.GetSymbolInt()) ? robot_sym.GetSymbolInt() : human_sym.GetSymbolInt();
  return 0;
}

int Game::Minimax(bool is_max) {
  int winner = GetWinner();
  int best_score;

  if (winner != 0) {
    // Has Winner
    return winner;
  } else if (IsFull()) {
    // Draw
    return 0;
  } else {
    if (is_max) {
      best_score = INT_MIN;
      for (int i = 1; i < state.size(); ++i) {
        if (state[i] == 0) {
          state[i] = robot_sym.GetSymbolInt();
          best_score = std::max(best_score, Minimax(!is_max));
          state[i] = 0;
        }
      }
    } else {
      best_score = INT_MAX;
      for (int i = 1; i < state.size(); ++i) {
        if (state[i] == 0) {
          state[i] = human_sym.GetSymbolInt();
          best_score = std::min(best_score, Minimax(!is_max));
          state[i] = 0;
        }
      }
    }
  };
  return best_score;
}

int Game::FindBestMove() {
  int best_score = INT_MIN;
  int best_move = 0;
  for (int i = 1; i <= state.size(); ++i) {
    if (state[i] == 0) {
      state[i] = robot_sym.GetSymbolInt();
      int score = Minimax(false);
      state[i] = 0;
      if (score > best_score) {
        best_score = score;
        best_move = i;
      }
    }
  }
  return best_move;
}

bool Game::IsOver() {
  if (IsFull() || GetWinner() != 0) {
    return true;
  }
  return false;
}

std::vector<int> Game::GetState() {
  return state;
}

std::string Game::GetResultMessage() {
  int winner = GetWinner();
  if (winner != 0) {
    return (winner == human_sym.GetSymbolInt()) ? "You Win!" : "You Lose!";
  } else {
    return "Draw!";
  }
}

bool Game::IsValid(int pos) {
  return (pos < 1 || pos > 9 || state[pos] == 0);
}

void Game::Place(int pos, Symbol symbol) {
  state[pos] = symbol.GetSymbolInt();
}