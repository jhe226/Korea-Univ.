#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Person
{
	char name[5];
	int age;
	char gender;
}p;

p* search(p list[], p target, int n)
{
	p* result = (p*)malloc(sizeof(p));
	for (int i = 0; i < n; i++)
	{
		if (strcmp(list[i].name, target.name) == 0)
		{
			result = &list[i];
			break;
		}
		else
		{
			result = NULL;
		}
	}

	return result;
}

void save_file(p tmp, int cnt)
{
	FILE* fp = NULL;
	fopen_s(&fp, "save.txt", "a");
	fprintf(fp, "(%d) 이름 : %s 나이 : %d 성별 : %s\n", cnt, tmp.name, tmp.age, tmp.gender);
	fclose(&fp);
}

int* distribution(p list[], int n)
{
	int* val = (int)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		val[i] = list[i].age / 10;
	}

	return val;
}

int find_max(int* val, int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (val[i] > max)
			max = val[i];
	}
	return max;
}

void print_person(int* val, int n, int max)
{
	for (int i = 0; i < max + 1; i++)
	{
		int tmp = 0;
		for (int j = 0; j < n; j++)
		{
			if (val[j] == (i + 1))
				tmp++;
		}
		printf("%d대 : %d명\n", (i + 1) * 10, tmp);
	}
}

int main()
{
	p list[] = { {"Han", 40, "M"},
				 {"Kim", 31, "M"},
				 {"Park", 25, "F"},
				 {"Seo", 19, "F"},
				 {"Lee", 49, "M"},
				 {"Choi", 20, "F"} };

	p tmp = {}, * p = NULL;
	int choice, cnt = 0, retry = 1, n = sizeof(list)/sizeof(list[0]);

	while (retry)
	{

		search(list, tmp, n);
		printf("재탐색하시겠습니까? 0. 예 1. 아니오");
		scanf_s("%d", &retry);
	}
}