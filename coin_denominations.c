/******************************************************************************

Coin Change Problem: Given a set of coin denominations, print out the different ways
you can make a target amount. You can use as many coins of each denomination as you like.
For example: If coins are [1,2,5] and the target is 5, output will be:
[1,1,1,1,1] [1,1,1,2] [1,2,2]
[5]

*******************************************************************************/

#include <stdio.h>
#include<stdbool.h>

void coinChange(int coin[], int arraySize, int buffer[], int bufferSize, int arrayIndex, int bufferIndex, int target, int sum) {
    if (sum == target) {
        int i;
        for(i=0;i<bufferIndex;i++) {
            printf("%d ",buffer[i]);
        }
        printf("\n");
        return ;
    }
    if(sum >target) {
        return;
    }
    
    for (int i = arrayIndex; i < arraySize; i++) {
            buffer[bufferIndex] = coin[i];
            coinChange(coin,arraySize,buffer,bufferSize,i,bufferIndex+1,target,sum + coin[i]);
            buffer[bufferIndex] = 0;
    }
}
int main()
{
    int coin[] = {1,2,5};
    int arraySize = sizeof(coin)/sizeof(coin[0]);
    int target =5;
    int buffer[target];
    coinChange(coin,arraySize,buffer,target,0,0,target,0);
    return 0;
}
