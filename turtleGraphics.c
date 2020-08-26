#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "turtleGraphics.h"
#include "defs.h"

enum Status  {UP, DOWN};
enum Direction {E, S, W, N};

void drawBoard(int** state, int dx, int dy, char border, char occ)
{
    int i,j;

    for(i=0 ; i<dx ; i++){
        printf("%2c",border);
    }
    printf("\n");

    for(i=0; i<dx-2 ; i++){
        printf("%2c",border);
        for(j=0 ; j<dy-2 ; j++){
           if(state[i][j]==1){
               printf("%2c",occ);
           } 
           else {
               printf("  ");
           }
        }
        printf("%2c\n",border);
    }
    for(i=0 ; i<dx ; i++)
    {
        printf("%2c",border);
    }
    printf("\n");
}

int** generateRandomBoard(int dx, int dy)
{
    int** board;
    int i,j;
    int randx;
    board=(int**)malloc(sizeof(int*)*dy);
    for(i=0 ; i<dy; i++)
    {
        board[i]=(int*)malloc(sizeof(int)*dx);
        for(j=0 ; j<dx ; j++)
        {
            srand( time(NULL)*i*rand());
            randx=rand()%4 +1;
            switch (randx)
            {
                case 1:
                    board[i][j] = 1;
                    break;
                default:
                    board[i][j] = 0;
                    break;
            }
        }
    }
    return board;
}

void modifyBoard(int** board, int pos[2], int direction, int distance)
{
    int i;
    printf("Direction is:%3d\n", direction);
    if(direction ==1)
    {
        for(i=0 ; i<distance ; i++)
        {
            board[pos[0]][pos[1]+i]=1;
        }
        pos[1] += direction;
    }

    else if(direction ==2)
    {
        for(i=0 ; i<distance ; i++)
        {
            board[pos[0]+i][pos[1]]=1;
        }
        pos[0] += direction;
    }
    else if(direction ==3)
    {
        for(i=0 ; i<distance ; i++)
        {
            board[pos[0]][pos[1]-i]=1;
        }
        pos[1] -= direction;
    }
    else 
    {
        for(i=0 ; i<distance ; i++)
        {
            board[pos[0]-i][pos[1]]=1;
        }
        pos[0] -= direction;
    }
}

void moveTurtle(int** board, int pos[2], int direction, int distance)
{
    if(direction ==1)
    {
        pos[1] += direction;
    }

    else if(direction ==2)
    {
        pos[0] += direction;
    }
    else if(direction ==3)
    {
        pos[1] -= direction;
    }
    else 
    {
        pos[0] -= direction;
    }
}

void updateBoard(int** board, int dx, int dy, char border, char occ, int* instructions)
{
    int count=0;
    int pos[2]={0,0}; 
    int distance;
    enum Status penStatus = UP;
    enum Direction heading = S; 


    while(instructions[count] != 9) {
        printf("%2d ",instructions[count]);
        switch (instructions[count])
        {
        case 1: penStatus = UP; break;
        case 2: penStatus = DOWN; break;
        case 3: heading =(heading + 1)%4 ; break;
        case 4: heading =(heading - 1)%4 ; break;
        case 5: 
        {
            printf("\nInstrucion 5 initialized\n");
            distance = instructions[count+1];
            count++;
            if(penStatus==DOWN){
                printf("Pen is down. Modification Initialized\n");
                modifyBoard(board, pos, heading, distance);
            }
            else {
                moveTurtle(board, pos, heading, distance);
            }
            break;
        }
        case 6: drawBoard(board, dx, dy, border, occ); break;

        default:
            break;
        }
        count++;
    }
}


