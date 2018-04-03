#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<vector<int> > v;
int n;
ll k;
vector<ll> val;
int res=0;
ll dfs(int x,int prev)
{
    vector<ll> vk;
    ll brojac=val[x];
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=prev)
        {
            ll a=dfs(v[x][i],x);
            brojac+=a;
            vk.push_back(a);
        }
    }
    sort(vk.begin(),vk.end());
    reverse(vk.begin(),vk.end());
    int i=0;
    while(brojac>k&&i<vk.size())
    {
        res++;
        brojac-=vk[i];
        i++;
    }
    return brojac;
}
int main()
{
    cin>>n>>k;
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
    cout<<res<<endl;
    return 0;
}