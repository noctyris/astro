#include "ui.c"
#include "calculus.c"

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

        struct ptm current_time = getTime(); // Récupère le temps avec nanosecondes

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        char jj_text[30];
        sprintf(jj_text, "JJ = %.15f", julianDate(current_time));
        drawText(jj_text, (SDL_Rect){10, HEIGHT - 50, 174, 50}, (SDL_Color){255, 255, 255, 255}, fontXS);

        char date_text[32];
        sprintf(date_text, "Date: %04d-%02d-%02d  %02d:%02d:%02d.%04d", current_time.year, current_time.month, current_time.day, current_time.hour, current_time.min, current_time.sec, (int)(current_time.ns / 1e5));
        drawText(date_text, (SDL_Rect){10, HEIGHT - 40, 192, 50}, (SDL_Color){255, 255, 255, 255}, fontXS);

        SDL_RenderPresent(renderer);
    }

    // Nettoyage
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

