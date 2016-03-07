/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include<stdlib.h>

int removeArrayDuplicates(int *arr, int len)
{
	if (arr == NULL || len <= 0)
		return -1;
	else
	{
		int *hash, count = 0, j = 0, i = 0;
		hash = (int*)calloc(10, sizeof(int));
		for (; i < len; i++)
		{
			j = arr[i];
			if (hash[j] == 0)
			{
				hash[j]++;
				arr[count] = arr[i];
				count++;
			}
		}
		return count;
	}
}