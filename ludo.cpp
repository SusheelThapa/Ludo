#include "ludo.hpp"

RedLudoPiece red_piece_one = RedLudoPiece({4, 1});
RedLudoPiece red_piece_two = RedLudoPiece({1, 1});
RedLudoPiece red_piece_three = RedLudoPiece({1, 4});
RedLudoPiece red_piece_four = RedLudoPiece({4, 4});

GreenLudoPiece green_piece_one = GreenLudoPiece({10, 1});
GreenLudoPiece green_piece_two = GreenLudoPiece({13, 1});
GreenLudoPiece green_piece_three = GreenLudoPiece({10, 4});
GreenLudoPiece green_piece_four = GreenLudoPiece({13, 4});

BlueLudoPiece blue_piece_one = BlueLudoPiece({1, 10});
BlueLudoPiece blue_piece_two = BlueLudoPiece({4, 10});
BlueLudoPiece blue_piece_three = BlueLudoPiece({1, 13});
BlueLudoPiece blue_piece_four = BlueLudoPiece({4, 13});

YellowLudoPiece yellow_piece_one = YellowLudoPiece({10, 10});
YellowLudoPiece yellow_piece_two = YellowLudoPiece({13, 10});
YellowLudoPiece yellow_piece_three = YellowLudoPiece({10, 13});
YellowLudoPiece yellow_piece_four = YellowLudoPiece({13, 13});

/*
=============================================================
    <---Starting of the Ludo Piece Class---->
*/

LudoPiece::LudoPiece()
{
    // Empty constructor
}

LudoPiece::~LudoPiece()
{
    // Empty destructor
}

// Costructor overloading
LudoPiece::LudoPiece(SDL_Point render_position)
{
    this->render_position = render_position;
}

void LudoPiece::setRenderPosition(SDL_Point render_position)
{
    this->render_position = render_position;
}

SDL_Point LudoPiece::getRenderPosition()
{
    return this->render_position;
}

void LudoPiece::render()
{

    SDL_Rect render_quad = {LUDO_BOARD_WIDTH / 15 * this->getRenderPosition().x + (LUDO_BOARD_WIDTH / 15 - 30) / 2, LUDO_BOARD_HEIGHT / 15 * this->getRenderPosition().y + (LUDO_BOARD_HEIGHT / 15 - 30) / 2, 30, 30};

    SDL_RenderFillRect(ludo_game_board_renderer, &render_quad);
}
/*
    <----Ending of the Ludo Piece Class----->
====================================================================
*/

/*
==================================================
    <----Starting of the RedLudoPiece---->
*/

RedLudoPiece::RedLudoPiece() : LudoPiece()
{
    render_position_movement_index = -1;
}

RedLudoPiece::~RedLudoPiece()
{
    // Empty destructor
}

// Constructor overloading
RedLudoPiece::RedLudoPiece(SDL_Point render_position)
{
    render_position_movement_index = -1;

    this->setRenderPosition(render_position);
}

SDL_Point RedLudoPiece ::getRenderPositionMovement(int dice_value)
{

    render_position_movement_index += dice_value;
    std::cout << render_position_movement_index << std::endl;
    return render_position_movement[render_position_movement_index];
}

void RedLudoPiece::setStatus(Status_Of_Ludo_Piece status)
{
    this->status = status;
}

Status_Of_Ludo_Piece RedLudoPiece::getStatus()
{
    return status;
}

void RedLudoPiece::renderLudoRedPiece()
{
    SDL_SetRenderDrawColor(ludo_game_board_renderer, 200, 0, 0, 255);
    this->render();
}

/*
    <----Ending of the RedLudoPiece---->
==================================================
*/

/*
==================================================
    <----Starting of the GreenLudoPiece---->
*/

GreenLudoPiece::GreenLudoPiece()
{
    render_position_movement_index = -1;
    status = HOME;
}
GreenLudoPiece::~GreenLudoPiece()
{
    // Empty destructor
}

// Constructor overloading
GreenLudoPiece::GreenLudoPiece(SDL_Point render_position)
{
    this->setRenderPosition(render_position);
}

SDL_Point GreenLudoPiece ::getRenderPositionMovement(int dice_value)
{
    if (render_position_movement_index > 55)
    {
        render_position_movement_index = 0;
    }
    else
    {
        if (render_position_movement_index > 55)
        {
            render_position_movement_index = 0;
        }
        else
        {
            render_position_movement_index += dice_value;
        }
    }
    return render_position_movement[render_position_movement_index];
}

