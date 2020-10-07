/******************************************************************************
Given a sentence, reverse the words of the sentence.
For example,
"i live in a house" becomes "house a in live i"
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "nitesh i live in a house";
    int strSize= strlen(str);
    
    printf("Lenght of string : %d",strSize);
    
    char str1[strSize];
    
    int startWord =0, endWord=strSize-1,i,k=0,j;
    
    for(i=strSize-1;i>=0;i--) {
        if(str[i] == ' ') {
            startWord = i + 1;
            for(j=startWord;j<=endWord;j++) {
                str1[k] = str[j];  
                k++;
            }
            if(startWord-2 >= 0) {
                str1[k] = ' ';
                k++;
                endWord = startWord-2;
                startWord = 0;
            }
        } else if (i == 0) {
            for(j=i;j<=endWord;j++) {
                str1[k] = str[j];  
                k++;
            }
        }
    }
    
        //print the new array
    printf("\n orginal string : %s",str);
    printf("\n final str is : %s",str1);
   
    
}
