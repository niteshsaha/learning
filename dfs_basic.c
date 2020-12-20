/******************************************************************************

  Program to print all node of graph by dept first search
  
  node     A B C D
  matrix A 0 1 0 1 
         B 0 0 0 1
         C 0 0 0 0
         D 0 0 1 0 

    unvisited    0
    visiting     1 
    visited      2

*******************************************************************************/
#include <stdio.h>

#define NODE 5
int node[NODE] = {0,0,0,0};
int vertix[NODE][NODE] = {0,1,0,1,0,0,0,1,0,0,0,0,0,0,1,0};

char  print_node(int i) {
    switch (i) {
        case 1:
          return 'A';
        case 2: 
          return 'B';
        case 3:
          return 'C';
        case 4:
          return 'D';
    }
}

void dfs_traverse(int i) {
    if(node[i] != 0) {
        return;
    }
    
    node[i] = 1;
    printf("%c ",print_node(i));
    
    // visiting each vertix of node 
    for (int j=0;j<NODE;j++) {
        if(vertix[i][j] == 1) {
           dfs_traverse(j);
      }
    }
    
    node[i] = 2;
}

int main()
{
    int i;
    //mark all node to unvisited
    for (i=0;i<NODE;i++) {
        node[i] = 0;
    }

    // traverse all node
        for (i=0;i<NODE;i++) {
            dfs_traverse(i);
    }
    return 0;
}
