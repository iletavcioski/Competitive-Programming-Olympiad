#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> dp1(100001,0);
vector<int> dp2(100001,0);
vector<int> vis(100001,0);
vector<int> dpi(100001,0);
vector<vector<pair<int,int> > > v;
int brojac=0;
void dfs1(int x,int prev)
{
    dp1[x]=0;
    vis[x]=brojac;
    bool isleaf=false;
    for(int i=0;i<v[x].size();i++)
    {
        int next=v[x][i].first;
        int edge=v[x][i].second;
        if(next==prev)
            continue;
        isleaf=true;
        dfs1(next,x);
        if(dp1[x]<dp1[next]+edge)
        {
            dp2[x]=dp1[x];
            dp1[x]=dp1[next]+edge;
            dpi[x]=next;
        }
        else if(dp2[x]<dp1[next]+edge)
        {
            dp2[x]=dp1[next]+edge;
        }
    }
    if(!isleaf)
    {
        dpi[x]=x;
    }
    return ;
}
void dfs2(int x,int prev,int edge)
{
    if(prev==-1) {

        for(int i=0;i<v[x].size();i++)
        {
            if(v[x][i].first!=prev) {
                dfs2(v[x][i].first, x,v[x][i].second);
            }
        }
        return;
    }
    int krak=edge;
    if(dp1[prev]>dp2[prev])
    {
        if(dpi[prev]==x)
            krak+=dp2[prev];
        else
            krak+=dp1[prev];
    }
    else {
        krak += dp2[prev];
    }
    dp2[x]=max(dp2[x],krak);
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i].first!=prev) {
            dfs2(v[x][i].first, x,v[x][i].second);
        }
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int> > vec;
    v.insert(v.begin(),n+1,vec);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    for(int i=0;i<n;i++) {
        if(vis[i]==0) {
            brojac++;
            dfs1(i, -1);
            dfs2(i, -1,-1);
        }
    }
    vector<int> kraj(brojac,1e9);
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        kraj[vis[i]-1]=min(kraj[vis[i]-1],max(dp1[i],dp2[i]));
        maxi=max(maxi,dp1[i]+dp2[i]);
    }
    sort(kraj.begin(),kraj.end());
    reverse(kraj.begin(),kraj.end());
    if(kraj.size()>1) {
        maxi = max(maxi, kraj[0] + kraj[1] + k);
    }
    if(kraj.size()>2)
    {
        maxi = max(maxi, kraj[1] + kraj[2] + k+k);
    }
    cout<<maxi<<endl;
    return 0;
}