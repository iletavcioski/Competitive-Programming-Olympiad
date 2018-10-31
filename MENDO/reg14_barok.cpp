#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    int mat[1001][1001];
    for(int i=0;i<=1000;i++)
    {
        for(int j=0;j<=1000;j++)
        {
            mat[i][j]='.';
        }
    }
    int k;
    cin>>k;
    int kk;
    cin>>kk;
    queue<int> qi;
    queue<int> qj;
    queue<int> qs;
    for(int i=0;i<kk;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        mat[a][b]='X';
        qi.push(a);
        qj.push(b);
        qs.push(0);
    }
    int brojac=0;
    while(!qi.empty())
    {
        int topi=qi.front();
        qi.pop();
        int topj=qj.front();
        qj.pop();
        int tops=qs.front();
        qs.pop();
        brojac++;
        if(brojac==k)
        {
            cout<<tops<<endl;
            return 0;
        }
        if(topi+1<n&&mat[topi+1][topj]=='.')
        {
            qi.push(topi+1);
            qj.push(topj);
            qs.push(tops+1);
            mat[topi+1][topj]='X';
        }
        if(topj-1>=0&&mat[topi][topj-1]=='.')
        {
            qi.push(topi);
            qj.push(topj-1);
            qs.push(tops+1);
            mat[topi][topj-1]='X';
        }
        if(topj+1<m&&mat[topi][topj+1]=='.')
        {
            qi.push(topi);
            qj.push(topj+1);
            qs.push(tops+1);
            mat[topi][topj+1]='X';
        }
        if(topi-1>=0&&mat[topi-1][topj]=='.')
        {
            qi.push(topi-1);
            qj.push(topj);
            qs.push(tops+1);
            mat[topi-1][topj]='X';
        }
    }
    return 0;
}