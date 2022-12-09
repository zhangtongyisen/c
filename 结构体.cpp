#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student {
	char num[16];
	char name[12];
	int score[3];
	float ave;
};

int judge(struct student x){
	for(int i=0;i<3;i++){
	if(x.score[i]<60)return 1;
	else return 0;
	}
}
int average(struct student *p){
	int i,sum=0;
	for(i=0;i<3;i++){
		sum=sum+(*p).score[i];
	}
	p->ave=sum/3.0;
	//return p->ave;
}
int main(){
	struct student st[10];
	struct student *ps;
	int i,j,n=0;
	for(i=0;i<10;i++){
		scanf("%s%s",st[i].num,st[i].name);
		for(j=0;j<3;j++){
			scanf("%d",&st[i].score[j]);
		}
		if(getchar()=='\n')break;
	}
	for(ps=st,j=0;ps<=st+i,j<=i;ps++,j++){
		average(ps);
		printf("%s,%s,%5.2f\n",(*ps).num,ps->name,st[j].ave);
	}
	for(j=0;j<=i;j++){
		if(judge(st[j]))
			n++;
	}
	printf("%d\n",n);
}
