#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct node
{
    int x;
    int broj;
    int b;
    int g;
};
int main()
{
    queue<node> qi;
    int n,m;
    cin>>n>>m;
    int k,l;
    cin>>k>>l;
    vector<vector<pair<int,int> > >v;
    vector<pair<int,int> >vec;
    v.insert(v.begin(),n+1,vec);
    int mm;
    cin>>mm;
    for(int i=0;i<mm;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    node g;
    g.x=0;
    g.broj=0;
    g.b=k;
    g.g=0;
    qi.push(g);
    static int dp[101][11][454];
    for(int i=0;i<101;i++)
    {
        for(int j=0;j<11;j++)
        {
            for(int k=0;k<454;k++)
            {
                dp[i][j][k]=10000000;
            }
        }
    }
    dp[0][k][0]=0;
    int maxi=1000000001;
    while(!qi.empty())
    {
        node g=qi.front();
        qi.pop();
        int topi=g.x;
        int tops=g.broj;
        int topk=g.b;
        int topg=g.g;
        if(topi==n-1)
        {
            maxi=min(maxi,tops);
            continue;
        }
        for(int i=0;i<v[topi].size();i++)
        {
            if(v[topi][i].first<m)
            {
                if(dp[v[topi][i].first][topk][0]>tops+v[topi][i].second)
                {
                    dp[v[topi][i].first][topk][0]=tops+v[topi][i].second;
                    node g;
                    g.x=v[topi][i].first;
                    g.broj=tops+v[topi][i].second;
                    g.b=topk;
                    g.g=0;
                    qi.push(g);
                }
                if(v[topi][i].second<=(l-topg)&&topg)
                    {
                        if(dp[v[topi][i].first][topk][0]>tops)
                        {
                            dp[v[topi][i].first][topk][0]=tops;
                            node g;
                            g.x=v[topi][i].first;
                            g.broj=tops;
                            g.b=topk;
                            g.g=0;
                            qi.push(g);
                        }
                    }
                if(v[topi][i].second<=l&&topk)
                {
                    if(dp[v[topi][i].first][topk-1][0]>tops)
                    {
                        dp[v[topi][i].first][topk-1][0]=tops;
                        node g;
                        g.x=v[topi][i].first;
                        g.broj=tops;
                        g.b=topk-1;
                        g.g=0;
                        qi.push(g);
                    }
                }
                 
            }
            else
            {
                if(topg==0)
                {
                    if(dp[v[topi][i].first][topk][0]>tops+v[topi][i].second)
                    {
                        dp[v[topi][i].first][topk][0]=tops+v[topi][i].second;
                        node g;
                        g.x=v[topi][i].first;
                        g.broj=tops+v[topi][i].second;
                        g.b=topk;
                        g.g=0;
                        qi.push(g);
                    }
                    if(v[topi][i].second<=(l-topg)&&topk)
                    {
                        if(dp[v[topi][i].first][topk-1][topg+v[topi][i].second]>tops)
                        {
                            dp[v[topi][i].first][topk-1][topg+v[topi][i].second]=tops;
                            node g;
                            g.x=v[topi][i].first;
                            g.broj=tops;
                            g.b=topk-1;
                            g.g=topg+v[topi][i].second;
                            qi.push(g);
                        }
                    }
                }
                else
                {
                    if(dp[v[topi][i].first][topk][0]>tops+v[topi][i].second)
                    {
                        dp[v[topi][i].first][topk][0]=tops+v[topi][i].second;
                        node g;
                        g.x=v[topi][i].first;
                        g.broj=tops+v[topi][i].second;
                        g.b=topk;
                        g.g=0;
                        qi.push(g);
                    }
                    if(v[topi][i].second<=(l-topg))
                    {
                        if(dp[v[topi][i].first][topk][topg+v[topi][i].second]>tops)
                        {
                            dp[v[topi][i].first][topk][topg+v[topi][i].second]=tops;
                            node g;
                            g.x=v[topi][i].first;
                            g.broj=tops;
                            g.b=topk;
                            g.g=topg+v[topi][i].second;
                            qi.push(g);
                        }
                    }
                    else if(topk)
                    {
                        if(dp[v[topi][i].first][topk-1][v[topi][i].second]>tops)
                        {
                            dp[v[topi][i].first][topk-1][v[topi][i].second]=tops;
                            node g;
                            g.x=v[topi][i].first;
                            g.broj=tops;
                            g.b=topk-1;
                            g.g=v[topi][i].second;
                            qi.push(g);
                        }
                    }
                }
            }
              
        }
    }
    cout<<maxi<<endl;
    return 0;
}