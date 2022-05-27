#include "ludo.hpp"

Ludo::Ludo()
{
    red_piece[0].setRenderPosition({4, 1});
    red_piece[1].setRenderPosition({1, 1});
    red_piece[2].setRenderPosition({1, 4});
    red_piece[3].setRenderPosition({4, 4});

    green_piece[0].setRenderPosition({10, 1});
    green_piece[1].setRenderPosition({13, 1});
    green_piece[2].setRenderPosition({10, 4});
    green_piece[3].setRenderPosition({13, 4});

    yellow_piece[0].setRenderPosition({10, 10});
    yellow_piece[1].setRenderPosition({13, 10});
    yellow_piece[2].setRenderPosition({10, 13});
    yellow_piece[3].setRenderPosition({13, 13});

    blue_piece[0].setRenderPosition({1, 10});
    blue_piece[1].setRenderPosition({4, 10});
    blue_piece[2].setRenderPosition({1, 13});
    blue_piece[3].setRenderPosition({4, 13});

    for (int i = 0; i < TOTAL_PIECE; i++)
    {
        red_piece[i].setRenderPositionMovementIndex(-1);
        green_piece[i].setRenderPositionMovementIndex(-1);
        yellow_piece[i].setRenderPositionMovementIndex(-1);
        blue_piece[i].setRenderPositionMovementIndex(-1);

        red_piece[i].setStatus(HOME);
        green_piece[i].setStatus(HOME);
        yellow_piece[i].setStatus(HOME);
        blue_piece[i].setStatus(HOME);
    }

    rotated_dice_value = 0;
    current_turn = RED_PIECE;
    LUDO_BOARD_HEIGHT = 900;
    LUDO_BOARD_WIDTH = 900;

    dice_rotated = false;
}

