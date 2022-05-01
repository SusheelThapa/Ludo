#pragma once

#if !defined(HEADER_EXIST)
#include "header.hpp"
#endif

const int LUDO_BOARD_WIDTH = 900;
const int LUDO_BOARD_HEIGHT = 900;

SDL_Window *ludo_game_board;
SDL_Renderer *ludo_game_board_renderer;
SDL_Event ludo_game_events;

SDL_Texture *star_in_ludo_board;

bool initializeLudoGame();
bool loadLudoGame();
int diceRotate();
void drawStar(int, int);
void closeLudoGame();