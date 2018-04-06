#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<vector<int> > v;
vector<vector<pair<int,int> > > graph;
int dp_lca[100001][18];
vector<int> dag;
vector<int> minsubtree(100001,1e9);
vector<int> visi(100001,0);
vector<int> dag2(100001,-1);
void dfs1(int x,int prev)
{
    minsubtree[x]=x;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=prev)
        {
            dfs1(v[x][i],x);
            graph[x].push_back(make_pair(minsubtree[v[x][i]],v[x][i]));
            minsubtree[x]=min(minsubtree[x],minsubtree[v[x][i]]);
        }
    }
}
void dfs2(int x,int prev)
{
    for(int i=0;i<graph[x].size();i++)
    {
        if(graph[x][i].second!=prev)
        {
            dfs2(graph[x][i].second,x);
            dp_lca[graph[x][i].second][0]=x;
        }
    }
    dag.push_back(x);
}
pair<int,int> lca(int x)
{
    int brojac=0;
    for(int i=17;i>=0;i--)
    {
        if(dp_lca[x][i]!=-1)
        {
            if(visi[dp_lca[x][i]])
            {
                x=dp_lca[x][i];
                brojac+=(1<<i);
            }
        }
            
    }
    return make_pair(x,brojac);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n,q;
    cin>>n>>q;
    int root=-1;
    vector<int> vec;
    v.insert(v.begin(),n+1,vec);
    vector<pair<int,int> > vec1;
    graph.insert(graph.begin(),n+1,vec1);
    set<pair<int,int> > s;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(!a)
            root=i+1;
        v[a].push_back(i+1);
    }
    for(int j=1;j<18;j++)
    {
        for(int i=0;i<=n;i++)
        {
            dp_lca[i][j]=-1;
        }
    }
    dfs1(root,0);
    for(int i=0;i<=n;i++)
    {
        sort(graph[i].begin(),graph[i].end());
    }
    dfs2(root,0);
    for(int j=1;j<18;j++)
    {
        for(int i=0;i<=n;i++)
        {
            if(dp_lca[i][j-1]!=-1)
            {
                dp_lca[i][j]=dp_lca[dp_lca[i][j-1]][j-1];
            }
        }
    }
    for(int i=0;i<dag.size();i++)
    {
        s.insert(make_pair(i+1,dag[i]));
        dag2[dag[i]]=i+1;
    }
    for(int i=0;i<q;i++)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int num;
            cin>>num;
            int last;
            while(num--)
            {
                pair<int,int> par=*s.begin();
                s.erase(s.begin());
                last=par.second;
                visi[par.second]=true;
                if(s.size()==0)
                    break;
            }
            cout<<last<<endl;
        }
        else
        {
            int pos;
            cin>>pos;
            s.erase(*s.find(make_pair(dag2[pos],pos)));
            pair<int,int> par=lca(pos);
            cout<<par.second<<endl;
            visi[par.first]=false;
            s.insert(make_pair(dag2[par.first],par.first));
        }
    }
    return 0;
}