void Ludo::drawLudoBoard(Window &window)
{
    /*Clearing the Window with white color*/
    SDL_SetRenderDrawColor(window.renderer, 255, 255, 255, 255);
    SDL_RenderClear(window.renderer);

    SDL_Rect small_block = {0, 0, window.getWidth() / 15, window.getHeight() / 15};
    SDL_Color block_color = {0, 0, 0, 255};

    SDL_SetRenderDrawColor(window.renderer, 0, 0, 0, 255);

    /*
    The below code will generate this geometry


    -------------------------
    |   |   |   |   |   |   |
    -------------------------
    |   |   |   |   |   |   |
    -------------------------
    |   |   |   |   |   |   |
    -------------------------
    |   |   |   |   |   |   |
    -------------------------
    |   |   |   |   |   |   |
    -------------------------           -------------------------
    |   |   |   |   |   |   |           |   |   |   |   |   |   |
    -------------------------           -------------------------
    |   | R | R | R | R | R |           | Y | Y | Y | Y | Y |   |
    -------------------------           -------------------------
    |   |   |   |   |   |   |           |   |   |   |   |   |   |
    -------------------------           -------------------------
                                        |   |   |   |   |   |   |
                                        -------------------------
                                        |   |   |   |   |   |   |
                                        -------------------------
                                        |   |   |   |   |   |   |
                                        -------------------------
                                        |   |   |   |   |   |   |
                                        -------------------------
                                        |   |   |   |   |   |   |
                                        -------------------------

    */
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 6; j++)
        {

            if (j >= 1 && i == 7 || i == 6 && j == 1 || i == 8 && j == 2)
            {
                /*
                This if is used to color the block with red(R) and make star
                    -------------------------
                    |   | * |   |   |   |   |
                    -------------------------
                    |   | R | R | R | R | R |
                    -------------------------
                    |   |   | * |   |   |   |
                    -------------------------
                */

                block_color = {255, 0, 0, 255}; // Red color
                SDL_SetRenderDrawColor(window.renderer, block_color.r, block_color.g, block_color.b, block_color.a);

                SDL_RenderFillRect(window.renderer, &small_block);

                block_color = {0, 0, 0, 255}; // Black color
                SDL_SetRenderDrawColor(window.renderer, block_color.r, block_color.g, block_color.b, block_color.a);

                if ((i == 6 && j == 1) || (i == 8 && j == 2))
                {
                    drawStar(window, small_block.y, small_block.x);
                }
            }

            SDL_RenderDrawRect(window.renderer, &small_block);

            /*Logic for another side rectangle drawing*/
            small_block.x += window.getWidth() / 15 * 9;
            small_block.y += window.getHeight() / 15 * 6;

            if ((j <= 4 && i == 1) || (i == 0 && j == 3) || (i == 2 && j == 4))
            {
                /*
                This if is used to color the block with yellow(Y).
                    -------------------------
                    |   |   |   | * |   |   |
                    -------------------------
                    | Y | Y | Y | Y | Y |   |
                    -------------------------
                    |   |   |   |   | * |   |
                    -------------------------
                */
                block_color = {240, 240, 0, 255}; // Yellow color
                SDL_SetRenderDrawColor(window.renderer, block_color.r, block_color.g, block_color.b, block_color.a);

                SDL_RenderFillRect(window.renderer, &small_block);

                block_color = {0, 0, 0, 255}; // Black color
                SDL_SetRenderDrawColor(window.renderer, block_color.r, block_color.g, block_color.b, block_color.a);

                if ((i == 0 && j == 3) || (i == 2 && j == 4))
                {
                    drawStar(window, small_block.y, small_block.x);
                }
            }

            SDL_RenderDrawRect(window.renderer, &small_block);

            small_block.x -= window.getWidth() / 15 * 9;
            small_block.y -= window.getHeight() / 15 * 6;

            small_block.x += window.getWidth() / 15;
        }
        small_block.x = 0;
        small_block.y += window.getHeight() / 15;
    }

    small_block = {0, window.getHeight() / 15 * 9, window.getWidth() / 15, window.getHeight() / 15};

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j == 7 && i <= 4 || j == 6 && i == 4 || j == 8 && i == 3)
            {
                block_color = {0, 0, 255, 255}; // Blue color
                SDL_SetRenderDrawColor(window.renderer, block_color.r, block_color.g, block_color.b, block_color.a);

                SDL_RenderFillRect(window.renderer, &small_block);

                block_color = {0, 0, 0, 255}; // Black color
                SDL_SetRenderDrawColor(window.renderer, block_color.r, block_color.g, block_color.b, block_color.a);

                if (j == 6 && i == 4 || j == 8 && i == 3)
                {
                    drawStar(window, small_block.y, small_block.x);
                }
            }
            SDL_RenderDrawRect(window.renderer, &small_block);

            /*Logic for another side rectangle drawing*/
            small_block.x += window.getWidth() / 15 * 6;
            small_block.y -= window.getHeight() / 15 * 9;

            if (j == 1 && i >= 1 || j == 0 && i == 2 || j == 2 && i == 1)
            {
                block_color = {0, 255, 0, 255}; // Green color
                SDL_SetRenderDrawColor(window.renderer, block_color.r, block_color.g, block_color.b, block_color.a);

                SDL_RenderFillRect(window.renderer, &small_block);

                block_color = {0, 0, 0, 255}; // Black color
                SDL_SetRenderDrawColor(window.renderer, block_color.r, block_color.g, block_color.b, block_color.a);

                if (j == 0 && i == 2 || j == 2 && i == 1)
                {
                    drawStar(window, small_block.y, small_block.x);
                }
            }

            SDL_RenderDrawRect(window.renderer, &small_block);

            small_block.x -= window.getWidth() / 15 * 6;
            small_block.y += window.getHeight() / 15 * 9;

            small_block.x += window.getWidth() / 15;
        }
        small_block.x = 0;
        small_block.y += window.getHeight() / 15;
    }

    /*Creating four color big boxes: red, blue, yellow, green*/
    SDL_Rect big_block = {0, 0, window.getWidth() / 15 * 6, window.getHeight() / 15 * 6};

    /*
    The below code will color the big box as the color indicated

    -------------------------------------------------------------
    |                       |   |   |   |                       |
    |                       |-----------|                       |
    |                       |   | G | * |                       |
    |                       |-----------|                       |
    |                       | * | G |   |                       |
    |                       |-----------|                       |
    |         RED           |   | G |   |         Green         |
    |                       |-----------|                       |
    |                       |   | G |   |                       |
    |                       |-----------|                       |
    |                       |   | G |   |                       |
    -------------------------------------------------------------
    |   | * |   |   |   |   |           |   |   |   | * |   |   |
    -------------------------           -------------------------
    |   |R  |R  |R  |R  |R  |           | Y | Y | Y | Y | Y |   |
    -------------------------           -------------------------
    |   |   | * |   |   |   |           |   |   |   |   | * |   |
    -------------------------------------------------------------
    |                       |   | B |   |                       |
    |                       |-----------|                       |
    |                       |   | B |   |                       |
    |                       |-----------|                       |
    |                       |   | B |   |                       |
    |                       |-----------|                       |
    |                       |   | B | * |                       |
    |                       |-----------|                       |
    |       Blue            | * | B |   |         YELLOW        |
    |                       |-----------|                       |
    |                       |   |   |   |                       |
    -------------------------------------------------------------
    */
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (i == 0 && j == 0)
            {
                block_color = {255, 0, 0, 255};
                SDL_SetRenderDrawColor(window.renderer, block_color.r, block_color.g, block_color.b, block_color.a);
            }
            else if (i == 0 && j == 1)
            {
                block_color = {0, 255, 0, 255};
                SDL_SetRenderDrawColor(window.renderer, block_color.r, block_color.g, block_color.b, block_color.a);
            }
            else if (i == 1 && j == 0)
            {
                block_color = {0, 0, 255, 255};
                SDL_SetRenderDrawColor(window.renderer, block_color.r, block_color.g, block_color.b, block_color.a);
            }
            else if (i == 1 && j == 1)
            {
                block_color = {240, 240, 0, 255};
                SDL_SetRenderDrawColor(window.renderer, block_color.r, block_color.g, block_color.b, block_color.a);
            }

            SDL_RenderFillRect(window.renderer, &big_block);
            big_block.x += window.getHeight() / 15 * 9;
        }
        big_block.x = 0;
        big_block.y += window.getWidth() / 15 * 9;
    }

    /*
    :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    In our real ludo board we have different arrow.
    And below line of code will draw the line like that of real ludo board
    :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    */
    block_color = {0, 0, 0, 255};
    SDL_SetRenderDrawColor(window.renderer, block_color.r, block_color.g, block_color.b, block_color.a);

    /*
         ---->
        |
        |
         ----
    */
    SDL_RenderDrawLine(window.renderer, window.getWidth() / 15 * 0.5, window.getHeight() / 15 * 7.5, window.getWidth() / 15 * 0.5, window.getHeight() / 15 * 8.5);
    SDL_RenderDrawLine(window.renderer, window.getWidth() / 15 * 0.5, window.getHeight() / 15 * 7.5, window.getWidth() / 15 * 1.5, window.getHeight() / 15 * 7.5);
    SDL_RenderDrawLine(window.renderer, window.getWidth() / 15 * 0.5, window.getHeight() / 15 * 8.5, window.getWidth() / 15 * 1.5, window.getHeight() / 15 * 8.5);

    /*
         ----
            |
            |
        <----
    */
    SDL_RenderDrawLine(window.renderer, window.getWidth() / 15 * 14.5, window.getHeight() / 15 * 7.5, window.getWidth() / 15 * 14.5, window.getHeight() / 15 * 6.5);
    SDL_RenderDrawLine(window.renderer, window.getWidth() / 15 * 13.5, window.getHeight() / 15 * 6.5, window.getWidth() / 15 * 14.5, window.getHeight() / 15 * 6.5);
    SDL_RenderDrawLine(window.renderer, window.getWidth() / 15 * 13.5, window.getHeight() / 15 * 7.5, window.getWidth() / 15 * 14.5, window.getHeight() / 15 * 7.5);

    /*
         ----
        |    |
        |    |
            \/(downarrow)
    */

    SDL_RenderDrawLine(window.renderer, window.getWidth() / 15 * 6.5, window.getHeight() / 15 * 0.5, window.getWidth() / 15 * 6.5, window.getHeight() / 15 * 1.5);
    SDL_RenderDrawLine(window.renderer, window.getWidth() / 15 * 7.5, window.getHeight() / 15 * 0.5, window.getWidth() / 15 * 7.5, window.getHeight() / 15 * 1.5);
    SDL_RenderDrawLine(window.renderer, window.getWidth() / 15 * 6.5, window.getHeight() / 15 * 0.5, window.getWidth() / 15 * 7.5, window.getHeight() / 15 * 0.5);

    /*
        /\(uparrow)
        |    |
        |    |
         ----
    */
    SDL_RenderDrawLine(window.renderer, window.getWidth() / 15 * 8.5, window.getHeight() / 15 * 13.5, window.getWidth() / 15 * 8.5, window.getHeight() / 15 * 14.5);
    SDL_RenderDrawLine(window.renderer, window.getWidth() / 15 * 7.5, window.getHeight() / 15 * 13.5, window.getWidth() / 15 * 7.5, window.getHeight() / 15 * 14.5);
    SDL_RenderDrawLine(window.renderer, window.getWidth() / 15 * 7.5, window.getHeight() / 15 * 14.5, window.getWidth() / 15 * 8.5, window.getHeight() / 15 * 14.5);

    /*
        ----->
    */
    SDL_RenderDrawLine(window.renderer, window.getWidth() / 15 * 4.5, window.getHeight() / 15 * 6.5, window.getWidth() / 15 * 5.5, window.getHeight() / 15 * 6.5);

    /*
        <-----
    */
    SDL_RenderDrawLine(window.renderer, window.getWidth() / 15 * 10.5, window.getHeight() / 15 * 8.5, window.getWidth() / 15 * 9.5, window.getHeight() / 15 * 8.5);
    /*
        /\(Uparrow)
        |
        |
        |
    */
    SDL_RenderDrawLine(window.renderer, window.getWidth() / 15 * 8.5, window.getHeight() / 15 * 4.5, window.getWidth() / 15 * 8.5, window.getHeight() / 15 * 5.5);

    /*
        |
        |
        |
        \/(Downarrow)
    */
    SDL_RenderDrawLine(window.renderer, window.getWidth() / 15 * 6.5, window.getHeight() / 15 * 9.5, window.getWidth() / 15 * 6.5, window.getHeight() / 15 * 10.5);

    block_color = {255, 255, 255, 255};
    SDL_SetRenderDrawColor(window.renderer, block_color.r, block_color.g, block_color.b, block_color.a);
    small_block = {window.getWidth() / 15, window.getHeight() / 15, window.getWidth() / 15, window.getHeight() / 15};

    /*
    This is will to create a place inside the big box to put the 4 pieces of each color
     _______________________
    |                       |
    |  ----           ----  |
    | |    |         |    | |
    |  ----           ----  |
    |                       |
    |  ----           ----  |
    | |    |         |    | |
    |  ----           ----  |
     -----------------------
    */
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            SDL_RenderFillRect(window.renderer, &small_block);
            small_block.x += window.getWidth() / 15 * 3;
            SDL_RenderFillRect(window.renderer, &small_block);
            small_block.x -= window.getWidth() / 15 * 3;

            small_block.y += window.getHeight() / 15 * 3;
            SDL_RenderFillRect(window.renderer, &small_block);
            small_block.x += window.getWidth() / 15 * 3;
            SDL_RenderFillRect(window.renderer, &small_block);
            small_block.x -= window.getWidth() / 15 * 3;
            small_block.y -= window.getHeight() / 15 * 3;

            small_block.x = window.getWidth() / 15 * 10;
        }
        small_block.x = window.getWidth() / 15;
        small_block.y = window.getHeight() / 15 * 10;
    }
}

