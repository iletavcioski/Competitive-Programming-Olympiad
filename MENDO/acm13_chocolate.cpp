#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll dp[55][55][11];
const ll mod=1e9+7;
int main()
{
    int t;
    cin>>t;
    for(int tt=0;tt<t;tt++)
    {
        int n,m,b,k;
        cin>>n>>m>>b>>k;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                for(int kk=1;kk<=k;kk++)
                {
                    if(kk==1)
                    {
                        dp[i][j][kk]=(i*j>=b);
                    }
                    else
                    {
                        dp[i][j][kk]=0;
                        dp[i][j][kk]%=mod;
                        for(int a=0;a<i;a++)
                        {
                            dp[i][j][kk]+=dp[i-a][j][kk-1]*2*(a*j>=b);
                        }
                        dp[i][j][kk]%=mod;
                        for(int bb=0;bb<j;bb++)
                        {
                            dp[i][j][kk]+=dp[i][j-bb][kk-1]*2*(bb*i>=b);
                        }
                        dp[i][j][kk]%=mod;
                    }
                }
            }
        }
        cout<<dp[n][m][k]<<endl;
    }
    return 0;
}