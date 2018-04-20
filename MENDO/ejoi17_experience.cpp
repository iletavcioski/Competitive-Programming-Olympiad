#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> val;
vector<ll> dp1(100001,0);
vector<ll> dp2(100001,0);
vector<vector<int> > v;
void dfs(int x,int prev)
{
    ll maxi=-1e9;
    ll mini=1e9;
    ll brmaxi=-1e9;
    ll brmini=1e9;
    ll brojac=0;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=prev)
        {
            dfs(v[x][i],x);
            brojac+=max(dp1[v[x][i]],dp2[v[x][i]]);
        }
    }
    dp1[x]=brojac;
    dp2[x]=brojac;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=prev)
        {
            brojac-=max(dp1[v[x][i]],dp2[v[x][i]]);
            if(val[x]>=val[v[x][i]])
            {
                dp1[x]=max(dp1[x],dp1[v[x][i]]+brojac+val[x]-val[v[x][i]]);
            }
            if(val[x]<=val[v[x][i]])
            {
                dp2[x]=max(dp2[x],dp2[v[x][i]]+brojac+val[v[x][i]]-val[x]);
            }
            brojac+=max(dp1[v[x][i]],dp2[v[x][i]]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin>>n;
    vector<int> vec;
    v.insert(v.begin(),n+1,vec);
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        val.push_back(a);
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0,-1);
    cout<<max(dp1[0],dp2[0])<<endl;
    return 0;
}