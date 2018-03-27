#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second
vector<int> val;
vector<vector<int> > v;
vector<pair<int,int> > v1(300005,mp(-2e9+1,1e8+1));
vector<pair<int,int> > v2(300005,mp(-2e9+1,1e8+1));
pair<int,int> dfs1(int x,int prev)
{
    int maxi1=-2e9;
    int maxi2=-2e9;
    int ind1=1e9;
    int ind2=1e9;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]==prev)
            continue;
        pair<ll,int> b=dfs1(v[x][i],x);
        if(b.f-1>maxi1||(b.f-1==maxi1&&b.s<ind1))
        {
            maxi2=maxi1;
            ind2=ind1;
            maxi1=b.f-1;
            ind1=b.s;
        }
        else if(b.f-1>maxi2||(b.f-1==maxi2&&b.s<ind2))
        {
            maxi2=b.f-1;
            ind2=b.s;
        }
    }
	v1[x]=(mp(maxi1,ind1));
    v2[x]=(mp(maxi2,ind2));
	if(val[x]>maxi1||(val[x]==maxi1&&x<ind1))
	{
		    maxi2=maxi1;
		    ind2=ind1;
			maxi1=val[x];
			ind1=x;
	}
    return mp(maxi1,ind1);
}
void dfs2(int x,int prev)
{
    if(val[x]>v2[x].f||(val[x]==v2[x].f&&x<v2[x].s))
	{
		v2[x].first=val[x];
		v2[x].second=x;
	}
    if(prev==-1)
    {
        for(int i=0;i<v[x].size();i++)
		{
			if(v[x][i]!=prev)
				dfs2(v[x][i],x);
		}
        return;
    }
    
    ll maxi1=-2e9;
    int ind1=1e8;
    ll maxi2=-2e9;
    int ind2=1e8;
	if(v1[x].f>maxi1||(v1[x].f==maxi1&&v1[x].s<ind1))
        {
            if(v1[x].s!=ind1)
            {
                ind2=ind1;
                maxi2=maxi1;
            }
            maxi1=v1[x].f;
            ind1=v1[x].s;
        }
        else if(v1[x].f>maxi2||(v1[x].f==maxi2&&v1[x].s<ind2))
        {
            if(v1[x].s!=ind1)
            {
                maxi2=v1[x].f;
                ind2=v1[x].s;
            }
        }
	if(v2[x].f>maxi1||(v2[x].f==maxi1&&v2[x].s<ind1))
        {
            if(v2[x].s!=ind1)
            {
                ind2=ind1;
                maxi2=maxi1;
            }
            maxi1=v2[x].f;
            ind1=v2[x].s;
        }
        else if(v2[x].f>maxi2||(v2[x].f==maxi2&&v2[x].s<ind2))
        {
            if(v2[x].s!=ind1)
            {
                maxi2=v2[x].f;
                ind2=v2[x].s;
            }
        }
	if(v1[prev].f-1>maxi1||(v1[prev].f-1==maxi1&&v1[prev].s<ind1))
        {
            if(v1[prev].s!=ind1)
            {
                ind2=ind1;
                maxi2=maxi1;
            }
            maxi1=v1[prev].f-1;
            ind1=v1[prev].s;
        }
        else if(v1[prev].f-1>maxi2||(v1[prev].f-1==maxi2&&v1[prev].s<ind2))
        {
            if(v1[prev].s!=ind1)
            {
                maxi2=v1[prev].f-1;
                ind2=v1[prev].s;
            }
        }
	if(v2[prev].f-1>maxi1||(v2[prev].f-1==maxi1&&v2[prev].s<ind1))
        {
            if(v2[prev].s!=ind1)
            {
                ind2=ind1;
                maxi2=maxi1;
            }
            maxi1=v2[prev].f-1;
            ind1=v2[prev].s;
        }
        else if(v2[prev].f-1>maxi2||(v2[prev].f-1==maxi2&&v2[prev].s<ind2))
        {
            if(v2[prev].s!=ind1)
            {
                maxi2=v2[prev].f-1;
                ind2=v2[prev].s;
            }
        }
    v1[x]=mp(maxi1,ind1);
    v2[x]=mp(maxi2,ind2);
    for(int i=0;i<v[x].size();i++)
	{
		if(v[x][i]!=prev)
			dfs2(v[x][i],x);
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll k;
    cin>>k;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        val.pb(a);
    }
    vector<int> vec;
    v.insert(v.begin(),n+10,vec);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs1(0,-1);
    dfs2(0,-1);
    for(int i=0;i<n;i++)
    {
        if(v1[i].s==i)
            v1[i]=v2[i];
    }
    v2.clear();
    int poc=0;
    vector<int> vk;
    vk.pb(0);
    vector<int> vis(n+1,false);
    for(int i=0;i<=n+1;i++)
    {
        
        int nov=v1[poc].s;
        if(vis[nov])
        {
            vk.push_back(nov);
            break;
        }
        else
        {
            vis[nov]=true;
        vk.pb(nov);
		poc=nov;
        }
    }
    vector<int> cikl;
    int broj=0;
    bool cc=false;
    for(int i=0;i<vk.size();i++)
    {
        if(vk[i]==vk[vk.size()-1]&&!cc)
        {
            cc=true;
            cikl.push_back(vk[i]);
        }
        else if(vk[i]!=vk[vk.size()-1]&&cc)
        {
            cikl.push_back(vk[i]);
        }
        else
        broj++;
    }
	broj-=2;
    if(broj>=k)
    cout<<vk[k]+1<<endl;
    else
    {
        k-=(broj);
        ll kk=k%(cikl.size());
        kk--;
        if(kk==-1)
        kk=cikl.size()-1;
        cout<<cikl[kk]+1<<endl;
    }
    return 0;
}
/*
7
5
0 1 1 1 2 2 3
1 2
1 3
1 4
4 5
4 6
6 7
*/