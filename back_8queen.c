#include <stdio.h>
#include <stdlib.h>
int Board[100][100];
int count = 0;
void printBoard(int n)
{
    count++;
    printf("Solution : %d\n",count);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (Board[i][j] == 1)
            {
                printf(" Q ");
            }
            else
            {
                printf(" # ");
            }
        }
        printf("\n");
    }
    printf("\n");
    
}
void putQueen(int i, int n)
{
    for (int j = 1; j <= n; j++)
    {
        int cQ = 0; //Count of contesting Queens
        for (int k = 1; k <= (i - 1); k++)
        {
            if (j - (i - k) > 0)
            {
                cQ = cQ + Board[k][j - (i - k)];
            }
            cQ = cQ + Board[k][j];
            if (j + (i - k) < (n + 1))
            {
                cQ = cQ + Board[k][j + (i - k)];
            }
        }
        if (cQ == 0)
        {
            Board[i][j] = 1;
            if (i == n)
            {
                printBoard(n);
            }
            else
            {
                putQueen(i + 1, n);
            }
            Board[i][j] = 0;
        }
    }
}
void nQueen(int n)
{
    int initCol = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            Board[i][j] = 0;
        }
    }
    for (int j = 1; j <= n; j++)
    {
        Board[initCol][j] = 1;
        putQueen(initCol + 1, n);
        Board[initCol][j] = 0;
    }
}

void main(void)
{
    int n;
    printf("Enter Number of Row/Column in Board : ");
    scanf("%d", &n);
    nQueen(n);
    printf("Total Soultion found for %d-Queen : %d\n",n,count);
}