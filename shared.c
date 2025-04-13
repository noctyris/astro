#define _POSIX_C_SOURCE 200809L // Active les fonctionnalités POSIX modernes
#define FONT "UbuntuMono.ttf"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Coordinate;

struct ptm {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    long ns;
};

int isClick;
Coordinate clickStart;
Coordinate clickEnd;
Coordinate mousePos;

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event event;
TTF_Font *fontS, *fontL, *fontXS;

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
    fontXS = TTF_OpenFont(FONT, 12);

    if (!fontS && !fontL && !fontXS) {
        printf("Failed to load font: %s\n", TTF_GetError());
        return EXIT_FAILURE;
    }

    return 0;
}

struct ptm getTime() {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);

    time_t t = ts.tv_sec;
    struct tm local_time;
    localtime_r(&t, &local_time);

    struct ptm result = {
        .year = local_time.tm_year + 1900,
        .month = local_time.tm_mon + 1,
        .day = local_time.tm_mday,
        .hour = local_time.tm_hour,
        .min = local_time.tm_min,
        .sec = local_time.tm_sec,
        .ns = ts.tv_nsec
    };

    return result;
}