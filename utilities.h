void fillArray(int arr[], int start, int size);
void fillArrayRandom(int arr[],int size, int start, int stop);
void printArray(int const arr[], int size);
float mean (int const arr[], int size);
int median (int const arr[], int size);
int frequency (int const arr[],int size, int value);
int mode(int const arr[], int size, int stop, int start);
int arrMax(int const arr[], int size, short select); // select=0 returns max value select=1 returns max index
int* arrMin(int const arr[], int size);// retur[0] is index, retur[1] is value;
void bubbleSort(int arr[], int size); 
void bubbleSortDesc(int arr[], int size); 
void selectionSort(int arr[], int size);
void shuffleArray(int arr[], int size);
int binarySearch(int arr[],int size, int number);
void swapArr(int arr[], int indexa, int indexb);
void setUnion(int arr[], int arr1[], int arr2[], int size);
int isInside(int arr[], int size, int n);
void setIntersection(int arr[], int arr1[], int arr2[], int size);
int** matrixMultp(int** arr1, int r1, int c1, int** arr2, int r2, int c2);
int isPrime(unsigned long long int n);
unsigned int* primeFactors(unsigned long long int n);
int getRandomInteger(int start, int stop);

void toUpperCase(char* sPtr);