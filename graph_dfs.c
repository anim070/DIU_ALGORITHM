#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*int VERTEX_COUNT = 0;
int *VISITED;*/
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
/*int *readAdjMatFromFile(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    char *code;
    size_t n = 0;
    int c;
    if (file == NULL)
        return NULL; //could not open file
    fseek(file, 0, SEEK_END);
    long f_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    code = malloc(f_size);
    int *ADJ;
    c = fgetc(file);
    do
    {
        char temp = (char)c;

        if (temp == '\n' || temp == '\r')
        {
            code[n++] = '*';
        }
        else
        {
            code[n++] = temp;
        }
    } while ((c = fgetc(file)) != EOF);

    code[n] = '\0';
    printf("Len:%d\n", n);
    int i = 0;
    while (code[i] != '\0')
    {
        if (i == 0)
        {
            char c[11]; //Assumed digit length not cross 10 (Potential bug)
            int j = 0;
            while (code[i] != '*')
            {
                c[j++] = code[i++];
            }
            c[j] = '\0';
            VERTEX_COUNT = atoi(c);
            printf("Ver:%d\n", VERTEX_COUNT);
            ADJ = malloc(sizeof(int) * VERTEX_COUNT * VERTEX_COUNT);
            memset(ADJ, 0, sizeof(int) * VERTEX_COUNT * VERTEX_COUNT);
        }

        for (int k = 0; k < VERTEX_COUNT; k++)
        {
            int j = 0;
            while (code[i] != '*')
            {
                if (code[i] == '1')
                {
                    printf("C %c ",code[i]);
                    *(ADJ + k * VERTEX_COUNT + j) = 1;
                    printf("A %d ",*(ADJ + k * VERTEX_COUNT + j));
                    j++;
                    i++;
                }
                else if (code[i] == '0')
                {
                    printf("C %c ",code[i]);
                    *(ADJ + k * VERTEX_COUNT + j) = 0;
                    printf("A %d ",*(ADJ + k * VERTEX_COUNT + j));
                    j++;
                    i++;
                }
                else
                {
                    i++;
                    continue;
                }
            }
        }
        i++;
    }
    return ADJ;
}*/
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
    char fileName[40];
    /*
    int *adjMat;
    printf("Enter Adjacency Matrix Name : ");
    scanf("%s", fileName);
    adjMat = readAdjMatFromFile(fileName);
    printAdjacencyMatrix(adjMat, VERTEX_COUNT);*/
    printf("\nEnter Number of Vertex : ");
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