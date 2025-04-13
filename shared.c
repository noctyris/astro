#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

#define FONT "UbuntuMono.ttf"

typedef struct {
    int x;
    int y;
} Coordinate;

int isClick;
Coordinate clickStart;
Coordinate clickEnd;
Coordinate mousePos;

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event event;
TTF_Font *fontS, *fontL;

int initialisation() {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        printf("Error while initialisation");
        return 1;
    }

    if (TTF_Init() < 0) {
        printf("SDL_ttf could not initialize! TTF_Error: %s\n", TTF_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // Création d'une fenêtre
    window = SDL_CreateWindow(
        "Astro",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (!renderer) {
        printf("Erreur lors de la création du renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    fontS = TTF_OpenFont(FONT, 20);
    fontL = TTF_OpenFont(FONT, 30);

    if (!fontS && !fontL){
        printf("Failed to load font: %s\n", TTF_GetError());
        return EXIT_FAILURE;
    }

    return 0;
}