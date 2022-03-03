#include "menger.h"
/**
 * menger - function that draws a 2D Menger Sponge
 * @level: Depth of Sponge
 * Return: Void
 */
void menger(int level)
{
	int x_axis, y_axis, d, dim = 1;

	if (level >= 0)
	{
		for (x_axis = 0; x_axis < level; x_axis++)
		{
			dim *= 3;
		}
		for (x_axis = 0; x_axis < dim; x_axis++)
		{
			for (y_axis = 0; y_axis < dim; y_axis++)
			{
				for (d = dim / 3; d > 0; d /= 3)
				{
					if ((x_axis % (d * 3)) / d == 1 &&
					    (y_axis % (d * 3)) / d == 1)
						break;
				}
				if (d)
				{
					printf(" ");
				} else
				{
					printf("#");
				}
			}
			printf("\n");
		}
	}
}
