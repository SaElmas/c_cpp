#include <stdio.h>
#include <string.h>
#include "recursiveFunctions.h"
#include "stdlib.h"
#include "utilities.h"

short int isPalindrome(char* const str){
    char* dest;
    if(strlen(str)<2) return 1;
    else if(strlen(str) == 2){
        return (str[0] == str[1]);
    }
    else {
        dest = (char*)malloc(sizeof(char)*strlen(str)-2); 
        strncpy(dest, str+1,strlen(str)-2);
        return (str[0]==str[strlen(str)-1] && isPalindrome(dest));
    }
}

size_t linearSearchRec(int const *arr, int key,int size){
    if (size==0) return -1;
    if(arr[size]==key) return size;
    else {
        return linearSearchRec(arr,key,size-1);
    }
    return 0 ;
}

size_t binarySearchR(int const *arr, int s, int e, int key){
    if(arr[s] == key) return s;
    if(arr[e] == key) return e;
    if(s-e ==-1) return -1;
    else if(arr[(s+e)/2]==key) return (s+e)/2;
    else if(arr[(s+e)/2] < key){
        return binarySearchR(arr, (s+e)/2, e, key);
    }
    else{
        return binarySearchR(arr, s,  (s+e)/2, key);
    }

}

int eightQueensR(int board[8][8] , int nq, int nf){ // nq:number of queens, nf:number of free spaces
    int i,j;
    int k,l;
    if (nq==0) return 1;
    if (nf==0) return 0;
    for(i=0 ; i<8; i++){
        for(j=0 ; j<8 ; j++){
            nf=0;
            for(k=0 ; k<8; k++){
                for(l=0; l<8; l++){
                    if(board[k][l] ==0) nf++;
                }
            }
//            printf("%2d%2d%3d\n",i,j,nf);
            if(board[i][j]!=0 && nf >0){
                continue;
            }
            else if(board[i][j]!=0 && nf==0) return 0;
            else if(board[i][j] == 0){
//                puts("==========================");
//                puts("======PUT THE QUEEN=======");
                putQueen(board, i,j);
//                for(k=0 ;k<8 ;k++){
//                   printArray(board[k],8);
//                }
                nf=0;
                for(k=0 ; k<8; k++){
                    for(l=0; l<8; l++){
                        if(board[k][l] ==0) nf++;
                    }
                }
//                printf("%2d%2d%3d\n",i,j,nf);
            }
            if(eightQueensR(board,nq-1, nf)){
                return 1;
            }
            else{
//                puts("==========================");
//                printf("===== i=%2d; j=%2d =====\n",i,j);
//                puts("====TAKE BACK THE QUEEN===");
                takeQueen(board,i,j);
                nf=0;
                for(k=0 ; k<8; k++){
                    for(l=0; l<8; l++){
                        if(board[k][l] ==0) nf++;
                    }
                }
//                printf("%2d%2d%3d\n",i,j,nf);

            }
        }
    }
    return 0;
}

void putQueen(int board[8][8], int x, int y){
    int i;
    board[x][y] = 2;
    for(i=1; i<8 ; i++){
        if(board[x][(y+i)%8] != 2) board[x][(y+i)%8]=-1; 
    }
    for(i=1; i<8 ; i++){
        if(board[(x+i)%8][y] != 2) board[(x+i)%8][y]=-1; 
    }
    for(i=1; i<8 ; i++){
        if(x+i < 8 && y+i <8){
            if(board[x+i][y+i] != 2) board[x+i][y+i]=-1; 
        }
    }
    for(i=1; i<8 ; i++){
        if(x-i > -1 && y+i <8){
            if(board[x-i][y+i] != 2) board[x-i][y+i]=-1; 
        }
    }
    for(i=1; i<8 ; i++){
        if(x-i > -1 && y-i >-1){
            if(board[x-i][y-i] != 2) board[x-i][y-i]=-1; 
        }
    }
    for(i=1; i<8 ; i++){
        if(y-i > -1 && x+i <8){
            if(board[x+i][y-i] != 2) board[x+i][y-i]=-1; 
        }
    }
}

void takeQueen(int board[8][8], int x ,int y){
    int i,j;
    board[x][y] =0;
    for(i=0 ; i<8; i++){
        for(j=0 ; j<8 ; j++){
            if(board[i][j]!=2) board[i][j]=0;
        }
    }
//    puts("==========================");
//    puts("====READY FOR PLACEMENT===");
//    for(i=0 ; i<8 ; i++){
//        printArray(board[i],8);
//    }
    for(i=0 ; i<8; i++){
        for(j=0 ; j<8 ; j++){
            if(board[i][j]==2) putQueen(board,i,j);
        }
    }
//    puts("==========================");
//    puts("=========REDECORATED======");
//    for(i=0 ; i<8 ; i++){
//        printArray(board[i],8);
//    }
    
}

int findMinRec(int arr[], int size){
    int min;
    if (size==1) return arr[0];
    min = findMinRec(arr+1,size-1);
    if(arr[0] < min) return arr[0];
    else return min;

}