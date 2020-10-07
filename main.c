#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
#include "utilities.h"
#include "playCrap.h"
#include "turtleGraphics.h"
#include "defs.h"
#include "knightsTour.h"
#include "eightQueens.h"
#include "recursiveFunctions.h"
#include "poker.h"
#include "maxSubSeq.h"



int main(int argc, char* argv[])
{
   int iArr[SIZE];
   int i;
   int *result=NULL;
   puts("A");
   
   fillArrayRandom(iArr,SIZE,START,STOP);
   for( i= 0; i<SIZE ; i++)
   {
      iArr[i] -= STOP /2;
   }
   puts("B");
   result = findMaxSub(iArr, 0, SIZE);
   printArray(iArr, SIZE);
   printf("%d %d %d\n", result[0], result[1], result[2]);

   return 0;
}

