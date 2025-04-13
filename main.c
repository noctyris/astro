#include "shared.c"

int main() {
    // Initialisation de SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        return -1;
    }

    // Création d'une fenêtre
    SDL_Window *window = SDL_CreateWindow(
        "Exemple SDL3",          // Titre de la fenêtre
        800,                     // Largeur
        600,                     // Hauteur
        SDL_WINDOW_RESIZABLE     // Drapeaux (fenêtre redimensionnable)
    );

    if (!window) {
        printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, "software");
    if (!renderer) {
        printf("Erreur lors de la création du renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Boucle principale
    int running = 1;
    SDL_Event event;

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
