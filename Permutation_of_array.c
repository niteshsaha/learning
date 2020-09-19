/******************************************************************************

Given an array A, print all permutations of size X.
For example,
Input:
A = [1,2,3] X=2
Output:
[1, 2] [1, 3] [2, 1] [2, 3] [3, 1] [3, 2]

*******************************************************************************/

#include <stdio.h>
#include<stdbool.h>

void printPermsHelper(int a[], int arraySize, int buffer[], int bufferSize, int bufferIndex, bool isInBuffer[]) {
    if (bufferIndex == bufferSize) {
        int i;
        for(i=0;i<bufferSize;i++) {
            printf("%d ",buffer[i]);
        }
        printf("\n");
        return ;
    }
    for (int i = 0; i < arraySize; i++) {
        if (!isInBuffer[i]) {
             buffer[bufferIndex] = a[i];
           isInBuffer[i] = true;
           printPermsHelper(a, arraySize, buffer, bufferSize, bufferIndex + 1, isInBuffer); 
           isInBuffer[i] = false;
        } 
    }
}
int main()
{
    int array[] = {1,2,3};
    int arraySize = sizeof(array)/sizeof(array[0]);
    int bufferSize =2;
    int buffer[bufferSize];
    bool isInBuffer[arraySize];
    int i;
    for(i=0;i<arraySize;i++) {
        isInBuffer[i]= false;
    }
    printPermsHelper(array,arraySize,buffer,bufferSize,0,isInBuffer);
    return 0;
}
