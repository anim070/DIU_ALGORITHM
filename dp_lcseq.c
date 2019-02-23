#include <stdio.h>
#include <string.h>
#define STR_LEN 100
#define UP 100 //UP ARROW
#define LF 200 //LEFT ARROW
#define DI 300 //DIAGONAL ARROW
int static c[STR_LEN + 1][STR_LEN + 1];
int static b[STR_LEN + 1][STR_LEN + 1];
int LCSeqLen(char X[], char Y[], size_t m, size_t n)
{
    //printf("%s, Length %ld\n%s, Length %ld\n",X,m,Y,n);
    /*for (int iter = m; iter >= 1; iter--)
    {
        X[iter] = X[iter - 1];
    }
    for (int iter = n; iter >= 1; iter--)
    {
        Y[iter] = Y[iter - 1];
    }*/
    for (int a = 0; a <= m; a++)
    {
        c[a][0] = 0;
    }
    for (int a = 0; a <= n; a++)
    {
        c[0][a] = 0;
    }
    for (size_t i = 1; i <= m; i++)
    {
        for (size_t j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = DI;
                printf("%c %c, %ld %ld\n", X[i - 1], Y[j - 1], i, j);
            }
            else
            {
                if (c[i - 1][j] >= c[i][j - 1])
                {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = UP;
                }
                else
                {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = LF;
                }
            }
        }
    }
    return c[m][n];
}
void PrintLCSeq(char X[], size_t i, size_t j)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    if (b[i][j] == DI)
    {
        PrintLCSeq(X, i - 1, j - 1);
        printf("%c", X[i-1]);
    }
    else if (b[i][j] == UP)
    {
        PrintLCSeq(X, i - 1, j);
    }
    else
    {
        PrintLCSeq(X, i, j - 1);
    }
}
void PrintLCSeqTable(size_t m, size_t n)
{
    for (size_t i = 0; i <= m; i++)
    {
        for (size_t j = 0; j <= n; j++)
        {
            if (b[i][j] == UP)
            {
                printf(" U ");
            }
            else if (b[i][j] == LF)
            {
                /* code */
                printf(" L ");
            }
            else if (b[i][j] == DI)
            {
                /* code */
                printf(" D ");
            }
            else
            {
                /* code */
                printf(" %d ", b[i][j]);
            }
        }
        printf("\n");
    }
}
void PrintLCSeqCostTable(size_t m, size_t n)
{
    for (size_t i = 0; i <= m; i++)
    {
        for (size_t j = 0; j <= n; j++)
        {
            if (c[i][j] == UP)
            {
                printf(" U ");
            }
            else if (c[i][j] == LF)
            {
                /* code */
                printf(" L ");
            }
            else if (c[i][j] == DI)
            {
                /* code */
                printf(" D ");
            }
            else
            {
                /* code */
                printf(" %d ", c[i][j]);
            }
        }
        printf("\n");
    }
}
void main()
{
    char X[STR_LEN], Y[STR_LEN];
    size_t m, n;
    printf("Input String 1:");
    scanf("%[^\n]%*c", X);
    printf("Input String 2:");
    scanf("%[^\n]%*c", Y);
    m = strlen(X);
    n = strlen(Y);
    //int c[m+1][n+1], b[m+1][n+1];
    //memset(c, 0, sizeof(int) * (m+1) * (n+1));
    //memset(b, 0, sizeof(int) * (m+1) * (n+1));
    //PrintLCSeqTable(m, n);
    printf("\nLCS Len - %d\n", LCSeqLen(X, Y, m, n));
    printf("LCS Seq - ");
    PrintLCSeq(X, m, n);
    printf("\n");
    //PrintLCSeqTable(m, n);
    //printf("\n");
    //PrintLCSeqCostTable(m, n);
}