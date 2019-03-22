#include <stdio.h>
int A[4][4];
int V[4];
int n = 4;

void DFS(int i);
int main(void)
{
    /*
    {{0, 1, 0, 0},
         {0, 0, 1, 1},
         {0, 0, 0, 1},
         {0, 0, 0, 0}}
    */
    printf("DFS on Directed Graph\n");
    //Undirected Graph
    A[4][4] = ((0, 1, 0, 0),
               (0, 0, 1, 1),
               (0, 0, 0, 1),
               (0, 0, 0, 0));
    V[4] = (0, 0, 0, 0);
    DFS(0);
}
void DFS(int i)
{
    int j;
    printf(" %d ", i);
    V[i] = 1;
    for (j = 0; j < n; j++)
    {
        if (V[j] == 0 && A[i][j] == 1)
        {
            DFS(j);
        }
    }
}