#include<stdio.h>
#include<stdlib.h>
enum weekday{sun,mon,tue,wed,thu,fri,sat};
int main(){
	int n;
	enum weekday today,day;
	char a[7][10]={"������","����һ","���ڶ�","������","������","������","������"};
	today=sun;
	printf("������������\n");
	scanf("%d",&n);
	day=(enum weekday)((today+n)%7);
	printf("today=%s\nday=%s\n",a[today],a[day]); 
}
