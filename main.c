#include "ui.c"

void quit() {
    SDL_Quit();
    exit(0);
}

int main() {
    initialisation();

    // Boucle principale
    int running = 1;

    while (running) {
        // Gestion des événements
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    return 0;
                case SDL_MOUSEBUTTONDOWN:
                    clickStart.x = event.motion.x;
                    clickStart.y = event.motion.y;
                    break;
                case SDL_MOUSEBUTTONUP:
                    clickEnd.x = event.motion.x;
                    clickEnd.y = event.motion.y;
                    isClick = 1;
                    break;
                case SDL_MOUSEMOTION:
                    mousePos.x = event.motion.x;
                    mousePos.y = event.motion.y;
                    break;
            }
        }

        button(
            (SDL_Rect){100, 100, 200, 50},
            "Quitter",
            (SDL_Color){255, 0, 0, 255},
            quit
        );

        SDL_RenderPresent(renderer);
    }

    // Nettoyage
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
