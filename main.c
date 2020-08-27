#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilities.h"
#include "playCrap.h"
#include "turtleGraphics.h"
#include "defs.h"
#include "knightsTour.h"



int main()
{
	int i;
	int max=0;
	int count;
	int maxIndex;
	for(i=0 ; i<10000 ; i++ ){
		count=startKnightsTour(0, i*197);
		if(count > max){
			max = count;
			maxIndex = i;
		}
	}
	printf("Max occured at %2d as %2d moves\n",maxIndex, max);
	printf("Go to the line %10d\n", 21*(maxIndex) +3);
	return 0;

}