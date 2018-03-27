#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
ll dp[1301][1301][2];
int N,M;
int main()
{
    int n;
    ll k;
    cin>>n>>k;
    vector<ll> vp,vn;
    set<ll> s;
    vn.push_back(1);
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        s.insert(a);
    }
    for(set<ll>::iterator it=s.begin();it!=s.end();it++)
    {
        if((*it)%2)
            vn.push_back(*it);
        else
            vp.push_back(*it);
    }
    for(int i=0;i<=1300;i++)
    {
        for(int j=0;j<=1300;j++)
        {
            dp[i][j][0]=dp[i][j][1]=1e18;
        }
    }
    N=vn.size();
    M=vp.size();
    if(!M)
    {
        cout<<(vn[N-1]-1)/2<<endl;
        return 0;
    }
    else if(!N)
    {
        cout<<(vp[M-1]-2)/2+k<<endl;
        return 0;
    }
 
    dp[1][0][0]=0;
    queue<int> qi,qj,qt;
    queue<ll> qs;
    qi.push(1);
    qj.push(0);
    qt.push(0);
    qs.push(0);
    while(!qi.empty())
    {
        int i=qi.front();
        qi.pop();
        int j=qj.front();
        qj.pop();
        int t=qt.front();
        qt.pop();
        ll s=qs.front();
        qs.pop();
         
        if(s>dp[i][j][t])
            continue;
        dp[i][j][t]=s;
        if(t==0)
        {
            if(i<N)
            {
                ll a=abs(vn[i]-vn[i-1])/2;
                if(s+a<dp[i+1][j][0])
                {
                    qi.push(i+1);
                    qj.push(j);
                    qt.push(0);
                    qs.push(s+a);
                    dp[i+1][j][0]=s+a;
                }
            }
            if(j<M)
            {
                ll a=abs(vp[j]-(vn[i-1]+1))/2;
                a+=k;
                if(s+a<dp[i][j+1][1])
                {
                    qi.push(i);
                    qj.push(j+1);
                    qt.push(1);
                    qs.push(s+a);
                    dp[i][j+1][1]=s+a;
                }
            }
        }
        else
        {
            if(j<M)
            {
                ll a=abs(vp[j]-vp[j-1])/2;
                if(s+a<dp[i][j+1][1])
                {
                    qi.push(i);
                    qj.push(j+1);
                    qt.push(1);
                    qs.push(s+a);
                    dp[i][j+1][1]=s+a;
                }
            }
            if(i<N)
            {
                ll a=abs(vn[i]-(vp[j-1]-1))/2;
                a+=k;
                if(s+a<dp[i+1][j][0])
                {
                    qi.push(i+1);
                    qj.push(j);
                    qt.push(0);
                    qs.push(s+a);
                    dp[i+1][j][0]=s+a;
                }
            }
        }
    }
    ll maxi=min(dp[N][M][0],dp[N][M][1]);
    int p0=max(vp[M-1],vn[N-1]+1);
    int p1=max(vn[N-1],vp[M-1]-1);
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=M;j++)
        {
         
            if(i==N&&j==M)
                continue;
            if(j==M)
                maxi=min(maxi,(ll)(dp[i][M][1]+abs(vp[M-1]-p0)/2+abs(p1-vn[i])/2+k));
            else if(i==N)
            {
 
                maxi=min(maxi,(ll)(dp[N][j][0]+abs(vn[N-1]-p1)/2+abs(p0-vp[j])/2+k));
            }
            else
            {
                if(j!=0)
                {
                    maxi=min(maxi,(ll)(dp[i][j][1]+abs(p1-vn[i])/2+k+abs(p0-vp[j-1])/2));
                }
                maxi=min(maxi,(ll)(dp[i][j][0]+abs(p0-vp[j])/2+k+abs(p1-vn[i-1])/2));
 
                 
                 
            }
        }
 
    }
    cout<<maxi<<endl;
    return 0;
}