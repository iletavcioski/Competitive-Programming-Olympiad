#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    bool visited[51][51];
    int mat[51][51];
    memset(visited,false,sizeof(visited));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    int brojpolinja=0;
    bool t=false;
    int brojac=0;
    while(t==false)
    {
        int x,y;
        int mini=99999;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]<mini&&visited[i][j]==false)
                {
                    x=i;
                    y=j;
                    mini=mat[i][j];
                }
            }
        }
        brojac++;
        queue<int>qi;
        queue<int>qj;
        qi.push(x);
        qj.push(y);
        visited[x][y]=true;
        brojpolinja++;
        while(!qi.empty())
        {
            int topi=qi.front();
            qi.pop();
            int topj=qj.front();
            qj.pop();
            if(topi-1>=0&&mat[topi][topj]<=mat[topi-1][topj]&&visited[topi-1][topj]==false)
            {
                visited[topi-1][topj]=true;
                brojpolinja++;
                qi.push(topi-1);
                qj.push(topj);
            }
            if(topj-1>=0&&mat[topi][topj]<=mat[topi][topj-1]&&visited[topi][topj-1]==false)
            {
                visited[topi][topj-1]=true;
                brojpolinja++;
                qi.push(topi);
                qj.push(topj-1);
            }
            if(topi+1<n&&mat[topi][topj]<=mat[topi+1][topj]&&visited[topi+1][topj]==false)
            {
                visited[topi+1][topj]=true;
                brojpolinja++;
                qi.push(topi+1);
                qj.push(topj);
            }
            if(topj+1<m&&mat[topi][topj]<=mat[topi][topj+1]&&visited[topi][topj+1]==false)
            {
                visited[topi][topj+1]=true;
                brojpolinja++;
                qi.push(topi);
                qj.push(topj+1);
            }
        }
        if(brojpolinja==n*m)
        {
            cout<<brojac<<endl;
            return 0;
        }
  
    }
    return 0;
}