void GreenLudoPiece::renderLudoGreenPiece()
{
    SDL_SetRenderDrawColor(ludo_game_board_renderer, 0, 200, 0, 255);
    this->render();
}

/*
    <----Ending of the RedLudoPiece---->
==================================================
*/

/*
==================================================
    <----Starting of the BlueLudoPiece---->
*/

BlueLudoPiece::BlueLudoPiece()
{
    render_position_movement_index = -1;
    status = HOME;
}
BlueLudoPiece::~BlueLudoPiece()
{
    // Empty destructor
}

// Constructor overloading
BlueLudoPiece::BlueLudoPiece(SDL_Point render_position)
{
    this->setRenderPosition(render_position);
}

SDL_Point BlueLudoPiece ::getRenderPositionMovement(int dice_value)
{
    if (render_position_movement_index > 55)
    {
        render_position_movement_index = 0;
    }
    else
    {
        render_position_movement_index += dice_value;
    }
    return render_position_movement[render_position_movement_index];
}

void BlueLudoPiece::renderLudoBluePiece()
{
    SDL_SetRenderDrawColor(ludo_game_board_renderer, 0, 0, 200, 255);
    this->render();
}
/*
    <----Ending of BlueLudoPiece---->
==================================================
*/

/*
==================================================
    <----Starting of the YellowLudoPiece---->
*/

YellowLudoPiece::YellowLudoPiece()
{
    render_position_movement_index = -1;
    status = HOME;
}
YellowLudoPiece::~YellowLudoPiece()
{
    // Empty destructor
}

// Constructor overloading
YellowLudoPiece::YellowLudoPiece(SDL_Point render_position)
{
    this->setRenderPosition(render_position);
}

SDL_Point YellowLudoPiece ::getRenderPositionMovement(int dice_value)
{
    if (render_position_movement_index > 55)
    {
        render_position_movement_index = 0;
    }
    else
    {
        render_position_movement_index += dice_value;
    }
    return render_position_movement[render_position_movement_index];
}

void YellowLudoPiece::renderLudoYellowPiece()
{
    SDL_SetRenderDrawColor(ludo_game_board_renderer, 200, 200, 0, 255);
    this->render();
}

/*
    <----Ending of YellowLudoPiece---->
==================================================
*/

/*
=======================
Helper Function
=======================
*/
bool initializeLudoGame()
{

    /*initialize function flag*/
    bool status = true;

    /*Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Unable to initialize SDL.\nSDL_GetError: " << SDL_GetError() << std::endl;
        status = false;
    }

#if defined(SDL_IMAGE_MAJOR_VERSION)

    /*Initialize SDL image()*/
    int image_flag = IMG_INIT_PNG;
    if (!(IMG_Init(image_flag) & image_flag))
    {
        std::cout << "Unable to initalize SDL Images.\nIMG_Error: " << IMG_GetError() << std::endl;
        status = false;
    }

#endif

#if defined(SDL_TTF_MAJOR_VERSION)

    /* Initialize SDL_ttf*/
    if (TTF_Init() == -1)
    {
        std::cout << "Unable to initalize SDL TTF.\nTTF_Error: " << TTF_GetError() << std::endl;
        status = false;
    }

#endif
    return status;
}

bool loadLudoGame()
{
    bool status = true;

    /*
    ((((((((((((((((()))))))))))))))))
    Create the window for the LUDO game
    ((((((((((((((((()))))))))))))))))
    */
    ludo_game_board = SDL_CreateWindow("LUDO", 200, 0, LUDO_BOARD_WIDTH, LUDO_BOARD_HEIGHT, SDL_WINDOW_SHOWN);
    if (ludo_game_board == NULL)
    {
        std::cout << "Unable to create window\n";
        status = false;
    }

    /*
    (((((((((((((((((())))))))))))))))))
    Create renderer object of the window
    (((((((((((((((((())))))))))))))))))
    */
    ludo_game_board_renderer = SDL_CreateRenderer(ludo_game_board, -1, SDL_RENDERER_ACCELERATED);
    if (ludo_game_board_renderer == NULL)
    {
        std::cout << "Unable to create renderer object of the window.\n";
        status = false;
    }

    current_turn = RED_PIECE;
    dice_rotate_value = 0;
    return status;
}

