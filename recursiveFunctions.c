#include <stdio.h>
#include <string.h>
#include "recursiveFunctions.h"
#include "stdlib.h"

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

short int linearSearchRec(int* const arr, int key,int size){
    if (size==0) return -1;
    if(arr[size]==key) return size;
    else {
        return linearSearchRec(arr,key,size-1);
    }
    return 0 ;
}