/******************************************************************************

Given an array A, print all permutations of size X.
For example,
Input:
A = [1,2,3] X=2
Output:
[1, 2] [1, 3] [2, 1] [2, 3] [3, 1] [3, 2]

*******************************************************************************/

#include <stdio.h>

#include <stdio.h>

void printsubSets(int arr[],int arrLen,int buffer[],int bufLen,int startIndex,int bufIndex) {
    int i;
    for (i=0;i<bufIndex;i++) {
        printf("%d ",buffer[i]);
    }
        printf("\n");
    if (bufIndex == bufLen) {
        return;
    }
    if (startIndex == arrLen) {
        return;
    }
    
    int j;
    for(j=startIndex;j<arrLen;j++) {
        buffer[bufIndex] = arr[j];
        
        printsubSets(arr,arrLen,buffer,bufLen,j+1,bufIndex+1);
    }
}

void main() {
    int a[] = {1,2,3};
    int arrlen = sizeof(a)/sizeof(a[0]);
    int buffer[arrlen];
    printsubSets(a,arrlen,buffer,arrlen,0,0);
}
