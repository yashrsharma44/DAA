
#include <stdio.h> 
#include <limits.h> 
#include<stdbool.h> 

#define V 5 
  
// A utility function to find the vertex with  
// minimum key value, from the set of vertices  
// not yet included in MST 
int minKey(int key[], bool mstSet[]) 
{ 
// Initialize min value 
int min = INT_MAX, min_index; 
int v;
for (v = 0; v < V; v++) 
    if (mstSet[v] == false && key[v] < min) 
        min = key[v], min_index = v; 
  
return min_index; 
} 
  
// A utility function to print the  
// constructed MST stored in parent[] 
int printMST(int parent[], int n, int graph[V][V]) 
{ 
printf("Edge \tWeight\n"); 
int i;
for (i = 1; i < V; i++) 
    printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]); 
} 
  
// Function to construct and print MST for  
// a graph represented using adjacency  
// matrix representation 
void primMST(int graph[V][V]) 
{ 
    // Array to store constructed MST 
    int parent[V];  
    // Key values used to pick minimum weight edge in cut 
    int key[V];  
    // To represent set of vertices not yet included in MST 
    bool mstSet[V];  
    int i;
    // Initialize all keys as INFINITE 
    for (i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
  
    // Always include first 1st vertex in MST. 
    // Make key 0 so that this vertex is picked as first vertex. 
    key[0] = 0;      
    parent[0] = -1; // First node is always root of MST  
    int count;
    // The MST will have V vertices 
    for ( count = 0; count < V-1; count++) 
    { 
        // Pick the minimum key vertex from the  
        // set of vertices not yet included in MST 
        int u = minKey(key, mstSet); 
  
        // Add the picked vertex to the MST Set 
        mstSet[u] = true; 
  
        // Update key value and parent index of  
        // the adjacent vertices of the picked vertex.  
        // Consider only those vertices which are not  
        // yet included in MST 
        int v;
        for (v = 0; v < V; v++) 
  
        // graph[u][v] is non zero only for adjacent vertices of m 
        // mstSet[v] is false for vertices not yet included in MST 
        // Update the key only if graph[u][v] is smaller than key[v] 
        if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
            parent[v] = u, key[v] = graph[u][v]; 
    } 
  
    // print the constructed MST 
    printMST(parent, V, graph); 
} 
  
  
// driver program to test above function 
int main() 
{ 
printf("Enter the values of the adjacency matrix for 5x5\n");
       int G[5][5];
       
       printf("Enter Values\n");
       int i,j;
       
       for(i=0;i<5;i++)
       {
            printf("Enter the weighted-values of %dth Node\n",i);
            for(j=0;j<5;j++)
            {
                scanf("%d",&G[i][j]);
            }
            printf("\n");
       }
       
       printf("The MST Graph connections are\n");
       primMST(G);
    return 0; 
} 

