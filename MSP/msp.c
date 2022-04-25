#include <stdlib.h>
#include <stdio.h>
#include "MSP.h"

/* input data */
extern unsigned num;
extern int data[];

int main()
{
    printf("%d\n", maxSubarray(0, num));
}

int maxSubarray(unsigned from, unsigned num)
{
    if (num == 1)
        return data[from];
    if (num == 2)
    {
        int max = data[from];
        if (max < data[from + 1])
            max = data[from + 1];
        if (max < data[from] + data[from + 1])
            max = data[from] + data[from + 1];
        return max;
    }
    if (num >= 3)
    {
        int mid = num / 2;
        int max1 = maxSubarray(from, mid);
        int max2 = maxSubarray(from + mid, num - mid);

        int max3L = 0;
        int maxL = 0;
        for (int k = from + mid; from < k; k--)
        {
            maxL += data[k];
            if (max3L < maxL)
            {
                max3L = maxL;
            }
        }
        int maxR = 0;
        int max3R = 0;
        for (int j = from + mid + 1; j < from + num; j++)
        {
            maxR += data[j];
            if (max3R < max3L)
            {
                max3R = maxR;
            }
        }
        int max3 = max3L + max3R;
        int max = max1;
        if (max < max2)
            max = max2;
        if (max < max3)
            max = max3;
        return max;
    }
}