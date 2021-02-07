/******************************************************************************

                            TRIE PROGRAMING IN C

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define ALL_LETTER 26
#define SIZE(a) sizeof(a)/sizeof(a[0])
#define CHAR_TO_INT(str) ((int)str - (int)'a')

typedef struct TrieNode {
    struct TrieNode *children[ALL_LETTER];
    bool is_end_of_word;
} TrieNode;

TrieNode *getNode(void) {
        int i;
        TrieNode *pnode = (TrieNode *) malloc(sizeof(TrieNode));
        if(pnode) {
            pnode->is_end_of_word = false;
            for(i=0;i<ALL_LETTER;i++) {
                pnode->children[i]=NULL;
            }
            
        }
}

void insert(TrieNode *root, const char *key) {
     int level;
     TrieNode *pnode = root;
     int index;
     
     for(level=0;level < strlen(key);level++) {
         index= CHAR_TO_INT(key[level]);
         if(!pnode->children[index]) {
             pnode->children[index] = getNode();
         }
         pnode= pnode->children[index];
     }
     //mark the last leaf as end of word
     pnode->is_end_of_word= true;
     
}

bool search(TrieNode *root, const char *key) {
    int level;
    TrieNode *pnode = root;
    int index;
    
    for(level =0;level <strlen(key);level++) {
        index = CHAR_TO_INT(key[level]);
        if(!pnode->children[index])
            return false;
        pnode = pnode->children[index];
    }
    
    return (pnode && pnode->is_end_of_word);
}

int main()
{
    char key[][7] = {"hi","this","is","nitesh","saha","from","india"};
    int i;
    TrieNode *root = getNode();
    for(i=0;i<SIZE(key);i++) 
       insert(root,key[i]);
        
    char toSearch[] = "is";
    search(root, toSearch) ? printf("FOUND : %s\n",toSearch) : printf("NOT-FOUND : %s\n",toSearch);
    return 0;
}
