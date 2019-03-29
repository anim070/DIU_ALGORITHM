#include <stdio.h>
#include <string.h>
void DFS(int *adjMatPtr, int vertexCount, int *visitedArrPtr, int stratingVertex)
{
    int j;
    printf(" %d ", stratingVertex);
    visitedArrPtr[stratingVertex] = 1;
    for (j = 0; j < vertexCount; j++)
    {
        if (visitedArrPtr[j] == 0 && *(adjMatPtr + stratingVertex * vertexCount + j) == 1)
        {
            DFS(adjMatPtr, vertexCount, visitedArrPtr, j);
        }
    }
}
void printAdjacencyMatrix(int *adjMatPtr, int vertexCount)
{
    for (short i = 0; i < vertexCount; i++)
    {
        for (short j = 0; j < vertexCount; j++)
        {
            printf(" %d ", *(adjMatPtr + i * vertexCount + j));
        }
        printf("\n");
    }
    printf("\n");
}
void main(void)
{
    int vc;
    int ei;
    int flag = 1;
    printf("Enter Number of Vertex : ");
    scanf("%d", &vc);
    int VISITED[vc];
    memset(VISITED, 0, sizeof(int) * vc);
    int ADJ[vc][vc];
    memset(ADJ, 0, sizeof(int) * vc * vc);
    printf("\nEnter Edge Infos for the Adjacency Matrix of the Graph\n");
    for (short i = 0; i < vc; i++)
    {
        for (short j = 0; j < vc; j++)
        {
            printf("Edge between %d %d (enter 1 if edge exists else enter 0)", i, j);
            scanf("%d", &ei);
            if (ei == 1)
            {
                ADJ[i][j] = ei;
            }
            else if (ei == 0)
            {
            }
            else
            {
                printf("\nInvalid Info");
                flag = 0;
                break;
            }
        }
        if (!flag)
            break;
    }
    printAdjacencyMatrix(&ADJ[0][0], vc);
    int stratingVertex = 0;
    printf("\nEnter Starting Vertex (Between 0 to %d):", vc - 1);
    scanf("%d", &stratingVertex);
    printf("\nDFS path of Graph from %d\n", stratingVertex);
    DFS(&ADJ[0][0], vc, VISITED, stratingVertex);
}