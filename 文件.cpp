#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct student{
	char num[16];
	char name[20];
	float score;
}; 
int main(){
	struct student stud;
	char str[20],ch;
	FILE *fp;
	if((fp=fopen("stud.dat","wb"))==NULL){
		printf("can`t open file stud.dat\n");
		exit(0);
	}
	do {
		printf("����ѧ�ţ�\n");
		gets(str);
		printf("����������\n");
		gets(stud.name);
		printf("����ɼ���\n");
		gets(str);
		stud.score=atof(str);
		fwrite(&stud,sizeof(struct student),1,fp);
		printf("������������ѧ������Ϣ��(y/n):");
		ch=getchar();
		getchar();
	}while(ch=='y');
	fclose(fp);
}
