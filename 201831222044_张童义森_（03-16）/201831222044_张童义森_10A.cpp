/*
	功能：实现背包问题 
	编译人：张童义森
	编译环境：Dev-C++ 5.11
	编译日期：2020.4.20 
	参考文献：屈婉玲《算法设计与分析（第2版）》
*/ 
#include<iostream>
#include<algorithm>
using namespace std;
int b;		//背包可的容量
int n;			//物品数
double jie=0;		//界函数值

struct thing{
    double avg;		//物品的 价值/重量 的比值 
    double value;		//价值
    double weight;		//重量
}x[10];

bool cmp(thing m,thing n)		//按照物品的 价值/重量 的比值对物品进行降序排序
{
    if(m.avg>n.avg)
    	return true;
    return false;
}

double search(int i,double v,double w)
{
    double dai=v+x[i].avg*(b-w);			//代价函数值 
    int t;
    if(w<=b)			//背包的容量大于此刻背包内物品的重量
    {
        if(i>=n&&v>jie)		//找到可行解，更新界函数值
            jie=v;
        for(int t=b/x[i].weight;t>=0;t--)		//背包容量整除第i个物品的重量，表示该背包能放t个 x[i] 物品 ，对每种情况进行深度搜索 
            search( i+1, v+t*x[i].value , w+t*x[i].weight );		//继续进行深度搜索
    }
    return jie;
}

int main()
{
    cout<<"输入物品的数量和背包的容量：";
    cin>>n>>b;
    cout<<"请依次输入"<<n<<"个物品的重量:"<<endl;
    for(int i=0;i<n;i++)
        cin>>x[i].weight;
    cout<<"请依次输入"<<n<<"个物品的价值:"<<endl;
    for(int i=0;i<n;i++)
        cin>>x[i].value;
    for(int i=0;i<n;i++)
        x[i].avg=x[i].value/x[i].weight;		//计算物品的 价值/重量 的比值
    sort(x,x+n,cmp);		//对按照物品的 价值/重量 的比值对物品进行排序
    double max=search(0,0,0);			//都初始化为0 
    cout<<"最大价值是:"<<max<<endl;
    return 0;
}
