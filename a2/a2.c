#include <stdio.h>
#include <stdlib.h> 

/***************************************************************
 * 
 * The following code has all been taken from 
 * https://www.geeksforgeeks.org/graph-and-its-representations/
 * to create adjacency matrices
 * 
 * 
 * start
 **************************************************************/
 // A structure to represent an adjacency list node 
struct AdjListNode 
{ 
    int dest; 
    struct AdjListNode* next; 
}; 
  
// A structure to represent an adjacency list 
struct AdjList 
{ 
    struct AdjListNode *head;  
}; 
  
// A structure to represent a graph. A graph 
// is an array of adjacency lists. 
// Size of array will be V (number of vertices  
// in graph) 
struct Graph 
{ 
    int V; 
    struct AdjList* array; 
}; 
  
// A utility function to create a new adjacency list node 
struct AdjListNode* newAdjListNode(int dest) 
{ 
    struct AdjListNode* newNode = 
     (struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
    newNode->dest = dest; 
    newNode->next = NULL; 
    return newNode; 
} 
  
// A utility function that creates a graph of V vertices 
struct Graph* createGraph(int V) 
{ 
    struct Graph* graph =  
        (struct Graph*) malloc(sizeof(struct Graph)); 
    graph->V = V; 
  
    // Create an array of adjacency lists.  Size of  
    // array will be V 
    graph->array =  
      (struct AdjList*) malloc(V * sizeof(struct AdjList)); 
  
    // Initialize each adjacency list as empty by  
    // making head as NULL 
    int i; 
    for (i = 0; i < V; ++i) 
        graph->array[i].head = NULL; 
  
    return graph; 
} 
  
// Adds an edge to an undirected graph 
void addEdge(struct Graph* graph, int src, int dest) 
{ 
    // Add an edge from src to dest.  A new node is  
    // added to the adjacency list of src.  The node 
    // is added at the begining 
    struct AdjListNode* newNode = newAdjListNode(dest); 
    newNode->next = graph->array[src].head; 
    graph->array[src].head = newNode; 
  
    // Since graph is undirected, add an edge from 
    // dest to src also 
    newNode = newAdjListNode(src); 
    newNode->next = graph->array[dest].head; 
    graph->array[dest].head = newNode; 
} 
  
// A utility function to print the adjacency list  
// representation of graph 
void printGraph(struct Graph* graph) 
{ 
    int v; 
    for (v = 0; v < graph->V; ++v) 
    { 
        struct AdjListNode* pCrawl = graph->array[v].head; 
        printf("\n Adjacency list of vertex %d\n head ", v); 
        while (pCrawl) 
        { 
            printf("-> %d", pCrawl->dest); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    } 
} 
/******************************************
 * end of taken code
 * ***************************************/

int main()
{
    FILE* f = fopen("test.txt", "r");
    int number = 0;
    int counter = 0;
    int n;
    int m;
    int k;
    struct Graph* graph;
    
    while( fscanf(f, "%d ", &number) > 0 )
    {
		int temp;
		if(counter==0)
		{
			n = number;
			//printf("%d\n",n);
			graph = createGraph(n);
		}
		else if(counter==1)
		{
			m = number;
			printf("%d\n",m);
		}
		else if(counter==2)
		{
			k = number;
			printf("%d\n",k);
		}
		else
		{
			if(counter%2 == 1)
			{
				//printf("%d-",number);
				temp = number;
			}
			else
			{
				printf("%d-%d\n",temp,number);
				addEdge(graph, temp, number);
			}
		}
		counter++;
    }
	printGraph(graph); 
    fclose(f);
}
