#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "knightsTour.h"
#include "utilities.h"
#include "eightQueens.h"


#define ELW 20 // Eliminted number of cells weight

void initQueenBoard(char board[8][8][3], int* pRow, int* pCol)
{
	int i,j;
	for(i=0 ; i<8 ; i++){
		for(j=0 ;j<8 ; j++){
            strcpy(board[i][j],"  ");
		}
	} 
    strcpy(board[*pRow][*pCol],"Q");
    crossTheBoard(board,*pRow,*pCol);
}

void crossTheBoard(char board[8][8][3], int pRow, int pCol){
    int i;
    int x,y;

    for(i=1 ; i<8 ; i++){
        x=pRow+i;
        y=pCol;
        if(strcmp(board[x%8][y],"Q")!=0)
            strcpy(board[x%8][y], "x");  
    }

    for(i=1 ; i<8 ; i++){
        x=pRow;
        y=pCol+i;
        if(strcmp(board[pRow][y%8],"Q")!=0)
        strcpy(board[pRow][y%8], "x");  
    }

    for(i=0 ; i<8 ; i++){
        x=pRow+i;
        y=pCol+i;
        if( x<8 && y<8 ){
            if(strcmp(board[x][y],"Q")!=0)
            strcpy(board[x][y], "x");
        }
    }

    for(i=0 ; i<8 ; i++){
        x=pRow-i;
        y=pCol+i;
        if( x>-1 && y<8 ){
            if(strcmp(board[x][y],"Q")!=0)
            strcpy(board[x][y], "x");
        }
    }

    for(i=0 ; i<8 ; i++){
        x=pRow+i;
        y=pCol-i;
        if( y>-1 && x<8 ){
            if(strcmp(board[x][y],"Q")!=0)
            strcpy(board[x][y], "x");
        }
    }

    for(i=0 ; i<8 ; i++){
        x=pRow-i;
        y=pCol-i;
        if( x>-1 && y>-1 ){
            if(strcmp(board[x][y],"Q")!=0)
            strcpy(board[x][y], "x");
        }
    }


    strcpy(board[pRow][pCol],"Q");
}

int placeQueen(char board[8][8][3], int* posRow, int* posCol, int* count){
    int i;
    int next= *posRow +1;
    int moveVal[8] = {500,500,500,500,500,500,500,500};
    int* minPtr=NULL;

    for(i=0 ; i<8 ; i++){
        if(strcmp(board[next][i], "  ") == 0){
            moveVal[i] = calcMoveValue(board, next, i);
        }
    }
    minPtr = arrMin(moveVal,8);
    printArray(moveVal, 8);
    if(minPtr[1] == 500) return 0;
    else {
        crossTheBoard(board, next, minPtr[0]);
        strcpy(board[next][minPtr[0]], "Q");
        *posRow = next;
        *posCol = minPtr[0];
        (*count)++;
        return 1;
    }
    return 1;
}

int calcMoveValue(char const board[8][8][3], int const pRow, int const pCol){
    int i;
    int x,y;
    int value=0;

    for(i=1 ; i<8 ; i++){
        x=pRow+i;
        y=pCol;
        if(strcmp(board[x%8][y],"  ") == 0)
        {
            value += ELW;
            if(pCol < 4) {
                value += pCol; 
            }
            else{
                value += 7-pCol;
            }
        }
    }

    for(i=1 ; i<8 ; i++){
        x=pRow;
        y=pCol+i;
        if(strcmp(board[pRow][y%8],"  ") == 0)
        {
            value += ELW;
            if(pCol < 4) {
                value += pCol; 
            }
            else{
                value += 7-pCol;
            }
        }
    }

    for(i=1 ; i<8 ; i++){
        x=pRow+i;
        y=pCol+i;
        if( x<8 && y<8 ){
            if(strcmp(board[x][y],"  ") == 0)
            {
                value += ELW;
                if(pCol < 4) {
                    value += pCol; 
                }
                else{
                    value += 7-pCol;
                }
            }
        }
    }

    for(i=1 ; i<8 ; i++){
        x=pRow-i;
        y=pCol+i;
        if( x>-1 && y<8 ){
            if(strcmp(board[x][y],"  ") == 0)
            {
                value += ELW;
                if(pCol < 4) {
                    value += pCol; 
                }
                else{
                    value += 7-pCol;
                }
            }
        }
    }

    for(i=1 ; i<8 ; i++){
        x=pRow+i;
        y=pCol-i;
        if( y>-1 && x<8 ){
            if(strcmp(board[x][y],"  ") == 0)
            {
                value += ELW;
                if(pCol < 4) {
                    value += pCol; 
                }
                else{
                    value += 7-pCol;
                }
            }
        }
    }

    for(i=1 ; i<8 ; i++){
        x=pRow-i;
        y=pCol-i;
        if( x>-1 && y>-1 ){
            if(strcmp(board[x][y],"  ") == 0 )
            {
                value += ELW;
                if(pCol < 4) {
                    value += pCol; 
                }
                else{
                    value += 7-pCol;
                }
            }
        }
    }
    return value;
}

