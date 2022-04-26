#include <stdlib.h>
#include <stdio.h>
#include "Activity.h"

/* input data */
extern unsigned num;
extern ACT activity[];

int main()
{
    sortActivity(activity, num);

    unsigned time = 0;
    int i = 0, currentFinish = activity[0].finish;
    printf("name : %s\n", activity[i].name);
    // for (int j = 0; j < num; j++)
    // {
    //     printf("%s : ", activity[j].name);
    // }
    while (1)
    {
        i++;
        if (i < num)
        {
            if (currentFinish <= activity[i].start)
            {
                currentFinish = activity[i].finish;
                printf("name : %s\n", activity[i].name);
            }
        }
        else
        {
            break;
        }
    }
}

void sortActivity(ACT act[], unsigned n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j >= i + 1; j--)
        {
            if (activity[j - 1].finish > activity[j].finish)
            {
                ACT temp;
                temp = activity[j];
                activity[j] = activity[j - 1];
                activity[j - 1] = temp;
            }
        }
    }
}