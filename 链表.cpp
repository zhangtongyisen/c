#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	float score;
	struct node *next;
}; 
struct node *creat(){
	struct node *p1=NULL,*p2=NULL,*head=NULL;
	int n;
	float s;;
	printf("请输入学号和成绩（输入0时结束）\n");
	scanf("%d%f",&n,&s);
	while(n!=0){
		p1=(struct node *)malloc(sizeof(struct node));
		p1->num=n;
		p1->score=s;
		if(head==NULL)head=p1;
		else p2->next=p1;
		p2=p1;
		scanf("%d%f",&n,&s);
	}
	p2->next=NULL;
	return (head);
}
struct node *del(struct node *head,int num){
	struct node *p1=NULL,*p2=NULL;
	if(head==NULL)printf("链表为空，不能进行删除操作！\n");
	else{
		p1=head;
		while((num!=p1->num)&&(p1->next!=NULL)){
			p2=p1;
			p1=p1->next;
		}
		if(num==p1->num){
			if(p1==head)head=p1->next;
			else p2->next=p1->next;
			free(p1);
			printf("节点删除！\n");
		}
		else printf("链表中不存在该节点，无法删除！\n");
	}
	return (head);
}
struct node *insert(struct node *head){
	struct node *p0,*p1,*p2;
	p0=(struct node *)malloc(sizeof(struct node));
	p0->next=NULL;
	printf("输入学号和成绩：\n");
	scanf("%d%f",&p0->num,&p0->score);
	getchar();
	if(head==NULL)head=p0;
	else{
		p1=head;
		while((p0->num>p1->num)&&(p1->next!=NULL)){
			p2=p1;
			p1=p1->next;
		}
		if(p0->num<=p1->num){
			if(head==p1)head=p0;
			else p2->next=p0;
			p0->next=p1;
		}
		else p1->next=p0;
	}
	return (head);
}
void list(struct node *head){
	struct node *p;
	if(head==NULL)printf("链表为空!\n");
	else{
		printf("链表信息如下：\n");
		p=head;
		while(p!=NULL){
			printf("%d,%5.2f\n",p->num,p->score);
			p=p->next;
		}
	}
}
int main(){
	struct node *head;
	char ch='y';
	int delnum,n;
	head=creat();
	list(head);
	printf("请输入要进行的操作：1.删除  2.插入\n");
	scanf("%d",&n) ;
	while(n!=0){
		if(n==1){
			printf("进行删除节点操作\n");
			while(ch=='y'||ch=='Y'){
			printf("输入要删除的学生学号：\n");
			scanf("%d",&delnum);
			getchar();
			head=del(head,delnum);
			printf("还要继续删除其他学生的信息吗？(y/n):");
			ch=getchar();
			getchar();
			}
			printf("删除后的学生信息：\n");
			list(head);
			ch='y';
			printf("请输入要进行的操作：1.删除  2.插入\n");
			scanf("%d",&n);
		}
		if(n==2){
			printf("进行插入节点操作\n");
			while(ch=='y'||ch=='Y'){
				head=insert(head);
				printf("还要继续插入其他学生信息吗(y/n)");
				ch=getchar();
				getchar();
			}
			printf("插入后的学生信息：\n");
			list(head);	
			ch='y';
			printf("请输入要进行的操作：1.删除  2.插入\n");
			scanf("%d",&n);
		}
		else printf("谢谢使用!再见\n");
	}
}
