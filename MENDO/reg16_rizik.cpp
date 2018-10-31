#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >v;
vector<int> visited(100002,0);
vector<bool> vis(100002,false);
int paricki;
void dfs(int x)
{
    if(vis[x])
        return;
    if(visited[x]==0&&vis[x]==false)
    {
        paricki++;
    }
    vis[x]=true;
     
    for(int i=0;i<v[x].size();i++)
    {
        dfs(v[x][i]);
    }
 
}
int main()
{
    int n,a1,a2,k;
     
    cin>>n>>a1>>a2>>k;
     
    vector<int > vv;
    v.insert(v.begin(),n+1,vv);
    for(int i=0;i<a1;i++)
    {
        int a;
        cin>>a;
        a--;
        visited[a]=2;
        vv.push_back(a);
    }
    for(int i=0;i<a2;i++)
    {
        int a;
        cin>>a;
        a--;
        visited[a]=1;
        vis[a]=true;
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
 
    for(int i=0;i<vv.size();i++)
    {
        dfs(vv[i]);
    }
    cout<<min(paricki,k)<<endl;
    return 0;
}