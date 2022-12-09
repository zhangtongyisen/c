#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
#define M 10
struct word{
	char english[40];
	char chinese[20];
}; 
void load(char *filename,struct word a[N]){
	FILE *fp;
	int i=0;
	if((fp=fopen(filename,"r"))==NULL){
		printf("can`t open file:%s!\n",filename);
		exit(0);
	}
	while(fscanf(fp,"%s %s",a[i].english,a[i].chinese)!=EOF){
		i++;
	}
}
void exercise(struct word a[]){
	int i,score,n=0;
	char c='y',eng[40];
	while(c=='y'){
		score=0;
		for(i=n;i<n+M;i++){
			puts(a[i].chinese);
			printf("请输入英文单词：\n");
			gets(eng);
			if(strcmp(eng,a[i].english)==0){
				score=score+10;
			}
			printf("本次联系得分：%d\n",score);
			n=i;
			printf("继续下一组练习吗？(y/n):");
			c=getchar();
			getchar();
		}
	}
}
int main(){
	char name[20];
	char c='y';
	struct word wd[N];
	while(c=='y'){
		printf("请输入单词文件名：\n");
		gets(name);
		load(name,wd);
		exercise(wd);
		printf("选择其他单词文件吗？(y/n):");
		c=getchar();
		getchar();
	} 
	printf("谢谢使用，再见！\n");
}
