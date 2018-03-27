#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> v;
vector<vector<int> > graf;
ll maxi;
int maxx;
ll vkupno;
ll dfs(int x,int prev)
{
	ll maxi1=0;
	ll brojac=0;
	bool cc=false;
	for(int i=0;i<graf[x].size();i++)
	{
		if(graf[x][i]!=prev)
		{
			ll broj1=dfs(graf[x][i],x);
			maxi1=max(maxi1,broj1);
			brojac+=broj1;
			cc=true;
		}
	}
	maxi1=max(maxi1,vkupno-brojac-v[x]);
	if(maxi1<maxi)
	{
		maxi=maxi1;
		maxx=x;
	}
	if(!cc)
		return v[x];
	return brojac+v[x];
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		v.push_back(a);
		vkupno+=a;
	}
	vector<int> vec;
	graf.insert(graf.begin(),n+1,vec);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	maxi=1e18;
	maxx=-1;
	ll a=dfs(0,-1);
	cout<<maxx<<endl;
	return 0;
}