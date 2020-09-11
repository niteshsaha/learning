/******************************************************************************

Given an array, reverse the order of its elements.
For example, [3,5,2,5,2,3,9] → [9,3,2,5,2,5,3]

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{

   int arr[] = {3,5,2,5,2,3,9,10};
   int len = sizeof(arr)/sizeof(arr[0]);
   
   int i;
   for(i=0;i<len/2;i++) {
       arr[i] = arr[i] + arr[len-i-1] - (arr[len-i-1] = arr[i]);
   }

   for(i=0;i<len;i++) {
      printf("%d ",arr[i]);   
   }

    return 0;
}
