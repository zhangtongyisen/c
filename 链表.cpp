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
	printf("������ѧ�źͳɼ�������0ʱ������\n");
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
	if(head==NULL)printf("����Ϊ�գ����ܽ���ɾ��������\n");
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
			printf("�ڵ�ɾ����\n");
		}
		else printf("�����в����ڸýڵ㣬�޷�ɾ����\n");
	}
	return (head);
}
struct node *insert(struct node *head){
	struct node *p0,*p1,*p2;
	p0=(struct node *)malloc(sizeof(struct node));
	p0->next=NULL;
	printf("����ѧ�źͳɼ���\n");
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
	if(head==NULL)printf("����Ϊ��!\n");
	else{
		printf("������Ϣ���£�\n");
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
	printf("������Ҫ���еĲ�����1.ɾ��  2.����\n");
	scanf("%d",&n) ;
	while(n!=0){
		if(n==1){
			printf("����ɾ���ڵ����\n");
			while(ch=='y'||ch=='Y'){
			printf("����Ҫɾ����ѧ��ѧ�ţ�\n");
			scanf("%d",&delnum);
			getchar();
			head=del(head,delnum);
			printf("��Ҫ����ɾ������ѧ������Ϣ��(y/n):");
			ch=getchar();
			getchar();
			}
			printf("ɾ�����ѧ����Ϣ��\n");
			list(head);
			ch='y';
			printf("������Ҫ���еĲ�����1.ɾ��  2.����\n");
			scanf("%d",&n);
		}
		if(n==2){
			printf("���в���ڵ����\n");
			while(ch=='y'||ch=='Y'){
				head=insert(head);
				printf("��Ҫ������������ѧ����Ϣ��(y/n)");
				ch=getchar();
				getchar();
			}
			printf("������ѧ����Ϣ��\n");
			list(head);	
			ch='y';
			printf("������Ҫ���еĲ�����1.ɾ��  2.����\n");
			scanf("%d",&n);
		}
		else printf("ллʹ��!�ټ�\n");
	}
}
