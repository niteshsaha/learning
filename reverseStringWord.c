/******************************************************************************
Given a sentence, reverse the words of the sentence.
For example,
"i live in a house" becomes "house a in live i"
*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

void revStr(char *abc,int start, int end) {
     int i;
     char temp;
     while(start<end) {
        temp = abc[start];
        abc[start] = abc[end];
        abc[end] = temp;
        start++;
        end --;
     }
}

void  revWord(char *abc,int leng) {
    //reverse entire str
    revStr(abc,0,leng-1);
    
    int i=0,start=0;
    // reverse word
    for(i=0;i<=leng;i++) {
        if((abc[i] == ' ') || (i == leng)) {
            revStr(abc,start,i-1);
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