void Ludo::drawStar(Window &window, int i, int j)
{
    /*
    ................................................
    This is used  to draw the star over the ludo box
    ................................................
    */
    SDL_RenderDrawLine(window.renderer, j + window.getWidth() / 15 * .5, i + window.getHeight() / 15 * 0, j + window.getWidth() / 15 * 24 / 110.0, i + window.getHeight() / 15 * .9);
    SDL_RenderDrawLine(window.renderer, j + window.getWidth() / 15 * .5, i + window.getHeight() / 15 * 0, j + window.getWidth() / 15 * 86 / 110.0, i + window.getHeight() / 15 * .9);
    SDL_RenderDrawLine(window.renderer, j + window.getWidth() / 15 * 24 / 110.0, i + window.getHeight() / 15 * .9, j + window.getWidth() / 15 * 107 / 110.0, i + window.getHeight() / 15 * 38 / 110.0);
    SDL_RenderDrawLine(window.renderer, j + window.getWidth() / 15 * 3 / 110.0, i + window.getHeight() / 15 * 38 / 110.0, j + window.getWidth() / 15 * 86 / 110.0, i + window.getHeight() / 15 * .9);
    SDL_RenderDrawLine(window.renderer, j + window.getWidth() / 15 * 3 / 110.0, i + window.getHeight() / 15 * 38 / 110.0, j + window.getWidth() / 15 * 107 / 110.0, i + window.getHeight() / 15 * 38 / 110.0);

    drawDice(window);

    return;
}

