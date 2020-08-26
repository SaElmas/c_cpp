
void drawBoard(int** state,int dx, int dy, char border, char occ);
int** generateRandomBoard(int dx, int dy);
void modifyBoard(int** board, int pos[2], int direction, int distance);
void updateBoard(int** board, int dx, int dy, char border, char occ, int* instructions);