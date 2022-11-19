#include<iostream>
#include<cstring>
using namespace std;
void lcslen( int L[][100], char *X, char *Y, int m, int n)
{
    for (int i=0; i<=m; i++)
        for (int j=0; j<=n; j++)
        {
            if(i==0||j == 0)
                L[i][j] = 0;
            else if(X[i-1]==Y[j-1])		//X[i-1]为第i行 ，Y[j-1]为第j行列 
                L[i][j]=L[i-1][j-1]+1;		//第i行和第j列相等，则该表格[i，j]内的数为为表格[i-1，j-1]的数加 1 
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);		//否则 表格[i，j]内的数为在表格[i-1，j]和[i，j-1]之间取较大的数 
        }
}
void Lcs(int L[][100], char *X, char *Y, int m, int n)
{
    int index=L[m][n];		// l[m][n]存储lcs的长度 
    char lcs[index+1];		//lcs[index+1]来存储lcs字符串 
    lcs[index]='\0'; 
    int i=m,j=n;		
    while(i>0&&j>0)
    {
        if(X[i-1]==Y[j-1])				// 该表格上方的数等于左边的数
        {
            lcs[index-1] = X[i-1];		//储存该字符 
            i--; j--; index--;   		// 向左上方移动 
        }
        else if(L[i-1][j]>=L[i][j-1])		//该表格上方的数大于左边的数，上移 
            i--;
        else
            j--;		//表格上方的数小于左边的数，左移 
    }
    cout<<"其最长公共子序列的长度是: "<<L[m][n]<<endl;		 
    cout<<"其最长公共子序列是: "<<lcs;
}
int main()
{
    char X[20];
    char Y[20];
    cout<<"请输入一个序列："<<endl; 
	cin>>X; 
	cout<<"请再输入一个序列："<<endl; 
	cin>>Y; 
    int lenx=strlen(X),leny=strlen(Y);
    int L[100][100]; 
    lcslen(L,X,Y,lenx,leny);
    Lcs(L,X,Y,lenx,leny);
    return 0;
}

