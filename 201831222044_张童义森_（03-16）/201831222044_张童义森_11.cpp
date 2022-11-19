#include <iostream>
#include <vector> 
#include <math.h>
#include<algorithm>
#include <iomanip>
using namespace std;

const int manx = 1000;
vector<int> V[manx];

struct node 	//������¼��ά�㼯 
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

double Eul_dis(double x1, double y1, double x2, double y2) 	//����ŷʽ����
{ 
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void Get_centroid(int n, int &k) 		//�õ���ʼ��k������ 
{  
    double x=0, y=0;
    for(int i = 1; i <= n; i++) 
	{
        cout<<"�������"<<i<<"���������꣺"; 
        cin>>s[i].x>>s[i].y;
        x += s[i].x;
        y += s[i].y;
    }
    x /= (double)n;
    y /= (double)n;        //ѡ��һ����ʼȫ������ 
    cout<<fixed<<setprecision(2)<<"��ʼһ�����ģ�("<<x<<", "<<y<<")"<<endl;
    for(int i = 1; i <= n; i++) 
	{
        ss[i].dis = Eul_dis(x, y, s[i].x, s[i].y);
        ss[i].id = i;
    }
    sort(ss + 1, ss + n + 1, cmp); 		//ѡ������ʼȫ��������Զ��k���㣬��Ϊ��ʼ��k������
    cout<<"��������������������Ⱥ������";
    cin>>k; 			//k������ 
    for(int i = 1; i <= k; i++) 
	{
        int cnt = ss[i].id;
        mean[i].x = s[cnt].x;
        mean[i].y = s[cnt].y;
    }
}

void K_means(int n, int k) 		//ͨ��������������
{  
    double max_dis = 0.0, limit_dis = 0.05; 
    
	do {    	//�˴�����������ƶ�������Ϊ�������� 
        for(int i = 1; i <= k;i++)
            V[i].clear();
        for(int i = 1; i <= n; i++) 	//ö�����ݵ�͸������� 
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
            V[cnt].push_back(i); 			//ʹ���ݵ��Ӧ������
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
            mean[i].x = ans1; 		//������������
            mean[i].y = ans2;
        }
    }while(max_dis > limit_dis);  
} 

void Print_node(int n, int k) 	//������ 
{
    for(int i = 1; i <= k; i++) 
	{
        cout<<endl<<endl;
        cout<<fixed<<setprecision(2)<<"��"<<i<<"���ص��������꣺("<<mean[i].x<<", "<<mean[i].y<<")"<<endl;
        cout<<fixed<<setprecision(2)<<"��"<<i<<"���ص����ݸ�����"<<V[i].size()<<endl;
        for(int j=0;j<V[i].size();j++) 
		{
            int cnt = V[i][j];
            cout<<"("<<s[cnt].x<<", "<<s[cnt].y<<")"<<endl;
        }
    }
}

int main() {
    int n, k;
    cout<<"����������Ŀ�������"; 
    cin>>n;   			 //n����ά�����
    Get_centroid(n, k); //�õ���ʼ��k������ 
    K_means(n, k);      //K-means �㷨�������� 
    Print_node(n, k);   //������ 
    return 0;
}

