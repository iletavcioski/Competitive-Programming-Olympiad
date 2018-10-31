#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char mat[303][303];
    int ei,ej,pi,pj;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
            if(mat[i][j]=='P')
            {
                pi=i;
            pj=j;
            }
            if(mat[i][j]=='K')
            {
                ei=i;
            ej=j;
            }
        }
    }
    queue<int> qi;
    queue<int> qj;
    queue<int> qs;
    queue<int> qq;
    qi.push(pi);
    qj.push(pj);
    qs.push(0);
    qq.push(0);
    int dp[303][303][4];
    for(int i=0;i<=301;i++)
    {
        for(int j=0;j<=301;j++)
        {
            for(int k=0;k<=3;k++)
            {
                dp[i][j][k]=999999;
            }
        }
    }
 
    while(!qi.empty())
    {
        int topi=qi.front();
        qi.pop();
        int topj=qj.front();
        qj.pop();
        int tops=qs.front();
        qs.pop();
        int topq=qq.front();
        qq.pop();
        if(tops>=dp[topi][topj][topq])
            continue;
        else
            dp[topi][topj][topq]=tops;
        int ii=topq+1;
        if(ii==4)
            ii=1;
        for(int i=1;i<=3;i++)
        {
            if(topi+i<n&&mat[topi+i][topj]!='#')
            {
                if(i==ii){
                qi.push(topi+i);
                qj.push(topj);
                qs.push(tops+1);
                qq.push(i);
                break;
                }
            }
            else
                break;
        }
        for(int i=1;i<=3;i++)
        {
            if(topi-i>=0&&mat[topi-i][topj]!='#')
            {
                if(ii==i){
                qi.push(topi-i);
                qj.push(topj);
                qs.push(tops+1);
                qq.push(i);
                break;
                }
            }
            else
                break;
        }
        for(int i=1;i<=3;i++)
        {
            if(topj+i<m&&mat[topi][topj+i]!='#')
            {
                if(ii==i){
                qi.push(topi);
                qj.push(topj+i);
                qs.push(tops+1);
                qq.push(i);
                break;
                }
            }
            else
                break;
        }
        for(int i=1;i<=3;i++)
        {
            if(topj-i>=0&&mat[topi][topj-i]!='#')
            {
                if(ii==i){
                qi.push(topi);
                qj.push(topj-i);
                qs.push(tops+1);
                qq.push(i);
                break;
                }
            }
            else
                break;
        }
    }
    cout<<min(dp[ei][ej][1],min(dp[ei][ej][2],dp[ei][ej][3]))<<endl;
    return 0;
}