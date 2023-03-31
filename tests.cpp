#include <stdio.h>
int main()
{
    int y;
    int x=scanf("%d", &y);
    char n=y;

    switch (n > 0)
    {
    case 1:
    {
        printf("%d is positive.", n);
        break;
    }
    case 0:
    {
        switch (n == 0)
        {
        case 1:
        {
            printf("%d is zero.", n);
            break;
        }
        case 0:
        {
            printf("%d is negative.", n);
            break;
        }
        }
    }
    }

    return 0;
}