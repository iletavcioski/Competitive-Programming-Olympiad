#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	int mat[3010][3010];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cin>>mat[i][j];
	}
	int l=1;
	int r=n*m;
	while(l<r)
	{
		int mid=(l+r)/2;
		int dp[3010][3010];
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
				dp[i][j]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(mat[i][j]<=mid)
					dp[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
			}
		}
		bool cc=false;
		for(int i=a;i<=n;i++)
		{
			for(int j=b;j<=m;j++)
			{
				int brojac=dp[i][j]-dp[i-a][j]-dp[i][j-b]+dp[i-a][j-b];
				if(brojac>((a*b)/2)){
					cc=true;
					break;
				}
			}
		}
		if(cc)
			r=mid;
		else
			l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}