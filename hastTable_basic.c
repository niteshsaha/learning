#include<stdlib.h>
#include<stdio.h>

struct DataItem {
  int data;
  int key;
};
struct DataItem* hashArray[];
void insert(int key, int data, struct DataItem* my_hashArray[], int size);
void display(struct DataItem* my_hashArray[], int size);
void delete(struct DataItem* item, struct DataItem* my_hashArray[], int size);
int hashSearch(int key,struct DataItem* my_hashArray[], int size);


int hashCode(int key, int size) {
  return key % size;
}

void insert(int key, int data, struct DataItem* my_hashArray[], int size) {
    
   int temp = hashSearch(3,hashArray,size);
  if(temp!= -1 && temp == data) {
     printf("Key already exist!\n");
     return;
  }
  
  struct DataItem* item = (struct DataItem *) malloc (sizeof(struct DataItem ));
  item->data = data;
  item->key= key;

  int hashIndex = hashCode(key,size);
  
  if(!my_hashArray) {
      printf("HashTable does not exist!");
      return;
  }

  while(my_hashArray[hashIndex] != NULL && my_hashArray[hashIndex]->key != -1) {
     ++hashIndex;
     hashIndex = hashCode(hashIndex,size);
  }

  my_hashArray[hashIndex] = item;

}

void display(struct DataItem* my_hashArray[], int size) {
  int i;
  if(!my_hashArray) {
      printf("HashTable does not exist!");
      return;
  }
  for(i=0;i<size;i++) {
     if(my_hashArray[i] != NULL) {
        printf(" (%d, %d) ",my_hashArray[i]->key,my_hashArray[i]->data);
     }
     else {
       printf(" ~~ ");
     }
  }
  printf("\n");
}

void delete(struct DataItem* item, struct DataItem* my_hashArray[], int size) {
  int hashIndex = hashCode(item->key,size);
  if(!my_hashArray) {
      printf("HashTable does not exist!");
      return;
  }
  while(my_hashArray[hashIndex] != NULL) {
   if(my_hashArray[hashIndex]->key == item->key && my_hashArray[hashIndex]->data == item->data) {
     my_hashArray[hashIndex]->key = -1;
     my_hashArray[hashIndex]->data = -1;
     free(my_hashArray[hashIndex]);
     my_hashArray[hashIndex]= NULL;
     return;
   }
   ++hashIndex;
   hashIndex = hashCode(hashIndex,size);
  }
}

int hashSearch(int key,struct DataItem* my_hashArray[], int size) {
    int hashIndex = hashCode(key,size);
    int count=0;
    
    while(my_hashArray[hashIndex] != NULL) {
        
        if(my_hashArray[hashIndex]->key == key) {
            return my_hashArray[hashIndex]->data;
        }
        
       ++hashIndex;
       hashIndex = hashCode(hashIndex,size);
       count++;
       if(count > size) {
           return -1;
       }
    }
    return -1;
}

void main() {

   int size =20;
   struct DataItem* item;
   insert(10,23,hashArray, size);
   insert(3,29,hashArray, size);
   insert(9,11,hashArray, size);
   display(hashArray,size);
   printf("seaching result for key : 3 %d\n", hashSearch(3,hashArray,size));
   item = hashArray[3];
   delete(item,hashArray,size);
   display(hashArray,size);
   printf("second attempt seaching result for key : 3 %d\n", hashSearch(3,hashArray,size));
}
