#include "visualization.h"
#include <stdbool.h>
#include <pthread.h>

long long time_passed=0;
long long old_timer=0;

Uint32 timer_callback(Uint32 interval , void *notused){
  time_passed++;
  return 0;
}

void show_window(){
  SDL_Event event;
  bool running=true;
  SDL_SetRenderDrawColor(renderer , 0 , 0 , 0 ,0);
  font_init();
  SDL_Rect font_rect;
  font_rect.x = 800;
  font_rect.y = 320;
  font_rect.w = 100;
  font_rect.h = 25;

  SDL_Rect timer_rect;
  timer_rect.x = 800;
  timer_rect.y = 295;
  timer_rect.w = 100;
  timer_rect.h = 25;

  long long total_sorted=0;

  SDL_Texture *timer_texture;
  SDL_Texture *font_texture;
  create_text("Sorted : 0" , &font_texture);
  create_text("Time passed : 0" , &timer_texture);
  int i_count=0;
  int j_count=0;
  int y;
  bool sort_stop=false;

  SDL_TimerID timerid = SDL_AddTimer(1000 , timer_callback , NULL);
  time_passed++;
  while (running){
    SDL_RenderClear(renderer);
    while(SDL_PollEvent(&event)){
      switch(event.type){
        case SDL_QUIT: exit(0);break;
      }
    }
    if (old_timer != time_passed){
      SDL_TimerID timer = SDL_AddTimer(1000 , timer_callback , NULL);

      SDL_DestroyTexture(timer_texture);
      char buffer[1024];
      snprintf(buffer , sizeof(buffer) , "Time passed : %llu" , time_passed);
      create_text(buffer , &timer_texture);
      old_timer = time_passed;
      long long length=0;
      long long n=time_passed;
      while(n > 0){
        n /= 10;
        length++;
      }
      timer_rect.w = 100 + (length * 2);
      
      //SDL_RemoveTimer(timer);

    }
    if (data_values[i_count] >  data_values[j_count] && !sort_stop){
      int x = data_values[i_count];
      data_values[i_count] = data_values[j_count];
      data_values[j_count] = x;
      total_sorted++;
      SDL_DestroyTexture(font_texture);
      char buffer[500];
      snprintf(buffer,sizeof(buffer), "sorted : %llu" , total_sorted);
      create_text(buffer , &font_texture);
    }

    if(!sort_stop){
      j_count++;
    }
    if (j_count == data_max){
      i_count++;
      j_count=i_count;
      if(i_count == data_max){
        printf("Stopping..\n");
        j_count=0;
        i_count=0;
        sort_stop=true;
      }
    }
    SDL_SetRenderDrawColor(renderer , 255 , 255 , 255 , 0);

    int x_max=5;
    for(int i=0;i<data_max;i++){
      SDL_Rect r;
      r.x = x_max;
      r.w = 500/data_max;
      if (r.w < 1){
        r.w = 1;
      }
      r.h = data_values[i] * (r.w);
      r.y = screen_height-r.h;
      x_max += r.w;
      if (i == j_count){
        SDL_SetRenderDrawColor(renderer , 0 , 0 , 255 , 255);
        SDL_RenderFillRect(renderer , &r);
      }
      else{
        SDL_RenderFillRect(renderer , &r);
      }
    }
    SDL_RenderCopy(renderer , font_texture , NULL , &font_rect);
    SDL_RenderCopy(renderer , timer_texture , NULL , &timer_rect);
    SDL_SetRenderDrawColor(renderer , 0 , 0 , 0 ,0);
    SDL_RenderPresent(renderer);
    SDL_RemoveTimer(timerid);
  }
}
