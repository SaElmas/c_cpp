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


int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int key;
	scanf("%d",&key);
	printf("%d\n",linearSearchRec(arr,key,10));
	return 0;
}