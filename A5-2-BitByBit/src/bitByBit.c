/**
 @file bitByBit.c
 @author Jenny Dietrich
 @date 1.0
 @brief flips given bits
*/


#include <stdio.h>
#include <math.h>

/**
 * inverts given bits of positive integer
 * @param x the integer to invert
 * @param p the point to start inverting
 * @param n the count of bits to invert
 */
int invert(unsigned int x, int p, int n)
{
    int xor = 0;
    for (int i = p; i > p - n; i--)
    {
        xor += pow(2, i);
    }
    return x ^ xor;
}

int main(int argc, char const *argv[])
{
    int a = 4;
    printf("%d \n", invert(a, 3, 3));
    return 0;
}