void Ludo::drawDice(Window &window)
{
    SDL_Rect dice_rectangle = {window.getWidth() / 15 * 6, window.getWidth() / 15 * 6, window.getWidth() / 15 * 3, window.getWidth() / 15 * 3};
    switch (current_turn)
    {
    case RED_PIECE:
        SDL_SetRenderDrawColor(window.renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(window.renderer, &dice_rectangle);
        break;

    case GREEN_PIECE:
        SDL_SetRenderDrawColor(window.renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(window.renderer, &dice_rectangle);
        break;

    case YELLOW_PIECE:
        SDL_SetRenderDrawColor(window.renderer, 255, 255, 0, 255);
        SDL_RenderFillRect(window.renderer, &dice_rectangle);
        break;

    case BLUE_PIECE:
        SDL_SetRenderDrawColor(window.renderer, 0, 0, 255, 255);
        SDL_RenderFillRect(window.renderer, &dice_rectangle);
        break;
    }

    /*

    The is the representation of the real dice where * denote the block dot over the dice.
    And the number of the side denote the position of the dot
    _____________       _____________
    | * | * | * |       | 1 | 2 | 3 |
    -------------       -------------
    | * | * | * |       | 4 | 5 | 6 |
    -------------       -------------
    | * | * | * |       | 7 | 8 | 9 |
    -------------       -------------

    SIX in the dice:
    To make six in the dice we have to render the black dot at position
    1,3,4,6,7,9
    _____________       _____________
    | * |   | * |       | 1 |   | 3 |
    -------------       -------------
    | * |   | * |       | 4 |   | 6 |
    -------------       -------------
    | * |   | * |       | 7 |   | 9 |
    -------------       -------------

    THREE in the dice:
    To make six in the dice we have to render the black dot at position
    2,5 8
    _____________       _____________
    |   | * |   |       |   | 2 |   |
    -------------       -------------
    |   | * |   |       |   | 5 |   |
    -------------       -------------
    |   | * |   |       |   | 8 |   |
    -------------       -------------

    FOUR in the dice:
    To make six in the dice we have to render the black dot at position
    1,3,7,9
    _____________       _____________
    | * |   | * |       | 1 |   | 3 |
    -------------       -------------
    |   |   |   |       |   |   |   |
    -------------       -------------
    | * |   | * |       | 7 |   | 9 |
    -------------       -------------

    Similarly, goes for the over value over the DICE.

    */

    SDL_Rect dice_black_dot_rectangle = {0, 0, 8, 8};

    SDL_SetRenderDrawColor(window.renderer, 0, 0, 0, 255);

    if (rotated_dice_value == 4 || rotated_dice_value == 6 || rotated_dice_value == 5)
    {
        /* At Position 1 */
        dice_black_dot_rectangle.x = window.getWidth() / 15 * 6 + 26;
        dice_black_dot_rectangle.y = window.getHeight() / 15 * 6 + 26;
        SDL_RenderFillRect(window.renderer, &dice_black_dot_rectangle);
    }

    if (rotated_dice_value == 3)
    {
        /* At Position 2 */
        dice_black_dot_rectangle.x = window.getWidth() / 15 * 7 + 26;
        dice_black_dot_rectangle.y = window.getHeight() / 15 * 6 + 26;
        SDL_RenderFillRect(window.renderer, &dice_black_dot_rectangle);
    }

    if (rotated_dice_value == 4 || rotated_dice_value == 5 || rotated_dice_value == 6)
    {
        /* At Position 3 */
        dice_black_dot_rectangle.x = window.getWidth() / 15 * 8 + 26;
        dice_black_dot_rectangle.y = window.getHeight() / 15 * 6 + 26;
        SDL_RenderFillRect(window.renderer, &dice_black_dot_rectangle);
    }

    if (rotated_dice_value == 2 || rotated_dice_value == 6)
    {
        /* At Position 4 */
        dice_black_dot_rectangle.x = window.getWidth() / 15 * 6 + 26;
        dice_black_dot_rectangle.y = window.getHeight() / 15 * 7 + 26;
        SDL_RenderFillRect(window.renderer, &dice_black_dot_rectangle);
    }

    if (rotated_dice_value == 3 || rotated_dice_value == 1 || rotated_dice_value == 5)
    {
        /* At Position 5 */
        dice_black_dot_rectangle.x = window.getWidth() / 15 * 7 + 26;
        dice_black_dot_rectangle.y = window.getHeight() / 15 * 7 + 26;
        SDL_RenderFillRect(window.renderer, &dice_black_dot_rectangle);
    }

    if (rotated_dice_value == 2 || rotated_dice_value == 6)
    {
        /* At Position 6 */
        dice_black_dot_rectangle.x = window.getWidth() / 15 * 8 + 26;
        dice_black_dot_rectangle.y = window.getHeight() / 15 * 7 + 26;
        SDL_RenderFillRect(window.renderer, &dice_black_dot_rectangle);
    }

    if (rotated_dice_value == 4 || rotated_dice_value == 6 || rotated_dice_value == 5)
    {
        /* At Position 7 */
        dice_black_dot_rectangle.x = window.getWidth() / 15 * 6 + 26;
        dice_black_dot_rectangle.y = window.getHeight() / 15 * 8 + 26;
        SDL_RenderFillRect(window.renderer, &dice_black_dot_rectangle);
    }

    if (rotated_dice_value == 3)
    {
        /* At Position 8 */
        dice_black_dot_rectangle.x = window.getWidth() / 15 * 7 + 26;
        dice_black_dot_rectangle.y = window.getHeight() / 15 * 8 + 26;
        SDL_RenderFillRect(window.renderer, &dice_black_dot_rectangle);
    }

    if (rotated_dice_value == 4 || rotated_dice_value == 6 || rotated_dice_value == 5)
    {
        /* At Position 9 */
        dice_black_dot_rectangle.x = window.getWidth() / 15 * 8 + 26;
        dice_black_dot_rectangle.y = window.getHeight() / 15 * 8 + 26;
        SDL_RenderFillRect(window.renderer, &dice_black_dot_rectangle);
    }
}

void Ludo::rotateDice()
{
    rotated_dice_value = rand() % 6 + 1;
}

void Ludo::renderPieces(Window &window)
{

    for (int i = 0; i < TOTAL_PIECE; i++)
    {
        red_piece[i].renderRedPiece(window);
        green_piece[i].renderGreenPiece(window);
        blue_piece[i].renderBluePiece(window);
        yellow_piece[i].renderYellowPiece(window);
    }
}

void Ludo::updateLudoPiece()
{
    for (int i = 0; i < TOTAL_PIECE; i++)
    {
        red_piece[i].updateRedPiece(this->current_turn, this->rotated_dice_value);
        green_piece[i].updateGreenPiece(this->current_turn, this->rotated_dice_value);
        blue_piece[i].updateBluePiece(this->current_turn, this->rotated_dice_value);
        yellow_piece[i].updateYellowPiece(this->current_turn, this->rotated_dice_value);
    }
}

void Ludo::render(Window &window)
{
    drawLudoBoard(window);
    renderPieces(window);
}

void Ludo::handleEvent(SDL_Event &e)
{
    /*It rotate the dice*/
    if (e.key.keysym.sym == SDLK_d && e.type == SDL_KEYDOWN && dice_rotated == false)
    {
        rotateDice();
        dice_rotated = true;
    }

    /*after rotation of the dice it execute when user pressed over peice it move that piece*/
    if (e.type == SDL_MOUSEBUTTONDOWN && dice_rotated == true)
    {

        SDL_Point mouse_clicked_position;

        SDL_GetMouseState(&mouse_clicked_position.x, &mouse_clicked_position.y);

        for (int i = 0; i < TOTAL_PIECE; i++)
        {
            if (current_turn == RED_PIECE)
            {
                if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == red_piece[i].getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == red_piece[i].getRenderPosition().y)
                {

                    red_piece[i].updateRedPiece(current_turn, rotated_dice_value);
                    dice_rotated = false;
                }
            }
            else if (current_turn == GREEN_PIECE)

            {
                if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == green_piece[i].getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == green_piece[i].getRenderPosition().y)
                {
                    green_piece[i].updateGreenPiece(current_turn, rotated_dice_value);
                    dice_rotated = false;
                }
            }
            else if (current_turn == YELLOW_PIECE)
            {
                if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == yellow_piece[i].getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == yellow_piece[i].getRenderPosition().y)
                {
                    yellow_piece[i].updateYellowPiece(current_turn, rotated_dice_value);
                    dice_rotated = false;
                }
            }
            else if (current_turn == BLUE_PIECE)
            {
                if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == blue_piece[i].getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == blue_piece[i].getRenderPosition().y)
                {
                    blue_piece[i].updateBluePiece(current_turn, rotated_dice_value);
                    dice_rotated = false;
                }
            }
        }
    }
}