#include "ludo.cpp"

int main()
{
    srand(time(0));

    bool quit = false;

    if (initializeLudoGame())
    {

        if (loadLudoGame())
        {

            while (!quit)
            {

                while (SDL_PollEvent(&ludo_game_events) != 0)
                {
                    if (ludo_game_events.key.keysym.sym == SDLK_ESCAPE || ludo_game_events.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                    if (ludo_game_events.key.keysym.sym == SDLK_d && ludo_game_events.type == SDL_KEYDOWN)
                    {
                        diceRotate();
                        std::cout << dice_rotate_value << std::endl;
                        updateLudoGamePieces(dice_rotate_value);
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