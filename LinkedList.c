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
    LINKLIST *aLList = (LINKLIST *)malloc(sizeof(LINKLIST));
    if(aLList == NULL)
    return NULL;
    aLList->head = NULL;
    aLList->tail = NULL;
    aLList->nodeCount = 0;
    return aLList;
}

void addLast(NODE *aNode){
    
}