#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilities.h"
#include "playCrap.h"
#include "defs.h"

#define PLAY 400000 

int main()
{
  int i;
  int win;
  for(i=0 ; i<PLAY ; i++){
    srand(time(NULL)*i);
    if(playCrap(0)==1) win++;
  }
  printf("You win %5d games\n",win);

  return 0;

}
