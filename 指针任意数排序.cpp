#include<stdio.h>
#include<stdlib.h>
void bubble(int *p,int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(*(p+j)<*(p+j+1)){
				temp=*(p+j+1);
				*(p+j+1)=*(p+j);
				*(p+j)=temp;
			}
		}
	}
}
void alt(int *p,int n){
	int i,j,k,temp;
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++){
			if(*(p+j)>*(p+k))k=j;
		}
		if(k!=i){
			temp=*(p+k);
			*(p+k)=*(p+i);
			*(p+i)=temp;
		}
	}
}
void sert(int *p,int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=*(p+i);
		for(j=i-1;j>=0&&temp>*(p+j);j--){
			*(p+j+1)=*(p+j);
		}
		*(p+j+1)=temp;
	}
}
int main(){
	int n,i,*p=NULL;
	scanf("%d",&n);
	p=(int *)malloc(n*sizeof(int));
	if(p==NULL){
		printf("分配失败！\n");
		exit(1);
	} 
	printf("请输入这些数：\n");
	for(i=0;i<n;i++){
		scanf("%d",p+i);
	}
	bubble(p,n);
	//alt(p,n);
	//sert(p,n);
	for(i=0;i<n;i++){
		if(i%5==0)
		printf("\n");
		printf("%8d",*(p+i));
	}
	printf("\n");
	free(p);
	return 0;
	}

