/******************************************************************************

Given a sorted array in non-decreasing order, 
return an array of squares of each number, also in non-decreasing order. 

For example:
[-4,-2,-1,0,3,5] -> [0,1,4,9,16,25] How can you do it in O(n) time?

*******************************************************************************/

#include <stdio.h>

static int abs(int number) {
    return number >= 0 ? number : -1 * number;
}

static int square(int number) { 
    return number * number;
}

int main()
{
   int arr[] = {-4,-2,-1,0,3,5};
   int len = sizeof(arr)/sizeof(arr[0]);
   int newArr[len];
   int start=0, end=len-1;
   int resultIndex = len-1;
   
   while(start <= end) {
       if(abs(arr[start]) > abs(arr[end])) {
           newArr[resultIndex] = square(arr[start]);
           start++;
       } else {
          newArr[resultIndex] = square(arr[end]);
           end--;
       }
       resultIndex--;
   }
   
   int i=0;
   for(i=0;i<len;i++) {
       printf("%d ",newArr[i]);
   }
    
   return 0;
}
