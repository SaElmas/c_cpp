#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utilities.h"

void fillArray(int arr[],int start, int size){
  unsigned short i;
  for(i=start ; i<size+start; i++){
    arr[i] = i;
  }
}

void fillArrayRandom(int arr[],int size, int start, int stop){
  /* Feed the random() at main */
  int randNumber;
  for(size_t i=0 ; i<size ; i++){
    randNumber= rand()%(stop-start+1) + start;
    arr[i] = randNumber;
  }
}

void printArray(int const arr[], int size){
  for(size_t i=1 ; i<=size ; i++){
    printf("%4d",arr[i-1]);
    if(i%10==0 ) printf("\n");
  }
  printf("\n");
}

float mean (int const arr[], int size){
  float sum = 0;
  for(size_t i=0 ; i<size ; i++){
    sum += arr[i];
  }
  return sum/size;
}

void bubbleSort(int arr[], int size){
  short sorted=0;
  for(size_t i=0 ; !sorted && i<size  ; i++){
    sorted=1;
    for(size_t j=0 ; j<size-1 ; j++){
      if(arr[j] > arr[j+1]){
        int hold=arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = hold;
        sorted =0;
      }
    }
  }
}

void bubbleSortDesc(int arr[], int size){
  short sorted=0;
  for(size_t i=0 ; !sorted && i<size  ; i++){
    sorted=1;
    for(size_t j=0 ; j<size-1 ; j++){
      if(arr[j] < arr[j+1]){
        int hold=arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = hold;
        sorted =0;
      }
    }
  }
}

void selectionSort(int arr[], int size){
  int minIndex;
  int i;

  for(i=0 ; i<size-1 ; i++){
    minIndex = arrMin(arr+i,size-i)[0];
    swapArr(arr+i,0,minIndex);
  }
}

void swapArr(int arr[], int indexa, int indexb){
  int temp;
  temp = arr[indexa];
  arr[indexa] = arr[indexb];
  arr[indexb] = temp;
}

int arrMax(int const arr[], int size, short select){
  int max=0;
  int index=0;
  for(size_t i=0 ; i<size ; i++){
    if(arr[i] > max ){
     max = arr[i];
     index = i;
    }
  }
  if (select ==0) return max;
  else return index;
}

int* arrMin(int const arr[], int  size){
  int min=arr[0];
  int index=0;
  int* rPtr;
  rPtr = (int*)malloc(sizeof(int)*2);
  for(size_t i=0 ; i<size ; i++){
    if(arr[i] < min ){
      min = arr[i];
      index = i;
    }
  }
  rPtr[0] = index;
  rPtr[1] = min;
  return rPtr;
}

int median (int const arr[], int size){
  return arr[(size +1)/2];
}

int frequency (int const arr[],int size, int value){
  int count=0;
  for(size_t i=0 ; i<size ; i++){
    if(arr[i] == value) count++;
  }
  return count;
}

int mode(int const arr[], int size, int stop, int start){ //start: range start, stop:range stop
  int nsize=stop-start+1;
  int a[nsize];

  for(size_t i=0 ; i<nsize ; i++){
      a[i] =0;
  }
  
  for(size_t i = 0 ; i<size ; i++){
    ++a[arr[i]-1];
  }
  return arrMax(a, nsize, 1) +1 ;
}

void shuffleArray(int arr[], int size){
  unsigned short i;
  unsigned short randIndex;
  int hold;
  for(i=0 ; i<10 ; i++) rand();
//  puts("Shuffle Initialized");
  for(i=0 ; i<size; i++){
    randIndex = rand()%(size-1); 
//    printf("random index number:%2d\n",randIndex);
    hold= arr[i];
    arr[i] = arr[randIndex];
    arr[randIndex]=hold;
  }
}

int binarySearch(int arr[],int size, int number){
  int i0, i1, m;
  i0 = 0;
  i1 = size-1;
  m = i1/2;
  while( i1-i0>1){
//    printf("%10s%5d%10s%5d%10s%5d%10s%5d\n","Start: ",i0,"Middle: ",m,"End: ",i1,"Value: ",arr[m]);
    if(arr[m] == number){
      return m;
    }
    else if(arr[m] > number){
      i1 = m;
      m= (i0+i1) / 2;
    }
    else {
      i0 = m;
      m= (i0+i1) / 2;
    }
  }
  return -1;
}

void setUnion(int arr[], int arr1[], int arr2[], int size){
  int i;
  int freeIndex=0;
  for(i=0 ; i<2*size ; i++){
    arr[i] = -1;
  }
  for(i=0 ; i<size ; i++){
    if(!isInside(arr,2*size,arr1[i])){
      arr[freeIndex] = arr1[i];
      freeIndex++;
    }
    if(!isInside(arr,2*size,arr2[i])){
      arr[freeIndex] = arr2[i];
      freeIndex++;
    }
  }
}

void setIntersection(int arr[], int arr1[], int arr2[], int size){
  int i;
  int arrIndex=0;
  for(i=0 ; i<size; i++){
    arr[i] = -1;
  }
  for(i=0 ; i<size ; i++){
    if(isInside(arr2, size, arr1[i]) && !isInside(arr, size, arr1[i])){
      printf("%5d\n",arr1[i]);
      arr[arrIndex++]=arr1[i];
    }
  }
}

int isInside (int arr[],int size, int n){
  int i;
  for(i=0 ; i<size; i++){
    if (arr[i] == n) return 1;
  }
  return 0;
}

int** matrixMultp(int** arr1, int r1, int c1, int** arr2, int r2, int c2){
  int** arr;
  int i,j,k;


  arr = (int**)malloc(sizeof(int*));
  for (i=0 ; i<r1 ; i++){
    arr[i] = (int*)malloc(sizeof(int)*c2);
  }
  for(i=0 ; i<r1 ; i++){
    for(j=0 ; j<c2 ; j++){
      arr[i][j] = 0;
    }
  }

  for(i=0 ; i<r1 ; i++) {
    for(j=0 ; j<c2 ; j++){
      for(k=0; k<r2 ; k++){
        arr[i][j] += arr1[i][k]*arr2[k][j];
      }
    }

  }

  if(c1!=r2) {
    puts("Check Matrix Dimentions");
    return arr;
  }
  return arr;
}

int isPrime(unsigned long long int n)
{
  unsigned long int i;
/*  printf("Program startswwith %lld...\n", n); */
  if(n==1 || n==2 || n==3) return 1;
  for(i=2 ; i<= n/2 ; i++)
  {
/*    printf("checking primity of %lld...\n", n); */
    if(n%i==0) return 0;
  }
  return 1;
}

unsigned int* primeFactors(unsigned long long int n)
{
  unsigned int count=0;
  unsigned int size=5;
  unsigned long int i;
  unsigned int* factors; 
  factors = (unsigned int*)calloc(size,sizeof(unsigned int));
  for(i=1 ; i<n/2 ; i++)
  {
    if(n%i == 0 && isPrime(i))
    {
      factors[count+1]=i;
      count++;
      if(count==size-1)
      {
        factors = (unsigned int*) realloc(factors, sizeof(unsigned int)*(size+5));
        size+=5;
      }
    }
  }
  factors[0] = count;
  return factors;
}

int getRandomInteger(int start, int stop)
{
  int randNumber;
  randNumber = rand()%(stop-start+1) +1;
  return randNumber;
}

void toUpperCase(char* sPtr)
{
  while(*sPtr != '\0'){
    if(*sPtr < 'z' && *sPtr > 'a'){
      printf("%c",*sPtr -= ('a' -'A'));
    }
    sPtr++;
  }

}