void closeLudoGame()
{
    SDL_DestroyRenderer(ludo_game_board_renderer);
    SDL_DestroyWindow(ludo_game_board);

#if defined(SDL_TTF_MAJOR_VERSION)

    TTF_Quit();

#endif

#if defined(SDL_IMAGE_MAJOR_VERSION)

    IMG_Quit();

#endif

    SDL_Quit();
}

void loadLudoGameBoard()
{
    /*Clearing the Window with white color*/
    SDL_SetRenderDrawColor(ludo_game_board_renderer, 255, 255, 255, 255);
    SDL_RenderClear(ludo_game_board_renderer);

    SDL_Rect small_block = {0, 0, LUDO_BOARD_WIDTH / 15, LUDO_BOARD_HEIGHT / 15};
    SDL_Color block_color = {0, 0, 0, 255};

    SDL_SetRenderDrawColor(ludo_game_board_renderer, 0, 0, 0, 255);

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
                SDL_SetRenderDrawColor(ludo_game_board_renderer, block_color.r, block_color.g, block_color.b, block_color.a);

                SDL_RenderFillRect(ludo_game_board_renderer, &small_block);

                block_color = {0, 0, 0, 255}; // Black color
                SDL_SetRenderDrawColor(ludo_game_board_renderer, block_color.r, block_color.g, block_color.b, block_color.a);

                if ((i == 6 && j == 1) || (i == 8 && j == 2))
                {
                    drawStar(small_block.y, small_block.x);
                }
            }

            SDL_RenderDrawRect(ludo_game_board_renderer, &small_block);

            /*Logic for another side rectangle drawing*/
            small_block.x += LUDO_BOARD_WIDTH / 15 * 9;
            small_block.y += LUDO_BOARD_HEIGHT / 15 * 6;

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
                SDL_SetRenderDrawColor(ludo_game_board_renderer, block_color.r, block_color.g, block_color.b, block_color.a);

                SDL_RenderFillRect(ludo_game_board_renderer, &small_block);

                block_color = {0, 0, 0, 255}; // Black color
                SDL_SetRenderDrawColor(ludo_game_board_renderer, block_color.r, block_color.g, block_color.b, block_color.a);

                if ((i == 0 && j == 3) || (i == 2 && j == 4))
                {
                    drawStar(small_block.y, small_block.x);
                }
            }

            SDL_RenderDrawRect(ludo_game_board_renderer, &small_block);

            small_block.x -= LUDO_BOARD_WIDTH / 15 * 9;
            small_block.y -= LUDO_BOARD_HEIGHT / 15 * 6;

            small_block.x += LUDO_BOARD_WIDTH / 15;
        }
        small_block.x = 0;
        small_block.y += LUDO_BOARD_HEIGHT / 15;
    }

    small_block = {0, LUDO_BOARD_HEIGHT / 15 * 9, LUDO_BOARD_WIDTH / 15, LUDO_BOARD_HEIGHT / 15};

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j == 7 && i <= 4 || j == 6 && i == 4 || j == 8 && i == 3)
            {
                block_color = {0, 0, 255, 255}; // Blue color
                SDL_SetRenderDrawColor(ludo_game_board_renderer, block_color.r, block_color.g, block_color.b, block_color.a);

                SDL_RenderFillRect(ludo_game_board_renderer, &small_block);

                block_color = {0, 0, 0, 255}; // Black color
                SDL_SetRenderDrawColor(ludo_game_board_renderer, block_color.r, block_color.g, block_color.b, block_color.a);

                if (j == 6 && i == 4 || j == 8 && i == 3)
                {
                    drawStar(small_block.y, small_block.x);
                }
            }
            SDL_RenderDrawRect(ludo_game_board_renderer, &small_block);

            /*Logic for another side rectangle drawing*/
            small_block.x += LUDO_BOARD_WIDTH / 15 * 6;
            small_block.y -= LUDO_BOARD_HEIGHT / 15 * 9;

            if (j == 1 && i >= 1 || j == 0 && i == 2 || j == 2 && i == 1)
            {
                block_color = {0, 255, 0, 255}; // Green color
                SDL_SetRenderDrawColor(ludo_game_board_renderer, block_color.r, block_color.g, block_color.b, block_color.a);

                SDL_RenderFillRect(ludo_game_board_renderer, &small_block);

                block_color = {0, 0, 0, 255}; // Black color
                SDL_SetRenderDrawColor(ludo_game_board_renderer, block_color.r, block_color.g, block_color.b, block_color.a);

                if (j == 0 && i == 2 || j == 2 && i == 1)
                {
                    drawStar(small_block.y, small_block.x);
                }
            }

            SDL_RenderDrawRect(ludo_game_board_renderer, &small_block);

            small_block.x -= LUDO_BOARD_WIDTH / 15 * 6;
            small_block.y += LUDO_BOARD_HEIGHT / 15 * 9;

            small_block.x += LUDO_BOARD_WIDTH / 15;
        }
        small_block.x = 0;
        small_block.y += LUDO_BOARD_HEIGHT / 15;
    }

    /*Creating four color big boxes: red, blue, yellow, green*/
    SDL_Rect big_block = {0, 0, LUDO_BOARD_WIDTH / 15 * 6, LUDO_BOARD_HEIGHT / 15 * 6};

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
                SDL_SetRenderDrawColor(ludo_game_board_renderer, block_color.r, block_color.g, block_color.b, block_color.a);
            }
            else if (i == 0 && j == 1)
            {
                block_color = {0, 255, 0, 255};
                SDL_SetRenderDrawColor(ludo_game_board_renderer, block_color.r, block_color.g, block_color.b, block_color.a);
            }
            else if (i == 1 && j == 0)
            {
                block_color = {0, 0, 255, 255};
                SDL_SetRenderDrawColor(ludo_game_board_renderer, block_color.r, block_color.g, block_color.b, block_color.a);
            }
            else if (i == 1 && j == 1)
            {
                block_color = {240, 240, 0, 255};
                SDL_SetRenderDrawColor(ludo_game_board_renderer, block_color.r, block_color.g, block_color.b, block_color.a);
            }

            SDL_RenderFillRect(ludo_game_board_renderer, &big_block);
            big_block.x += LUDO_BOARD_HEIGHT / 15 * 9;
        }
        big_block.x = 0;
        big_block.y += LUDO_BOARD_WIDTH / 15 * 9;
    }

    /*
    :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    In our real ludo board we have different arrow.
    And below line of code will draw the line like that of real ludo board
    :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    */
    block_color = {0, 0, 0, 255};
    SDL_SetRenderDrawColor(ludo_game_board_renderer, block_color.r, block_color.g, block_color.b, block_color.a);

    /*
         ---->
        |
        |
         ----
    */
    SDL_RenderDrawLine(ludo_game_board_renderer, LUDO_BOARD_WIDTH / 15 * 0.5, LUDO_BOARD_HEIGHT / 15 * 7.5, LUDO_BOARD_WIDTH / 15 * 0.5, LUDO_BOARD_HEIGHT / 15 * 8.5);
    SDL_RenderDrawLine(ludo_game_board_renderer, LUDO_BOARD_WIDTH / 15 * 0.5, LUDO_BOARD_HEIGHT / 15 * 7.5, LUDO_BOARD_WIDTH / 15 * 1.5, LUDO_BOARD_HEIGHT / 15 * 7.5);
    SDL_RenderDrawLine(ludo_game_board_renderer, LUDO_BOARD_WIDTH / 15 * 0.5, LUDO_BOARD_HEIGHT / 15 * 8.5, LUDO_BOARD_WIDTH / 15 * 1.5, LUDO_BOARD_HEIGHT / 15 * 8.5);

    /*
         ----
            |
            |
        <----
    */
    SDL_RenderDrawLine(ludo_game_board_renderer, LUDO_BOARD_WIDTH / 15 * 14.5, LUDO_BOARD_HEIGHT / 15 * 7.5, LUDO_BOARD_WIDTH / 15 * 14.5, LUDO_BOARD_HEIGHT / 15 * 6.5);
    SDL_RenderDrawLine(ludo_game_board_renderer, LUDO_BOARD_WIDTH / 15 * 13.5, LUDO_BOARD_HEIGHT / 15 * 6.5, LUDO_BOARD_WIDTH / 15 * 14.5, LUDO_BOARD_HEIGHT / 15 * 6.5);
    SDL_RenderDrawLine(ludo_game_board_renderer, LUDO_BOARD_WIDTH / 15 * 13.5, LUDO_BOARD_HEIGHT / 15 * 7.5, LUDO_BOARD_WIDTH / 15 * 14.5, LUDO_BOARD_HEIGHT / 15 * 7.5);

    /*
         ----
        |    |
        |    |
            \/(downarrow)
    */

    SDL_RenderDrawLine(ludo_game_board_renderer, LUDO_BOARD_WIDTH / 15 * 6.5, LUDO_BOARD_HEIGHT / 15 * 0.5, LUDO_BOARD_WIDTH / 15 * 6.5, LUDO_BOARD_HEIGHT / 15 * 1.5);
    SDL_RenderDrawLine(ludo_game_board_renderer, LUDO_BOARD_WIDTH / 15 * 7.5, LUDO_BOARD_HEIGHT / 15 * 0.5, LUDO_BOARD_WIDTH / 15 * 7.5, LUDO_BOARD_HEIGHT / 15 * 1.5);
    SDL_RenderDrawLine(ludo_game_board_renderer, LUDO_BOARD_WIDTH / 15 * 6.5, LUDO_BOARD_HEIGHT / 15 * 0.5, LUDO_BOARD_WIDTH / 15 * 7.5, LUDO_BOARD_HEIGHT / 15 * 0.5);

    /*
        /\(uparrow)
        |    |
        |    |
         ----
    */
    SDL_RenderDrawLine(ludo_game_board_renderer, LUDO_BOARD_WIDTH / 15 * 8.5, LUDO_BOARD_HEIGHT / 15 * 13.5, LUDO_BOARD_WIDTH / 15 * 8.5, LUDO_BOARD_HEIGHT / 15 * 14.5);
    SDL_RenderDrawLine(ludo_game_board_renderer, LUDO_BOARD_WIDTH / 15 * 7.5, LUDO_BOARD_HEIGHT / 15 * 13.5, LUDO_BOARD_WIDTH / 15 * 7.5, LUDO_BOARD_HEIGHT / 15 * 14.5);
    SDL_RenderDrawLine(ludo_game_board_renderer, LUDO_BOARD_WIDTH / 15 * 7.5, LUDO_BOARD_HEIGHT / 15 * 14.5, LUDO_BOARD_WIDTH / 15 * 8.5, LUDO_BOARD_HEIGHT / 15 * 14.5);

    /*
        ----->
    */
    SDL_RenderDrawLine(ludo_game_board_renderer, LUDO_BOARD_WIDTH / 15 * 4.5, LUDO_BOARD_HEIGHT / 15 * 6.5, LUDO_BOARD_WIDTH / 15 * 5.5, LUDO_BOARD_HEIGHT / 15 * 6.5);

    /*
        <-----
    */
    SDL_RenderDrawLine(ludo_game_board_renderer, LUDO_BOARD_WIDTH / 15 * 10.5, LUDO_BOARD_HEIGHT / 15 * 8.5, LUDO_BOARD_WIDTH / 15 * 9.5, LUDO_BOARD_HEIGHT / 15 * 8.5);
    /*
        /\(Uparrow)
        |
        |
        |
    */
    SDL_RenderDrawLine(ludo_game_board_renderer, LUDO_BOARD_WIDTH / 15 * 8.5, LUDO_BOARD_HEIGHT / 15 * 4.5, LUDO_BOARD_WIDTH / 15 * 8.5, LUDO_BOARD_HEIGHT / 15 * 5.5);

    /*
        |
        |
        |
        \/(Downarrow)
    */
    SDL_RenderDrawLine(ludo_game_board_renderer, LUDO_BOARD_WIDTH / 15 * 6.5, LUDO_BOARD_HEIGHT / 15 * 9.5, LUDO_BOARD_WIDTH / 15 * 6.5, LUDO_BOARD_HEIGHT / 15 * 10.5);

    block_color = {255, 255, 255, 255};
    SDL_SetRenderDrawColor(ludo_game_board_renderer, block_color.r, block_color.g, block_color.b, block_color.a);
    small_block = {LUDO_BOARD_WIDTH / 15, LUDO_BOARD_HEIGHT / 15, LUDO_BOARD_WIDTH / 15, LUDO_BOARD_HEIGHT / 15};

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
            SDL_RenderFillRect(ludo_game_board_renderer, &small_block);
            small_block.x += LUDO_BOARD_WIDTH / 15 * 3;
            SDL_RenderFillRect(ludo_game_board_renderer, &small_block);
            small_block.x -= LUDO_BOARD_WIDTH / 15 * 3;

            small_block.y += LUDO_BOARD_HEIGHT / 15 * 3;
            SDL_RenderFillRect(ludo_game_board_renderer, &small_block);
            small_block.x += LUDO_BOARD_WIDTH / 15 * 3;
            SDL_RenderFillRect(ludo_game_board_renderer, &small_block);
            small_block.x -= LUDO_BOARD_WIDTH / 15 * 3;
            small_block.y -= LUDO_BOARD_HEIGHT / 15 * 3;

            small_block.x = LUDO_BOARD_WIDTH / 15 * 10;
        }
        small_block.x = LUDO_BOARD_WIDTH / 15;
        small_block.y = LUDO_BOARD_HEIGHT / 15 * 10;
    }
}

