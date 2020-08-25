#include <stdio.h>
#include "playCrap.h"
#include "utilities.h"


enum Status { WIN, LOST, CONT};

int playCrap(int details) {
    int dice[2];
    int sum;
    int thePoint;
    int turnCounterWin=0;
    int turnCounterLost=0;
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
        turnCounterWin++;
        gameStatus = WIN;
        return 1;
    }
    else if( sum == 2 || sum == 3 || sum == 12){
        if(details){
            printf("You lost\n");
        }
        turnCounterWin++;
        gameStatus = LOST;
        return 0;
    }
    else {
        if(details){
            printf("Your point is:%d\n",sum);
        }
        thePoint=sum;
        gameStatus=CONT;
        while (gameStatus==CONT){
            fillArrayRandom(dice,2,1,6);
                if(details){
                    printf("You rolled %d-%d\n",dice[0], dice[1]);
                }
            sum = dice[0] + dice[1];
            if(sum==7) {
                if(details){
                    printf("You lost\n");
                }
                turnCounterLost++;
                gameStatus=LOST;
                return 0;
            }
            else if(sum==thePoint){
                if(details){
                    printf("You win\n");
                }
                turnCounterWin++;
                gameStatus=WIN;
                return 1;
            }
        }

    }
    return 0;
}