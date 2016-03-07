
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

void * studentsCount(int *Ar, int len, int score, int *lessCount, int *moreCount) 
{
	if (len<=0 || Ar==NULL)
	return NULL;
	else
	{
		int i = 0,less_Count=0,more_Count=0;
		for (; i < len; i++)
		{
			if (Ar[i] < score)
				less_Count++;
			else if (Ar[i]>score)
				more_Count++;
		}
		*lessCount = less_Count;
		*moreCount = more_Count;
	}
	return NULL;
}