void drawStar(int i, int j)
{
    /*
    ................................................
    This is used  to draw the star over the ludo box
    ................................................
    */
    SDL_RenderDrawLine(ludo_game_board_renderer, j + LUDO_BOARD_WIDTH / 15 * .5, i + LUDO_BOARD_HEIGHT / 15 * 0, j + LUDO_BOARD_WIDTH / 15 * 24 / 110.0, i + LUDO_BOARD_HEIGHT / 15 * .9);
    SDL_RenderDrawLine(ludo_game_board_renderer, j + LUDO_BOARD_WIDTH / 15 * .5, i + LUDO_BOARD_HEIGHT / 15 * 0, j + LUDO_BOARD_WIDTH / 15 * 86 / 110.0, i + LUDO_BOARD_HEIGHT / 15 * .9);
    SDL_RenderDrawLine(ludo_game_board_renderer, j + LUDO_BOARD_WIDTH / 15 * 24 / 110.0, i + LUDO_BOARD_HEIGHT / 15 * .9, j + LUDO_BOARD_WIDTH / 15 * 107 / 110.0, i + LUDO_BOARD_HEIGHT / 15 * 38 / 110.0);
    SDL_RenderDrawLine(ludo_game_board_renderer, j + LUDO_BOARD_WIDTH / 15 * 3 / 110.0, i + LUDO_BOARD_HEIGHT / 15 * 38 / 110.0, j + LUDO_BOARD_WIDTH / 15 * 86 / 110.0, i + LUDO_BOARD_HEIGHT / 15 * .9);
    SDL_RenderDrawLine(ludo_game_board_renderer, j + LUDO_BOARD_WIDTH / 15 * 3 / 110.0, i + LUDO_BOARD_HEIGHT / 15 * 38 / 110.0, j + LUDO_BOARD_WIDTH / 15 * 107 / 110.0, i + LUDO_BOARD_HEIGHT / 15 * 38 / 110.0);

    return;
}

