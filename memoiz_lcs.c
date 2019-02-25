#include <stdio.h>
#include <string.h>
#define STR_LEN 100
/*
* TEST CASE
* X = AAACCGTGAGTTATTCGTTCTAGAA
* Y = CACCCCTAAGGTACCTTTGGTTC
* LCS LENGTH 13
*/
/*Memoization Table*/
int static cache[STR_LEN][STR_LEN];
/* returns maximum of x and y*/
int getMax(int x,int y){
    return (x > y) ? x : y;
}
/* returns the longest common subsequence length*/
int LCSLen(char *X,char *Y,int m,int n){
    //termenating condition for recursion
    if(m == 0 || n == 0){
        return 0;
    }
    if(cache[m][n] != -1){
        return cache[m][n];
    }
    if(X[m-1] == Y[n-1]){
        cache[m][n] = 1 + LCSLen(X,Y,m-1,n-1);
    }else{
        cache[m][n] = getMax(LCSLen(X,Y,m,n-1),LCSLen(X,Y,m-1,n));
    }
    return cache[m][n];
}

void main()
{
    char X[STR_LEN], Y[STR_LEN];
    size_t m, n;
    printf("Input String X:");
    scanf("%[^\n]%*c", X);
    printf("Input String Y:");
    scanf("%[^\n]%*c", Y);
    m = strlen(X);
    n = strlen(Y);
    memset(cache, -1, sizeof(int) * (STR_LEN) * (STR_LEN));
    printf("\nLCS Length - %d\n",LCSLen(X,Y,m,n));
}