#include "slide_line.h"

/**
 * slide_line - This function slides and merges an array of integers
 * @line: Points to an array of integers containing
 * @size: Number of elements
 * @direction: Direction represented
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	int i = 0, j = 0;

	if (!line)
		return (0);
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	for (i = (direction == SLIDE_RIGHT) ? size - 1 : 0;
	     (direction == SLIDE_RIGHT) ? i >= 0 : (i < (int)size); i += direction)
	{
		for (j = i + direction;
		     (direction == SLIDE_RIGHT) ? j >= 0 : (j < (int)size)
			     ; j += direction)
		{
			if (line[i] == 0 && line[j] != 0)
			{
				line[i] = line[j];
				line[j] = 0;
				i -= direction;
				break;
			}
			else if (line[i] == line[j] && line[i] != 0)
			{
				line[i] <<= 1;
				line[j] = 0;
				break;
			}
			else if (line[i] != line[j] && line[i] == 0)
				break;
		}
	}

	return (1);
}
