
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
                }

                loadLudoGameBoard();

                SDL_RenderPresent(ludo_game_board_renderer);
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