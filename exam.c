#include <stdio.h>
#define S 1000
#define maxi(x, y) x > y ? x : y
int main()
{
    int x1 = 25;
    int x2 = 15;
    int y1 = 64;
    int y2 = 13;
    int z=(x1&y1);
    printf("%d\n",z);
    printf("1: %d %d\n", x1, x2);
    printf("2: %d %d\n", x1 & x2, !x2);
    if (y1&x2 > x1|y2)
        printf("3: %d %d\n", y1, y2 = maxi(y1++, x1 & y1));
    else
        printf("4: %d %d\n", y2, y1 = maxi(y2++, x2 & y2));

    printf("5: %d %d %d %d\n", x1, x2, y1, y2);
    for (int i = x1; i < x2; i += y1)
    {

        y2 = x1 & x2 | y1;
    }

    printf("6: %d %d %d %d\n", x1, x2, y1, y2);

    return 0;
}