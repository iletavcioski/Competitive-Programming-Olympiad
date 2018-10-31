#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    long long dp[22][22][22][22];
    memset(dp,0,sizeof(dp));
    int n,a,b,k;
    cin>>n;
    cin>>a>>b;
    cin>>k;
    if(a>=1)
    dp[1][0][1][0]=1;
    dp[1][0][0][0]=1;
    if(a>=1&&b>=1&&k>=1)
    dp[1][1][1][1]=1;
    if(b>=1)
        dp[1][0][0][1]=1;
    if(n>=2){
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            for(int ii=0;ii<=a;ii++)
            {
                for(int jj=0;jj<=b;jj++)
                {
                    if(dp[i][j][ii][jj]!=0){
                    dp[i+1][j][ii][jj]+=dp[i][j][ii][jj];
                    if(ii+1<=a) dp[i+1][j][ii+1][jj]+=dp[i][j][ii][jj];
                    if(ii+1<=a&&jj+1<=b&&j+1<=k) dp[i+1][j+1][ii+1][jj+1]+=dp[i][j][ii][jj];
                    if(jj+1<=b) dp[i+1][j][ii][jj+1]+=dp[i][j][ii][jj];
                    }
                }
            }
        }
    }
    }
    long long brojac=0;
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<=a;j++)
        {
            for(int ii=0;ii<=b;ii++)
                brojac+=dp[n][i][j][ii];
        }
    }
    cout<<brojac<<endl;
    return 0;
}