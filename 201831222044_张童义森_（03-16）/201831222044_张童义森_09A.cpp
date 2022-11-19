/*
	功能：实现n皇后问题 
	编译人：张童义森
	编译环境：Dev-C++ 5.11
	编译日期：2020.5.3
	题目：输入皇后个数n，输出其解的个数 
	参考文献：屈婉玲《算法设计与分析（第2版）》
*/ 
#include <iostream>
using namespace std; 
#define MAX_Length 1024 
    int is_conflict(int *a,int n) 		//检查第n行的皇后与前n-1行的皇后是否有冲突 
	{ 
        int flag=0; 
        int i; 
        for(i=0;i<n;i++ ) 
            if(a[i]==a[n] || a[i]-a[n]==n-i || a[n]-a[i]==n-i ) //两皇后处于同一列，即a[i] == a[n] 
			{ 													//两皇后处于同一斜线，即|a[i]-a[n]| == |i - n| == n - i 
                flag = 1; 
                break; 
            } 
        return flag; 
    } 
   
    void print_board(int *a, int n) 		//输出皇后的排列 
	{ 
        int i,j; 
        for(i=0;i<n;i++) 
		{ 
            for(j=0;j<a[i];j++ ) 
                printf("口"); 
            printf("Q"); 
            for (j=a[i]+1;j<n;j++ ) 
                cout<<"口"; 
            cout<<endl;
        } 
        printf("---------------------------------");
		cout<<endl; 
    } 
   
    void init_board(int *a, int n) 			//初始化棋盘，所有皇后都在第0列
	{ 
        int i; 
        for(i=0;i<n;i++ ) 
            a[i]=0; 
    } 
   
    int queen(int n) 		//解决N皇后问题 
	{ 
        int count=0; 
        int a[MAX_Length]; 		//使用一个一维数组表示皇后的位置 ,其中数组的下标表示皇后所在的行 ,
								//数组元素的值表示皇后所在的列 ,这样设计的棋盘，所有皇后必定不在同一行 
        init_board(a, n); 
        int i=0; 
        while(1) 
		{ 
            if(a[i]<n ) 	// 如果皇后的位置尚未超出棋盘范围,需要检查第i行的皇后是否与前i-1行的皇后冲突 
			{ 
                if(is_conflict(a,i) ) 		// 如果冲突，尝试下一个位置 
				{ 
                    a[i]++; 
                    continue; 
                } 
                if(i>=n-1) 		// 如果已经到最后一行，也即找到一个解，首先输出它 
				{ 
                    count++; 
                    print_board(a, n); 		 // 然后尝试当前行的皇后的下一个位置 
                    a[n-1]++; 
                    continue; 
                } 
                i++;			// 没有冲突，尝试下一行  
                continue; 
            } 
            else 		// 皇后的位置已经超出棋盘范围 ,那么该行的皇后复位  
			{   
                a[i]=0; 	   
                i--; 			// 回退到上一行  
                if(i<0 ) 		// 已经不能再退了，函数结束 
                    return count; 
                a[i]++; 	// 尝试上一行的皇后的下个位置 
                continue; 
            } 
        } 
    } 
    int main() 
	{ 
        int n;
		cout<<"请输入皇后的个数:";
		cin>>n; 
        int count = queen(n); 
        cout<<n<<"皇后问题的解有:"<<count<<"种"<<endl;
        return 0; 
    }

