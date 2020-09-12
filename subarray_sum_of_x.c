/******************************************************************************

Given an array of positive integers, find a subarray that sums to a given number X.
For e.g, input = [1,2,3,5,2] and X=8, Result = [3,5] (indexes 2,3)

*******************************************************************************/

#include <stdio.h>
#define TARGET 8

int main()
{
    int arr[] = {1,2,3,5,21};
    int len = sizeof(arr)/sizeof(arr[0]);
    int i, start=0,end=0,sum =arr[0];
    
    while(start < len) {
        if(sum < TARGET) {
            if(end == (len-1)) {
                break;
            }
            end++;
            sum = sum + arr[end];
        } else if(sum > TARGET) {
            sum = sum - arr[start];
            start ++;
        } else {
            //return pair(start, end);
            printf("for TARGET: %d, sub array (%d,%d) \n",TARGET,arr[start],arr[end]);
            break;
        }
        
        // check if start move ahead of end due to any high value present in array corner case:
        if(start > end) {
            end = start;
            sum = arr[start];
        }
    }
    return 0;
}
