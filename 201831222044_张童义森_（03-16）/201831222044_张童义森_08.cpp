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
            else if(X[i-1]==Y[j-1])		//X[i-1]Ϊ��i�� ��Y[j-1]Ϊ��j���� 
                L[i][j]=L[i-1][j-1]+1;		//��i�к͵�j����ȣ���ñ��[i��j]�ڵ���ΪΪ���[i-1��j-1]������ 1 
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);		//���� ���[i��j]�ڵ���Ϊ�ڱ��[i-1��j]��[i��j-1]֮��ȡ�ϴ���� 
        }
}
void Lcs(int L[][100], char *X, char *Y, int m, int n)
{
    int index=L[m][n];		// l[m][n]�洢lcs�ĳ��� 
    char lcs[index+1];		//lcs[index+1]���洢lcs�ַ��� 
    lcs[index]='\0'; 
    int i=m,j=n;		
    while(i>0&&j>0)
    {
        if(X[i-1]==Y[j-1])				// �ñ���Ϸ�����������ߵ���
        {
            lcs[index-1] = X[i-1];		//������ַ� 
            i--; j--; index--;   		// �����Ϸ��ƶ� 
        }
        else if(L[i-1][j]>=L[i][j-1])		//�ñ���Ϸ�����������ߵ��������� 
            i--;
        else
            j--;		//����Ϸ�����С����ߵ��������� 
    }
    cout<<"������������еĳ�����: "<<L[m][n]<<endl;		 
    cout<<"���������������: "<<lcs;
}
int main()
{
    char X[20];
    char Y[20];
    cout<<"������һ�����У�"<<endl; 
	cin>>X; 
	cout<<"��������һ�����У�"<<endl; 
	cin>>Y; 
    int lenx=strlen(X),leny=strlen(Y);
    int L[100][100]; 
    lcslen(L,X,Y,lenx,leny);
    Lcs(L,X,Y,lenx,leny);
    return 0;
}

