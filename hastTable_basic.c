#include<stdlib.h>
#include<stdio.h>

#define SIZE 20

struct DataItem {
  int data;
  int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* item;

int hashCode(int key) {
  return key % SIZE;
}

void insert(int key, int data) {
  struct DataItem* item = (struct DataItem *) malloc (sizeof(struct DataItem ));
  item->data = data;
  item->key= key;

  int hashIndex = hashCode(key);

  while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
     ++hashIndex;
     hashIndex = hashCode(hashIndex);
  }

 hashArray[hashIndex] = item;

}

void display() {
  int i;
  for(i=0;i<SIZE;i++) {
     if(hashArray[i] != NULL) {
        printf(" (%d, %d) ",hashArray[i]->key,hashArray[i]->data);
     }
     else {
       printf(" ~~ ");
     }
  }
  printf("\n");
}

void delete(struct DataItem* item) {
  int hashIndex = hashCode(item->key);
  while(hashArray[hashIndex] != NULL) {
   if(hashArray[hashIndex]->key == item->key && hashArray[hashIndex]->data == item->data) {
     hashArray[hashIndex]->key = -1;
     hashArray[hashIndex]->data = -1;
     free(hashArray[hashIndex]);
     hashArray[hashIndex]= NULL;
     return;
   }
   ++hashIndex;
   hashIndex = hashCode(hashIndex);
  }
}

void main() {
   insert(10,23);
   insert(3,29);
   insert(9,11);
   display();
   item = hashArray[3];
   delete(item);
   display();
}
