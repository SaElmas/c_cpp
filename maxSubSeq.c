#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "maxSubSeq.h"
#include "utilities.h"

int *findMaxCross(int const arr[], int low, int mid, int high)
{    
  int i;
  int maxLeft, maxRight, sumL, sumR;
  int leftSum = INT_MIN;
  int rightSum = INT_MIN;
  int *returnValues = NULL;

  returnValues = (int*) malloc(sizeof(int)*3);

  for (i = mid, sumL = 0 ; i >= low ; i--)
  {
    sumL += arr[i];
    if ( sumL > leftSum)
    {
      leftSum = sumL;
      maxLeft = i;
    }
  }

  for (i = mid, sumR = 0 ; i<=high ; i++)
  {
    sumR += arr[i];
    if( sumR > rightSum)
    {
      rightSum = sumR;
      maxRight = i;
    }
  }
  returnValues[0] = maxLeft;
  returnValues[1] = maxRight;
  returnValues[2] =  leftSum + rightSum;

  return returnValues;
}

int *findMaxSub(int const arr[], int low, int high)
{
  puts("C");
  printf("low:%d high:%d\n",low, high);
  int *rArr, *rArrL, *rArrR, *rArrC;
  int mid;
  if ( high == low)
  {
    rArr = (int*) malloc(sizeof(int)*3);
    rArr[0] = low;
    rArr[1] = high;
    rArr[2] = arr[low];
    return rArr; 
  }
  else
  {
    mid = (high + low) /2;
    rArrL = (int*) malloc(sizeof(int)*3);
    rArrR = (int*) malloc(sizeof(int)*3);
    rArrC = (int*) malloc(sizeof(int)*3);

    rArrL = findMaxSub(arr, low, mid);
    rArrR = findMaxSub(arr, mid+1, high);
    rArrC = findMaxCross(arr, low, mid, high);

    if (rArrL[2] > rArrR[2] && rArrL[2] > rArrC[2]) return rArrL;
    else if ( rArrR[2] > rArrL[2] && rArrR[2] > rArrC[2]) return rArrR;
    else return rArrC;

  }
  
}