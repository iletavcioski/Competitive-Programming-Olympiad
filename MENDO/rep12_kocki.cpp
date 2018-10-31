#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    ll dp[81];
    for(int i=0;i<81;i++)
        dp[i]=0;
    dp[3]=1;
    for(int i=4;i<=80;i++)
    {
        for(int j=3;j<=i;j++)
            dp[i]+=i-j+1;
        for(int k=3;k<=n;k++)
        {
            for(int j=i-k-1;j>0;j--)
                dp[i]+=dp[j];
        }
    }
    cout<<dp[n]+1<<endl;
    return 0;
}