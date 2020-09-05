#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	srand(time(NULL));
	int a[5][5];
	int min[5];
	int flag = 0;
	int temp = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			a[i][j] = rand() % 100;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	for (int i = 0; i < 5; i++)
	{
		flag = a[i][0];
		min[i] = a[i][0];
		for (int j = 0; j < 4; j++)
		{
			if (flag < a[i][j + 1])
				flag = a[i][j + 1];
			if (min[i] > a[i][j + 1])
				min[i] = a[i][j + 1];
		}
			printf("최댓값: %d ", flag);
	}
	printf("\n");
	for (int k = 0; k < 5; k++)
		printf("최솟값: %d ", min[k]);
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (a[i][k] < a[i][k + 1])
				{
					temp = a[i][k];
					a[i][k] = a[i][k + 1];
					a[i][k + 1] = temp;
				}
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

