#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
char mat[101][101];
int n,m;
int bfs(int pi,int pj,int ei,int ej, char t)
{
    queue<int> qi;
    queue<int> qj;
    queue<int> qs;
    qi.push(pi);
    qj.push(pj);
    qs.push(0);
    bool visited[101][101];
    for(int i=0;i<=100;i++)
    {
        for(int j=0;j<=100;j++)
            visited[i][j]=false;
    }
    visited[pi][pj]=true;
    while(!qi.empty())
    {
        int topi=qi.front();
        qi.pop();
        int topj=qj.front();
        qj.pop();
        int tops=qs.front();
        qs.pop();
        if(topi==ei&&topj==ej)
            return tops;
        if(topi+1<n&&mat[topi+1][topj]!='#'&&!visited[topi+1][topj])
        {
            qi.push(topi+1);
            qj.push(topj);
            qs.push(tops+1);
            visited[topi+1][topj]=true;
        }
        if(topj-1>=0&&mat[topi][topj-1]!='#'&&!visited[topi][topj-1])
        {
            qi.push(topi);
            qj.push(topj-1);
            qs.push(tops+1);
            visited[topi][topj-1]=true;
        }
        if(topi-1>=0&&mat[topi-1][topj]!='#'&&!visited[topi-1][topj])
        {
            qi.push(topi-1);
            qj.push(topj);
            qs.push(tops+1);
            visited[topi-1][topj]=true;
        }
        if(topj+1<m&&mat[topi][topj+1]!='#'&&!visited[topi][topj+1])
        {
            qi.push(topi);
            qj.push(topj+1);
            qs.push(tops+1);
            visited[topi][topj+1]=true;
        }
    }
    return 999999;
}
int main()
{
    cin>>n>>m;
    int d=0;
    vector<pair<int,int> > v(5);
    int matt[5][5];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            matt[i][j]=0;
 
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
            if(mat[i][j]=='S')
                v[0]=make_pair(i,j);
            if(mat[i][j]=='B')
                v[4]=make_pair(i,j);
            if(mat[i][j]=='D')
            {
                d++;
                v[d]=make_pair(i,j);
            }
        }
    }
    vector<int> dd;
    for(int i=1;i<=d;i++)
        dd.push_back(i);
    int maxi=999999999;
    do{
        int b1=bfs(v[0].first,v[0].second,v[dd[0]].first,v[dd[0]].second,'D');
        int b2=bfs(v[dd[dd.size()-1]].first,v[dd[dd.size()-1]].second,v[4].first,v[4].second,'B');
        int brojac=0;
        brojac+=b1;
        brojac+=b2;
        for(int i=0;i<dd.size()-1;i++)
        {
            brojac+=(bfs(v[dd[i]].first,v[dd[i]].second,v[dd[i+1]].first,v[dd[i+1]].second,'D'));
        }
        maxi=min(maxi,brojac);
    }while(next_permutation(dd.begin(),dd.end()));
    if(maxi>10000)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<maxi<<endl;
    }
    return 0;
}