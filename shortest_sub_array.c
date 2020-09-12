/******************************************************************************

Given an array of integers, find the shortest sub array, that if sorted, results in the entire array being sorted.
For example:
[1,2,4,5,3,5,6,7] --> [4,5,3] - If you sort from indices 2 to 4, 
the entire array is sorted. [1,3,5,2,6,4,7,8,9] --> [3,5,2,6,4] - If you sort from indices 1 to 5, the entire array is sorted.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int arr[] = {1,3,5,2,6,4,7,8,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    int start =0, end = 0;
    int i;
    int min=0, max=0;
    
    for(start=0;start<len-1;start++) {
        if(arr[start +1] < arr[start]) {
            break;
        }
     }
     if(start == (len-1)) {
         printf("Sorted array!");
         return 0;
     }
     
     for(end = len-1;end > 0;end--) {
        if(arr[end -1]  > arr[end]) {
            break;
        }
     }
    
    printf("start : %d, end %d\n",start,end);
    // find max and min number between start and end
    min = max = start;
    for(i=start;i<=end;i++) {
        if(min > arr[i] ) {
            min = arr[i];
        }
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    
    printf("min %d, max %d \n",min,max);
    
    while(start > 0 && (start-1) > min) {
        start--;
    }
    while(end < len-1 && (end+1) < max) {
        end++;
    }
    for(i=start;i<=end;i++) {
      printf(" %d ",arr[i]);
    }
    return 0;
}
