#include <iostream>
using namespace std;
int mat[202][202];
int dp[202][202][202];
int main()
{
	int n;
	cin>>n;
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		mat[a][b]=true;
		mat[b][a]=true;
	}
	int brojac=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(i==j||j==k||i==k)
					continue;
				if(dp[i][j][k])
					continue;
				if(!mat[i][j]&&!mat[i][k]&&!mat[j][k])
				{
					dp[i][j][k]=true;
					dp[i][k][j]=true;
					dp[j][k][i]=true;
					dp[j][i][k]=true;
					dp[k][i][j]=true;
					dp[k][j][i]=true;
					brojac++;
				}
			}
		}
	}
	cout<<brojac<<endl;
}