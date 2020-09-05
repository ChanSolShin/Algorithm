#include<stdio.h>
int main()
{
	char answer[3];
	char ch[3] = { '-','-','-' };
	char qwe;
	for (int i = 0; i < 3; i++)
		scanf("%c", &answer[i]);
		getchar();
	for (int i = 0; i < 5; i++)
	{
		scanf("%c", &qwe);
		getchar();
		if (qwe == answer[0])
		{
			ch[0] = answer[0];
		}
		else if (qwe == answer[1])
		{
			ch[1] = answer[1];
		
		}
		else if (qwe == answer[2])
		{
			ch[2] = answer[2];
		}
		for (int i = 0; i < 3; i++)
			printf(" %c", ch[i]);
		printf("\n");
		if (ch[0] == answer[0] && ch[1] == answer[1] && ch[2] == answer[2])
			break;
	}
