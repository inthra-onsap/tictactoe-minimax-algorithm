cmake_minimum_required(VERSION 3.7)
project(tictactoe_algorithm)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cc game_engine/game.cc game_engine/game.h widget/board/board.cc widget/board/board.h widget/symbol/symbol.cc widget/symbol/symbol.h strategy/minimax/minimax.cc strategy/minimax/minimax.h)
add_executable(tictactoe_algorithm ${SOURCE_FILES})