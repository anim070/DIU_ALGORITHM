#include <stdio.h>
#include <string.h>
int profit[50][50];
int getMax(int x, int y)
{
    return (x > y) ? x : y;
}
int knapsack(int maxCapacity, int *weight, int *price, int itemCount)
{

    for (int i = 0; i <= itemCount; i++)
    {
        profit[i][0] = 0;
    }
    for (int w = 0; w <= maxCapacity; w++)
    {
        profit[0][w] = 0;
    }
    for (int item = 1; item <= itemCount; item++)
    {
        for (int capacity = 1; capacity <= maxCapacity; capacity++)
        {
            if (weight[item - 1] <= capacity)
            {
                profit[item][capacity] = getMax(profit[item - 1][capacity], (profit[item - 1][capacity - weight[item - 1]] + price[item - 1]));
            }
            else
            {
                profit[item][capacity] = profit[item - 1][capacity];
            }
        }
    }
    return profit[itemCount][maxCapacity];
}
void printProfitTable(int *weight,int *price,int itemCount, int maxCapacity)
{
    for (int item = -1; item <= itemCount; item++)
    {
        for (int capacity = -1; capacity <= maxCapacity; capacity++)
        {
            if (item == -1 || capacity == -1)
            {
                if(item == -1){
                    if(capacity == -1){
                        printf(" P  W  I");
                    }else if(capacity == 0){
                        printf(" %2d ",0);
                    }else{
                        printf(" %2d ",capacity);
                    }
                }else{
                    if(capacity == -1 && item == 0){
                        printf(" 0  0  0");
                    }else{
                        printf("%2d %2d %2d",price[item-1],weight[item-1],item);
                    }
                }
            }else{
                printf(" %2d ",profit[item][capacity]);
            }
            
        }
        printf("\n");
    }
    printf("\n");
}
void main()
{
    printf("Scenario 1\nWeight = {6,3,5,7,10}\nPrice = {30,10,5,3,70}\nKnapsack Capacity = 7");
    int weight[] = {6, 3, 5, 7, 10};
    int price[] = {30, 10, 5, 3, 70};
    int knapsackCapacity = 7;
    int itemCount = sizeof(weight) / sizeof(weight[0]);
    memset(profit, 0, sizeof(int) * 50 * 50);
    printf("\nMax Profit - %d\n", knapsack(knapsackCapacity, weight, price, itemCount));
    printProfitTable(weight, price,itemCount,knapsackCapacity);
    memset(profit, 0, sizeof(int) * 50 * 50);
    printf("Scenario 2\nWeight = {2, 3, 7, 4}\nPrice = {1, 3, 5, 5}\nKnapsack Capacity = 7");
    int weight1[] = {2, 3, 7, 4};
    int price1[] = {1, 3, 5, 5};
    int knapsackCapacity1 = 7;
    int itemCount1 = sizeof(weight1) / sizeof(weight1[0]);
    printf("\nMax Profit - %d\n", knapsack(knapsackCapacity1, weight1, price1, itemCount1));
    printProfitTable(weight1, price1,itemCount1,knapsackCapacity1);
}