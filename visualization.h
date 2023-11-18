#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define visual_width 55
#define screen_width 1024
#define screen_height 640


extern int* data_values;
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern long long total_data;
extern long long data_max;

void create_window();
void insert_datas();
void create_textures();
void show_window();
void font_init();
void create_text(char *text , SDL_Texture **texture);
long long convert_long(char *text);
