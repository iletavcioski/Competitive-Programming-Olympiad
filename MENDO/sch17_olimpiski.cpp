#include<iostream>
#include<vector>
using namespace std;
int dp[100001][2];
vector<int> v;
int n;
int funkcija()
{
    if(v[0]==0)
        dp[0][0]=dp[0][1]=1;
    if(v[0]==3)
        dp[0][0]=dp[0][1]=0;
    if(v[0]==2)
        dp[0][0]=0,dp[0][1]=1;
    if(v[0]==1)
        dp[0][0]=1,dp[0][1]=0;
    for(int i=1;i<n;i++)
    {
        if(v[i]==3)
        {
            dp[i][0]=min(dp[i][0],min(dp[i-1][0]+1,dp[i-1][1]));
            dp[i][1]=min(dp[i][1],min(dp[i-1][1]+1,dp[i-1][0]));
        }
        else if(v[i]==0)
        {
            dp[i][0]=min(dp[i][0],min(dp[i-1][0]+1,dp[i-1][1]+1));
            dp[i][1]=min(dp[i][1],min(dp[i-1][1]+1,dp[i-1][0]+1));
        }
        else if(v[i]==1)
        {
            dp[i][1]=min(dp[i][1],min(dp[i-1][0],dp[i-1][1]+1));
            dp[i][0]=min(dp[i][0],min(dp[i-1][0]+1,dp[i-1][1]+1));
        }
        else if(v[i]==2)
        {
            dp[i][0]=min(dp[i][0],min(dp[i-1][1],dp[i-1][0]+1));
            dp[i][1]=min(dp[i][1],min(dp[i-1][0]+1,dp[i-1][1]+1));
        }
    }
    return min(dp[n-1][0],dp[n-1][1]);
}
int main()
{
  
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<=100000;i++){
        dp[i][0]=dp[i][1]=9999999;
    }
    int res=funkcija();
    cout<<n-res<<endl;
    return 0;
}