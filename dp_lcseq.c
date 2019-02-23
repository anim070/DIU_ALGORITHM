#include <stdio.h>
#include <string.h>
#define STR_LEN 100
void LCSeqLen(char *X, char *Y, size_t m, size_t n, int (*ptr_c)[n],int (*ptr_b)[n])
{
    //printf("%s, Length %ld\n%s, Length %ld\n",X,m,Y,n);
    for (size_t i = 1; i <= m; i++)
    {
        for (size_t j = 1; j <= n; j++)
        {
            printf("C[%ld][%ld] = %d ", i, j, ptr_c[i][j]);
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
    int c[m + 1][n + 1],b[m+1][n+1];
    memset(c, 0, sizeof(int) * (m+1) * (n+1));
    memset(b, 0, sizeof(int) * (m+1) * (n+1));
    LCSeqLen(X, Y, m, n, c, b);
}