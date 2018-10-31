#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> >v;
vector<bool> visited(100006,false);
vector<int> v1;
void dfs(int x)
{
    if(visited[x])
        return;
    visited[x]=true;
    v1.push_back(x);
    for(int i=0;i<v[x].size();i++)
    {
        dfs(v[x][i]);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    v.insert(v.begin(),n+1,vec);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0);
    vector<int> vk;
    for(int i=0;i<v1.size();i++)
    vk.push_back(v1[i]);
    v1.clear();
    dfs(n);
    reverse(v1.begin(),v1.end());
    for(int i=0;i<v1.size();i++)
    vk.push_back(v1[i]);
    cout<<vk[0];
    for(int i=1;i<vk.size();i++)
        cout<<" "<<vk[i];
    cout<<endl;
    return 0;
}