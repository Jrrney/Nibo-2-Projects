/**
 @file scalarDataTypesSandbox.c
 @author Jenny Dietrich
 @date 1.0
 @brief scalar data types sandbox
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>

int main(int argc, char const *argv[])
{
    short s;
    int short_bytes = sizeof(s);
    printf("short_bytes: %d\n", short_bytes);
    printf("short_min: %ld\n", (long)-pow(2, (short_bytes * 8) - 1));
    printf("short_max: %ld\n", (long)pow(2, (short_bytes * 8) - 1) - 1);

    int i;
    int int_bytes = sizeof(i);
    printf("int_bytes: %d\n", int_bytes);
    printf("int_min: %ld\n", (long)-pow(2, (int_bytes * 8) - 1));
    printf("int_max: %ld\n", (long)pow(2, (int_bytes * 8) - 1) - 1);

    long l;
    int long_bytes = sizeof(l);
    printf("long_bytes: %d\n", long_bytes);
    printf("long_precision: %d\n", long_bytes * 8);

    char c;
    int char_bytes = sizeof(c);
    printf("char_bytes: %d\n", char_bytes);
    printf("char_min: %ld\n", (long)-pow(2, (char_bytes * 8) - 1));
    printf("char_max: %ld\n", (long)pow(2, (char_bytes * 8) - 1) - 1);

    float f;
    int float_bytes = sizeof(f);
    printf("float_bytes: %d\n", float_bytes);
    printf("float_precision: %d\n", FLT_DIG);

    double d;
    int double_bytes = sizeof(d);
    printf("double_bytes: %d\n", double_bytes);
    printf("double_precision: %d\n", DBL_DIG);

    long double ld;
    int long_double_bytes = sizeof(ld);
    printf("long_double_bytes: %d\n", long_double_bytes);
    printf("long_double_precision: %d\n", LDBL_DIG);

    unsigned short us;
    int unsigned_short_bytes = sizeof(us);
    printf("unsigned_short_bytes: %d\n", unsigned_short_bytes);

    unsigned int ui;
    int unsigned_int_bytes = sizeof(ui);
    printf("unsigned_int_bytes: %d\n", unsigned_int_bytes);

    unsigned long ul;
    int unsigned_long_bytes = sizeof(ul);
    printf("unsigned_long_bytes: %d\n", unsigned_long_bytes);

    bool b;
    int bool_bytes = sizeof(b);
    printf("bool_bytes: %d\n", bool_bytes);

    return 0;
}
