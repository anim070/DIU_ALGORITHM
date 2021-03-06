#include <stdio.h>
#include <string.h>
int knapsack(int maxCapacity,int *weight,int *price,int itemCount){
    /* Termaneting condition for recursion, either no item left or knapsack is full */
    if(itemCount <= 0 || maxCapacity <= 0){
        return 0;
    }
    if(weight[itemCount-1] > maxCapacity){
        return knapsack(maxCapacity,weight,price,itemCount-1);
    }
    // nth item included
    int x = price[itemCount-1] + knapsack(maxCapacity-weight[itemCount-1],weight,price,itemCount-1);
    // nth item not included
    int y = knapsack(maxCapacity,weight,price,itemCount-1);
    return (x > y) ? x : y;
}
void main(){
    int weight[] = {2,3,7,4};
    int price[] = {1,3,5,5};
    int knapsackCapacity = 7;
    int itemCount = sizeof(weight)/sizeof(weight[0]);
    printf("Max Profit - %d\n",knapsack(knapsackCapacity,weight,price,itemCount));
}