#include <iostream>
#include <queue>
using namespace std;
int n,t;
int dp[808][808];
char mat[808][808];
int pi,pj,ei,ej;
queue<int> qi1;
queue<int> qj1;
queue<int> qs1;
bool visi[808][808];
void bfs1()
{

	while(!qi1.empty())
	{
		int topi=qi1.front();
		qi1.pop();
		int topj=qj1.front();
		qj1.pop();
		int tops=qs1.front();
		qs1.pop();
		if(topi==ei&&ej==topj)
			continue;
		if(topi+1<n&&mat[topi+1][topj]!='T'&&!visi[topi+1][topj])
		{
			qi1.push(topi+1);
			qj1.push(topj);
			qs1.push(tops+t);
			dp[topi+1][topj]=tops+t;
			visi[topi+1][topj]=true;
		}
		if(topj-1>=0&&mat[topi][topj-1]!='T'&&!visi[topi][topj-1])
		{
			qi1.push(topi);
			qj1.push(topj-1);
			qs1.push(tops+t);
			dp[topi][topj-1]=tops+t;
			visi[topi][topj-1]=true;
		}
		if(topj+1<n&&mat[topi][topj+1]!='T'&&!visi[topi][topj+1])
		{
			qi1.push(topi);
			qj1.push(topj+1);
			qs1.push(tops+t);
			dp[topi][topj+1]=tops+t;
			visi[topi][topj+1]=true;
		}
		if(topi-1>=0&&mat[topi-1][topj]!='T'&&!visi[topi-1][topj])
		{
			qi1.push(topi-1);
			qj1.push(topj);
			qs1.push(tops+t);
			dp[topi-1][topj]=tops+t;
			visi[topi-1][topj]=true;
		}
	}
}
bool visited[808][808];
void init()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			visited[i][j]=0;
	}
}
bool mozi(int pocetok)
{
	
	init();
	queue<int> qi;
	queue<int> qj;
	queue<int> qs;
	qi.push(pi);
	qj.push(pj);
	qs.push(pocetok);
	visited[pi][pj]=true;
	while(!qi.empty())
	{
		int topi=qi.front();
		qi.pop();
		int topj=qj.front();
		qj.pop();
		int tops=qs.front();
		qs.pop();
		if(tops>=dp[topi][topj])
			continue;
		if(topi==ei&&topj==ej)
			return true;
		if(topi+1<n&&dp[topi+1][topj]>tops+1&&!visited[topi+1][topj]&&mat[topi+1][topj]!='T')
		{
			qi.push(topi+1);
			qj.push(topj);
			qs.push(tops+1);
			visited[topi+1][topj]=true;
		}
		if(topj-1>=0&&dp[topi][topj-1]>tops+1&&!visited[topi][topj-1]&&mat[topi][topj-1]!='T')
		{
			qi.push(topi);
			qj.push(topj-1);
			qs.push(tops+1);
			visited[topi][topj-1]=true;
		}
		if(topi-1>=0&&dp[topi-1][topj]>tops+1&&!visited[topi-1][topj]&&mat[topi-1][topj]!='T')
		{
			qi.push(topi-1);
			qj.push(topj);
			qs.push(tops+1);
			visited[topi-1][topj]=true;
		}
		if(topj+1<n&&dp[topi][topj+1]>tops+1&&!visited[topi][topj+1]&&mat[topi][topj+1]!='T')
		{
			qi.push(topi);
			qj.push(topj+1);
			qs.push(tops+1);
			visited[topi][topj+1]=true;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>t;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
			if(mat[i][j]=='H'){
				qi1.push(i);
				qj1.push(j);
				qs1.push(0);
				visi[i][j]=1;
				dp[i][j]=0;
			}
			else{
					dp[i][j]=-1;
			}
			if(mat[i][j]=='M'){
				pi=i;
			pj=j;
			}
			if(mat[i][j]=='D')
			{
				ei=i;
			ej=j;
		}
		}
	}
	bfs1();
	dp[ei][ej]=n*n*t;
	int l=-1;
	int r=n*n*2;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(mozi(mid*t))
			l=mid;
		else
			r=mid;
	}
	cout<<l<<endl;
	return 0;
}