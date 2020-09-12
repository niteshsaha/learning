/******************************************************************************

You are given an array of integers. 
Rearrange the array so that all zeroes are at the beginning of the array.
For example, [4,2,0,1,0,3,0] -> [0,0,0,4,1,2,3]


*******************************************************************************/

#include <stdio.h>

int main()
{
    int arr[] = {4,2,0,1,0,3,0};
    int len = sizeof(arr)/sizeof(arr[0]);
    int i,cloud=0;
    
    for (i=0;i<len;i++) {
        if(arr[i] == 0) {
            arr[i] = arr[i] + arr[cloud] - (arr[cloud] =  arr[i]);
            cloud++;
        }
    }

    for (i=0;i<len;i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}
