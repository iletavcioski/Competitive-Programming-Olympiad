#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
int n;
vector<vector<int> > v;
ll val[100001];
vector<int> visi(100001+1,false);
void dfs(int x)
{
    if(visi[x])
        return;
    visi[x]=true;
    for(int i=0;i<v[x].size();i++)
    {
        if(!visi[v[x][i]])
        {
            val[v[x][i]]+=val[x];
            dfs(v[x][i]);
        }
    }
}
int main()
{
        ios_base::sync_with_stdio(false);
    int q;
    cin>>n>>q;
    vector<int> vec;
    v.insert(v.begin(),n+1,vec);
    vector<int> pocetok;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        val[i]=a;
        if(b==-1)
            pocetok.push_back(i);
        else
        v[b].push_back(i);
    }
    for(int i=0;i<pocetok.size();i++)
    {
        if(!visi[pocetok[i]])
            dfs(pocetok[i]);
    }
    int broj=0;
    for(int i=0;i<100000;i++)
    {
        if(!visi[i])
        {
            val[i]=1e18;
            broj++;
        }
    }
    n=100000;
    sort(val,val+n);
    n-=broj;
    for(int i=0;i<q;i++)
    {
        int a;
        cin>>a;
        int pos=lower_bound(val,val+n,a+1)-val-1;
        if(pos==-1)
            cout<<"none"<<endl;
        else
            cout<<val[pos]<<endl;
    }
    return 0;
}