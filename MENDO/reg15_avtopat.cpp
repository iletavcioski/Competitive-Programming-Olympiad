#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=999999999999999;
vector<vector<pair<int,ll> > >v;
vector<ll> dist(100009,inf);
vector<bool> visited(100001,false);
void dfs(int x)
{
    if(visited[x])
        return;
    visited[x]=true;
    for(int i=0;i<v[x].size();i++)
    {
        if(!visited[v[x][i].first])
        {
            if(x>v[x][i].first)
            {
                dist[v[x][i].first]=dist[x]-v[x][i].second;
                dfs(v[x][i].first);
            }
            else
            {
                dist[v[x][i].first]=dist[x]+v[x][i].second;
                dfs(v[x][i].first);
            }
        }
         
    }
}
int main()
{
    int t1,t2;
    cin>>t1>>t2;
    int n,m;
    cin>>n>>m;
    t1--;
    t2--;
    if(t1>t2)
        swap(t1,t2);
    vector<pair<int,ll> > vecc;
    v.insert(v.begin(),n+1,vecc);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        ll c;
        cin>>c;
            v[a].push_back(make_pair(b,c));
            v[b].push_back(make_pair(a,c));
         
    }
    dist[t1]=0;
    dfs(t1);
     
    if(dist[t2]==inf)
        cout<<-1<<endl;
    else
        cout<<dist[t2]<<endl;
    return 0;
}