#include <stdlib.h>
#include <stdio.h>
#include "Knapsack.h"

/* test data */
extern unsigned num;
extern OBJ object[];
extern float knapsack;

int main()
{
    for (unsigned i = 0; i < num; i++)
        object[i].performance = object[i].value / object[i].weight;
    sortObject(object, num);
    float result = 0;
    float sum = 0;
    for (int j = 0; j < num; j++)
    {
        if (knapsack == 0)
        {
            printf("result_price : %f", sum);
            return 0;
        }
        if (knapsack < object[j].weight)
        {
            float balance = object[j].weight - knapsack;
            knapsack -= object[j].weight - balance;
            sum += (balance)*object[j].performance;
        }
        else
        {
            knapsack -= object[j].weight;
            sum += object[j].value;
        }
        printf("kanpsack : %f sum : %f\n", knapsack, sum);
    }
    printf("result_price : %f", sum);
}

void sortObject(OBJ obj[], unsigned n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j >= i + 1; j--)
        {
            if (object[j].performance > object[j - 1].performance)
            {
                OBJ temp;
                temp = object[j - 1];
                object[j - 1] = object[j];
                object[j] = temp;
                // temp.name = object[j - 1].name;
                // temp.value = object[j - 1].value;
                // temp.weight = object[j - 1].weight;
                // temp.performance = object[j - 1].performance;
                // object[j - 1].name = object[j].name;
                // object[j - 1].value = object[j].value;
                // object[j - 1].weight = object[j].weight;
                // object[j - 1].performance = object[j].performance;
                // object[j].name = temp.name;
                // object[j].value = temp.value;
                // object[j].weight = temp.weight;
                // object[j].performance = temp.performance;
            }
        }
    }
}