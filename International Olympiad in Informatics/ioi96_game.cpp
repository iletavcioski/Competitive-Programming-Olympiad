#include<iostream>
using namespace std;
int zbir[101][101];
int dp[101][101];
int main()
{
	int n;
	cin>>n;	
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		zbir[i][i]=a;
		dp[i][i]=a;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			zbir[i][j]=(zbir[i][j-1]+zbir[j][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j+i<n;j++)
		{
			dp[j][j+i]=(zbir[j][j+i]-min(dp[j+1][j+i],dp[j][j+i-1]));
		}
	}
	
	cout<<dp[0][n-1]<<" "<<zbir[0][n-1]-dp[0][n-1]<<endl;
	return 0;
}