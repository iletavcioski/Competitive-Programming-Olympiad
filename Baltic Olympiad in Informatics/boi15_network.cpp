#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector<vector<int> > v;
int brojac=0;
vector<int> toc;
void dfs(int x,int prev)
{
	
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=prev)
		dfs(v[x][i],x);
	if(v[x].size()==1)
		toc.push_back(x);
}
int main()
{
	int n;
	cin>>n;
	vector<int> vec;
	v.insert(v.begin(),n+1,vec);
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	brojac=0;
	for(int i=0;i<n;i++)
	{
		if(v[i].size()>1){
			dfs(i,-1);
		break;}
	}
	printf("%d\n",(toc.size()+1)/2);
	for(int i=0;i<(toc.size()+1)/2;i++)
	{
		printf("%d %d\n",toc[i]+1,toc[i+(toc.size())/2]+1);
	}
	return 0;
}