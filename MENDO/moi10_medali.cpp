#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[3][30003];
vector<int> v;
int n;
int rez()
{
    dp[0][0]=1;
    dp[1][0]=1;
    dp[2][0]=1;
    if(v[0]==1)
        dp[0][0]=0;
    else if(v[0]==2)
        dp[1][0]=0;
    else if(v[0]==3)
        dp[2][0]=0;
    for(int i=1;i<n;i++)
    {
        if(v[i]==1)
        {
            dp[0][i]=dp[0][i-1];
        }
        else
            dp[0][i]=dp[0][i-1]+1;
        if(v[i]==2)
        {
            dp[1][i]=min(dp[0][i-1],dp[1][i-1]);
        }
        else
            dp[1][i]=min(dp[0][i-1],dp[1][i-1])+1;
        if(v[i]==3)
        {
            dp[2][i]=min(dp[2][i-1],min(dp[0][i-1],dp[1][i-1]));
        }
        else
            dp[2][i]=min(dp[2][i-1],min(dp[0][i-1],dp[1][i-1]))+1;
    }
    return min(dp[0][n-1],min(dp[1][n-1],dp[2][n-1]));
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    memset(dp,0,sizeof(dp));
    int maxi=999999;
    maxi=min(maxi,rez());
    memset(dp,0,sizeof(dp));
    reverse(v.begin(),v.end());
    maxi=min(maxi,rez());
    cout<<maxi<<endl;
    return 0;
}