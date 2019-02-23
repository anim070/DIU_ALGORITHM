#include<stdio.h>
#include<string.h>
#define STR_LEN 100
void LCSeqLen(){

}
void main(){
    char X[STR_LEN],Y[STR_LEN];
    size_t m,n;
    printf("Input String 1:");
    scanf("%[^\n]%*c", X);
    printf("Input String 2:");
    scanf("%[^\n]%*c", Y);
    m = strlen(X);
    n = strlen(Y);
    printf("%s, Length %ld\n%s, Length %ld\n",X,m,Y,n);
}