/******************************************************************************

Given an array of numbers, replace each even number with two of the same number. 
e.g, [1,2,5,6,8, , , ,] -> [1,2,2,5,6,6,8,8].
Assume that the array has the exact amount of space to accommodate the result.

*******************************************************************************/

#include <stdio.h>

int findlastvalidNumber(int arr[],int lastIndex) {
    int i;
    for(i=lastIndex;i>=0;i--) {
        if(arr[i] !=-1) {
            return i;
        }
    }
    return 0;
}

int main()
{
    int arr[] = {1,2,5,6,8,-1,-1,-1};
    
    int lastIndex = sizeof(arr) / sizeof(arr[0]);
    
    int lastValidNumber = findlastvalidNumber(arr,lastIndex-1);
    
    printf("lastValidNumber : %d , lastIndex %d\n",lastValidNumber,lastIndex);
    int i;
    
    for(i=lastValidNumber;i >=0;i--) {
        if(arr[i] % 2 == 0) {
            arr[--lastIndex] = arr[i] ;
            arr[--lastIndex]= arr[i];
        } else {
            arr[--lastIndex] = arr[i];
        }
    }
    
    lastIndex = sizeof(arr) / sizeof(arr[0]);
    
    for (i=0;i<lastIndex;i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}
