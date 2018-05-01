#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf=999999999;
int dp[18][(1<<18)+1];
int dist[18][18];
vector<vector<pair<int,int> > > v;
int n,m,k;
void dijkstra(int pocetok,int kraj,int ii,int jj)
{
    queue<int> qi;
    qi.push(pocetok);
    int dis[40004];
   for(int i=0;i<n;i++)
    dis[i]=inf;
    dis[pocetok]=0;
    while(!qi.empty())
    {
        int topi=qi.front();
        qi.pop();
        for(int i=0;i<v[topi].size();i++)
        {
            if(dis[topi]+v[topi][i].second<dis[v[topi][i].first])
            {
                dis[v[topi][i].first]=dis[topi]+v[topi][i].second;
                qi.push(v[topi][i].first);
            }
        }
    }
    dist[ii][jj]=dis[kraj];
    dist[jj][ii]=dis[kraj];
}
void tsp(int p1,int bitmask)
{
    for(int i=0;i<k;i++)
    {
        if((bitmask&(1<<i))==0)
        {
            int cc=(bitmask|(1<<i));
            if(dp[i][cc]>dp[p1][bitmask]+dist[p1][i])
            {
                dp[i][cc]=dp[p1][bitmask]+dist[p1][i];
                tsp(i,cc);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
   cin>>n>>k>>m;
    vector<pair<int,int> > vecc;
   v.insert(v.begin(),n+3,vecc);
   vector<int> vk;
   vk.push_back(0);
   for(int i=0;i<k;i++)
   {
       int a;
       cin>>a;
       vk.push_back(a);
   }
   for(int i=0;i<m;i++)
   {
       int a,b,c;
       cin>>a>>b>>c;
       v[a].push_back(make_pair(b,c));
       v[b].push_back(make_pair(a,c));
   }
   k++;
   for(int i=0;i<=k;i++)
   {
       for(int j=0;j<=k;j++)
        dist[i][j]=0;
   }
   for(int i=0;i<=k;i++)
   {
       for(int j=0;j<=(1<<(k+1))+1;j++)
        dp[i][j]=inf;
   }
   for(int i=0;i<k;i++)
   {
       for(int j=i+1;j<k;j++)
       {
           dijkstra(vk[i],vk[j],i,j);
       }
   }
 
   dp[0][1<<0]=0;
   tsp(0,(1<<0));
   int res=inf;
   for(int i=1;i<k;i++)
   {
       res=min(res,dp[i][(1<<k)-1]+dist[i][0]);
   }
   cout<<res<<endl;
    return 0;
}