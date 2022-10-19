/**
 @file fahr2Celcius.c
 @author Jenny Dietrich
 @date 1.0
 @brief table of fahr to celcius
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    printf("Fahreneinheit  Celcius\n");
    printf("----------------------\n");
    while (i <= 300)
    {
    	// calculate celcius
        printf("%d\t\t%d\n", i, (int)((5.0 / 9.0) * (i - 32)));
        i += 20;
    }

    return 0;
}
