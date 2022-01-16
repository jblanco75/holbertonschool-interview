#include "sandpiles.h"
/**
 * sandpiles_sum - Stablish the sandpile result of a sum of two sandpiles.
 *
 * @grid1: First Sandpile.
 * @grid2: Second Sandpile.
 * Return: Nothing.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int n = 0, i, j, new_grid[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3)
				n++;
		}
	}
	while (n != 0)
	{
		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				new_grid[i][j] = grid1[i][j];
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (new_grid[i][j] > 3)
				{
					grid1[i][j] -= 4;
					(i - 1) >= 0 ? grid2[i - 1][j] += 1 : 0;
					(i + 1) <= 2 ? grid2[i + 1][j] += 1 : 0;
					(j - 1) >= 0 ? grid2[i][j - 1] += 1 : 0;
					(j + 1) <= 2 ? grid2[i][j + 1] += 1 : 0;
				}
			}
		}
		n = 0;
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (grid1[i][j] > 3)
					n++;
	}
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
