#include <stdio.h>

int main()
{
    int limit, i, u, z;
    int main[limit];
    int sort[limit];
    int x = scanf("%d", &limit);
    // input
    for (i = 0; i < limit; i++)
    {
        x = scanf("%d", &main[i]);
    }
    // output
    for (i = 0; i < limit; i++)
    {
        printf(" %d ", main[i]);
    }
    // sorting
    for (i = 0; i < limit; i++)
    {
        z = limit;
        for (u = 0; u < limit; u++)
        {
            if (main[i] <= main[u])
            {
                z = z - 1;
            }
        }
        // same input sorting
        if (sort[z] == main[i])
        {
            for (int x = z; x < limit; x++)
            {
                if (sort[z] == main[i])
                {
                    z += 1;
                }
            }
        }

        sort[z] = main[i];
    }
    // output sorting
    printf("\n\n");
    for (i = 0; i < limit; i++)
    {
        printf(" %d ", sort[i]);
    }

    return 0;
}