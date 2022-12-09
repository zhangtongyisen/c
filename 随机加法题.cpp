#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int justify(int x,char ch,int y,int comp){
	int i=2,result;
	while(i>0){
	printf("wrong!");
	printf("还有%d次机会\n",i--);
	printf("%d%c%d=",x,ch,y);
	scanf("%d",&result);
	getchar();
	if(result==comp) printf("right!\n");
    }
	printf("wrong!,%d%c%d=%d\n",x,ch,y,comp);
}
int main(){
	int x,y,comp,result,temp;
	char ch,choice;
	srand(time(0));
	system("cls");
	do{
		system("cls");
		x=rand()%100;
		y=rand()%100;
		if(rand()%2==0){
			ch='-';
			if(x<y){
				temp=x;
				x=y;
				y=temp;
			}}
		else ch='+';
		printf("%d%c%d=",x,ch,y);
		scanf("%d",&result);
		getchar();
		if(ch=='-') comp=x-y;
		else comp=x+y;
		if(result==comp) printf("right!\n");
		else {
			justify(x,ch,y,comp);
		}	
		printf("go on?(y/n)");
		choice=getchar();
		
	}while(choice=='y'||choice=='Y');
} 
