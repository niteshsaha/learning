/******************************************************************************

Given a sorted array of integers, 
find two numbers in the array that sum to a given integer target.
For example, if a = [1,2,3,5,6,7] and target = 11, the answer will be 5 and 6.

*******************************************************************************/

#include <stdio.h>

#define TARGET 11

int main()
{

   int arr[] = {1,2,3,5,6,7};

   int len = sizeof(arr)/sizeof(arr[0]);
   
   int firstIndex = 0;
   int lastIndex = len-1;
   while((arr[firstIndex] + arr[lastIndex]) != TARGET) {
        if((arr[firstIndex] + arr[lastIndex]) < TARGET) {
            firstIndex++;
        } else {
            lastIndex--;
        } 
   }
   printf("Two number is : (%d, %d)",arr[firstIndex],arr[lastIndex]);
   return 0;
}
