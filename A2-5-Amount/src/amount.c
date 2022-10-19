/**
 @file amount.c
 @author Jenny Dietrich
 @date 1.0
 @brief amount of 10 & -3
*/

#include <stdio.h>

#define AMOUNT(x) x < 0 ? -x : x

int main(int argc, char const *argv[])
{
    printf("Amount of %d: %d\n", 10, AMOUNT(10));
    printf("Amount of %d: %d\n", -3, AMOUNT(-3));
    return 0;
}
