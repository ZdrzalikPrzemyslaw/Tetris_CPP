#include <iostream>
#include <Game.h>
#include <FrameLimiter.h>


auto main(int argc, char *args[]) -> int {
    Game *game = new Game();
    game->init("title", 200, 200, Static_Board_Constant::x_dim * 32, Static_Board_Constant::y_dim * 32, false);

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
