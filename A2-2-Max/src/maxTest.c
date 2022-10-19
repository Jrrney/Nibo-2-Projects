/**
 @file maxTest.c
 @author Jenny Dietrich
 @date 1.0
 @brief Test calculate max of 2 floats
*/

#include <stdio.h>
#include "max.h"

int main(int argc, char const *argv[])
{
    float f1;
    float f2;
    printf("float 1: ");
    if (!scanf("%f", &f1))
    {
        printf("no float\n");
        return 0;
    }
    printf("float 2: ");
    if (!scanf("%f", &f2))
    {
        printf("no float\n");
        return 0;
    }
    printf("max: %f\n", max(f1, f2));
    return 0;
}
