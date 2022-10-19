#include <stdio.h>
#include <stdarg.h>

/**
 * sums ints
 *
 * @return sum of all ints
 */
int mySum(int num, ...)
{
    va_list valist;
    int sum = 0;
    int i;

    va_start(valist, num);

    for (i = 0; i < num; i++)
    {
        int a = va_arg(valist, int);
        sum += a;
    }

    va_end(valist);

    return sum;
}

int main()
{
    printf("Sum %d\n", mySum(6, 1, 2, 3, 4, 5, 6));
}
