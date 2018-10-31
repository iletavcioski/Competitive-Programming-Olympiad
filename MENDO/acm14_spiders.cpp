#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,s;
        cin>>n>>k>>s;
        int niza[1001];
        for(int i=1;i<=s;i++)
            cin>>niza[i];
        static int dp[12][102][1002];
        for(int i=0;i<=n+1;i++)
        {
            for(int j=0;j<=k;j++)
            {
                for(int jj=0;jj<=s;jj++)
                {
                    dp[i][j][jj]=-1;
                }
            }
        }
        dp[1][0][0]=0;
        int maxi=0;
        for(int jj=1;jj<=s;jj++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<=k;j++)
                {
                 
                    if(dp[i][j][jj-1]!=-1)
                    {
                        dp[i][j][jj]=max(dp[i][j][jj],dp[i][j][jj-1]+(niza[jj]==i));
                    }
                    if(dp[i-1][j-1][jj-1]!=-1)
                    {
                        if(j!=0)
                        dp[i][j][jj]=max(dp[i][j][jj],dp[i-1][j-1][jj-1]+(niza[jj]==i));
                    }
                    if(dp[i+1][j-1][jj-1]!=-1)
                    {
                        if(j!=0)
                        dp[i][j][jj]=max(dp[i][j][jj],dp[i+1][j-1][jj-1]+(niza[jj]==i));
                    }
                    maxi=max(maxi,dp[i][j][jj]);
                }
            }
        }
        cout<<maxi<<endl;
    }
    return 0;
}