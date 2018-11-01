#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include<cstring>
using namespace std;
int main()
{
ifstream fin("numtri.in");
ofstream fout("numtri.out");
    int n;
    cin>>n;
    int mat[1001][1001];
    int dp[1001][1001];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=0;j<=i;j++)
        {
            dp[i][j]+=mat[i][j];
            if(j!=0)
                dp[i-1][j-1]=max(dp[i-1][j-1],dp[i][j]);
            if(j!=i)
                dp[i-1][j]=max(dp[i-1][j],dp[i][j]);
        }
    }
    cout<<dp[0][0]+mat[0][0]<<endl;
    return 0;
}