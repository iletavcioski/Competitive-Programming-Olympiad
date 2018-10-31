#include<iostream>
typedef long long ll;
using namespace std;
const ll mod = 1000000007; 
ll calc(ll movies,ll days,ll sep)
{
    ll brojac=1;
    for(ll i=0;i<days;i++)
    {
        brojac*= movies-min(i,sep);
        brojac%=mod;
    }
    return brojac;
}
   
ll dp[151][151];
ll binom(ll n,ll k)
{
    if(dp[n][k]==-1)
    {
        if(k==0||n==k)
        {
            dp[n][k]=1;
        }
        else
        {
            dp[n][k]=binom(n-1,k-1)+binom(n-1,k);
            dp[n][k]%=mod;
        }
    }
    return dp[n][k];
}
int main()
{
    ios::sync_with_stdio(false);
    for(int i=0;i<150;i++)
    {
        for(int j=0;j<150;j++)
        {
            dp[i][j]=-1;
        }
    }
    ll n,m,d;
    cin>>n>>m>>d;
    ll table[151+1];
    for(ll i=1;i<=n;i++)
    {
        table[i]=calc(i,m,d);
    }
    for(ll i=2;i<=n;i++)
    {
        for(ll j=1;j<i;j++)
        {
            table[i]-=binom(i,j)*table[j];
            ll jmp=mod;
            while(table[i]<0)
            {
                table[i]+=jmp;
                jmp*=2;
            }
            table[i]%=mod;
        }
    }
    cout<<table[n]<<endl;
    return 0;
}