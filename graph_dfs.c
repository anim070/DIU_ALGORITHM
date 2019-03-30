#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int VERTEX_COUNT = 0;
int *VISITED;
void printAdjacencyMatrix(int *adjMatPtr, int vertexCount);
void printAdjacencyList(int *adjMatPtr, int vertexCount);
void DFS(int *adjMatPtr, int vertexCount, int *visitedArrPtr, int stratingVertex);
int *getAdjMatFromFile(char *fileName);

void main(void)
{
    int vc;
    int ei;
    int flag = 1;
    char fileName[40];

    int *adjMat;
    printf("Enter Adjacency Matrix FileName : ");
    scanf("%s", fileName);
    adjMat = getAdjMatFromFile(fileName);
    if (adjMat != NULL)
    {
        printf("Number of Vertices : %d\n", VERTEX_COUNT);
        printAdjacencyMatrix(adjMat, VERTEX_COUNT);
        printf("Adjacency List\n");
        printAdjacencyList(adjMat,VERTEX_COUNT);
        int VISITED[VERTEX_COUNT];
        memset(VISITED, 0, sizeof(int) * VERTEX_COUNT);
        int stratingVertex = 0;
        printf("\nEnter Starting Vertex (Between 0 to %d):", VERTEX_COUNT - 1);
        scanf("%d", &stratingVertex);
        printf("\nDFS path of Graph from %d\n", stratingVertex);
        DFS(adjMat, VERTEX_COUNT, VISITED, stratingVertex);
    }
    else
    {
        printf("File Error\n");
    }
}
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
int *getAdjMatFromFile(char *fileName)
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
    static int *ADJ;
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
    int inner = 0;
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
            inner = VERTEX_COUNT;
            ADJ = (int *)malloc(sizeof(int) * VERTEX_COUNT * VERTEX_COUNT);
            memset(ADJ, 0, sizeof(int) * VERTEX_COUNT * VERTEX_COUNT);
        }
        else
        {
            int j = 0;
            int k = VERTEX_COUNT - inner;
            while (code[i] != '*')
            {
                if (code[i] == '1')
                {
                    *(ADJ + k * VERTEX_COUNT + j) = 1;
                    j++;
                    i++;
                }
                else if (code[i] == '0')
                {
                    *(ADJ + k * VERTEX_COUNT + j) = 0;
                    j++;
                    i++;
                }
                else
                {
                    i++;
                    continue;
                }
            }
            //}
            if (i > 1)
                inner--;
            i++;
        }
    }
    return ADJ;
}
void printAdjacencyMatrix(int *adjMatPtr, int vertexCount)
{
    printf("Adjacency Matrix\n");
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
void printAdjacencyList(int *adjMatPtr, int vertexCount)
{
    for (short i = 0; i < vertexCount; i++)
    {
        printf("%d-->", i);
        for (short j = 0; j < vertexCount; j++)
        {
            if (*(adjMatPtr + i * vertexCount + j) == 1)
            {
                printf("| %d |", j);
                if (j < vertexCount - 1)
                    printf("-->");
            }
        }
        printf("\n");
    }
    printf("\n");
}