#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int mat[1001][1001];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    int dp[1001][1001];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            dp[i][j]=0;
    }
    dp[0][0]=mat[0][0];
    for(int i=1;i<m;i++)
    {
        dp[0][i]=dp[0][0]+mat[0][i];
    }
    for(int i=1;i<n;i++)
    {
        int j;
        if(i==1)
            j=1;
        else
            j=0;
        int maxi1=0;
        int ind1=-1;
        int maxi2=0;
        int ind2=-1;
        for(;j<m;j++)
        {
            if((mat[i][j]+dp[i-1][j])>maxi1)
            {
                maxi2=maxi1;
                ind2=ind1;
                maxi1=(mat[i][j]+dp[i-1][j]);
                ind1=j;
            }
            else if((mat[i][j]+dp[i-1][j])>maxi2)
            {
                maxi2=(mat[i][j]+dp[i-1][j]);
                ind2=j;
            }
        }
        if(i!=n-1){
        for(int j=0;j<m;j++)
        {
            if(j!=ind1)
                dp[i][j]+=maxi1;
            else
                dp[i][j]+=maxi2;
            dp[i][j]+=mat[i][j];
        }
        }
        else
        {
            for(int j=0;j<m;j++)
            {
                if(j!=ind1)
                {
                    dp[i][j]=max(dp[i][j]+dp[i-1][j],maxi1);
                }
                else
                    dp[i][j]=max(dp[i][j]+dp[i-1][j],maxi2);
                dp[i][j]+=mat[i][j];
            }
        }
    }
    cout<<dp[n-1][m-1]<<endl;
    return 0;
}