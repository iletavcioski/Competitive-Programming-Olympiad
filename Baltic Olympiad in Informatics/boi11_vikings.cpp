#include <iostream>
#include <queue>
using namespace std;
const int inf=1000000000;
int dp[701][701];
int vis[701][701];
int vis2[701][701];
char mat[701][701];
int main()
{
	int n,m;
	cin>>n>>m;
	int vi,vj,pi,pj,ki,kj;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>mat[i][j];
			if(mat[i][j]=='V')
			{
				vi=i;
				vj=j;
			}
			else if(mat[i][j]=='Y')
			{
				pi=i;
				pj=j;
			}
			else if(mat[i][j]=='T')
			{
				ki=i;
				kj=j;
			}
			vis[i][j]=inf;
			dp[i][j]=inf;
		}
	}
	queue<int> qi;
	queue<int> qj;
	queue<int> qs;
	qi.push(vi);
	qj.push(vj);
	qs.push(0);
	vis[vi][vj]=0;
	while(!qi.empty())
	{
		int topi=qi.front();
		qi.pop();
		int topj=qj.front();
		qj.pop();
		int tops=qs.front();
		qs.pop();
		if(topi+1<n&&vis[topi+1][topj]==inf&&mat[topi+1][topj]!='I')
		{
			vis[topi+1][topj]=tops+1;
			qi.push(topi+1);
			qj.push(topj);
			qs.push(tops+1);
		}
		if(topi-1>=0&&vis[topi-1][topj]==inf&&mat[topi-1][topj]!='I')
		{
			vis[topi-1][topj]=tops+1;
			qi.push(topi-1);
			qj.push(topj);
			qs.push(tops+1);
		}
		if(topj+1<m&&vis[topi][topj+1]==inf&&mat[topi][topj+1]!='I')
		{
			vis[topi][topj+1]=tops+1;
			qi.push(topi);
			qj.push(topj+1);
			qs.push(tops+1);
		}
		if(topj-1>=0&&vis[topi][topj-1]==inf&&mat[topi][topj-1]!='I')
		{
			vis[topi][topj-1]=tops+1;
			qi.push(topi);
			qj.push(topj-1);
			qs.push(tops+1);
		}
	}
	
	for(int i=0;i<n;i++)
	{
		int mini=inf;
		int pr=0;
		int j=0;
		while(j<m)
		{
			
			mini=min(mini,vis[i][j]);
			if(j==m-1)
			{
				for(int k=j;k>=pr;k--)
				{
					dp[i][k]=mini;
				}
				if(mat[i][j]=='I')
					dp[i][j]=inf;
				break;
			}
			else if(mat[i][j]=='I')
			{
				for(int k=j-1;k>=pr;k--)
				{
					dp[i][k]=mini;
				}
				pr=j+1;
				dp[i][j]=inf;
				mini=inf;
			}
			j++;
		}
	}
	
	for(int j=0;j<m;j++)
	{
		int mini=inf;
		int pr=0;
		int i=0;
		while(i<n)
		{
			mini=min(mini,vis[i][j]);
			if(i==n-1)
			{
				for(int k=i;k>=pr;k--)
				{
					dp[k][j]=min(dp[k][j],mini);
				}
				if(mat[i][j]=='I')
					dp[i][j]=inf;
				break;
			}
			else if(mat[i][j]=='I')
			{
				for(int k=i-1;k>=pr;k--)
				{
					dp[k][j]=min(dp[k][j],mini);
				}
				pr=i+1;
				dp[i][j]=inf;
				mini=inf;
			}
			i++;
		}
	}
	
	while(!qi.empty())
	{
		qi.pop();
	}
	while(!qj.empty())
	{
		qj.pop();
	}
	while(!qs.empty())
	{
		qs.pop();
	}
	qi.push(pi);
	qj.push(pj);
	qs.push(0);
	while(!qi.empty())
	{
		int topi=qi.front();
		qi.pop();
		int topj=qj.front();
		qj.pop();
		int tops=qs.front();
		qs.pop();
		//cout<<topi<<" "<<topj<<" "<<tops<<endl;
		if(tops>=dp[topi][topj]&&tops!=0)
		{
			continue;
		}
		if(topi==ki&&topj==kj)
		{
			cout<<"YES"<<endl;
			return 0;
		}
		if(topi+1<n&&!vis2[topi+1][topj]&&mat[topi+1][topj]!='I')
		{
			vis2[topi+1][topj]=true;
			qi.push(topi+1);
			qj.push(topj);
			qs.push(tops+1);
		}
		if(topi-1>=0&&!vis2[topi-1][topj]&&mat[topi-1][topj]!='I')
		{
			vis2[topi-1][topj]=true;
			qi.push(topi-1);
			qj.push(topj);
			qs.push(tops+1);
		}
		if(topj+1<m&&!vis2[topi][topj+1]&&mat[topi][topj+1]!='I')
		{
			vis2[topi][topj+1]=true;
			qi.push(topi);
			qj.push(topj+1);
			qs.push(tops+1);
		}
		if(topj-1>=0&&!vis2[topi][topj-1]&&mat[topi][topj-1]!='I')
		{
			vis2[topi][topj-1]=true;
			qi.push(topi);
			qj.push(topj-1);
			qs.push(tops+1);
		}
	}
	cout<<"NO"<<endl;
	return 0;
}