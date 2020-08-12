#include <stdio.h>
#include <stdlib.h>

/* define graph data structure for adjacemcy list node */
typedef struct adjlistnode{
    int dest;
    struct adjlistnode *next;
} adjlistnode;

/* define graph data structure for adjacemcy list */
typedef struct {
    adjlistnode *heap;
} adjlist;

/* define graph data structure */
typedef struct {
    int V; /* size of array */
    adjlist *array;
} Graph;

/* create the new node */
adjlistnode *newadjlistnode(int dest)
{
    adjlistnode *newnode;
    if ( NULL == (newnode = (adjlistnode *)malloc(sizeof(adjlistnode))))
        return NULL;
    newnode->dest = dest;
    newnode->next = NULL;
    /* RETURN NEW NODE */
    return newnode;
}

/* create the new graph */
Graph *create_graph(int V)
{
    Graph *graph;
    adjlist *array;

    /* create the graph */
    if ( NULL == (graph = (Graph *)malloc(sizeof(Graph))))
        return NULL;
    graph->V = V;

    /* create the new array of adjacency lists, the size is V */
    if ( NULL == (array = (adjlist *)malloc(sizeof(adjlist) * V)))
        return NULL;
    graph->array = array;

    /* initalization the echo list is empty */
    for (int i = 0; i < V; i++)
        graph->array[i].heap = NULL;
    return graph;
}

/* add the edge to undirected graph */
void addedge(Graph *graph, int src, int dest)
{
    /* add the edge from src to dest */
    adjlistnode *newnode;
    newnode = newadjlistnode(dest);
    newnode->next = graph->array[src].heap;
    graph->array[src].heap = newnode;
}

/* print the graph*/
void printgraph(Graph *graph)
{
    adjlistnode *curindex;
    for (int  i = 0; i < graph->V; i++)
    {
        curindex = graph->array[i].heap;
        printf("The adjacency list of vertex %d\n heap", i);
        /* printf the each item */
        while (curindex)
        {
            printf("-> %d", curindex->dest);
            curindex = curindex->next;
        }
        printf("\n");
    }
}

/* test function */
int main(int argc, char *argv[])
{
    int V = 5;
    Graph *graph;
    graph = create_graph(V);
    addedge(graph, 0 , 1);
    addedge(graph, 0 , 4);
    addedge(graph, 1 , 2);
    addedge(graph, 1 , 3);
    addedge(graph, 1 , 4);
    addedge(graph, 2 , 3);
    addedge(graph, 3 , 4);

    /* printf the graph items */
    printgraph(graph);

    /* free memory */
    free(graph);
    return 0;
}

/* result */
/*
The adjacency list of vertex 0
 heap-> 4-> 1
The adjacency list of vertex 1
 heap-> 4-> 3-> 2
The adjacency list of vertex 2
 heap-> 3
The adjacency list of vertex 3
 heap-> 4
The adjacency list of vertex 4
 heap
 */