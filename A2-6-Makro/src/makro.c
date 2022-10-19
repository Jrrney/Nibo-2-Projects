/**
 @file makro.c
 @author Jenny Dietrich
 @date 1.0
 @brief makros
*/

#include <stdio.h>

#define MAX(x, y) x > y ? x : y
#define SQUARE(x) x * x

int main(int argc, char const *argv[])
{
	int a = 5;
	int b = -5;
	int c = 10;
	int d = -10;
    printf("MAX(a,b) = %d \n", MAX(a, b));
    printf("MAX(a+b,c+d) = %d \n", MAX(a + b, c+ d));
    printf("SQUARE(a) = %d \n", SQUARE(a));
    printf("SQUARE(a + 1) = %d \n", SQUARE((a + 1))); // Klammern müssen gesetzt werden, sonst a + 1 * a + 1 statt (a + 1) * (a + 1)
    printf("SQUARE(-a) = %d \n", SQUARE(-a));

    return 0;
}
