
struct card
{
    /* data */
    short suit;
    short face;
};

int dealCards();
void playPoker();
int dealCards(int* deck, struct card* player1, struct card* player2);
int evaluateRank(struct card const *cards);
void displayCards(struct card* cards, int size);
int catchQuad(struct card const *cards);