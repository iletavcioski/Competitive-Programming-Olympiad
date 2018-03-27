#include <iostream>
#include <queue>
using namespace std;
const int inf=1000000000;
struct node
{
	int i,s;
};
const bool operator<(const node &x,const node &y)
{
	return x.s>y.s;
}
int main()
{
	int n,m;
	cin>>n>>m;
	if((n+m)%2)
	{
		cout<<"NO SOLUTION"<<endl;
		return 0;
	}
	vector<pair<int,int> > vec;
	vector<vector<pair<int,int> > > v(n*m+100000,vec);
	for(int i=0;i<n;i++)
	{
		string ss;
		cin>>ss;
		for(int j=0;j<m;j++)
		{
			if((i+j)%2==0)
			{
				int a=i*(m+1)+j;
				int b=(i+1)*(m+1)+j+1;
				int d=0;
				if(ss[j]=='/')
					d=1;
				v[a].push_back(make_pair(b,d));
				v[b].push_back(make_pair(a,d));
			}
			else
			{
				int a=(i+1)*(m+1)+j;
				int b=i*(m+1)+j+1;
				int d=1;
				if(ss[j]=='/')
					d=0;
				v[a].push_back(make_pair(b,d));
				v[b].push_back(make_pair(a,d));
			}
		}
	}
	vector<int> dp(n*m+100000,inf);
	priority_queue<node> q;
	node g;
	g.i=0;
	g.s=0;
	q.push(g);
	while(!q.empty())
	{
		node g=q.top();
		q.pop();
		int topi=g.i;
		int tops=g.s;
		//cout<<topi<<" "<<tops<<endl;
		if(tops>=dp[topi])
			continue;
		dp[topi]=tops;
		for(int i=0;i<v[topi].size();i++)
		{
			g.s=tops+v[topi][i].second;
			g.i=v[topi][i].first;
			q.push(g);
		}
	}
	cout<<dp[n*(m+1)+m]<<endl;
	return 0;
}