#include <SDL3/SDL.h>
#include <stdio.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event event;

int initialisation() {
    // Initialisation de SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        return -1;
    }

    // Création d'une fenêtre
    window = SDL_CreateWindow(
        "Astro",
        800, 600,
        SDL_WINDOW_RESIZABLE
    );

    if (!window) {
        printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    renderer = SDL_CreateRenderer(window, "software");
    if (!renderer) {
        printf("Erreur lors de la création du renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    return 0;
}