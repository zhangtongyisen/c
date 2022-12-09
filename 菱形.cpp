#include <stdio.h>
int main()
{
	int line = 0;
	int i = 0;
	int j = 0;
	int k = 0;	
	scanf("%d", &line);//上三角的行数
	for (i = 0; i < line; i++)//循环line次；行数=i+1
	{
		for (j = 0; j < line - (i + 1); j++)//空格=line-行数
		{
			printf(" ");
		}
		for (k = 0; k <2*(i+1)-1;k++)//*的个数=2*行数-1
		{
			printf("*");
		}
		printf("\n");
		
	}
	for (i = 0; i < line - 1;i++)//循环line-1次；
	{
		for (j = 0; j < i + 1;j++)//空格=line
		{
			printf(" ");
		}
		for (k = (2 * line) - 2 * (i + 1) -1; k>0;k--)
		{
			printf("*");
		}
		printf("\n");
 
	}
 
	return 0;
}
