/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *array, int len)
{
	if (array == NULL || len <= 0)
		return NULL;
	else
	{
		int element1 = array[0], element2, i = 0, flag = 0, pos1, pos2;
		while (i < len)
		{
			if (element1 < array[i])
				element1 = array[i];
			else if (element1>array[i])
			{
				flag = 1;
				pos1 = i - 1;
				break;
			}
			i++;
		}
		element2 = array[i];
		while (i < len)
		{
			if (element2 < array[i])
				element2 = array[i];
			else if (element2>array[i])
			{
				flag = 1;
				pos2 = i;
				break;
			}
			i++;
		}
		if (flag != 0)//swapping
		{
			array[pos1] = array[pos1] - array[pos2];
			array[pos2] = array[pos2] + array[pos1];
			array[pos1] = array[pos2] - array[pos1];
		}
	}
	return NULL;
}