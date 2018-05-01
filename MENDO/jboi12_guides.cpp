#include <iostream>
#include <vector>
using namespace std;
int sum[15];
int mat[101][15];
int dp[101][1<<15];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
            sum[j]+=mat[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            mat[i][j]=sum[j]-mat[i][j];
        }
    }
     
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(1<<m);j++)
        {
            dp[i][j]=1e8;
        }
    }
    dp[0][0]=0;
    for(int j=0;j<m;j++)
    {
        dp[0][1<<j]=mat[0][j];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<(1<<m);j++)
        {
            dp[i][j]=min(dp[i-1][j],dp[i][j]);
            for(int k=0;k<m;k++)
            {
                if(j&(1<<k))
                {
                    int bit=j^(1<<k);
                    dp[i][j]=min(dp[i][j],dp[i-1][bit]+mat[i][k]);
                }
            }
        }
    }
    int maxi=1e8;
    for(int i=0;i<n;i++)
        maxi=min(maxi,dp[i][(1<<m)-1]);
    cout<<maxi<<endl;
    return 0;
}