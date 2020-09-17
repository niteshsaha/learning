/******************************************************************************


Phone Number Mnemonics: Given an N digit phone number, 
print all the strings that can be made from that phone number. 
Since 1 and 0 don't correspond to any characters, ignore them.

*******************************************************************************/

#include <stdio.h>

char * getLetters(int digit, int *letterSize) { 
 switch (digit) {
    case 0: *letterSize = 0; return ""; 
    case 1: *letterSize = 0; return "";
    case 2: *letterSize = 3; return "abc";
    case 3: *letterSize = 3;  return "def";
    case 4: *letterSize = 3;  return "ghi";
    case 5: *letterSize = 3;  return "jkl";
    case 6: *letterSize = 3;  return "mno";
    case 7: *letterSize = 4;  return "pqrs";
    case 8: *letterSize = 3;  return "tuv";
    case 9: *letterSize = 4;  return "wxyz";
  }
}

void printDialNumberCombos(int arr[],int arrLen,char buffer[],int bufLen,int aIndex,int bufIndex) {
    if (bufIndex == bufLen || aIndex >= arrLen) {
        int i;
       //printf("%s ",buffer);
        for (i=0;i<bufLen;i++) {
           printf("%c ",buffer[i]);
        }
        printf("\n");
        return;
    }
    int letterSize;
    char *letter = getLetters(arr[aIndex], &letterSize);
    if ( letterSize == 0) {
       printDialNumberCombos(arr,arrLen,buffer,bufLen,aIndex+1,bufIndex+1); 
    }
    int j;
    for(j=0;j<letterSize-1;j++) {
        buffer[bufIndex] = letter[j];
        printf("%c",letter[j]);
        printDialNumberCombos(arr,arrLen,buffer,bufLen,aIndex+1,bufIndex+1);
    }
}

int main()
{
    int array[] = {1,2,3};
    char buffer[3];
    
    printDialNumberCombos(array, (sizeof(array)/sizeof(array[0])),buffer,(sizeof(buffer)/sizeof(buffer[0])),
                0,0);
    return 0;
}
