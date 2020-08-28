#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utilities.h"
#include "knightsTour.h"

void initEmptyBoard(char board[8][8][3], int* pRow, int* pCol)
{
	int i,j;
	for(i=0 ; i<8 ; i++){
		for(j=0 ;j<8 ; j++){
            strcpy(board[i][j],"  ");
		}
	} 
    strcpy(board[*pRow][*pCol],"00");
}

void drawChessBoard(char board[8][8][3], int count)
{
    int i;
    int row, column;
    row = column =0;
    puts("+----+----+----+----+----+----+----+----+"); 
    printf("+          MOVE COUNT : %2d              +\n",count); 
    puts("+----+----+----+----+----+----+----+----+"); 
    for(i=0 ; i< 8 ; i++)
    {
        printf("| %2s ",board[row][column++]);
    }
    printf("|\n");
    
    puts("+----+----+----+----+----+----+----+----+"); /* Row2  */
    for(i=0 ; i< 8 ; i++)
    {
        printf("| %2s ",board[row][column++]);
    }
    printf("|\n");
    
    puts("+----+----+----+----+----+----+----+----+"); /* Row3  */
    for(i=0 ; i< 8 ; i++)
    {
        printf("| %2s ",board[row][column++]);
    }
    printf("|\n");
    
    puts("+----+----+----+----+----+----+----+----+"); /* Row4  */
    for(i=0 ; i< 8 ; i++)
    {
        printf("| %2s ",board[row][column++]);
    }
    printf("|\n");
    
    puts("+----+----+----+----+----+----+----+----+"); /* Row5  */
    for(i=0 ; i< 8 ; i++)
    {
        printf("| %2s ",board[row][column++]);
    }
    printf("|\n");
    
    puts("+----+----+----+----+----+----+----+----+"); /* Row6  */
    for(i=0 ; i< 8 ; i++)
    {
        printf("| %2s ",board[row][column++]);
    }
    printf("|\n");
    
    puts("+----+----+----+----+----+----+----+----+"); /* Row7  */
    for(i=0 ; i< 8 ; i++)
    {
        printf("| %2s ",board[row][column++]);
    }
    printf("|\n");
    
    puts("+----+----+----+----+----+----+----+----+"); /* Row8  */
    for(i=0 ; i< 8 ; i++)
    {
        printf("| %2s ",board[row][column++]);
    }
    printf("|\n");
    puts("+----+----+----+----+----+----+----+----+"); /* Row8  */
    printf("\n\n");

}

void drawRawChessBoard(char board[8][8][3])
{
    int i,j;
    for(i=0 ; i<8 ; i++){
        for(j=0 ; j<8 ; j++){
            printf("%2s",board[i][j]);
        }
        puts("");
    }
}

int cellVisited(char board[][8][3], int row, int column)
{
    if(strcmp(board[row][column],"  ") != 0) return 1;
    return 0;
}

int isInBoard(int row, int col)
{
    if(row>7 || row <0 || col > 7 || col < 0) return 0;
    return 1;
}

int moveKnight(char board[][8][3], int* pRow, int* pColumn, int* counter)
{
    int i;
    int minPriority=8;
    int minPriorityIndex;
    int noMoveLeft=0;
    char str[3];
    int tRow, tColumn;
    int mRow[8] =    { 2, 1, -1, -2, -2, -1, 1, 2};
    int mColumn[8] = {-1,-2, -2, -1,  1,  2, 2, 1};
    static int randMove[8]={0,1,2,3,4,5,6,7};
    static int posMatrix [8][2] = {{1,8},{1,8},{1,8},{1,8},{1,8},{1,8},{1,8},{1,8}};
    int priority[8][8]=  {  {2,3,4,4,4,4,3,2},
                            {3,4,6,6,6,6,4,3},
                            {4,6,8,8,8,8,6,4},
                            {4,6,8,8,8,8,6,4},
                            {4,6,8,8,8,8,6,4},
                            {4,6,8,8,8,8,6,4},
                            {3,4,6,6,6,6,4,3},
                            {2,3,4,4,4,4,3,2} };

    shuffleArray(randMove, 8);

// Calculate available moves with priority values;
    for(i=0 ; i<8 ; i++){
        tRow = *pRow + mRow[randMove[i]];
        tColumn = *pColumn + mColumn[randMove[i]];
        if(!cellVisited(board,tRow,tColumn) && isInBoard(tRow,tColumn)){
            posMatrix[i][0] = 1; //Cell is Available
            posMatrix[i][1] = priority[tRow][tColumn]; //Assigns the priority value 
        }
        else{
            posMatrix[i][0] = 0; //Cell is not Available
        }
    }

    noMoveLeft=1;
    for(i=0 ; i<8 ; i++){
        if(posMatrix[i][0]==1){
            noMoveLeft=0;
            break;
        }
    }
    if(noMoveLeft) return 0;


// print possiblity matrix
//    for(i=0 ;i<8 ; i++){
//        printf("%3d%3d\n",posMatrix[i][0], posMatrix[i][1]);
//    }

// find the highest priority move
    for(i=0 ; i<8 ; i++ ){
        if(posMatrix[i][0] == 1 && posMatrix[i][1] <= minPriority){
            minPriorityIndex = i;
            minPriority = posMatrix[i][1];
        }
    }
//    puts("");
//    printf("High priority move is indexed with: %d\n",minPriorityIndex);

    (*counter)+=1;
    sprintf(str,"%2d",*counter);
    *pRow += mRow[randMove[minPriorityIndex]];
    *pColumn += mColumn[randMove[minPriorityIndex]];
    strcpy(board[*pRow][*pColumn],str);
    return 1;
}

int startKnightsTour(int showSteps, int randSeed)
{
    char board[8][8][3];
    int* pRow, *pCol, *counter;
    pRow = (int*)malloc(sizeof(int));
    pCol = (int*)malloc(sizeof(int));
    counter = (int*)malloc(sizeof(int));
    *pRow =0;
    *pCol =0;
    *counter =0;
//puts("Inside startKnight. Variables Initiated");
    initEmptyBoard(board, pRow, pCol );
    srand(time(NULL)*randSeed);
    while(moveKnight(board, pRow, pCol, counter )){
        if(showSteps == 1)
        drawChessBoard(board, *counter);
    }
    if(showSteps ==0) drawChessBoard(board,*counter);
    return *counter;
}