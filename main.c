#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilities.h"
#include "defs.h"

#define CASES 36000 

int main()
{
  int i;
  int arr[2]={0};
  int sums[CASES];
  
  for(i=0 ; i<CASES; i++){
    srand(time(NULL));
    fillArrayRandom(arr,2,1,6);
    printArray(arr,2);
    sums[i] = arr[0] + arr[1];
  }
  selectionSort(sums,CASES);

  return 0;
}
