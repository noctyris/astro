#include "shared.c"

int posIn(Coordinate pos, SDL_Rect area) {
    return (area.x < pos.x && pos.x < area.x+area.w && area.y < pos.y && pos.y < area.y+area.h) ? 1 : 0;
}

int drawText(const char* text, SDL_Rect textArea, SDL_Color textColor, TTF_Font* font) {
    SDL_Surface *textSurface= TTF_RenderText_Solid(font, text, textColor);
    if (!textSurface) {
        printf("Failed to create text surface: %s\n", TTF_GetError());
        return EXIT_FAILURE;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!textTexture){
        printf("Échec de création de la texture de texte : %s\n", SDL_GetError());
        SDL_FreeSurface(textSurface);
        return -1;
    }

    // Obtenir les dimensions du texte
    int textWidth = textSurface->w;
    int textHeight = textSurface->h;

    // Calculer la position pour centrer le texte dans le bouton
    SDL_Rect textRect = {
        .x = textArea.x + (textArea.w - textWidth) / 2,
        .y = textArea.y + (textArea.h - textHeight) / 2,
        .w = textWidth,
        .h = textHeight
    };

    // Dessiner le texte sur le rendu
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

    // Libérer les ressources
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);

    return 0;
}

void button(SDL_Rect rect, const char *text, SDL_Color color, void (*action)()) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
    drawText(text, rect, (SDL_Color){255, 255, 255, 255}, fontL);
    if (isClick && posIn(clickStart, rect) && posIn(clickEnd, rect)) action();
}