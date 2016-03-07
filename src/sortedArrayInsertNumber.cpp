/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *arry, int len, int num)
{
	if(arry==NULL || len<=0 )
	return NULL;
	else
	{
		int pos = 0, i = 0,*Arr,temp1,temp2,flag=0;
		Arr = (int*)malloc(sizeof(int)*len);
		for (i = 0; i < len; i++)
			Arr[i] = arry[i];
		for (i = 0; i < len; )
		{
			if (num > Arr[i] && i < len - 1)
				i++;
			else if (num > Arr[i] && i == len - 1)
			{
				pos = i + 1;
				break;
			}
			else if (num < Arr[i])
			{
				pos = i;
				break;
			}
		}
		Arr = (int*)realloc(Arr, len + 1);
		for (i = 0; i < len + 1; i++)
		{
			if (i == pos)
			{
				flag = 1;
				temp1 = Arr[i];
				Arr[i] = num;
			}
			else if (flag==1)
			{
				temp2 = Arr[i];
				 Arr[i]=temp1;
				 temp1 = temp2;
			}
		}
		return Arr;
	}
}