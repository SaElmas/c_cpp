#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilities.h"
#include "playCrap.h"
#include "defs.h"

#define CASES 36000 

int main()
{
  srand(time(NULL));
  printf("%d\n",playCrap(1));

}
