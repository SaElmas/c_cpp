#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilities.h"
#include "defs.h"

#define CASES 36000 

int main()
{
  int i,j;
  int arr[2]={0};
  int count[11];
  int sums[CASES];
  
  for(i=0 ; i<CASES; i++){
    srand(time(NULL)*(i+1));
    rand(); rand() ; rand();
    fillArrayRandom(arr,2,1,6);
    sums[i] = arr[0] + arr[1];
  }
  selectionSort(sums,CASES);
  for(i=0 ; i<CASES ; i++){
    switch (arr[i]){

      case 2: count[0]++;
      break;

      case 3: count[1]++;
      break;

      case 4: count[2]++;
      break;

      case 5: count[3]++;
      break;

      case 6: count[4]++;
      break;

      case 7: count[5]++;
      break;

      case 8: count[6]++;
      break;

      case 9: count[7]++;
      break;

      case 10: count[8]++;
      break;

      case 11: count[9]++;
      break;

      case 12: count[10]++;
      break;

    }
  }

  for (i=0 ; i<11 ; i++){
    int r;
    r=count[i] /36;
    printf("%3d:",i+2);
    for(j=0 ;j<r ;j++){
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
