#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include <time.h>
#include "utilities.h"
#include "poker.h"


// game runner
void playPoker(){
    //Initialize the deck of cards;
    int deck[52] = {0};
    struct card wholeDeck[52];
    struct card player1[5];
    struct card player2[5];
    
    fillArray(deck, 0 ,52);
    srand(time(NULL));
    shuffleArray(deck,52);
    for(int i=0 ; i<52; i++){
        wholeDeck[i].face=deck[i]%13;
        wholeDeck[i].suit=deck[i]/13;
    }
    dealCards(deck, player1, player2);

    displayCards(player1, 5);
    displayCards(player2, 5);

    evaluateRank(player1);

}

//display player's hand in human readible format
void displayCards(struct card* cards, int size){
    int suitNo, faceNo;
	setlocale(LC_ALL,"");
	const wchar_t clubs=L'\u2663';
    const wchar_t spades=L'\u2660';
    const wchar_t hearts=L'\u2665';
    const wchar_t diamonds=L'\u2666';
    const wchar_t suits[4] = {spades, hearts, diamonds, clubs};
    const char faces[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    for(int i=0; i<size ; i++){
        suitNo = (cards+i)->suit;
        faceNo = (cards+i)->face;
        printf("%lc%c ", suits[suitNo],faces[faceNo]);
    }
    printf("\n");

}

//Deals cards to two players. Each player holds 5 cards.
int dealCards(int* deck, struct card* player1, struct card* player2)
{
    int i;
    int currentDeckSize = 52;

    for(i=0; i<5; i++){
        player1[i].suit = deck[currentDeckSize-1]/13;
        player1[i].face = deck[currentDeckSize-1]%13;
        currentDeckSize--;
    }
    for(i=0; i<5; i++){
        player2[i].suit = deck[currentDeckSize-1]/13;
        player2[i].face = deck[currentDeckSize-1]%13;
        currentDeckSize--;
    }

   return 0;
}

//evaluate hand rank
int evaluateRank(struct card const *cards){
    int rank=0;
    struct card demo[5];
    if((rank = catchQuad(cards)) > -1){
        printf("%d\n",rank);
    } 

    demo[4].suit =0;
    demo[4].face =1;
    demo[2].suit =1;
    demo[2].face =1;
    demo[1].suit =2;
    demo[1].face =1;
    demo[3].suit =3;
    demo[3].face =1;
    demo[0].suit =1;
    demo[0].face =4;
    displayCards(demo,5);
    if((rank = catchQuad(demo)) > -1){
        printf("%d\n",rank+15);
    } 


    return rank;
}


int catchQuad(struct card const *cards){
    if( cards[0].face == cards[1].face && cards[1].face == cards[2].face && cards[2].face == cards[3].face )
    {
        return cards[0].face;
    }
    else if( cards[0].face == cards[1].face && cards[1].face == cards[2].face && cards[2].face == cards[4].face )
    {
        return cards[0].face;
    }
    else if( cards[0].face == cards[1].face && cards[1].face == cards[3].face && cards[3].face == cards[4].face )
    {
        return cards[0].face;
    }
    else if( cards[0].face == cards[2].face && cards[2].face == cards[3].face && cards[3].face == cards[4].face )
    {
        return cards[0].face;
    }
    else if( cards[1].face == cards[2].face && cards[2].face == cards[3].face && cards[3].face == cards[4].face )
    {
        return cards[1].face;
    }

    return -1;
}