#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    int maxi=0;
    int brojac=1;
    bool visited[1002][1002];
    memset(visited,false,sizeof(visited));
    queue<int> qi;
    queue<int> qj;
    queue<int> qs;
    qi.push(a);
    qj.push(b);
    qs.push(0);
    visited[a][b]=true;
     
    while(!qi.empty())
    {
        int topi=qi.front();
        qi.pop();
        int topj=qj.front();
        qj.pop();
        int tops=qs.front();
        qs.pop();
        if(tops>maxi)
    {
        maxi=tops;
        brojac=1;
    }
    else if(tops==maxi)
        brojac++;
        if(!visited[topi+1][topj]&&topi+1<n)
        {
            qi.push(topi+1);
            qj.push(topj);
            qs.push(tops+1);
            visited[topi+1][topj]=true;
        }
        if(!visited[topi][topj-1]&&topj-1>=0)
        {
            qi.push(topi);
            qj.push(topj-1);
            qs.push(tops+1);
            visited[topi][topj-1]=true;
        }
        if(!visited[topi][topj+1]&&topj+1<m)
        {
            qi.push(topi);
            qj.push(topj+1);
            qs.push(tops+1);
            visited[topi][topj+1]=true;
        }
        if(!visited[topi-1][topj]&&topi-1>=0)
        {
            qi.push(topi-1);
            qj.push(topj);
            qs.push(tops+1);
            visited[topi-1][topj]=true;
        }
    }
    cout<<maxi<<endl;
    cout<<brojac<<endl;
    return 0;
}