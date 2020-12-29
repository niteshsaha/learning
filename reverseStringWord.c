/******************************************************************************
Given a sentence, reverse the words of the sentence.
For example,
"i live in a house" becomes "house a in live i"
*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

void revStr(char *abc,int start, int Length) {
     int i;
     char temp;
     int end = Length -1;
     for(i = start;i < ((Length-start)/2 + start);i++) {
        temp = abc[i];
        abc[i] = abc[end];
        abc[end] = temp;
        end --;
     }
}

void  revWord(char *abc,int leng) {
    //reverse entire str
    revStr(abc,0,leng);
    
    int i=0,start=0;
    // reverse word
    for(i=0;i<=leng;i++) {
        if((abc[i] == ' ') || (i == leng)) {
            revStr(abc,start,i);
            start = i+1;
        }
    }
    
}

int main()
{
    char abc[] = "this is nitesh saha";
    int leng = strlen(abc);
    printf("Length of string is %d\n",leng);

    revWord(abc,leng);
    printf("Reverse string is %s",abc);
    return 0;
}
