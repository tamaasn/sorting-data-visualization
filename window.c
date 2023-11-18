#include "visualization.h"

SDL_Window *window;
SDL_Renderer *renderer;

void create_window(){
  window = SDL_CreateWindow("Data sorting visualization" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , screen_width , screen_height , 0);
  renderer = SDL_CreateRenderer(window , SDL_RENDERER_ACCELERATED , -1);
}
