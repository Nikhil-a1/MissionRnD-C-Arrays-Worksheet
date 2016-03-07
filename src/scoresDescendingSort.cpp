/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct student {
	char name[10];
	int score;
};

void mergesort(struct student*, int, int);
void merge(struct student*, int, int);
void copy_name(char*, char*);

void * scoresDescendingSort(struct student *students, int len)
{
	if (len <= 0 || students == NULL)
		return NULL;
	int low = 0, high = len - 1, i = 0;
	mergesort(students, low, high);
}
	void mergesort(struct student *students, int low, int high)
{
	int mid;
	mid = (low + high) / 2;
	if (low >= high)
		return;
	mergesort(students, low, mid);
	mergesort(students, mid + 1, high);
	merge(students, low, high);
	return;
}
void merge(struct student *students, int i, int j)
{
	int mid = (i + j) / 2, start = i, k = mid + 1, begin = start;
	struct stud
	{
		int score;
		char* name;
	};
	struct stud studen[20];
	while (start <= mid && k <= j)
	{
		if (students[start].score >= students[k].score)
		{
			studen[begin].score = students[start].score;
			studen[begin].name = students[start].name;
			start++;
			begin++;
		}
		else
		{
			studen[begin].score = students[k].score;
			studen[begin].name = students[k].name;
			begin++;
			k++;
		}
	}
	if (start> mid)
	{
		for (; k <= j; k++)
		{
			studen[begin].score = students[k].score;
			studen[begin].name = students[k].name;
			begin++;
		}
	}
	else if (k > j)
	{
		for (; start <= mid; start++)
		{
			studen[begin].score = students[start].score;
			studen[begin].name = students[start].name;
			begin++;
		}
	}
	for (; i <=j; i++)
	{
		students[i].score = studen[i].score;
		copy_name(studen[i].name, students[i].name);
	}
}

void copy_name(char* name1, char* name2)
{
	while (*name1 != '\0')
	{
		*name2 = *name1;
		name1++;
		name2++;
	}
}