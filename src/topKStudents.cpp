/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

void megesort(struct student*, int, int);
void mege(struct student*, int, int);

struct student ** topKStudents(struct student *students, int len, int K) 
{

	if (len < 0 || students == NULL || K <= 0)
		return NULL;
	else
	{
		int low = 0, high = len - 1, i = 0;
		struct student **stud;
		stud = &students;
		megesort(students, low, high);
		stud = (struct student**)malloc(sizeof(struct student*)*K);
		for (i = 0; i < K; i++)
		{
			stud[i] = (struct student*)malloc(sizeof(struct student) * 1);
			stud[i][0].score = students[i].score;
			stud[i][0].name = students[i].name;
		}
		return stud;
	}
}
void megesort(struct student *students, int low, int high)
{
	int mid;
	mid = (low + high) / 2;
	if (low >= high)
		return;
	megesort(students, low, mid);
	megesort(students, mid + 1, high);
	mege(students, low, high);
	return;
}
void mege(struct student *students, int i, int j)
{
	int mid = (i + j) / 2, start = i, k = mid + 1, begin = i;
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
		students[i].name = studen[i].name;
	}

}
