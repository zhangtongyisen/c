#include<stdio.h>
#include<stdlib.h>
enum weekday{sun,mon,tue,wed,thu,fri,sat};
int main(){
	int n;
	enum weekday today,day;
	char a[7][10]={"星期天","星期一","星期二","星期三","星期四","星期五","星期六"};
	today=sun;
	printf("输入间隔天数：\n");
	scanf("%d",&n);
	day=(enum weekday)((today+n)%7);
	printf("today=%s\nday=%s\n",a[today],a[day]); 
}
