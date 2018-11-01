#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
char mat[100][100];
bool visited[100][100];
bool bfsvisited[100][100];
int matt[100][100];
int n,m;
int brojac;
int iii;
int jjj;
void floodfill(int x,int y)
{
    if(visited[x][y]||mat[x][y]!='x')
        return;
    matt[x][y]=brojac;
    visited[x][y]=true;
    if(x+1<n)
    floodfill(x+1,y);
    if(x-1>=0)
    floodfill(x-1,y);
    if(y+1<m)
    floodfill(x,y+1);
    if(y-1>=0)
    floodfill(x,y-1);
    if(x-1>=0&&y-1>=0)
        floodfill(x-1,y-1);
    if(x-1>=0&&y+1<m)
        floodfill(x-1,y+1);
    if(x+1<n&&y-1>=0)
        floodfill(x+1,y-1);
    if(x+1<n&&y+1<m)
        floodfill(x+1,y+1);
}
bool BFS(int ii,int jj)
{
    queue<int>qi;
    queue<int>qj;
    qi.push(ii);
    qj.push(jj);
    int topi,topj;
    memset(bfsvisited,false,sizeof(bfsvisited));
    bfsvisited[ii][jj]=true;
    while(!qi.empty())
    {
        topi=qi.front();
        qi.pop();
        topj=qj.front();
        qj.pop();
        if(topi==n-1||topj==m-1||topi==0||topj==0)
        {
            iii=-1;
            return false;
        }
        if(topi-1>=0&&!bfsvisited[topi-1][topj])
        {
            if(mat[topi-1][topj]=='.'||matt[topi-1][topj]==matt[topi][topj])
            {
                qi.push(topi-1);
                qj.push(topj);
                bfsvisited[topi-1][topj]=true;
            }
            else
                iii=min(iii,matt[topi-1][topj]);
        }
        if(topj+1<m&&!bfsvisited[topi][topj+1])
        {
            if(mat[topi][topj+1]=='.'||matt[topi][topj+1]==matt[topi][topj])
            {
                qi.push(topi);
                qj.push(topj+1);
                bfsvisited[topi][topj+1]=true;
            }
            else
                iii=min(iii,matt[topi][topj+1]);
        }
        if(topi+1<n&&!bfsvisited[topi+1][topj])
        {
            if(mat[topi+1][topj]=='.'||matt[topi+1][topj]==matt[topi][topj])
            {
                qi.push(topi+1);
                qj.push(topj);
                bfsvisited[topi+1][topj]=true;
            }
            else
                iii=min(iii,matt[topi+1][topj]);
        }
        if(topj-1>=0&&!bfsvisited[topi][topj-1])
        {
            if(mat[topi][topj-1]=='.'||matt[topi][topj-1]==matt[topi][topj])
            {
                qi.push(topi);
                qj.push(topj-1);
                bfsvisited[topi][topj-1]=true;
            }
            else
                iii=min(iii,matt[topi][topj-1]);
        }
    }
    return true;
   
}
void floodfill2(int x,int y)
{
    if(visited[x][y]||mat[x][y]!='x')
        return;
     jjj=matt[x][y];
    visited[x][y]=true;
    bool kkkkk=BFS(x,y);
    if(!kkkkk)
    {
        iii=-1;
        return;
    }
    if(x+1<n&&matt[x+1][y]==matt[x][y])
    floodfill2(x+1,y);
    if(x-1>=0&&matt[x-1][y]==matt[x][y])
    floodfill2(x-1,y);
    if(y+1<m&&matt[x][y+1]==matt[x][y])
    floodfill2(x,y+1);
    if(y-1>=0&&matt[x][y+1]==matt[x][y])
    floodfill2(x,y-1);
    if(x-1>=0&&y-1>=0&&matt[x-1][y-1]==matt[x][y])
        floodfill2(x-1,y-1);
    if(x-1>=0&&y+1<m&&matt[x-1][y+1]==matt[x][y])
        floodfill2(x-1,y+1);
    if(x+1<n&&y-1>=0&&matt[x+1][y-1]==matt[x][y])
        floodfill2(x+1,y-1);
    if(x+1<n&&y+1<m&&matt[x+1][y+1]==matt[x][y])
        floodfill2(x+1,y+1);
}
int main()
{
    cin>>n>>m;
    brojac=0;
    memset(visited,false,sizeof(visited));
    memset(matt,0,sizeof(matt));
    bool vvisited[30000];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
   
   
   
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visited[i][j]&&mat[i][j]=='x')
            {
                brojac++;
                floodfill(i,j);
            }
        }
    }
    memset(visited,false,sizeof(visited));
    int mattt[3000];
    memset(vvisited,false,sizeof(vvisited));
    memset(mattt,-1,sizeof(mattt));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visited[i][j]&&mat[i][j]=='x'&&!vvisited[matt[i][j]])
            {
            iii=99999;
            jjj=-1;
            floodfill2(i,j);
            vvisited[matt[i][j]]=true;
            if(jjj!=-1)
            mattt[jjj]=max(mattt[jjj],0);
            if(iii!=-1)
            {
                mattt[iii]=max(mattt[iii],mattt[jjj]+1);
                memset(visited,false,sizeof(visited));
                memset(vvisited,false,sizeof(vvisited));
            }
            }
               
        }
    }
    vector<int>v(100,-1);
    for(int i=1;i<=brojac;i++)
    {
        if(mattt[i]!=-1)
        v[mattt[i]]++;
    }
  
    for(int i=0;i<v.size();i++)
    {
        if(v[i]!=-1)
            cout<<v[i]+1<<endl;
    }
    return 0;
}