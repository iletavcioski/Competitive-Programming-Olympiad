#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int main()
{
    char mat[252][252];
    bool visited[252][252];
    int n,m;
    cin>>n>>m;
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
        visited[i][j]=false;
   }
    int ov=0,vol=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visited[i][j]&&mat[i][j]!='#')
            {
                queue<int> qi;
                qi.push(i);
                queue<int> qj;
                qj.push(j);
                int ovci=0,volci=0;
                visited[i][j]=true;
                while(!qi.empty())
                {
                    int topi=qi.front();
                    qi.pop();
                    int topj=qj.front();
                    qj.pop();
                    if(mat[topi][topj]=='o')
                        ovci++;
                    else if(mat[topi][topj]=='v')
                        volci++;
                    if(topi+1<n&&!visited[topi+1][topj]&&mat[topi+1][topj]!='#')
                    {
                        qi.push(topi+1);
                        qj.push(topj);
                        visited[topi+1][topj]=true;
                    }
                    if(topj-1>=0&&!visited[topi][topj-1]&&mat[topi][topj-1]!='#')
                    {
                        qi.push(topi);
                        qj.push(topj-1);
                        visited[topi][topj-1]=true;
                    }
                    if(topi-1>=0&&!visited[topi-1][topj]&&mat[topi-1][topj]!='#')
                    {
                        qi.push(topi-1);
                        qj.push(topj);
                        visited[topi-1][topj]=true;
                    }
                    if(topj+1<m&&!visited[topi][topj+1]&&mat[topi][topj+1]!='#')
                    {
                        qi.push(topi);
                        qj.push(topj+1);
                        visited[topi][topj+1]=true;
                    }
                }
                if(ovci>volci)
                    ov+=ovci;
                else
                    vol+=volci;
            }
        }
    }
    cout<<ov<<" "<<vol<<endl;
    return 0;
}