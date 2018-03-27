#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
struct node
{
    int f,s,t;
};
int main()
{
    int n,m;
    cin>>n>>m;
    bool mat[1002][1002];
    node dp[1002][1002][2];
    node g;
    for(int i=0;i<1002;i++)
    {
        for(int j=0;j<1002;j++)
        {
            mat[i][j]=0;

            g.f=-1,
                    g.s=-1;
            g.t=-1;
            dp[i][j][0]=dp[i][j][1]=g;
        }
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        mat[a][b]=true;
        mat[b][a]=true;
    }
    queue<int> qi;
    queue<int> qj;
    queue<int> qt;
    queue<int> qs;
    for(int i=0;i<n;i++)
    {
        qi.push(i);
        qj.push(i);
        qt.push(0);
        qi.push(i);
        qj.push(i);
        qt.push(1);
        qs.push(1);
        qs.push(1);
        while(!qi.empty())
        {
            int topi=qi.front();
            qi.pop();
            int topj=qj.front();
            qj.pop();
            int topt=qt.front();
            qt.pop();
            int tops=qs.front();
            qs.pop();
            if(tops==n)
            {
                int a=topi;
                int b=topj;
                int g=topt;
               node k=dp[topi][topj][topt];
                vector<int> vkraj;
                while(true)
                {
                    if(k.f!=a)
                        vkraj.push_back(a);
                    else
                        vkraj.push_back(b);
                    a=k.f;
                    b=k.s;
                    g=k.t;
                    if(a==-1)
                        break;
                    k=dp[a][b][g];
                }
                for(int i=vkraj.size()-1;i>=0;i--)
                {
                    cout<<vkraj[i]+1<<endl;
                }
                return 0;
            }
            int prv=topi-1;
            if(prv<0)
                prv+=n;
            int vtor=topj+1;
            if(vtor>=n)
                vtor-=n;
            if(topt==0)
            {
                if(dp[prv][topj][0].f==-1&&mat[prv][topi])
                {
                    g.f=topi;
                    g.s=topj;
                    g.t=0;
                    dp[prv][topj][0]=g;
                    qi.push(prv);
                    qj.push(topj);
                    qt.push(0);
                    qs.push(tops+1);
                }
                if(dp[topi][vtor][1].f==-1&&mat[vtor][topi])
                {
                    g.f=topi;
                    g.s=topj;
                    g.t=0;
                    dp[topi][vtor][1]=g;
                    qi.push(topi);
                    qj.push(vtor);
                    qt.push(1);
                    qs.push(tops+1);
                }
            }
            else
            {
                if(dp[prv][topj][0].f==-1&&mat[prv][topj])
                {
                    g.f=topi;
                    g.s=topj;
                    g.t=1;
                    dp[prv][topj][0]=g;
                    qi.push(prv);
                    qj.push(topj);
                    qt.push(0);
                    qs.push(tops+1);
                }
                if(dp[topi][vtor][1].f==-1&&mat[vtor][topj])
                {
                    g.f=topi;
                    g.s=topj;
                    g.t=1;
                    dp[topi][vtor][1]=g;
                    qi.push(topi);
                    qj.push(vtor);
                    qt.push(1);
                    qs.push(tops+1);
                }
            }
        }
    }
    cout<<-1<<endl;
}