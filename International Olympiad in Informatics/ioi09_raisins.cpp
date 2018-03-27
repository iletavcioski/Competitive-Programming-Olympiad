#include <iostream>
using namespace std;
typedef long long ll;
int mat[51][51];
ll dp[51][51][51][51];
int dp1[51][51];
ll mar(int a,int b,int c,int d)
{
	int a1=0,a2=0,a3=0;
	if(a-1>=0)
		a1=dp1[a-1][d];
	if(b-1>=0)
		a2=dp1[c][b-1];
	if(a-1>=0&&b-1>=0)
		a3=dp1[a-1][b-1];
	return (dp1[c][d]-a1-a2+a3);
}
ll rek(int x,int y,int a,int b)
{
	if(dp[x][y][a][b]!=1e18)
		return dp[x][y][a][b];
	ll maxi=1e18;
	for(int i=y+1;i<=b;i++)
	{
		maxi=min(maxi,rek(x,y,a,i-1)+rek(x,i,a,b));
	}
	for(int i=x+1;i<=a;i++)
	{
		maxi=min(maxi,rek(x,y,i-1,b)+rek(i,y,a,b));
	}
	dp[x][y][a][b]=(maxi+mar(x,y,a,b));
	//cout<<x<<" "<<y<<" "<<a<<" "<<b<<" "<<mar(x,y,a,b)<<endl;
	return dp[x][y][a][b];
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			dp1[i][j]=0;
	}
	for(int i=0;i<51;i++)
	{
		for(int j=0;j<51;j++)
		{
			for(int k=0;k<51;k++)
			{
				for(int l=0;l<51;l++)
					dp[i][j][k][l]=1e18;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>mat[i][j];
			dp[i][j][i][j]=mat[i][j];
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			dp1[i][j]+=mat[i][j];
			int a1=0;
			int a2=0;
			int a3=0;
			if(i-1>=0)
				a1=dp1[i-1][j];
			if(j-1>=0)
				a2=dp1[i][j-1];
			if(i-1>=0&&j-1>=0)
				a3=dp1[i-1][j-1];
			dp1[i][j]+=((a1+a2)-a3);
		}
	}
	

	rek(0,0,n-1,m-1);
	cout<<dp[0][0][n-1][m-1]-mar(0,0,n-1,m-1)<<endl;
	return 0;
}