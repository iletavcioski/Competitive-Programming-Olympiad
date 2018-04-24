#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<vector<int> > v;
int n,m,k;
int broj;
int s[100005];
int e[100005];
int dfn[100005];
int par[17][100005];
int dep[100005];
int cnt[100005];
void dfs(int x,int p)
{
    broj++;
    dfn[x]=broj;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=p)
        {
            dep[v[x][i]]=dep[x]+1;
            par[0][v[x][i]]=x;
            dfs(v[x][i],x);
        }
    }
}
int lca(int s,int e)
{
    if(dep[s]<dep[e]) 
        swap(s, e);
    int dx=dep[s]-dep[e];
    for(int i=0;i<17;i++)
    {
        if((dx>>i)&1) 
            s=par[i][s];
    }
    for(int i=16;i>=0;i--)
    {
        if(par[i][s]!=par[i][e])
        {
            s=par[i][s];
            e=par[i][e];
        }
    }
    if(s==e) 
        return s;
    return par[0][s];
}
void upd(int s,int e)
{
    int l=lca(s,e);
    cnt[s]++;
    cnt[e]++;
    cnt[l]-=2;
}
void dfs2(int x,int p)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=p)
        {
            dfs2(v[x][i],x);
            cnt[x]+=cnt[v[x][i]];
        }
    }
}
int main()
{
    cin>>n>>m>>k;
    vector<int> vec;
    v.insert(v.begin(),n+1,vec);
    for(int i=0;i<n-1;i++)
    {
        cin>>s[i]>>e[i];
        v[s[i]].push_back(e[i]);
        v[e[i]].push_back(s[i]);
    }
    dfs(1,-1);
    for(int i=1;i<17;i++)
    {
        for(int j=1;j<=n;j++)
        {
            par[i][j]=par[i-1][par[i-1][j]];
        }
    }
    for(int i=0;i<m;i++)
    {
        int t;
        cin>>t;
        vector<int> g;
        for(int j=0;j<t;j++)
        {
            int a;
            cin>>a;
            g.push_back(a);
        }
        sort(g.begin(),g.end(),[&](const int &a, const int &b)
        {
            return dfn[a]<dfn[b];
        });
        for(int i=0;i<g.size();i++)
        {
            upd(g[i],g[(i+1)%g.size()]);
        }
    }
    dfs2(1,-1);
    vector<int> vkraj;
    for(int i=0;i<n-1;i++)
    {
        if(dfn[s[i]]>dfn[e[i]]) 
            swap(s[i],e[i]);
        if(cnt[e[i]]>=2*k) 
            vkraj.push_back(i+1);
    }
    cout<<vkraj.size()<<endl;
    for(int i=0;i<vkraj.size();i++)
    {
        if(i)
            cout<<" ";
        cout<<vkraj[i];
    }
    cout<<endl;
    return 0;
}