#include <stdio.h>
#include <string.h>
#define STR_LEN 100
/* returns the longest common subsequence length*/
int LCSLen(char *X,char *Y,int m,int n){
    //termenating condition for recursion
    if(m == 0 || n == 0){
        return 0;
    }
    if(X[m-1] == Y[n-1]){
        return 1 + LCSLen(X,Y,m-1,n-1);
    }else{
        return getMax(LCSLen(X,Y,m,n-1),LCSLen(X,Y,m-1,n));
    }

}
int getMax(int x,int y){
    return (x > y) ? x : y;
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
    printf("\nLCS Length - %d\n",LCSLen(X,Y,m,n));
}