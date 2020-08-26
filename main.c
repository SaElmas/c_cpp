#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilities.h"
#include "playCrap.h"
#include "defs.h"

#define PLAY 400000 

int main()
{
	int i,j;
	int r1,c1,r2,c2;
	int** arr1;
	int** arr2;
	int** arr;
	r1=2, c1=3, r2=3, c2=4;
	arr=(int**)malloc(sizeof(int*));
	arr1=(int**)malloc(sizeof(int*));
	arr2=(int**)malloc(sizeof(int*));

	puts("Main Declerations completed");

	for (i=0 ; i< r1 ; i++){
		arr1[i] = (int*)malloc(sizeof(int)*c1);
		for (j=0 ;j<c1 ; j++){
			arr1[i][j] = i*c1+j+1;
		}
	}
	puts("First array initiated");
	for(i=0 ; i<r1 ; i++){
		for(j=0 ; j<c1 ; j++){
			printf("%3d",arr1[i][j]);
		}
		puts("");
	}

	for (i=0 ; i< r2 ; i++){
		arr2[i] = (int*)malloc(sizeof(int)*c2);
		for (j=0 ;j<c2 ; j++){
			arr2[i][j] = i*c2+j+1;
		}
	}

	puts("Second array initiated");
	for(i=0 ; i<r2 ; i++){
		for(j=0 ; j<c2 ; j++){
			printf("%3d",arr2[i][j]);
		}
		puts("");
	}
	puts("");


	arr = matrixMultp(arr1, r1, c1, arr2, r2, c2);

	for(i=0 ; i<2 ; i++){
		for(j=0 ; j<4 ; j++){
			printf("%5d",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
