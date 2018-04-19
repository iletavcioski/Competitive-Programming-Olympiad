#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int inf = 1000000000;
vector<vector<pair<int,int> > > v;
vector<int> val;
vector<int> dist(101,0);
int dp[101][101][55];
void dfs(int x,int d)
{
    dist[x]=d;
    for(int i=0;i<v[x].size();i++)
    {
        dfs(v[x][i].first,d+v[x][i].second);
    }
}
int rec(int x,int sub,int nearest,int left)
{
    if(v[x].size()==sub)
    {
        if(sub>0)
        {
            if(left)
                return inf;
            else
                return 0;
        }
        else
        {
            if(left==0)
            {
                return val[x]*(dist[x]-dist[nearest]);
            }
            else if(left==1)
            {
                return 0;
            }
            else
            {
                return inf;
            }
        }
    }
    if(dp[v[x][sub].first][nearest][left]!=-1)
        return dp[v[x][sub].first][nearest][left];
    int res=inf;
    if(sub==0)
    {
        for(int i=0;i<left;i++)
        {
            res=min(res,rec(v[x][sub].first,0,x,i)+rec(x,sub+1,x,left-i-1));
        }
        for(int i=0;i<=left;i++)
        {
            res=min(res,rec(v[x][sub].first,0,nearest,i)+rec(x,sub+1,nearest,left-i)+(val[x]*(dist[x]-dist[nearest])));
        }
    }
    else
    {
        for(int i=0;i<=left;i++)
        {
            res=min(res,rec(v[x][sub].first,0,nearest,i)+rec(x,sub+1,nearest,left-i));
        }
    }
    return dp[v[x][sub].first][nearest][left]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n,k;
    cin>>n>>k;
    vector<pair<int,int> > vec;
    v.insert(v.begin(),n+1,vec);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int l=0;l<=k;l++)
            {
                dp[i][j][l]=-1;
            }
        }
    }
    val.push_back(0);
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        val.push_back(a);
        v[b].push_back(make_pair(i,c));
    }
    dfs(0,0);
    cout<<rec(0,0,0,k)<<endl;
    return 0;
}