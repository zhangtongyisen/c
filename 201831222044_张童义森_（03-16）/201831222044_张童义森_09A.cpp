/*
	���ܣ�ʵ��n�ʺ����� 
	�����ˣ���ͯ��ɭ
	���뻷����Dev-C++ 5.11
	�������ڣ�2020.5.3
	��Ŀ������ʺ����n��������ĸ��� 
	�ο����ף������ᡶ�㷨������������2�棩��
*/ 
#include <iostream>
using namespace std; 
#define MAX_Length 1024 
    int is_conflict(int *a,int n) 		//����n�еĻʺ���ǰn-1�еĻʺ��Ƿ��г�ͻ 
	{ 
        int flag=0; 
        int i; 
        for(i=0;i<n;i++ ) 
            if(a[i]==a[n] || a[i]-a[n]==n-i || a[n]-a[i]==n-i ) //���ʺ���ͬһ�У���a[i] == a[n] 
			{ 													//���ʺ���ͬһб�ߣ���|a[i]-a[n]| == |i - n| == n - i 
                flag = 1; 
                break; 
            } 
        return flag; 
    } 
   
    void print_board(int *a, int n) 		//����ʺ������ 
	{ 
        int i,j; 
        for(i=0;i<n;i++) 
		{ 
            for(j=0;j<a[i];j++ ) 
                printf("��"); 
            printf("Q"); 
            for (j=a[i]+1;j<n;j++ ) 
                cout<<"��"; 
            cout<<endl;
        } 
        printf("---------------------------------");
		cout<<endl; 
    } 
   
    void init_board(int *a, int n) 			//��ʼ�����̣����лʺ��ڵ�0��
	{ 
        int i; 
        for(i=0;i<n;i++ ) 
            a[i]=0; 
    } 
   
    int queen(int n) 		//���N�ʺ����� 
	{ 
        int count=0; 
        int a[MAX_Length]; 		//ʹ��һ��һά�����ʾ�ʺ��λ�� ,����������±��ʾ�ʺ����ڵ��� ,
								//����Ԫ�ص�ֵ��ʾ�ʺ����ڵ��� ,������Ƶ����̣����лʺ�ض�����ͬһ�� 
        init_board(a, n); 
        int i=0; 
        while(1) 
		{ 
            if(a[i]<n ) 	// ����ʺ��λ����δ�������̷�Χ,��Ҫ����i�еĻʺ��Ƿ���ǰi-1�еĻʺ��ͻ 
			{ 
                if(is_conflict(a,i) ) 		// �����ͻ��������һ��λ�� 
				{ 
                    a[i]++; 
                    continue; 
                } 
                if(i>=n-1) 		// ����Ѿ������һ�У�Ҳ���ҵ�һ���⣬��������� 
				{ 
                    count++; 
                    print_board(a, n); 		 // Ȼ���Ե�ǰ�еĻʺ����һ��λ�� 
                    a[n-1]++; 
                    continue; 
                } 
                i++;			// û�г�ͻ��������һ��  
                continue; 
            } 
            else 		// �ʺ��λ���Ѿ��������̷�Χ ,��ô���еĻʺ�λ  
			{   
                a[i]=0; 	   
                i--; 			// ���˵���һ��  
                if(i<0 ) 		// �Ѿ����������ˣ��������� 
                    return count; 
                a[i]++; 	// ������һ�еĻʺ���¸�λ�� 
                continue; 
            } 
        } 
    } 
    int main() 
	{ 
        int n;
		cout<<"������ʺ�ĸ���:";
		cin>>n; 
        int count = queen(n); 
        cout<<n<<"�ʺ�����Ľ���:"<<count<<"��"<<endl;
        return 0; 
    }

