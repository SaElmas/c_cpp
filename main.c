#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilities.h"
#include "playCrap.h"
#include "defs.h"

#define PLAY 400000 

int main()
{
  int i;
  int win;
  int* gameResult;
  int turnCountWin[13]={0};
  int turnCountLost[13]={0};
  for(i=0 ; i<PLAY ; i++){
    srand(time(NULL)*i);
    gameResult=playCrap(0);
    if (gameResult[0] == 1){
      win++;
      switch (gameResult[1]){
        case 1:
          turnCountWin[0]++;
          break;

        case 2:
          turnCountWin[1]++;
          break;

        case 3:
          turnCountWin[2]++;
          break;

        case 4:
          turnCountWin[3]++;
          break;

        case 5:
          turnCountWin[4]++;
          break;

        case 6:
          turnCountWin[5]++;
          break;

        case 7:
          turnCountWin[6]++;
          break;

        case 8:
          turnCountWin[7]++;
          break;

        case 9:
          turnCountWin[8]++;
          break;

        case 10:
          turnCountWin[9]++;
          break;

        case 11:
          turnCountWin[10]++;
          break;

        case 12:
          turnCountWin[11]++;
          break;

        default:
          turnCountWin[12]++;
          break;

      }
    }
    else {
       switch (gameResult[1]){
        case 1:
          turnCountLost[0]++;
          break;

        case 2:
          turnCountLost[1]++;
          break;

        case 3:
          turnCountLost[2]++;
          break;

        case 4:
          turnCountLost[3]++;
          break;

        case 5:
          turnCountLost[4]++;
          break;

        case 6:
          turnCountLost[5]++;
          break;

        case 7:
          turnCountLost[6]++;
          break;

        case 8:
          turnCountLost[7]++;
          break;


        case 9:
          turnCountLost[8]++;
          break;

        case 10:
          turnCountLost[9]++;
          break;

        case 11:
          turnCountLost[10]++;
          break;

        case 12:
          turnCountLost[11]++;
          break;

        default:
          turnCountLost[12]++;
          break;
      }

    }
  }
  printf("You win %5d games\n",win);
  printf("\n");
  printf("%-s35\n","WINNING STATICTICS");
  for(i=0 ; i<13; i++){
    printf("%25s%4d:%5d\n","Wınning games in turn",i+1, turnCountWin[i]);
  }

  printf("%-s35\n","LOST GAME STATICTICS");
  for(i=0 ; i<13; i++){
    printf("%25s%4d:%5d\n","Lost games in turn",i+1, turnCountLost[i]);
  }

  printf("CHANCE OF WIN BY TURNS\n");
  for(i=0 ; i<13; i++){
    printf("%-15s%4d:%5f\n","in turn",i+1, ((float) turnCountWin[i]) / turnCountLost[i]);
  }
  return 0;

}
