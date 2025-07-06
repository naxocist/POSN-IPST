#include "insects.h"

int min_cardinality(int N) {

  int k = 1;
  move_inside(0);
  for(int i=1; i<N; ++i) {
    move_inside(i);
    if(press_button() == 2) move_outside(i);
    else k ++;
  }
  return k;
}