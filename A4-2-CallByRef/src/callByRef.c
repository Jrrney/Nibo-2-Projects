/**
 @file callByRef.c
 @author Jenny Dietrich
 @date 1.0
 @brief call by reference
*/

#include <stdio.h>
#include <stdbool.h>

void swap(int *i1, int *i2)
{
    int s = *i1;
    *i1 = *i2;
    *i2 = s;
}

int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 5;
    swap(&a, &b);

    printf("%d; %d\n", a, b);

    return 0;
}
