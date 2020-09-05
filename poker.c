#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include "utilities.h"
#include "poker.h"


int dealCards()
{
    int i;
    int suitNo, faceNo;
	setlocale(LC_ALL,"");
    int deck[52]={0};
	const wchar_t clubs=L'\u2663';
    const wchar_t spades=L'\u2660';
    const wchar_t hearts=L'\u2665';
    const wchar_t diamonds=L'\u2666';
    const wchar_t suits[4] = {spades, hearts, diamonds, clubs};
    const char faces[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    fillArray(deck,0,52);
    printArray(deck, 52);
    shuffleArray(deck,52);
    printArray(deck, 52);
    for(i=0; i<52 ; i++){
        suitNo=deck[i]/13;
        faceNo=deck[i]%13;
        printf("%lc%c ", suits[suitNo],faces[faceNo]);
        if((i+1)%5==0){
            printf("\n");
        }
    }

   return 0;
}

void playPoker(){
    dealCards();
}

