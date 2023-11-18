#include "visualization.h"

TTF_Font *font;
SDL_Color color = {255,255,255};

void font_init(){
  TTF_Init();
  font = TTF_OpenFont("arial.ttf" , 24);
}

void create_text(char *text , SDL_Texture **texture){
  SDL_Surface *surface = TTF_RenderText_Solid(font , text , color);
  *texture = SDL_CreateTextureFromSurface(renderer , surface);
  SDL_FreeSurface(surface);
}
