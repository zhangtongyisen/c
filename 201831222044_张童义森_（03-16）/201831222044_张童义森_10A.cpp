/*
	���ܣ�ʵ�ֱ������� 
	�����ˣ���ͯ��ɭ
	���뻷����Dev-C++ 5.11
	�������ڣ�2020.4.20 
	�ο����ף������ᡶ�㷨������������2�棩��
*/ 
#include<iostream>
#include<algorithm>
using namespace std;
int b;		//�����ɵ�����
int n;			//��Ʒ��
double jie=0;		//�纯��ֵ

struct thing{
    double avg;		//��Ʒ�� ��ֵ/���� �ı�ֵ 
    double value;		//��ֵ
    double weight;		//����
}x[10];

bool cmp(thing m,thing n)		//������Ʒ�� ��ֵ/���� �ı�ֵ����Ʒ���н�������
{
    if(m.avg>n.avg)
    	return true;
    return false;
}

double search(int i,double v,double w)
{
    double dai=v+x[i].avg*(b-w);			//���ۺ���ֵ 
    int t;
    if(w<=b)			//�������������ڴ˿̱�������Ʒ������
    {
        if(i>=n&&v>jie)		//�ҵ����н⣬���½纯��ֵ
            jie=v;
        for(int t=b/x[i].weight;t>=0;t--)		//��������������i����Ʒ����������ʾ�ñ����ܷ�t�� x[i] ��Ʒ ����ÿ���������������� 
            search( i+1, v+t*x[i].value , w+t*x[i].weight );		//���������������
    }
    return jie;
}

int main()
{
    cout<<"������Ʒ�������ͱ�����������";
    cin>>n>>b;
    cout<<"����������"<<n<<"����Ʒ������:"<<endl;
    for(int i=0;i<n;i++)
        cin>>x[i].weight;
    cout<<"����������"<<n<<"����Ʒ�ļ�ֵ:"<<endl;
    for(int i=0;i<n;i++)
        cin>>x[i].value;
    for(int i=0;i<n;i++)
        x[i].avg=x[i].value/x[i].weight;		//������Ʒ�� ��ֵ/���� �ı�ֵ
    sort(x,x+n,cmp);		//�԰�����Ʒ�� ��ֵ/���� �ı�ֵ����Ʒ��������
    double max=search(0,0,0);			//����ʼ��Ϊ0 
    cout<<"����ֵ��:"<<max<<endl;
    return 0;
}
