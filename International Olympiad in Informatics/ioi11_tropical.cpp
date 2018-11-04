#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<cassert>
using namespace std;
int best[150001][2];
int deg[150001];
int out[300003];
vector<vector<int> > v;
int dist[2][300003];
int n,m,p,len[2],src;
int visited[300003];
void dfs(int x)
{
	visited[x]=true;
	for(int i=0;i<v[x].size();i++)
	{
		if(visited[v[x][i]])
		{
			len[src]=dist[src][x]-dist[src][v[x][i]]+1;
			continue;
		}
		dist[src][v[x][i]]=dist[src][x]+1;
		dfs(v[x][i]);
	}
}
int order[150001];
pair<int,int> queries[2002];
int ct[300003];
int ans[2002];
int q;
int compare(int a,int b)
{
	return dist[src][a]<dist[src][b];
}
void init()
{
	vector<int> vec;
	v.insert(v.begin(),2*n+2,vec);
	memset(out,-1,sizeof(out));
	for(int i=0;i<n;i++)
	{
		int broj=i;
		for(int k=0;k<deg[i];k++,broj+=n)
		{
			out[broj]=best[i][k];
		}
	}
	for(int i=0;i<n*2;i++)
	{
		if(out[i]<0)
			continue;
		int broj=out[i];
		if(deg[broj]>=2&&(i%n)==best[broj][0]) 
			broj+=n;
		v[broj].push_back(i);
		out[i]=broj;
	}
	for(int i=0;i<n*2;i++) 
		dist[0][i]=dist[1][i]=1e9;
	len[0]=len[1]=1e9+1;
	for(int i=0;i<n;i++)
	{
		order[i]=i;
	}
	for(;src<2;src++)
	{
		memset(visited,0,sizeof(visited));
		dist[src][p+src*n]=0;
		dfs(p+src*n);
	}
	sort(queries,queries+q);
}
void compute()
{

	for(src=0;src<2;src++)
	{
		sort(order,order+n,compare);
		int k=0;
		memset(ct,0,sizeof(ct));
		for(int i=0;i<q;i++)
		{
			while(k<n&&dist[src][order[k]]<=queries[i].first)
			{
				int broj=dist[src][order[k++]];
				if(broj>=1e9)
					continue;
				ct[broj%len[src]]++;
			}
			ans[queries[i].second]+=(queries[i].first%len[src])>2*n?0:ct[queries[i].first%len[src]];
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(deg[b]<2)
		{
			best[b][deg[b]++]=a;
		}
		if(deg[a]<2)
		{
			best[a][deg[a]++]=b;
		}
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d",&queries[i].first);
		queries[i].second=i;
	}
	init();
	compute();
	for(int i=0;i<q;i++)
	{
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}