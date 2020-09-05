short int isPalindrome(char* str);
size_t linearSearchRec(int const *arr, int key,int size);
size_t binarySearchR(int const *arr, int s, int e, int key);
int eightQueensR(int board[8][8] , int nq, int nf); // nq:number of queens, nf:number of free spaces
void putQueen(int board[8][8], int x, int y);
void takeQueen(int board[8][8], int x ,int y);
int findMinRec(int arr[], int size);