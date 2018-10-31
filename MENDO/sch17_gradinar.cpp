#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m;
char mat[1001][1001];
int visi[1001][1001];
int dp[1001][1001];
void bfs(int ei,int ej,int br,int cekori)
{
    queue<int> qi;
    queue<int> qj;
    queue<int> qs;
    qi.push(ei);
    qj.push(ej);
    qs.push(0);
    visi[ei][ej]=br;
    while(!qi.empty())
    {
        int topi=qi.front();
        qi.pop();
        int topj=qj.front();
        qj.pop();
        int tops=qs.front();
        qs.pop();
        if(tops>cekori)
            continue;
        dp[topi][topj]++;
        if(topi+1<n&&mat[topi+1][topj]!='#'&&visi[topi+1][topj]<br)
        {
            qi.push(topi+1);
            qj.push(topj);
            qs.push(tops+1);
            visi[topi+1][topj]=br;
        }
        if(topi-1>=0&&mat[topi-1][topj]!='#'&&visi[topi-1][topj]<br)
        {
            qi.push(topi-1);
            qj.push(topj);
            qs.push(tops+1);
            visi[topi-1][topj]=br;
        }
        if(topj+1<m&&mat[topi][topj+1]!='#'&&visi[topi][topj+1]<br)
        {
            qi.push(topi);
            qj.push(topj+1);
            qs.push(tops+1);
            visi[topi][topj+1]=br;
        }
        if(topj-1>=0&&mat[topi][topj-1]!='#'&&visi[topi][topj-1]<br)
        {
            qi.push(topi);
            qj.push(topj-1);
            qs.push(tops+1);
            visi[topi][topj-1]=br;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    cin>>m;
    int w;
    cin>>w;
    vector<int> vi,vj;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
            if(mat[i][j]=='C')
            {
            vi.push_back(i);
            vj.push_back(j);
            }
        }
    }
    int broj=1;
    for(int i=0;i<vi.size();i++)
    {
        bfs(vi[i],vj[i],broj,w);
        broj++;
    }
    int maxi=0;
    int kraji=-1;
    int krajj=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(maxi<dp[i][j]&&mat[i][j]!='C'&&mat[i][j]!='C')
            {
                maxi=dp[i][j];
                kraji=i;
                krajj=j;
            }
        }
    }
    cout<<kraji+1<<" "<<krajj+1<<endl;
    return 0;
}