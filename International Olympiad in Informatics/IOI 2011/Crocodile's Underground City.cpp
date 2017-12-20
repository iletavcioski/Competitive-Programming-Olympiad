#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
int main()
{
        ios_base::sync_with_stdio(false);
	int N,M,K;
	cin>>N>>M>>K;
	vector<vector<pair<ll,int> > > v;
	vector<ll> dp1(N+1,1e18);
	vector<ll> dp2(N+1,1e18);
	set<pair<ll,int> > s;
	vector<pair<ll,int> > vec;
	v.insert(v.begin(),N+1,vec);
	for(int i=0;i<M;i++)
	{
		int a,b;
		ll c;
		cin>>a>>b>>c;
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	for(int i=0;i<K;i++)
	{
		int a;
		cin>>a;
		s.insert(make_pair(0,a));
		dp1[a]=0;
		dp2[a]=0;
	}

	while(s.size())
	{
		pair<ll,int> p=(*s.begin());
		s.erase(*s.begin());
		int x=p.second;
		if(x==0)
		{
		    cout<<dp2[0]<<endl;
		    return 0;
		}
		for(int i=0;i<v[x].size();i++)
		{
			if(p.first+v[x][i].second<dp1[v[x][i].first])
			{
				s.erase(*s.find(make_pair(dp2[v[x][i].first],v[x][i].first)));
				s.insert(make_pair(dp1[v[x][i].first],v[x][i].first));
				dp2[v[x][i].first]=dp1[v[x][i].first];
				dp1[v[x][i].first]=p.first+v[x][i].second;
			}
			else if(p.first+v[x][i].second<dp2[v[x][i].first])
			{
				s.erase(*s.find(make_pair(dp2[v[x][i].first],v[x][i].first)));
				s.insert(make_pair(p.first+v[x][i].second,v[x][i].first));
				dp2[v[x][i].first]=p.first+v[x][i].second;
			}
		}
	}
	return 0;
}