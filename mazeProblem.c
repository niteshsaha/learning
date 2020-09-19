/******************************************************************************

Maze Problem: You are given a 2D array that represents a maze. 
It can have 2 values - 0 and 1. 1 represents a wall and 0 represents a path.
The objective is to reach the bottom right corner, 
i.e, A[A.length-1][A.length-1]. You start from A[0][0]. 
You can move in 4 directions - up, down, left and right. 
Find if a path exists to the bottom right of the maze.

For example, a path exists in the following maze:
0111 
0111 
0000 
1110

*******************************************************************************/

#include <stdio.h>
#include<stdbool.h>

#define N  3

enum STATE {
    UNVISITED,
    VISITING,
    PATH_NOT_FOUND,
};

bool oob(int rowLen, int colLen,int i, int j) {
    return i < 0 || i >= rowLen-1 || j < 0 || j >=colLen-1;
}

bool findPath(int path[][N],int rowLen,int colLen,int i , int j, int memo[][N]) {
    if(oob(rowLen,colLen,i,j) || path[i][j] == 1) {
        return false;
    }
    
    if (memo[i][j] == VISITING || memo[i][j] == PATH_NOT_FOUND) {
        return false;
    }
    
    if(i == rowLen -1 && j == colLen -1) {
        return true;
    }
    
    // take array of size 4 for four side

    int buff[4][2] = {i,j+1,i,j-1,i+1,j,i-1,j};
    for(int k=0;k < 4;k++) {
        if(findPath(path,rowLen,colLen,buff[k][0],buff[k][1],memo) ) {
            return true;
        }
    }
    //if path not found this would finally come here after exist of loop
    memo[i][j] = PATH_NOT_FOUND;
    return false;
}

int main()
{
    int rowLen;
    int colLen;
    int path[N][N] = {0,1,1,0,0,1,0,0,0};
    rowLen = sizeof(path)/sizeof(path[0]);
    colLen = (sizeof(path)/sizeof(path[0][0]))/rowLen;
    int memo[N][N] = {};

    if(findPath(path,rowLen,colLen,0,0,memo)) {
        printf("Path EXIT!!");
    } else {
        printf("PATH DOES NOT EXIT!");
    }
    return 0;
}
