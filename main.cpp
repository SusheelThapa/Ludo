#include "ludo.cpp"

int main()
{
    srand(time(0));

    bool quit = false;
    bool dice_rotated = false;

    if (initializeLudoGame())
    {

        if (loadLudoGame())
        {

            while (!quit)
            {

                while (SDL_PollEvent(&ludo_game_events) != 0)
                {
                    /*If handle the quit of the game event*/
                    if (ludo_game_events.key.keysym.sym == SDLK_ESCAPE || ludo_game_events.type == SDL_QUIT)
                    {
                        quit = true;
                    }

                    /*It rotate the dice*/
                    if (ludo_game_events.key.keysym.sym == SDLK_d && ludo_game_events.type == SDL_KEYDOWN && dice_rotated == false)
                    {
                        diceRotate();
                        dice_rotated = true;
                    }

                    /*after rotation of the dice it execute when user pressed over peice it move that piece*/
                    if (ludo_game_events.type == SDL_MOUSEBUTTONDOWN && dice_rotated == true)
                    {

                        SDL_Point mouse_clicked_position;

                        SDL_GetMouseState(&mouse_clicked_position.x, &mouse_clicked_position.y);

                        switch (current_turn)
                        {
                        case RED_PIECE:

                            if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == red_piece_one.getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == red_piece_one.getRenderPosition().y)
                            {
                                red_piece_one.updateRedPiece();
                                dice_rotated = false;
                            }
                            else if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == red_piece_two.getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == red_piece_two.getRenderPosition().y)
                            {
                                red_piece_two.updateRedPiece();
                                dice_rotated = false;
                            }
                            else if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == red_piece_three.getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == red_piece_three.getRenderPosition().y)
                            {
                                red_piece_three.updateRedPiece();
                                dice_rotated = false;
                            }
                            else if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == red_piece_four.getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == red_piece_four.getRenderPosition().y)
                            {
                                red_piece_four.updateRedPiece();
                                dice_rotated = false;
                            }

                            break;
                        case GREEN_PIECE:

                            if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == green_piece_one.getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == green_piece_one.getRenderPosition().y)
                            {
                                green_piece_one.updateGreenPiece();
                                dice_rotated = false;
                            }
                            else if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == green_piece_two.getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == green_piece_two.getRenderPosition().y)
                            {
                                green_piece_two.updateGreenPiece();
                                dice_rotated = false;
                            }
                            else if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == green_piece_three.getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == green_piece_three.getRenderPosition().y)
                            {
                                green_piece_three.updateGreenPiece();
                                dice_rotated = false;
                            }
                            else if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == green_piece_four.getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == green_piece_four.getRenderPosition().y)
                            {
                                green_piece_four.updateGreenPiece();
                                dice_rotated = false;
                            }
                            break;
                        case YELLOW_PIECE:

                            if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == yellow_piece_one.getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == yellow_piece_one.getRenderPosition().y)
                            {
                                yellow_piece_one.updateYellowPiece();
                                dice_rotated = false;
                            }
                            else if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == yellow_piece_two.getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == yellow_piece_two.getRenderPosition().y)
                            {
                                yellow_piece_two.updateYellowPiece();
                                dice_rotated = false;
                            }
                            else if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == yellow_piece_three.getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == yellow_piece_three.getRenderPosition().y)
                            {
                                yellow_piece_three.updateYellowPiece();
                                dice_rotated = false;
                            }
                            else if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == yellow_piece_four.getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == yellow_piece_four.getRenderPosition().y)
                            {
                                yellow_piece_four.updateYellowPiece();
                            }

                            break;
                        case BLUE_PIECE:

                            if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == blue_piece_one.getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == blue_piece_one.getRenderPosition().y)
                            {
                                blue_piece_one.updateBluePiece();
                                dice_rotated = false;
                            }
                            else if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == blue_piece_two.getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == blue_piece_two.getRenderPosition().y)
                            {
                                blue_piece_two.updateBluePiece();
                                dice_rotated = false;
                            }
                            else if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == blue_piece_three.getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == blue_piece_three.getRenderPosition().y)
                            {
                                blue_piece_three.updateBluePiece();
                                dice_rotated = false;
                            }
                            else if (mouse_clicked_position.x * 15 / LUDO_BOARD_WIDTH == blue_piece_four.getRenderPosition().x && mouse_clicked_position.y * 15 / LUDO_BOARD_HEIGHT == blue_piece_four.getRenderPosition().y)
                            {
                                blue_piece_four.updateBluePiece();
                                dice_rotated = false;
                            }

                            break;
                        }
                    }
                }

                loadLudoGameBoard();
                loadLudoGamePieces();
                loadDice();
                SDL_RenderPresent(ludo_game_board_renderer);
                SDL_Delay(300);
            }
        }
        else
        {
            std::cout << "Unable to load ludo game renderer" << std::endl;
        }
    }
    else
    {
        std::cout << "Unable to render window" << std::endl;
    }

    closeLudoGame();
    return 0;
}