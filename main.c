#include "shared.c"

int main() {
    initialisation();

    // Boucle principale
    int running = 1;

    while (running) {
        // Gestion des événements
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    // L'utilisateur a cliqué sur le bouton de fermeture
                    running = 0;
                    break;

                case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
                    // Une requête de fermeture a été envoyée
                    running = 0;
                    break;

                default:
                    break;
            }
        }

        // Effacer l'écran (remplir avec une couleur noire)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Dessiner ici si nécessaire
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_FRect rect = {100, 100, 150, 150};
        SDL_RenderFillRect(renderer, &rect);

        // Mettre à jour l'affichage
        SDL_RenderPresent(renderer);
    }

    // Nettoyage
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
