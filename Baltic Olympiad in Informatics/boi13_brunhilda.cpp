#include <iostream>
#include <queue>
using namespace std;
int dp_max[10000001];
int dp[10000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        for(int j=a;j-1<=10000000;j+=a)
        {
            dp_max[j-1]=a-1;
        }
        dp_max[10000000]=max(dp_max[10000000],10000000%a);
    }
    for(int i=9999999;i>=1;i--)
        dp_max[i]=max(dp_max[i],dp_max[i+1]-1);
    for(int i=1;i<=10000000;i++)
    {
        if(dp[i-dp_max[i]]==-1||dp_max[i]==0)
            dp[i]=-1;
        else
            dp[i]=dp[i-dp_max[i]]+1;
    }
    for(int i=0;i<q;i++)
    {
        int a;
        cin>>a;
        if(dp[a]==-1)
            cout<<"oo"<<"\n";
        else
            cout<<dp[a]<<"\n";
    }
    return 0;
}