#include "window.hpp"
#include "ludo.hpp"

const int LUDO_BOARD_WIDTH = 900;
const int LUDO_BOARD_HEIGHT = 900;

int main()
{
    srand(time(0));

    // Created Ludo Window
    Window window("Ludo", LUDO_BOARD_WIDTH, LUDO_BOARD_HEIGHT);

    Ludo ludo;

    SDL_Event e;

    bool dice_rotated = false;

    while (!window.isWindowClosed())
    {

        while (SDL_PollEvent(&e) != 0)
        {
            window.handleEvent(e);
            ludo.handleEvent(e);
        }

        window.clear({255, 255, 255, 255});

        ludo.render(window);

        window.present();
    }

    return 0;
}
