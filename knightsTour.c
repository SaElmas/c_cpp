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
    strcpy(board[3][3],"00");
    *pRow = 3;
    *pCol = 3;
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
    char str[3];
    int tRow, tColumn;
    int mRow[8] =    { 2, 1, -1, -2, -2, -1, 1, 2};
    int mColumn[8] = {-1,-2, -2, -1,  1,  2, 2, 1};
    int randMove[8]={1,2,3,4,5,6,7,8};
    shuffleArray(randMove, 8);

    for(i=0 ; i<8 ; i++){
 //       printf("Checking move number %2d\n",randMove[i]);
        tRow = *pRow + mRow[randMove[i]-1];
        tColumn = *pColumn + mColumn[randMove[i]-1];
        if(!cellVisited(board, tRow, tColumn) && isInBoard(tRow, tColumn))
        {
            (*counter)+=1;
            sprintf(str,"%2d",*counter);
            *pRow= tRow;
            *pColumn= tColumn;
            strcpy(board[*pRow][*pColumn],str);
            return 1;
            break;
        }
   }
   return 0;
}

int startKnightsTour(int showSteps, int randSeed)
{
    char board[8][8][3];
    int* pRow, *pCol, *counter;
    pRow = (int*)malloc(sizeof(int));
    pCol = (int*)malloc(sizeof(int));
    counter = (int*)malloc(sizeof(int));
    *pRow =3;
    *pCol =3;
    initEmptyBoard(board, pRow, pCol );
    srand(time(NULL)*randSeed);
    while(moveKnight(board, pRow, pCol, counter )){
        if(showSteps == 1)
        drawChessBoard(board, *counter);
    }
    if(showSteps ==0) drawChessBoard(board,*counter);
    return *counter;
}