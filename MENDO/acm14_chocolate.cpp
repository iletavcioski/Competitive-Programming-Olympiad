#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t;
    cin>>t;
    vector<ll> v;
    while(t--)
    {
        ll n,m,b,p;
        cin>>n>>m>>b>>p;
        ll dp[51][51][11];
        for(ll i=0;i<=n;i++)
        {
            for(ll j=0;j<=m;j++)
            {
                for(ll k=0;k<=p;k++)
                {
                    dp[i][j][p]=0;
                }
            }
        }
        for(ll i=0;i<=n;i++)
        {
            for(ll j=0;j<=m;j++)
            {
                for(ll k=1;k<=p;k++)
                {
                    if(k==1)
                    {
                        if(i*j>=b)
                        {
                            dp[i][j][k]=1;
                        }
                        else
                        {
                            dp[i][j][k]=0;
                        }
                    }
                    else
                    {
                        dp[i][j][k]=0;
                        dp[i][j][k]%=mod;
                        for(ll ii=0;ii<i;ii++)
                        {
                            if(j*ii>=b)
                            {
                                dp[i][j][k]+=dp[i-ii][j][k-1]*2*(j*ii>=b);
                                dp[i][j][k]%=mod;
                            }
                        }
                        dp[i][j][k]%=mod;
                        for(ll jj=0;jj<j;jj++)
                        {
                            if(i*jj>=b)
                            {
                                dp[i][j][k]+=dp[i][j-jj][k-1]*2;
                                dp[i][j][k]%=mod;
                            }
                        }
                        dp[i][j][k]%=mod;
                    }
                }
            }
        }
        ll brojac=dp[n][m][p];
        v.push_back(brojac);
    }
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    return 0;
}