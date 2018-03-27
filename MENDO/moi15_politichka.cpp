#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll dp[2][50001];
vector<int> dag;
vector<vector<int> > v;
vector<int> d(50001,0);
vector<ll> dpsubtree(50001,0);
int brojac=0;
vector<ll> value(50001,0);
ll dfs(int x,int prev)
{
    d[x]=brojac;
    brojac++;
    dpsubtree[x]=value[x];
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=prev)
        {
            dpsubtree[x]+=dfs(v[x][i],x);
        }
    }
    d[x]=brojac-d[x];
    dag.push_back(x);
    return dpsubtree[x];
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        ll a;
        cin>>a;
        value[i]=a;
    }
    vector<int> vec;
    v.insert(v.begin(),n+2,vec);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int prev=0,next=1;
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        dp[prev][i]=dp[prev][i-1]+value[dag[i-1]];
    }
    for(int j=0;j<k;j++)
    {
        for(int i=1;i<=n;i++) {
            dp[next][i]=dp[prev][i];
            dp[next][i] = max(dp[next][i], dp[prev][i - d[dag[i - 1]]]);
        }
        for(int i=1;i<=n;i++)
        {
 
            dp[next][i]=max(dp[next][i],dp[next][i-1]+value[dag[i-1]]);
        }
        swap(prev,next);
    }
    cout<<dp[prev][n]<<endl;
    return 0;
}