
int placeQueen(char board[8][8][3], int* posRow, int* posCol, int* count);
void runEightQueen();
void crossTheBoard(char board[8][8][3], int pRow, int pCol);
int calcMoveValue(char const board[8][8][3], int pRow, int pCol);
int calcBoardCap(char const board[8][8][3]);
void copyBoards(char targetBoard[8][8][3], char const sourceBoard[8][8][3]);
int checkBoard(char const board[8][8][3]);