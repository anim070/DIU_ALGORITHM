#include <stdio.h>
typedef struct
{
    int A[4][4];
} GRAPH;

void DFS(GRAPH *a, int *Visited, int vertexCount, int i);
int main(void)
{
    printf("DFS on Undirected Graph\n");
    //Undirected Graph
    GRAPH A = {
        {
            {0, 1, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}
        }
    };
    int VA[4] = {0, 0, 0, 0};
    DFS(&A, VA, 4, 3);
    printf("\nDFS on Directed Graph\n");
    //Directed Graph
    GRAPH B = {
        {
            {0, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}
        }
    };
    int VB[4] = {0, 0, 0, 0};
    DFS(&B, VB, 4, 0);
}
void DFS(GRAPH *a, int *Visited, int vertexCount, int i)
{
    int j;
    printf(" %d ", i);
    Visited[i] = 1;
    for (j = 0; j < vertexCount; j++)
    {
        if (Visited[j] == 0 && a->A[i][j] == 1)
        {
            DFS(a, Visited, vertexCount, j);
        }
    }
}