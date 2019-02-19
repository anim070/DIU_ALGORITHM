#include<stdio.h>
typedef struct dataMap
{
    char* hashVal;
    long offset;
}DATA;

typedef struct node
{
    DATA aData;
    struct node *next;
    //struct node *prev;
}NODE;

typedef struct linklist{
    NODE *head;
    NODE *tail;
    int nodeCount;
}LINKLIST;

LINKLIST* creatLinkList(){

}

void addLast(NODE *aNode){
    
}