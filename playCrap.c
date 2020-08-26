#include <stdio.h>
#include "playCrap.h"
#include "utilities.h"


enum Status { LOST, WIN, CONT};

int* playCrap(int details) {
   
    static int returnArr[2]={0,0};
    int dice[2];
    int sum;
    int thePoint;
    int turnCount=0;
    enum Status gameStatus=CONT;
    fillArrayRandom(dice, 2, 1, 6);
    if(details){
        printf("You rolled %d-%d\n",dice[0], dice[1]);
    }
    sum = dice[0] + dice[1];
    if(sum==7 || sum ==11) {
        if(details){
            printf("You won\n");
        }
        turnCount++;
        gameStatus = WIN;
        returnArr[0] = gameStatus;
        returnArr[1] = turnCount;
        return returnArr;
    }
    else if( sum == 2 || sum == 3 || sum == 12){
        if(details){
            printf("You lost\n");
        }
        turnCount++;
        gameStatus = LOST;
        returnArr[0] = gameStatus;
        returnArr[1] = turnCount;
        return returnArr;
    }
    else {
        if(details){
            printf("Your point is:%d\n",sum);
        }
        thePoint=sum;
        gameStatus=CONT;
        while (gameStatus==CONT){
            turnCount++;
            fillArrayRandom(dice,2,1,6);
                if(details){
                    printf("You rolled %d-%d\n",dice[0], dice[1]);
                }
            sum = dice[0] + dice[1];
            if(sum==7) {
                if(details){
                    printf("You lost\n");
                }
                gameStatus=LOST;
                returnArr[0] = gameStatus;
                returnArr[1] = turnCount;
                return returnArr;
            }
            else if(sum==thePoint){
                if(details){
                    printf("You win\n");
                }
                gameStatus=WIN;
                returnArr[0] = gameStatus;
                returnArr[1] = turnCount;
                return returnArr;
            }
        }

    }
    return 0;
}