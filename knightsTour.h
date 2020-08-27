void initEmptyBoard(char board[8][8][3], int* pRow, int* pCol);
void drawChessBoard(char board[8][8][3], int count);
int cellVisited(char board[][8][3], int row, int column);
int moveKnight(char board[][8][3], int* pRow, int* pColumn, int* counter);
int startKnightsTour(int showSteps, int randSeed);