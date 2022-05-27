#pragma once

#include "window.hpp"

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
    YELLOW_PIECE,
    TOTAL_PIECE,
};

class LudoPiece
{
private:
    SDL_Point render_position;

    int render_position_movement_index;

    Status_Of_Ludo_Piece status;

public:
    LudoPiece();
    LudoPiece(SDL_Point);

    ~LudoPiece();

    void setRenderPosition(SDL_Point);
    void setRenderPositionMovementIndex(int);
    void setStatus(Status_Of_Ludo_Piece);

    SDL_Point getRenderPosition();
    Status_Of_Ludo_Piece getStatus();
    int getRenderPositionMovementIndex();

    // It render the piece.
    void render(Window &);
};

class RedLudoPiece : public LudoPiece
{
private:
    const SDL_Point render_position_movement[TOTAL_DICE_MOVES] = {{1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 5}, {6, 4}, {6, 3}, {6, 2}, {6, 1}, {6, 0}, {7, 0}, {8, 0}, {8, 1}, {8, 2}, {8, 3}, {8, 4}, {8, 5}, {9, 6}, {10, 6}, {11, 6}, {12, 6}, {13, 6}, {14, 6}, {14, 7}, {14, 8}, {13, 8}, {12, 8}, {11, 8}, {10, 8}, {9, 8}, {8, 9}, {8, 10}, {8, 11}, {8, 12}, {8, 13}, {8, 14}, {7, 14}, {6, 14}, {6, 13}, {6, 12}, {6, 11}, {6, 10}, {6, 9}, {5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}, {0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}};

public:
    RedLudoPiece();
    RedLudoPiece(SDL_Point);

    ~RedLudoPiece();

    void updateRedPiece(Turn &, int);

    void renderRedPiece(Window &);
};

class GreenLudoPiece : public LudoPiece
{
private:
    const SDL_Point render_position_movement[TOTAL_DICE_MOVES] = {{8, 1}, {8, 2}, {8, 3}, {8, 4}, {8, 5}, {9, 6}, {10, 6}, {11, 6}, {12, 6}, {13, 6}, {14, 6}, {14, 7}, {14, 8}, {13, 8}, {12, 8}, {11, 8}, {10, 8}, {9, 8}, {8, 9}, {8, 10}, {8, 11}, {8, 12}, {8, 13}, {8, 14}, {7, 14}, {6, 14}, {6, 13}, {6, 12}, {6, 11}, {6, 10}, {6, 9}, {5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}, {0, 7}, {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 5}, {6, 4}, {6, 3}, {6, 2}, {6, 1}, {6, 0}, {7, 0}, {7, 1}, {7, 2}, {7, 3}, {7, 4}, {7, 5}};

public:
    GreenLudoPiece();
    GreenLudoPiece(SDL_Point render_position);

    ~GreenLudoPiece();

    void updateGreenPiece(Turn &, int);

    void renderGreenPiece(Window &);
};

class YellowLudoPiece : public LudoPiece
{
private:
    const SDL_Point render_position_movement[TOTAL_DICE_MOVES] = {{13, 8}, {12, 8}, {11, 8}, {10, 8}, {9, 8}, {8, 9}, {8, 10}, {8, 11}, {8, 12}, {8, 13}, {8, 14}, {7, 14}, {6, 14}, {6, 13}, {6, 12}, {6, 11}, {6, 10}, {6, 9}, {5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}, {0, 7}, {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 5}, {6, 4}, {6, 3}, {6, 2}, {6, 1}, {6, 0}, {7, 0}, {8, 0}, {8, 1}, {8, 2}, {8, 3}, {8, 4}, {8, 5}, {9, 6}, {10, 6}, {11, 6}, {12, 6}, {13, 6}, {14, 6}, {14, 7}, {13, 7}, {12, 7}, {11, 7}, {10, 7}, {9, 7}};

public:
    YellowLudoPiece();
    YellowLudoPiece(SDL_Point render_position);

    ~YellowLudoPiece();

    void updateYellowPiece(Turn &, int);

    void renderYellowPiece(Window &);
};

class BlueLudoPiece : public LudoPiece
{
private:
    const SDL_Point render_position_movement[TOTAL_DICE_MOVES] = {{6, 13}, {6, 12}, {6, 11}, {6, 10}, {6, 9}, {5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}, {0, 7}, {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 5}, {6, 4}, {6, 3}, {6, 2}, {6, 1}, {6, 0}, {7, 0}, {8, 0}, {8, 1}, {8, 2}, {8, 3}, {8, 4}, {8, 5}, {9, 6}, {10, 6}, {11, 6}, {12, 6}, {13, 6}, {14, 6}, {14, 7}, {14, 8}, {13, 8}, {12, 8}, {11, 8}, {10, 8}, {9, 8}, {8, 9}, {8, 10}, {8, 11}, {8, 12}, {8, 13}, {8, 14}, {7, 14}, {7, 13}, {7, 12}, {7, 11}, {7, 10}, {7, 9}};

public:
    BlueLudoPiece();
    BlueLudoPiece(SDL_Point render_position);

    ~BlueLudoPiece();

    void updateBluePiece(Turn &, int);

    void renderBluePiece(Window &);
};
