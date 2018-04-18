#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<vector<int> > v;
vector<int> val;
vector<vector<int> > rv;
vector<int> scc(500001,0);
vector<bool> vis(500001,0);
vector<bool> oz(500001,0);
vector<vector<int> > vc; 
pair<int,int> mem[500001];
vector<int> valscc(500001,0);
int br;
stack<int> st;
void dfs(int x)
{
    if(vis[x])
        return;
    vis[x]=true;
    for(int i=0;i<v[x].size();i++)
    {
        dfs(v[x][i]);
    }
    st.push(x);
}
void rdfs(int x)
{
    if(scc[x])
        return;
    scc[x]=br;
    for(int i=0;i<rv[x].size();i++)
    {
        rdfs(rv[x][i]);
    }
}
pair<int,int> rec(int x)
{
    if(mem[x].first!=-1)
        return mem[x];
    int a=0,res=0;
    for(int i=0;i<vc[x].size();i++)
    {
        pair<int,int> k=rec(vc[x][i]);
        if(k.first)
            a=true,res=max(res,k.second);
    }
    if(a)
    {
        return mem[x]=make_pair(1,valscc[x]+res);
    }
    else if(oz[x])
    {
        return mem[x]=make_pair(1,valscc[x]);
    }
    else if(!oz[x]&&!a)
    {
        return mem[x]=make_pair(0,0);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> vec;
    v.insert(v.begin(),n+1,vec);
    rv.insert(rv.begin(),n+1,vec);
    vc.insert(vc.begin(),n+1,vec);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        rv[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        val.push_back(c);
        mem[i]=make_pair(-1,-1);
    }
    
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            dfs(i);
    }
    vis.clear();
    while(!st.empty())
    {
        int topi=st.top();
        st.pop();
        if(!scc[topi])
        {
            br++;
            rdfs(topi);
        }
    }
    rv.clear();
    for(int i=0;i<n;i++)
    {
        valscc[scc[i]]+=val[i];
    }
    val.clear();
    for(int i=0;i<n;i++)
    {
        vis[i+1]=false;
        vis[i]=false;
        for(int j=0;j<v[i].size();j++)
        {
            if(scc[i]!=scc[v[i][j]])
            {
                vc[scc[i]].push_back(scc[v[i][j]]);
            }
        }
    }
    scc.clear();
    int s,p;
    cin>>s>>p;
    s--;
    for(int i=0;i<p;i++)
    {
        int x;
        cin>>x;
        x--;
        oz[scc[x]]=true;
    }
    cout<<rec(scc[s]).second<<endl;
    return 0;
}