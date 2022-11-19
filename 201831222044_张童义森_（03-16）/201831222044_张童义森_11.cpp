#include <iostream>
#include <vector> 
#include <math.h>
#include<algorithm>
#include <iomanip>
using namespace std;

const int manx = 1000;
vector<int> V[manx];

struct node 	//用来记录二维点集 
{ 
    double x;
    double y;
}s[manx], mean[manx];

struct Node 
{
    double dis;
    int id; 
}ss[manx];

bool cmp(Node a, Node b) 
{
    return a.dis > b.dis;
}

double Eul_dis(double x1, double y1, double x2, double y2) 	//计算欧式距离
{ 
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void Get_centroid(int n, int &k) 		//得到初始的k个质心 
{  
    double x=0, y=0;
    for(int i = 1; i <= n; i++) 
	{
        cout<<"请输入第"<<i<<"个数据坐标："; 
        cin>>s[i].x>>s[i].y;
        x += s[i].x;
        y += s[i].y;
    }
    x /= (double)n;
    y /= (double)n;        //选择一个初始全局质心 
    cout<<fixed<<setprecision(2)<<"初始一个质心：("<<x<<", "<<y<<")"<<endl;
    for(int i = 1; i <= n; i++) 
	{
        ss[i].dis = Eul_dis(x, y, s[i].x, s[i].y);
        ss[i].id = i;
    }
    sort(ss + 1, ss + n + 1, cmp); 		//选择距离初始全局质心最远的k个点，作为初始的k个质心
    cout<<"请输入您想收敛的数据群个数：";
    cin>>k; 			//k个质心 
    for(int i = 1; i <= k; i++) 
	{
        int cnt = ss[i].id;
        mean[i].x = s[cnt].x;
        mean[i].y = s[cnt].y;
    }
}

void K_means(int n, int k) 		//通过迭代更新质心
{  
    double max_dis = 0.0, limit_dis = 0.05; 
    
	do {    	//此处用质心最大移动距离作为收敛条件 
        for(int i = 1; i <= k;i++)
            V[i].clear();
        for(int i = 1; i <= n; i++) 	//枚举数据点和各个质心 
		{							 
            double dis = -1.0;
            int cnt;
            for(int j = 1; j <= k; j++) 
			{
                double ans = Eul_dis(s[i].x, s[i].y, mean[j].x, mean[j].y);
                if(ans > dis) 
				{
                    dis = ans;
                    cnt = j;
                }
            }
            V[cnt].push_back(i); 			//使数据点对应其质心
        }
        for(int i = 1; i <= k;i++) 
		{
            double sum_x = 0.0, sum_y = 0.0;
            for(int j = 0; j < V[i].size(); j++) {
                int cnt = V[i][j];
                sum_x += s[cnt].x;
                sum_y += s[cnt].y;
            }
            double ans1 = sum_x / (double)V[i].size();
            double ans2 = sum_y / (double)V[i].size();
            max_dis = min(max_dis, Eul_dis(mean[i].x, mean[i].y, ans1, ans2));
            mean[i].x = ans1; 		//更新质心坐标
            mean[i].y = ans2;
        }
    }while(max_dis > limit_dis);  
} 

void Print_node(int n, int k) 	//输出结果 
{
    for(int i = 1; i <= k; i++) 
	{
        cout<<endl<<endl;
        cout<<fixed<<setprecision(2)<<"第"<<i<<"个簇的质心坐标：("<<mean[i].x<<", "<<mean[i].y<<")"<<endl;
        cout<<fixed<<setprecision(2)<<"第"<<i<<"个簇的数据个数："<<V[i].size()<<endl;
        for(int j=0;j<V[i].size();j++) 
		{
            int cnt = V[i][j];
            cout<<"("<<s[cnt].x<<", "<<s[cnt].y<<")"<<endl;
        }
    }
}

int main() {
    int n, k;
    cout<<"请输入数据目标个数："; 
    cin>>n;   			 //n个二维坐标点
    Get_centroid(n, k); //得到初始的k个质心 
    K_means(n, k);      //K-means 算法迭代过程 
    Print_node(n, k);   //输出结果 
    return 0;
}

