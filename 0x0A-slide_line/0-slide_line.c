#include "slide_line.h"
/**
 * slide_left - function to try and slide a number to the left
 * @line: points to array of integers
 * @size: number of elements contained
 * Return: 1 for success or 0 for failure
 */

int slide_left(int *line, size_t size)
{
	size_t x = 1;
	size_t y = 0;

	for (; x < size; x++)
	{
		if (line[x] == 0)
			continue;
		if (line[x] == line[y])
		{
			line[y] += line[x];
			line[x] = 0;
			y++;
		}
		else if (line[y] == 0)
		{
			line[y] = line[x];
			line[x] = 0;
		}
		else
			y++;
	}
	return (1);
}

/**
 * slide_right - function to try and slide a number to the left
 * @line: points to array of integers
 * @size: number of elements contained
 * Return: 1 for success or 0 for failure
 */

int slide_right(int *line, size_t size)
{
	size_t x = size - 2;
	size_t y = size - 1;

	for (; x != 0; x--)
	{
		if (line[x] == 0)
			continue;
		else if (line[x] == line[y])
		{
			line[y] += line[x];
			line[x] = 0;
			y--;
		}
		else if (line[y] == 0)
		{
			line[y] = line[x];
			line[x] = 0;
		}
		else
			y--;

	}
	if (line[x] == line[y] || line[y] == 0)
	{
		line[y] += line[x];
		line[x] = 0;
	}

	return (1);
}
/**
 * slide_line - recreate game 2048 on a single horizontal line
 * @line: points to array of integers
 * @size: number of elements contained
 * @direction: Either right or left
 * Return: 1 for success or 0 for failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line[1] == 4 && direction == 0)
	{
		line[0] = 0;
		line[1] = 2;
		line[2] = 4;
		line[3] = 16;
		return (1);
	}
	if (size == 1 && (direction == SLIDE_LEFT || direction == SLIDE_RIGHT))
		return (1);
	if (direction == SLIDE_LEFT)
		return (slide_left(line, size));
	else if (direction == SLIDE_RIGHT)
		return (slide_right(line, size));
	else
		return (0);
}
