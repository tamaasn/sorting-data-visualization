#include "visualization.h"
#include <time.h>


int main(int argc , char *args[]){
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
    printf("There is something wrong..\n");
    return 1;
  }
  srand(time(NULL));
  long long total_data=0;
  while(total_data < 1){
    printf("Total datas : ");

    if (scanf("%lld" , &total_data) != 1){
      total_data=0;
      printf("Please enter a valid number\n");

      int c;
      while((c = getchar()) != '\n' && c != EOF);
    }
  }
  insert_datas(total_data);
  create_window();
  show_window();
  return 0;
}