void loadDice()
{

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

    SDL_SetRenderDrawColor(ludo_game_board_renderer, 0, 0, 0, 255);

    if (dice_rotate_value == 4 || dice_rotate_value == 6 || dice_rotate_value == 5)
    {
        /* At Position 1 */
        dice_black_dot_rectangle.x = LUDO_BOARD_WIDTH / 15 * 6 + 26;
        dice_black_dot_rectangle.y = LUDO_BOARD_HEIGHT / 15 * 6 + 26;
        SDL_RenderFillRect(ludo_game_board_renderer, &dice_black_dot_rectangle);
    }

    if (dice_rotate_value == 3)
    {
        /* At Position 2 */
        dice_black_dot_rectangle.x = LUDO_BOARD_WIDTH / 15 * 7 + 26;
        dice_black_dot_rectangle.y = LUDO_BOARD_HEIGHT / 15 * 6 + 26;
        SDL_RenderFillRect(ludo_game_board_renderer, &dice_black_dot_rectangle);
    }

    if (dice_rotate_value == 4 || dice_rotate_value == 5 || dice_rotate_value == 6)
    {
        /* At Position 3 */
        dice_black_dot_rectangle.x = LUDO_BOARD_WIDTH / 15 * 8 + 26;
        dice_black_dot_rectangle.y = LUDO_BOARD_HEIGHT / 15 * 6 + 26;
        SDL_RenderFillRect(ludo_game_board_renderer, &dice_black_dot_rectangle);
    }

    if (dice_rotate_value == 2 || dice_rotate_value == 6)
    {
        /* At Position 4 */
        dice_black_dot_rectangle.x = LUDO_BOARD_WIDTH / 15 * 6 + 26;
        dice_black_dot_rectangle.y = LUDO_BOARD_HEIGHT / 15 * 7 + 26;
        SDL_RenderFillRect(ludo_game_board_renderer, &dice_black_dot_rectangle);
    }

    if (dice_rotate_value == 3 || dice_rotate_value == 1 || dice_rotate_value == 5)
    {
        /* At Position 5 */
        dice_black_dot_rectangle.x = LUDO_BOARD_WIDTH / 15 * 7 + 26;
        dice_black_dot_rectangle.y = LUDO_BOARD_HEIGHT / 15 * 7 + 26;
        SDL_RenderFillRect(ludo_game_board_renderer, &dice_black_dot_rectangle);
    }

    if (dice_rotate_value == 2 || dice_rotate_value == 6)
    {
        /* At Position 6 */
        dice_black_dot_rectangle.x = LUDO_BOARD_WIDTH / 15 * 8 + 26;
        dice_black_dot_rectangle.y = LUDO_BOARD_HEIGHT / 15 * 7 + 26;
        SDL_RenderFillRect(ludo_game_board_renderer, &dice_black_dot_rectangle);
    }

    if (dice_rotate_value == 4 || dice_rotate_value == 6 || dice_rotate_value == 5)
    {
        /* At Position 7 */
        dice_black_dot_rectangle.x = LUDO_BOARD_WIDTH / 15 * 6 + 26;
        dice_black_dot_rectangle.y = LUDO_BOARD_HEIGHT / 15 * 8 + 26;
        SDL_RenderFillRect(ludo_game_board_renderer, &dice_black_dot_rectangle);
    }

    if (dice_rotate_value == 3)
    {
        /* At Position 8 */
        dice_black_dot_rectangle.x = LUDO_BOARD_WIDTH / 15 * 7 + 26;
        dice_black_dot_rectangle.y = LUDO_BOARD_HEIGHT / 15 * 8 + 26;
        SDL_RenderFillRect(ludo_game_board_renderer, &dice_black_dot_rectangle);
    }

    if (dice_rotate_value == 4 || dice_rotate_value == 6 || dice_rotate_value == 5)
    {
        /* At Position 9 */
        dice_black_dot_rectangle.x = LUDO_BOARD_WIDTH / 15 * 8 + 26;
        dice_black_dot_rectangle.y = LUDO_BOARD_HEIGHT / 15 * 8 + 26;
        SDL_RenderFillRect(ludo_game_board_renderer, &dice_black_dot_rectangle);
    }
}

