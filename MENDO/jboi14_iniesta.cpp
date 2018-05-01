#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n,m,broj;
    cin>>n>>m>>broj;
    int levo[212][212][55];
    int gore[212][212][55];
    int desno[212][212][55];
    int dolu[212][212][55]; 
    int redici[212][212][55];
    int koloni[212][212][55];
    int dp[212][212][55];
    char mat[212][212];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    memset(levo,0,sizeof(levo));
    memset(gore,0,sizeof(gore));
    memset(desno,0,sizeof(desno));
    memset(dolu,0,sizeof(dolu));
    memset(redici,0,sizeof(redici));
    memset(koloni,0,sizeof(koloni));
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<=broj;k++)
            {
                if(mat[i][j]=='.')
                {
                    levo[i][j][k]=(j?levo[i][j-1][k]:0)+1;
                    gore[i][j][k]=(i?gore[i-1][j][k]:0)+1;
                }
                else
                {
                    levo[i][j][k]=(k?(j?levo[i][j-1][k-1]:0)+1:0);
                    gore[i][j][k]=(k?(i?gore[i-1][j][k-1]:0)+1:0);
                }
            }
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>= 0;j--)
        {
            for(int k=0;k<=broj;k++)
            {
                if(mat[i][j]=='.')
                {
                    desno[i][j][k]=(j<m-1?desno[i][j+1][k]:0)+1;
                    dolu[i][j][k]=(i<n-1?dolu[i+1][j][k]:0)+1;
                }
                else
                {
                    desno[i][j][k]=(k?(j<m-1?desno[i][j+1][k-1]:0)+1:0);
                    dolu[i][j][k]=(k?(i<n-1?dolu[i+1][j][k-1]:0)+1:0);
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<=broj;k++)
            {
                for(int p=0;p<=k;p++)
                {
                    redici[i][j][k]=max(redici[i][j][k],(j?levo[i][j-1][p]:0)+desno[i][j][k-p]);
                    koloni[i][j][k]=max(koloni[i][j][k],(i?gore[i-1][j][p]:0)+(i<n-1?dolu[i+1][j][k-p]:0)+1);
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<=broj;k++)
            {
                for(int p=0;p<=k;p++)
                {
                    dp[i][j][k]=max(dp[i][j][k],redici[i][j][p]+koloni[i][j][k-p]-1);
                }
            }
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            maxi=max(maxi,dp[i][j][broj]);
        }
    }
    cout<<maxi<<endl;
    return 0;
}