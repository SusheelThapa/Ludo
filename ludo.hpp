#pragma once

#if !defined(HEADER_EXIST)
#include "header.hpp"
#endif

/*<----Constants---->*/
const int LUDO_BOARD_WIDTH = 900;
const int LUDO_BOARD_HEIGHT = 900;
const int TOTAL_DICE_MOVES = 56;

enum Status_Of_Ludo_Piece
{
    HOME,
    RUNNING,
    COMPLETED
};

enum Turn
{
    RED_PIECE,
    BLUE_PIECE,
    GREEN_PIECE,
    YELLOW_PEICE
};

/*
=========================================================
                    <----LudoPiece---->
And by inheritance we have created 4 different ludo piece
=========================================================
*/
class LudoPiece
{
private:
    SDL_Point render_position;

public:
    // Constructor
    LudoPiece();
    LudoPiece(SDL_Point render_position);

    // Destructor
    ~LudoPiece();

    // It sets the position where we render the piece.
    void setRenderPosition(SDL_Point render_position);

    // It gets the render position of the piece we have render.
    SDL_Point getRenderPosition();

    // It render the piece.
    void render();
};

class RedLudoPiece : public LudoPiece
{
private:
    // Array of point where our peice will move in the ludo board
    const SDL_Point render_position_movement[TOTAL_DICE_MOVES] = {{1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 5}, {6, 4}, {6, 3}, {6, 2}, {6, 1}, {6, 0}, {7, 0}, {8, 0}, {8, 1}, {8, 2}, {8, 3}, {8, 4}, {8, 5}, {9, 6}, {10, 6}, {11, 6}, {12, 6}, {13, 6}, {14, 6}, {14, 7}, {14, 8}, {13, 8}, {12, 8}, {11, 8}, {10, 8}, {9, 8}, {8, 9}, {8, 10}, {8, 11}, {8, 12}, {8, 13}, {8, 14}, {7, 14}, {6, 14}, {6, 13}, {6, 12}, {6, 11}, {6, 10}, {6, 9}, {5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}, {0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}};

    // Keep track of the index in the above movement array
    int render_position_movement_index;

    // Keep whether the piece is  inside the home, in the game or compelete the game
    Status_Of_Ludo_Piece status;

public:
    RedLudoPiece();
    RedLudoPiece(SDL_Point render_position);

    ~RedLudoPiece();

    SDL_Point getRenderPositionMovement(int dice_value);

    void setStatus(Status_Of_Ludo_Piece status);
    Status_Of_Ludo_Piece getStatus();
    int getRenderPositionMovement() { return render_position_movement_index; }

    void renderLudoRedPiece();
};

class GreenLudoPiece : public LudoPiece
{
private:
    // Array of point where our peice will move in the ludo board
    const SDL_Point render_position_movement[TOTAL_DICE_MOVES] = {{8, 1}, {8, 2}, {8, 3}, {8, 4}, {8, 5}, {9, 6}, {10, 6}, {11, 6}, {12, 6}, {13, 6}, {14, 6}, {14, 7}, {14, 8}, {13, 8}, {12, 8}, {11, 8}, {10, 8}, {9, 8}, {8, 9}, {8, 10}, {8, 11}, {8, 12}, {8, 13}, {8, 14}, {7, 14}, {6, 14}, {6, 13}, {6, 12}, {6, 11}, {6, 10}, {6, 9}, {5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}, {0, 7}, {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 5}, {6, 4}, {6, 3}, {6, 2}, {6, 1}, {6, 0}, {7, 0}, {7, 1}, {7, 2}, {7, 3}, {7, 4}, {7, 5}};

    // Keep track of the index in the above movement array
    int render_position_movement_index;

    // Keep whether the piece is  inside the home, in the game or compelete the game
    Status_Of_Ludo_Piece status;

public:
    GreenLudoPiece();
    GreenLudoPiece(SDL_Point render_position);

    ~GreenLudoPiece();

    SDL_Point getRenderPositionMovement(int dice_value);

    void renderLudoGreenPiece();
};

class YellowLudoPiece : public LudoPiece
{
private:
    // Array of point where our peice will move in the ludo board
    const SDL_Point render_position_movement[TOTAL_DICE_MOVES] = {{13, 8}, {12, 8}, {11, 8}, {10, 8}, {9, 8}, {8, 9}, {8, 10}, {8, 11}, {8, 12}, {8, 13}, {8, 14}, {7, 14}, {6, 14}, {6, 13}, {6, 12}, {6, 11}, {6, 10}, {6, 9}, {5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}, {0, 7}, {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 5}, {6, 4}, {6, 3}, {6, 2}, {6, 1}, {6, 0}, {7, 0}, {8, 0}, {8, 1}, {8, 2}, {8, 3}, {8, 4}, {8, 5}, {9, 6}, {10, 6}, {11, 6}, {12, 6}, {13, 6}, {14, 6}, {14, 7}, {13, 7}, {12, 7}, {11, 7}, {10, 7}, {9, 7}};

    // Keep track of the index in the above movement array
    int render_position_movement_index;

    // Keep whether the piece is  inside the home, in the game or compelete the game
    Status_Of_Ludo_Piece status;

public:
    YellowLudoPiece();
    YellowLudoPiece(SDL_Point render_position);

    ~YellowLudoPiece();

    SDL_Point getRenderPositionMovement(int dice_value);

    void renderLudoYellowPiece();
};

class BlueLudoPiece : public LudoPiece
{
private:
    // Array of point where our peice will move in the ludo board
    const SDL_Point render_position_movement[TOTAL_DICE_MOVES] = {{6, 13}, {6, 12}, {6, 11}, {6, 10}, {6, 9}, {5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}, {0, 7}, {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 5}, {6, 4}, {6, 3}, {6, 2}, {6, 1}, {6, 0}, {7, 0}, {8, 0}, {8, 1}, {8, 2}, {8, 3}, {8, 4}, {8, 5}, {9, 6}, {10, 6}, {11, 6}, {12, 6}, {13, 6}, {14, 6}, {14, 7}, {14, 8}, {13, 8}, {12, 8}, {11, 8}, {10, 8}, {9, 8}, {8, 9}, {8, 10}, {8, 11}, {8, 12}, {8, 13}, {8, 14}, {7, 14}, {7, 13}, {7, 12}, {7, 11}, {7, 10}, {7, 9}};

    // Keep track of the index in the above movement array
    int render_position_movement_index;

    // Keep whether the piece is  inside the home, in the game or compelete the game
    Status_Of_Ludo_Piece status;

public:
    BlueLudoPiece();
    BlueLudoPiece(SDL_Point render_position);

    ~BlueLudoPiece();

    SDL_Point getRenderPositionMovement(int dice_value);

    void renderLudoBluePiece();
};

bool initializeLudoGame();
bool loadLudoGame();
void diceRotate();
void drawStar(int, int);
void closeLudoGame();

SDL_Window *ludo_game_board;
SDL_Renderer *ludo_game_board_renderer;
SDL_Event ludo_game_events;

Turn current_turn;
int dice_rotate_value;