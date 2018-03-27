#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n,m;
	cin>>m>>n;
	int x1,y1,x2,y2;
	cin>>y1>>x1>>y2>>x2;
	vector<string> v;
	static int dp[501][501][2];
	for(int i=0;i<2*n+1;i++)
	{
		string ss;
		cin>>ss;
		v.push_back(ss);
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			dp[i][j][0]=1000000000;
			dp[i][j][1]=1000000000;
		}
	}
	queue<int> qi;
	queue<int> qj;
	queue<int> qt;
	queue<int> qs;
	qi.push(x1);
	qj.push(y1);
	qt.push(0);
	qs.push(0);
	qi.push(x1);
	qj.push(y1);
	qt.push(1);
	qs.push(0);
	dp[x1][y1][0]=0;
	dp[x1][y1][1]=0;
	while(!qi.empty())
	{
		int topi=qi.front();
		qi.pop();
		int topj=qj.front();
		qj.pop();
		int tops=qs.front();
		qs.pop();
		int topt=qt.front();
		qt.pop();
		//cout<<topi<<" "<<topj<<" "<<topt<<" "<<tops<<endl;  
		if(topt==1)
		{
			if(2*topi<v.size())
			{
				if(topj-1>=0)
				{
					if(v[2*topi][topj-1]=='w'&&dp[topi][topj-1][0]>tops+1)
					{
						qi.push(topi);
						qj.push(topj-1);
						qs.push(tops+1);
						qt.push(0);
						dp[topi][topj-1][0]=tops+1;
					}
				}
				if(v[2*topi][topj]=='w'&&dp[topi][topj+1][0]>tops+1)
				{
					qi.push(topi);
					qj.push(topj+1);
					qs.push(tops+1);
					qt.push(0);
					dp[topi][topj+1][0]=tops+1;
				}
				
			}
			if(2*topi-1>=0)
			{
				if(v[2*topi-1][2*topj]=='w'&&dp[topi-1][topj][0]>tops+1)
				{
					qi.push(topi-1);
					qj.push(topj);
					qs.push(tops+1);
					qt.push(0);
					dp[topi-1][topj][0]=tops+1;
				}
				if(2*topj+1<v[2*topi-1].size())
				{
					if(v[2*topi-1][2*topj+1]=='w'&&dp[topi-1][topj+1][0]>tops+1)
					{
						qi.push(topi-1);
						qj.push(topj+1);
						qs.push(tops+1);
						qt.push(0);
						dp[topi-1][topj+1][0]=tops+1;
					}
				}
			}
			if(2*topi+1<v.size())
			{

				if(v[2*topi+1][2*topj]=='w'&&dp[topi+1][topj][0]>tops+1)
				{
					qi.push(topi+1);
					qj.push(topj);
					qs.push(tops+1);
					qt.push(0);
					dp[topi+1][topj][0]=tops+1;
				}
				if(2*topj-1>=0)
				{
					if(v[2*topi+1][2*topj-1]=='w'&&dp[topi+1][topj-1][0]>tops+1)
					{
						qi.push(topi+1);
						qj.push(topj-1);
						qs.push(tops+1);
						qt.push(0);
						dp[topi+1][topj-1][0]=tops+1;
					}
				}
			}
		}
		else
		{
			if(2*topi<v.size())
			{
				if(topj-1>=0)
				{
					if(v[2*topi][topj-1]=='b'&&dp[topi][topj-1][1]>tops+1)
					{
						qi.push(topi);
						qj.push(topj-1);
						qs.push(tops+1);
						qt.push(1);
						dp[topi][topj-1][1]=tops+1;
					}
				}
				if(v[2*topi][topj]=='b'&&dp[topi][topj+1][1]>tops+1)
				{						
					qi.push(topi);
					qj.push(topj+1);
					qs.push(tops+1);
					qt.push(1);
					dp[topi][topj+1][1]=tops+1;
				}
			}
			if(2*topi-1>=0)
			{
				if(v[2*topi-1][2*topj]=='b'&&dp[topi-1][topj][1]>tops+1)
				{
					qi.push(topi-1);
					qj.push(topj);
					qs.push(tops+1);
					qt.push(1);
					dp[topi-1][topj][1]=tops+1;
				}
				if(2*topj+1<v[2*topi-1].size())
				{
					if(v[2*topi-1][2*topj+1]=='b'&&dp[topi-1][topj+1][1]>tops+1)
					{
						qi.push(topi-1);
						qj.push(topj+1);
						qs.push(tops+1);
						qt.push(1);
						dp[topi-1][topj+1][1]=tops+1;
					}
				}
			}
			if(2*topi+1<v.size())
			{

				if(v[2*topi+1][2*topj]=='b'&&dp[topi+1][topj][1]>tops+1)
				{
					qi.push(topi+1);
					qj.push(topj);
					qs.push(tops+1);
					qt.push(1);
					dp[topi+1][topj][1]=tops+1;
				}
				if(2*topj-1>=0)
				{
					if(v[2*topi+1][2*topj-1]=='b'&&dp[topi+1][topj-1][1]>tops+1)
					{
						qi.push(topi+1);
						qj.push(topj-1);
						qs.push(tops+1);
						qt.push(1);
						dp[topi+1][topj-1][1]=tops+1;
					}
				}
			}
		}
	}
	cout<<min(dp[x2][y2][0],dp[x2][y2][1])<<endl;
	return 0;
}