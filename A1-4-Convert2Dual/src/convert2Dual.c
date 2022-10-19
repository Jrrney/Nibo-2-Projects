/**
 @file convert2Dual.c
 @author Jenny Dietrich
 @date 1.0
 @brief convert a number to dual
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    long decimal;
    long binary = 0;
    int potenz = 0;
    printf("positive int number: ");
    int x = scanf("%ld", &decimal);
    if (x)
    {
    	// calculation decimal -> dual
        while (decimal > 0)
        {
            binary += (decimal % 2) * pow(10, potenz++);
            decimal /= 2;
        }

        printf("binary: %ld\n", binary);
    }
    else
    {
        printf("No positive int number!\n");
    }

    return 0;
}
