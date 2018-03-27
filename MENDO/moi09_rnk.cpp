#include <iostream>
#include <string>
using namespace std;
int f(char a,char b)
{
    if((a=='A'&&b=='U')||(a=='U'&&b=='A')||(a=='U'&&b=='G')||(a=='G'&&b=='U')||(a=='G'&&b=='C')||(a=='C'&&b=='G'))
        return 1;
    else
        return 0;
}
int dp[250][250];
int main()
{
    int n;
    cin>>n;
    string ss;
    cin>>ss;
    for(int i=2;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int k=j-i;
            dp[k][j]=max(dp[k][j],dp[k+1][j-1]+f(ss[k],ss[j]));
            for(int ii=k;ii<j;ii++)
            {
                dp[k][j]=max(dp[k][j],dp[k][ii]+dp[ii+1][j]);
            }
             
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}