#include <iostream>
#include <Game.h>
#include <FrameLimiter.h>


auto main(int argc, char *args[]) -> int {
    Game *game = new Game();
    game->init("title", 200, 200, 720/2, 1280/2, false);

    FrameLimiter frameLimiter(60);

    while(game->get_is_running()) {
        frameLimiter.wait();
        game->handle_events();
        game->update();
        game->render();
    }
    game->clean();
    delete game;
}
