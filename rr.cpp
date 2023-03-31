#include <stdio.h>

void erase(int **arr, int index, int n)
{
    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int limit, i, e, index;
    printf("enter limit:");
    scanf("%d", &limit);
    int a[limit];
    // taking elements
    for (i = 0; i < limit; i++)
    {
        scanf("%d", &e);
        a[i] = e;
    }
    // printing elements
    printf("\n array:");
    for (i = 0; i < limit; i++)
    {
        printf(" %d ", a[i]);
    }
    // erase elements
    printf("\n enter index:");
    scanf("%d", &index);
    if (index <= limit)
    {
        erase((int **)&a, index, limit);
    }
    // printing new array
    printf("\n new array:");
    for (i = 0; i < limit; i++)
    {
        printf(" %d ", a[i]);
    }

    return 0;
}