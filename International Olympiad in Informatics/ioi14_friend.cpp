#include<iostream>
using namespace std;
int dp[100001][2];
int h[100001];
int p[100001];
int c[100001];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		dp[i][1]=c[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		cin>>h[i]>>p[i];
	}
	for(int i=n-1;i>0;i--)
	{
		if(p[i]==0)
		{
			dp[h[i]][1]+=dp[i][0];
			dp[h[i]][0]+=max(dp[i][0],dp[i][1]);
		}
		else if(p[i]==1)
		{
			dp[h[i]][1]=max(dp[h[i]][1]+max(dp[i][0],dp[i][1]),dp[h[i]][0]+dp[i][1]);
			dp[h[i]][0]+=dp[i][0];
		}
		else
		{
			dp[h[i]][1]=max(dp[h[i]][1]+dp[i][0],dp[h[i]][0]+dp[i][1]);
			dp[h[i]][0]+=dp[i][0];
		}
	}
	cout<<max(dp[0][0],dp[0][1])<<endl;
	return 0;
}