#include <stdio.h>
int main()
{
	int line = 0;
	int i = 0;
	int j = 0;
	int k = 0;	
	scanf("%d", &line);//�����ǵ�����
	for (i = 0; i < line; i++)//ѭ��line�Σ�����=i+1
	{
		for (j = 0; j < line - (i + 1); j++)//�ո�=line-����
		{
			printf(" ");
		}
		for (k = 0; k <2*(i+1)-1;k++)//*�ĸ���=2*����-1
		{
			printf("*");
		}
		printf("\n");
		
	}
	for (i = 0; i < line - 1;i++)//ѭ��line-1�Σ�
	{
		for (j = 0; j < i + 1;j++)//�ո�=line
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
