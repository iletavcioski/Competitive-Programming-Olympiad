#include <iostream>
#include <vector>
using namespace std;
int dp[601][601];
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> v1,v2;
	int k;
	cin>>k;
	for(int i=1;i<=600;i++)
	{
		for(int j=1;j<=600;j++)
			dp[i][j]=1e9;
	}
	for(int i=0;i<k;i++)
	{
		int a,b;
		cin>>a>>b;
		v1.push_back(a);
		v2.push_back(b);
		dp[a][b]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			
			for(int l=0;l<k;l++)
			{

				if(i-v1[l]>=0&&j-v2[l]>=0)
				{
					dp[i][j]=min(dp[i][j],min(dp[v1[l]][j-v2[l]]+dp[i-v1[l]][j],dp[i][j-v2[l]]+dp[i-v1[l]][v2[l]]));
				}

			}
			dp[i][j]=min(dp[i][j],min(dp[1][j-1]+dp[i-1][j]+1,dp[i-1][1]+dp[i][j-1]+1));
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}