/******************************************************************************

Given an array of integers, both -ve and +ve, f
ind a contiguous subarray that sums to a number X.
For example: [2,4,-2,1,-3,5,-3], X = 5 --> Result = [2,4,-2,1]

*******************************************************************************/

#include<stdlib.h>
#include<stdio.h>

struct DataItem {
  int data;
  int key;
};
#define SIZE 7
#define TARGET 5

struct DataItem* my_hashArray[7];

int hashCode(int key) {
  return key % SIZE;
}

void insert(int key, int data) {
  struct DataItem* item = (struct DataItem *) malloc (sizeof(struct DataItem ));
  item->data = data;
  item->key= key;
  int hashIndex = hashCode(key);
  if(!my_hashArray) {
      printf("HashTable does not exist!");
      return;
  }
  my_hashArray[hashIndex] = item;
}

int hashKeyContain(int key) {
    int hashIndex = hashCode(key);
     if(my_hashArray[hashIndex]) {
         return my_hashArray[hashIndex]->key;
     }
     return -999;
}

int hashSearch(int key) {
    int hashIndex = hashCode(key);
    int count=0;
    
    while(my_hashArray[hashIndex] != NULL) {
        
        if(my_hashArray[hashIndex]->key == key) {
            return my_hashArray[hashIndex]->data;
        }
        
       ++hashIndex;
       hashIndex = hashCode(hashIndex);
       count++;
       if(count > SIZE) {
           return -999;
       }
    }
    return -999;
}

void display() {
  int i;
  if(!my_hashArray) {
      printf("HashTable does not exist!");
      return;
  }
  for(i=0;i<SIZE;i++) {
     if(my_hashArray[i] != NULL) {
        printf(" (%d, %d) ",my_hashArray[i]->key,my_hashArray[i]->data);
     }
     else {
       printf(" ~~ ");
     }
  }
  printf("\n");
}

int main()
{
    int arr[] = {2,4, -2,1,-3, 5,-3};
    int len = sizeof(arr)/ sizeof(arr[0]);
    int sum=0,i;
    
    for(i=0;i<len;i++) {
        sum = sum + arr[i];
        if(sum == TARGET) {
            // you can return also if using funtion
            printf("Found sub array position: (%d,%d) \n",0,i);
             break;
        }
        if(hashKeyContain(sum-TARGET) == (sum-TARGET)) {
            // you can return also if using funtion
            int val = hashSearch(sum);
            printf("Found sub array : position :( %d,%d)\n",val,i);
            break;
        }
        insert(sum,i);
    }
    return 0;
}
