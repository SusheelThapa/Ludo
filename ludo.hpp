#pragma once

#include "window.hpp"
#include "ludo_piece.hpp"

class Ludo
{
private:
    RedLudoPiece red_piece[TOTAL_PIECE];
    BlueLudoPiece blue_piece[TOTAL_PIECE];
    GreenLudoPiece green_piece[TOTAL_PIECE];
    YellowLudoPiece yellow_piece[TOTAL_PIECE];

    Turn current_turn;

    int rotated_dice_value;

    bool dice_rotated;

    int LUDO_BOARD_WIDTH;
    int LUDO_BOARD_HEIGHT;

public:
private:
    void drawLudoBoard(Window &);

    void drawStar(Window &, int, int);

    void drawDice(Window &);

    void renderPieces(Window &);

    void rotateDice();

    void updateLudoPiece();

public:
    Ludo();

    void render(Window &);

    void handleEvent(SDL_Event &e);
};