void clearBoard(char board [8][8][3]){
    int i,j;
    for(i=0 ;i<8; i++)
        for(j=0 ; j<8 ; j++){
            strcpy(board[i][j], "  ");
        }
}

int placeQueen_BF(char board[8][8][3]){
puts("Inside placeQueen_BF");
    int counter=0;
    int i,j,k,l,m,n,o,p;
    for(i=0 ;i<8 ; i++) 
    for(j=0 ;j<8 ; j++)
    for(k=0 ;k<8 ; k++)
    for(l=0 ;l<8 ; l++)
    for(m=0 ;m<8 ; m++)
    for(n=0 ;n<8 ; n++)
    for(o=0 ;o<8 ; o++)
    for(p=0 ;p<8 ; p++){
        clearBoard(board);
        strcpy(board[0][i],"Q");
        strcpy(board[1][j],"Q");
        strcpy(board[2][k],"Q");
        strcpy(board[3][l],"Q");
        strcpy(board[4][m],"Q");
        strcpy(board[5][n],"Q");
        strcpy(board[6][o],"Q");
        strcpy(board[7][p],"Q");

        if(checkBoard(board)){
            drawChessBoard(board,0);
            ++counter;
        }
    }
    printf("%d\n",counter);
    return 1;
}

int checkBoard(char const board[8][8][3]){
    int i,j,k;
    int x,y;
    for(k=0 ; k<8 ; k++){
        for(j=0 ; j<8 ; j++){
            if(strcmp(board[k][j], "Q") == 0)
            {
                for(i=1 ; i<8 ; i++)
                {
                    x=k+i;
                    y=j;
                    if(strcmp(board[x%8][y],"Q") == 0) return 0;
                }
                for(i=1 ; i<8 ; i++)
                {
                    x=k;
                    y=j+i;
                    if(strcmp(board[x][y%8],"Q") == 0) return 0;
                    
                }

                for(i=1 ; i<8 ; i++){
                    x=k+i;
                    y=j+i;
                    if( x<8 && y<8 ){
                        if(strcmp(board[x][y],"Q") == 0) return 0;
                    }
                }
                for(i=1 ; i<8 ; i++){
                    x=k+i;
                    y=j-i;
                    if( x<8 && y>-1 ){
                        if(strcmp(board[x][y],"Q") == 0) return 0;
                    }
                }
                for(i=1 ; i<8 ; i++){
                    x=k-i;
                    y=j+i;
                    if( x>-1 && y<8 ){
                        if(strcmp(board[x][y],"Q") == 0) return 0;
                    }
                }
                for(i=1 ; i<8 ; i++){
                    x=k-i;
                    y=j-i;
                    if( x>-1 && y>-1 ){
                        if(strcmp(board[x][y],"Q") == 0) return 0;
                    }
                }
            }
        }
    }
    return 1;
}

void copyBoards(char targetBoard[8][8][3], char const sourceBoard[8][8][3]){
    int i,j;
    for(i=0 ; i<8 ; i++){
        for(j=0 ; j<8 ;j ++){
            strcpy(targetBoard[i][j], sourceBoard[i][j]);
        }
    }

}

void runEightQueen(){
    char board[8][8][3];
 /*   int* posRow, *posCol, *count;
    posRow = (int*) malloc(sizeof(int));
    posCol = (int*) malloc(sizeof(int));
    count  = (int*) malloc(sizeof(int));
    *count = 1;
    *posCol =0;
 */

    placeQueen_BF(board);
//    drawChessBoard(board,1);

/*
    for(int i=0 ; i<1 ; i++){
        *posCol=0;
        *posRow=0;
        *count =1;
        initQueenBoard(board, posRow, posCol);
        drawChessBoard(board, *count);
        while(placeQueen(board, posRow, posCol, count)){
            drawChessBoard(board, *count);
        }
        if(*count >4) drawChessBoard(board, *count);
    }
*/
}