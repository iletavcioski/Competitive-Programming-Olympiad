#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<vector<pair<ll,ll> > > v;
vector<int> oz(100001,0);
ll kraj=0;
pair<ll,ll> dfs(int x,int prev)
{
    ll brojac=0;
    ll maxi=0;
    bool cc=false;
    int broj=0;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i].first==prev)
            continue;
        pair<ll,ll> p=dfs(v[x][i].first,x);
        if(p.first)
        {
            cc=true;
            broj++;
            brojac+=min(v[x][i].second,p.second);
            maxi=max(maxi,min(v[x][i].second,p.second));
        }
    }
    
    if(oz[x])
    {
        kraj+=brojac;
        return make_pair(1,1e9);
    }
    else
    {
        kraj+=(brojac-maxi);
        return make_pair(cc,maxi);
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<pair<ll,ll> > vec;
    v.insert(v.begin(),n+1,vec);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        ll c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        oz[a]=true;
    }
    dfs(0,-1);
    cout<<kraj<<endl;
    return 0;
}