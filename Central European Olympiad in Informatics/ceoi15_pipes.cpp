#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> p1(100001,-1);
vector<int> p2(100001,-1);
vector<vector<pair<int,int> > > v; 
vector<int> lo;
vector<int> ind;
int edges=0;
int broj=1;
int dsu1(int x)
{
    int px=x;
    while(p1[x]!=-1)
        x=p1[x];
    int y=x;
    while(px!=y)
    {
        int xx=p1[px];
        p1[px]=y,px=xx;
    }
    return x;
}
int dsu2(int x)
{
    int px=x;
    while(p2[x]!=-1)
        x=p2[x];
    int y=x;
    while(px!=y)
    {
        int xx=p2[px];
        p2[px]=y,px=xx;
    }
    return x;
}
void bridges(int x,int prev,int broj)
{
    lo[x]=broj;
    ind[x]=broj;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i].second==prev)
            continue;
        if(ind[v[x][i].first]==-1)
        {
            bridges(v[x][i].first,v[x][i].second,broj+1);
            lo[x]=min(lo[x],lo[v[x][i].first]);
            if(lo[v[x][i].first]>ind[x])
            {
                cout<<x+1<<" "<<v[x][i].first+1<<endl;
            }
        }
        else
            lo[x]=min(lo[x],ind[v[x][i].first]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > vec;
    v.insert(v.begin(),n,vec);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        int x=dsu1(a);
        int y=dsu1(b);
        if(x!=y)
        {
            p1[x]=y;
            v[a].push_back(make_pair(b,edges));
            v[b].push_back(make_pair(a,edges));
            edges++;
        }
        else
        {
            int x1=dsu2(a);
            int y1=dsu2(b);
            if(x1!=y1)
            {
                p2[x1]=y1;
                v[a].push_back(make_pair(b,edges));
                v[b].push_back(make_pair(a,edges));
                edges++;
            }
 
        }
    }
    p1.clear();
    p2.clear();
    for(int i=0;i<n;i++)
    {
        lo.push_back(0);
        ind.push_back(-1);
    }
    for(int i=0;i<n;i++)
    {
        if(ind[i]==-1)
        {
            bridges(i,-1,1);
        }
    }
    return 0;
}