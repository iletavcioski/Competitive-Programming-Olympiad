#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
struct node
{
    int x;
    ll dist;
};
const bool operator<(const node &x,const node &y)
{
    return x.dist>y.dist;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n,m;
    cin>>n>>m;
    vector<ll> dp(n+1,1e18);
    vector<int> oznaceni(n+1,0);
    vector<ll> dp2(n+1,1e18);
    vector<vector<pair<int,ll> > > v;
    vector<pair<int,ll> > vec;
    v.insert(v.begin(),n+1,vec);
    for(int i=0;i<m;i++)
    {
        int a,b;
        ll c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int a;
        cin>>a;
        oznaceni[a]=true;
    }
    priority_queue<node> q;
    node g;
    g.dist=0;
    g.x=0;
    q.push(g);
    ll maxi=1e18;
    int maxx=-1;
    while(!q.empty())
    {
        g=q.top();
        q.pop();
        if(dp[g.x]<=g.dist)
        {
            continue;
        }
        else
        {
            dp[g.x]=g.dist;
            if(g.dist<maxi&&oznaceni[g.x]){
                maxi=g.dist;
                maxx=g.x;
            }
            for(int i=0;i<v[g.x].size();i++)
            {
                node g1;
                g1.dist=g.dist+v[g.x][i].second;
                g1.x=v[g.x][i].first;
                q.push(g1);
            }
        }
    }
    g.dist=0;
    g.x=maxx;
    q.push(g);
    ll brojac=maxi;
    while(!q.empty())
    {
        if(k==0)
            break;
        g=q.top();
        q.pop();
        if(dp2[g.x]<g.dist)
        {
            continue;
        }
        else
        {
            node g1;
            if(oznaceni[g.x]){
                k--;
                brojac+=g.dist;
                oznaceni[g.x]=0;
                g.dist=0;
            }
            dp2[g.x]=g.dist;
            for(int i=0;i<v[g.x].size();i++)
            {
                g1.dist=g.dist+v[g.x][i].second;
                g1.x=v[g.x][i].first;
                q.push(g1);
            }
        }
    }
    cout<<brojac<<endl;
    return 0;
}