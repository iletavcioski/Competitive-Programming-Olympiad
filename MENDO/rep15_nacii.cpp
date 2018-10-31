#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<vector<int> > v;
bool visited[100005];
int brojac;
void dfs(int x)
{
    if(visited[x])
        return;
    visited[x]=true;
    brojac++;
    for(int i=0;i<v[x].size();i++)
        dfs(v[x][i]);
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> vec;
    memset(visited,0,sizeof(visited));
    v.insert(v.begin(),n+1,vec);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
       v[a].push_back(b);
       v[b].push_back(a);
    }
    vector<int> vk;
    ll zbir=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i]){
        brojac=0;
        dfs(i);
        zbir+=brojac;
        vk.push_back(brojac);
        }
    }
    ll res=0;
    for(int i=0;i<vk.size();i++)
    {
        res+=vk[i]*(zbir-vk[i]);
    }
    res/=2;
    cout<<res<<endl;
    return 0;
}