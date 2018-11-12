// Prims Algorithm using a Min Heap

#include <stdio.h>
#include <stdlib.h>

// A structure defined to represent an edge
typedef struct edge {
    // from ---> to with weight d
    int from;
    int to;
    int d;
} edge;


// Heap data structure
typedef struct heap {
	edge* arr;
	int size;
} heap;

// Linked List data structure
typedef struct node {
    edge e;
    struct node* next;
} node;

void exch(edge* a, int i, int j) {
    edge t = a[i];
	a[i] = a[j];
	a[j] = t;
}

// It takes an element and moves it down till heap property is restored in its subtree.
void sink(heap* h, int i) {
	edge* a = h->arr;
	while (2*i <= h->size) {
		int j = 2*i;
		if (j < h->size && a[j].d > a[j+1].d)
			j++;
		if (a[j].d > a[i].d)
			break;
		exch(a, i, j);
		i = j;
	}
}

// It takes an element and moves it up till it moves to its right place 
// (i.e till no element is found greater than itself in its path to root).
void swim(heap* h, int i) {
	edge* a = h->arr;
	while (i > 1) {
		if (a[i].d > a[i/2].d)
			break;
		exch(a, i, i/2);
		i = i/2;
	}
}

// Deletes the minimum element of the heap.	
edge delMin(heap* h) {
	exch(h->arr, 1, h->size);
	edge val = (h->arr)[h->size--];
	sink(h, 1);
	return val;
}

// Inserts an element into the heap.
void insert(heap* h, edge val) {
	(h->arr)[++h->size] = val;
	swim(h, h->size);
}


// Linked List Helper functions

// Inserts a node in a linked list
node* insertNode(node* x, edge e) {
    if (x == NULL) {
        node* newNode = (node*) malloc(sizeof(node));
        newNode->e = e;
        newNode->next = NULL;
        return newNode; 
    }
    
    x->next = insertNode(x->next, e);
    return x;
}

int main() {    
    int i;
    
    // No. of vertices in a graph
    int V;
    printf("Enter no. of vertices : ");
    scanf("%d", &V);
    printf("\n");
     
    // The Graph is represented using an Array of LinkedLists (Adjacency List Representation)
    node** graph = (node**) malloc(sizeof(node*) * V);
    for (i = 0; i < V; i++) {
        graph[i] = NULL;
    }
    
    // No. of Edges
    int E;
    printf("Enter no. of edges : ");
    scanf("%d", &E);
    printf("\n");
    
    // The graph generated will be an undirected graph
    // For each pair of vertex (v, w) two edges will be constructed (from v to w and vice versa)
    printf("Enter Edges (from, to and weight all space separated): \n");
    for (i = 0; i < E; i++) {
        int v, w, d;
        scanf("%d %d %d", &v, &w, &d);
        edge e1;
        edge e2;
        e1.from = v;
        e1.to = w;
        e1.d = d;
        e2.from = w;
        e2.to = v;
        e2.d = d;
        // insert the respective edges into the graph
        graph[v] = insertNode(graph[v], e1);
        graph[w] = insertNode(graph[w], e2); 
    }
    
    // An array to store edges of a Minimum Spanning Tree
    edge* mstEdges = (edge*) malloc(sizeof(edge) * (V - 1));
    
    // Creating a priority queue for storing V * E Edges
    heap* pq = (heap*) malloc(sizeof(heap));
    pq->size = 0;
    pq->arr = (edge*) malloc(sizeof(int) * V * E);
    
    // An array to track the vertices which have been visited
    int* marked = (int*) malloc(sizeof(int) * V);
    
    int edgeCount = 0;
    
    // Start with vertex 0, and mark it
    marked[0] = 1;
    // Add All edges of vertex 0 to the heap
    node* temp = graph[0];
    while (temp != NULL) {
        insert(pq, temp->e);
        temp = temp->next;
    } 
    
    // Find all V - 1 Edges of an MST
    while (edgeCount < V-1) {
        // Find the vertex with min weight
        edge minEdge = delMin(pq);
        int w = minEdge.to;
        
        // If the edge had already been marked, find another one
        if (marked[w])
            continue;
        
        marked[w] = 1;
        mstEdges[edgeCount++] = minEdge;
            
        // Add all edges of the next vertex to the heap
        temp = graph[w];
        while (temp != NULL) {
            insert(pq, temp->e);
            temp = temp->next;
        }
    }
    
    printf("MST Edges : \n");
    for (i = 0; i < V-1; i++) {
        printf("%d --- %d, weight: %d \n", mstEdges[i].from, mstEdges[i].to, mstEdges[i].d);
    }
    printf("\n");
      
}
