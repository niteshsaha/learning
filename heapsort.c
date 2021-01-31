/******************************************************************************

                            Heap sort algo

*******************************************************************************/

#include <stdio.h>

void swap (int *a,int *b) {
    return (*a = *a + *b - (*b=*a));
}

void heapify(int arr[],int n, int i) {
    int large = i;
    int l= 2*i+1;
    int r = 2*i+2;
    
    if(l<n && (arr[l] > arr[large]))
        large =l;
        
    if(r<n && (arr[r] > arr[large]))
        large =r;
    
    if(large !=i) {
        swap(&arr[large],&arr[i]);
        heapify(arr,n,large);
    }
}

void heap_sort(int arr[],int n) {
   for (int i = (n/2 -1);i>=0;i--)
      heapify(arr,n,i);
      
   for (int i = (n-1);i>0;i--) {
       swap (&arr[0],&arr[i]);
       heapify(arr,i,0);
   }

}

int main()
{
    int n =10;
   int arr[] = {1,3,4,2,7,6,5,8,10,9 };
   
   
   heap_sort(arr,n);
   for(int i=0;i<n;i++) {
       printf ("%d ",arr[i]);
   }

}
