#include <iostream>
#include <queue>
using namespace std;
int n,m;
char mat[4004][4004];
bool vis[4004][4004];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int brojac;
queue<pair<int,int> > q1,q2;
void bfs(queue<pair<int,int> > &q1,queue<pair<int,int> > &q2,int broj)
{
    if(q1.empty())
        return;
    brojac=broj;
    while(!q1.empty())
    {
        pair<int,int> g=q1.front();
        q1.pop();
        for(int i=0;i<4;i++)
        {
            if(g.first+dx[i]<n&&g.first+dx[i]>=0&&g.second+dy[i]<m&&g.second+dy[i]>=0)
            {
                if(!vis[g.first+dx[i]][g.second+dy[i]]&&mat[g.first+dx[i]][g.second+dy[i]]!='.')
                {
                    if(mat[g.first+dx[i]][g.second+dy[i]]!=mat[g.first][g.second])
                    {
                        q2.push(make_pair(g.first+dx[i],g.second+dy[i]));
                        vis[g.first+dx[i]][g.second+dy[i]]=true;
                    }
                    else
                    {
                        q1.push(make_pair(g.first+dx[i],g.second+dy[i]));
                        vis[g.first+dx[i]][g.second+dy[i]]=true;
                    }
                }
            }
        }
    }
    bfs(q2,q1,broj+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>mat[i];
    }
    q1.push(make_pair(0,0));
    vis[0][0]=true;
    bfs(q1,q2,1);
    cout<<brojac<<endl;
    return 0;
}