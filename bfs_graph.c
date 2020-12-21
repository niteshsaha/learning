/******************************************************************************
  Program to print all node of graph by breath first search
  
  node     1 2 3 4 5 6
  matrix 1 0 1 1 0 0 0
         2 0 0 0 1 0 0
         3 0 0 0 1 1 0
         4 0 0 0 0 0 1
         5 0 0 0 0 0 1
         6 0 0 0 0 0 0
    unvisited    0
    visiting     1 
    visited      2
*******************************************************************************/
#include <stdio.h>

#define NODE 6
int node[NODE] = {0,0,0,0,0,0};
int Queue[NODE] = {-1,-1,-1,-1,-1,-1};
int vertix[NODE][NODE] = {0,1,1,0,0,0,
                          0,0,0,1,0,0,
                          0,0,0,1,1,0,
                          0,0,0,0,0,1,
                          0,0,0,0,0,1,
                          0,0,0,0,0,0};

void bfs_traverse(int node_val, int queue_start, int queue_current) {
    // add to queue
    Queue[queue_current] = node_val;
    queue_current++;
    node[node_val] = 1;
    while(Queue[queue_start] != -1 && queue_start < NODE) {
        
        // pop out from queue
        int temp = Queue[queue_start];
        Queue[queue_start] = -1;
        queue_start++;
        
        printf("%d ", temp+1);
        
        // visiting each neigh of node 
        for (int j=0;j<NODE;j++) {
          // search the neigh and check that node is unvisited
          if(vertix[temp][j] == 1 && node[j] == 0) {
              // add to queue
              Queue[queue_current] = j;
              queue_current++;
              node[j] = 1;
          }
           
          node[temp] = 2;
        }
    }
}

int main()
{
    int i;
    //mark all node to unvisited
    for (i=0;i<NODE;i++) {
        node[i] = 0;
    }

    bfs_traverse(0,0,0);
    return 0;
}
