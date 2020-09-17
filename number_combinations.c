/******************************************************************************

Given an array of integers, print all combinations of size X.

*******************************************************************************/

#include <stdio.h>

void printCombos(int arr[],int arrLen,int buffer[],int bufLen,int startIndex,int bufIndex) {
    if (bufIndex == bufLen) {
        int i;
        for (i=0;i<bufLen;i++) {
            printf("%d ",buffer[i]);
        }
        printf("\n");
        return;
    }
    if (startIndex == arrLen) {
        return;
    }
    
    int j;
    for(j=startIndex;j<arrLen;j++) {
        buffer[bufIndex] = arr[j];
        
        printCombos(arr,arrLen,buffer,bufLen,j+1,bufIndex+1);
    }
