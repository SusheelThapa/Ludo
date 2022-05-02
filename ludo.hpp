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

class LudoPiece
{
private:
    SDL_Point render_position;

public:
    LudoPiece()
    {
    }
    LudoPiece(SDL_Point render_position)
    {
        this->render_position = render_position;
    }
    ~LudoPiece()
    {
    }

    void setRenderPosition(SDL_Point render_position)
    {
        this->render_position = render_position;
    }

    SDL_Point getRenderPosition()
    {
        return this->render_position;
    }
};

class RedLudoPiece : public LudoPiece
{
private:
    const SDL_Point render_position_movement[57] = {{1, 1}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 5}, {6, 4}, {6, 3}, {6, 2}, {6, 1}, {6, 0}, {7, 0}, {8, 0}, {8, 1}, {8, 2}, {8, 3}, {8, 4}, {8, 5}, {9, 6}, {10, 6}, {11, 6}, {12, 6}, {13, 6}, {14, 6}, {14, 7}, {14, 8}, {13, 8}, {12, 8}, {11, 8}, {10, 8}, {9, 8}, {8, 9}, {8, 10}, {8, 11}, {8, 12}, {8, 13}, {8, 14}, {7, 14}, {6, 14}, {6, 13}, {6, 12}, {6, 11}, {6, 10}, {6, 9}, {5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}, {0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}};

public:
    RedLudoPiece()
    {
        this->setRenderPosition(render_position_movement[0]);
    }

    SDL_Point getRenderPositionMovement(int index)
    {
        return render_position_movement[index];
    }
    void render()
    {
        SDL_SetRenderDrawColor(ludo_game_board_renderer, 200, 23, 229, 255);

        SDL_Rect render_quad = {LUDO_BOARD_WIDTH / 15 * this->getRenderPosition().x + (LUDO_BOARD_WIDTH / 15 - 30) / 2, LUDO_BOARD_HEIGHT / 15 * this->getRenderPosition().y + (LUDO_BOARD_HEIGHT / 15 - 30) / 2, 30, 30};

        SDL_RenderFillRect(ludo_game_board_renderer, &render_quad);

        SDL_RenderPresent(ludo_game_board_renderer);

        SDL_SetRenderDrawColor(ludo_game_board_renderer, 255, 255, 255, 255);
    }
};