void updateLudoGamePieces(int dice_rotate_value)
{

    if (red_piece_one.getStatus() == HOME)
    {
        if (dice_rotate_value == 1)
        {
            red_piece_one.setStatus(RUNNING);
            red_piece_one.setRenderPosition(red_piece_one.getRenderPositionMovement(dice_rotate_value));
            // std::cout << "Render position value : " << red_piece_one.getRenderPosition().x << " " << red_piece_one.getRenderPosition().y << std::endl;
        }
    }
    else if (red_piece_one.getStatus() == RUNNING)
    {

        if (red_piece_one.getRenderPositionMovement() + dice_rotate_value == 56)
        {
            red_piece_one.setStatus(COMPLETED);
            std::cout << "Game over";
            red_piece_one.setRenderPosition({0, 14});
        }

        if (red_piece_one.getRenderPositionMovement() + dice_rotate_value < 56)
        {
            red_piece_one.setRenderPosition(red_piece_one.getRenderPositionMovement(dice_rotate_value));
        }
    }
}

void diceRotate()
{
    dice_rotate_value = rand() % 6 + 1;
}

void loadLudoGamePieces()
{
    red_piece_one.renderLudoRedPiece();
    red_piece_two.renderLudoRedPiece();
    red_piece_three.renderLudoRedPiece();
    red_piece_four.renderLudoRedPiece();

    green_piece_one.renderLudoGreenPiece();
    green_piece_two.renderLudoGreenPiece();
    green_piece_three.renderLudoGreenPiece();
    green_piece_four.renderLudoGreenPiece();

    blue_piece_one.renderLudoBluePiece();
    blue_piece_two.renderLudoBluePiece();
    blue_piece_three.renderLudoBluePiece();
    blue_piece_four.renderLudoBluePiece();

    yellow_piece_one.renderLudoYellowPiece();
    yellow_piece_two.renderLudoYellowPiece();
    yellow_piece_three.renderLudoYellowPiece();
    yellow_piece_four.renderLudoYellowPiece();
}