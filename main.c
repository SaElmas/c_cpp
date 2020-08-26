#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilities.h"
#include "playCrap.h"
#include "turtleGraphics.h"
#include "defs.h"



int main()
{
	int** board;
	int instructions[10] = {1, 5, 3, 2, 5, 6, 9};
	int dx, dy;
	int i,j;

	dx = DX;
	dy = DY;

	board = (int**)malloc(sizeof(int*)*dx);
	for(i=0 ; i<dx ; i++)
	{
		board[i] = (int*)malloc(sizeof(int*)*dy);
		for(j=0 ; j<dy ; j++)
		{
			board[i][j]=0;
		}
	}

	updateBoard(board,dx,dy,'#', '0', instructions);	
	drawBoard(board, dx, dy, '#', '*');
	return 0;
}