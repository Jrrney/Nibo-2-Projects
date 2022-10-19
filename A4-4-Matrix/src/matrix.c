/*
 ============================================================================
 Name        : matrix.c
 Author      : Janett Mohnke, Jenny Dietrich
 Version     : 1.0
 Description : Printing a two-dimensional array ....
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define NUM_ROWS 4
#define NUM_COL 5

void printMatrix(int h, int w, float matrix[h][w])
{
	// add code to print array
	for (size_t m = 0; m < h; m++)
	{
		for (size_t n = 0; n < w; n++)
		{
			printf("%f\t", matrix[m][n]);
		}
		printf("\n");
	}
}

/*
 * ... and it works:
 */
int main(void)
{
	float myMatrix[4][5] = {{1, 2, 3, 4, 5},
							{6, 7, 8, 9, 10},
							{11, 12, 13, 14, 15},
							{16, 17, 18, 19, 20}};
	printf("Matrix:\n");
	printMatrix(4, 5, myMatrix);

	return EXIT_SUCCESS;
}
