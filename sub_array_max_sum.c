/******************************************************************************

find the sub-array with max sum

*******************************************************************************/

#include <stdio.h>

int max (int a, int b) {
  return (a > b ? a : b );
}

int main()
{
    int arr[] = {-2,-3,4,-1,-2,1,5,-1};

    int len = sizeof(arr)/sizeof(arr[0]);
    int result,maxEndingHere,i;
    result = maxEndingHere = arr[0];
    
    for(i=0;i<len;i++) {
          maxEndingHere = max(arr[i],(maxEndingHere+arr[i]));
          result = max(result , maxEndingHere);
    }
    
    printf("%d %d\n", result,maxEndingHere);
    
    return result;
}
