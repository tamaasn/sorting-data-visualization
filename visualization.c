#include "visualization.h"
#include <stdbool.h>

long long data_max;
int *data_values;

void insert_datas(long long data_len){
  data_max=data_len;
  data_values = (int*)malloc(sizeof(int) * data_max);
  memset(data_values , 0 , sizeof(*data_values));
  for(int i=1;i<data_max;i++){
    data_values[i]=i;
  }

  for(int i=1;i<data_max;i++){
    int j=rand()%i;
    int temp=data_values[i];
    data_values[i] = data_values[j];
    data_values[j] = temp;

  }
}


