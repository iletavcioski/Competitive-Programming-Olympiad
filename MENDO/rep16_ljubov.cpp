#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
char mat[1001][1001];
int n,m;
int dist[1001][1001];
int dist2[1001][1001];
void bfs(int i,int j)
{
    queue<int> qi;
    queue<int> qj;
    queue<int> qs;
    bool visited[1001][1001];
    memset(visited,false,sizeof(visited));
    qi.push(i);
    qj.push(j);
    qs.push(0);
    visited[i][j]=true;
    dist[i][j]=0;
    while(!qi.empty())
    {
        int topi=qi.front();
        qi.pop();
        int topj=qj.front();
        qj.pop();
        int tops=qs.front();
        qs.pop();
        if(topi+1<n&&!visited[topi+1][topj])
        {
            dist[topi+1][topj]=tops+1;
            if(mat[topi+1][topj]!='#')
            {
                qi.push(topi+1);
                qj.push(topj);
                qs.push(tops+1);
                 
            }
            visited[topi+1][topj]=true;
        }
        if(topj-1>=0&&!visited[topi][topj-1])
        {
            dist[topi][topj-1]=tops+1;
            if(mat[topi][topj-1]!='#')
            {
                qi.push(topi);
                qj.push(topj-1);
                qs.push(tops+1);
                 
            }
            visited[topi][topj-1]=true;
        }
        if(topj+1<m&&!visited[topi][topj+1])
        {
            dist[topi][topj+1]=tops+1;
            if(mat[topi][topj+1]!='#')
            {
                qi.push(topi);
                qj.push(topj+1);
                qs.push(tops+1);
                 
            }
            visited[topi][topj+1]=true;
        }
        if(topi-1>=0&&!visited[topi-1][topj])
        {
            dist[topi-1][topj]=tops+1;
            if(mat[topi-1][topj]!='#')
            {
                qi.push(topi-1);
                qj.push(topj);
                qs.push(tops+1);
                 
            }
            visited[topi-1][topj]=true;
        }
    }
}
int main()
{
    cin>>n>>m;
    memset(dist,0,sizeof(dist));
    int pi,pj,ei,ej;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
            if(mat[i][j]=='S'){
                pi=i;
                pj=j;
            }
            if(mat[i][j]=='E')
            {
                ei=i;
                ej=j;
            }
        }
    }
    bfs(ei,ej);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dist2[i][j]=dist[i][j];
            dist[i][j]=0;
        }
    }
    if(dist2[pi][pj]!=0)
    {
        cout<<dist2[pi][pj]<<endl;
    }
    else
    {
        int res=-1;
        bfs(pi,pj);
 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='#'&&dist[i][j]!=0&&dist2[i][j]!=0)
                {
                    res=max(res,(dist[i][j]+dist2[i][j]));
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}