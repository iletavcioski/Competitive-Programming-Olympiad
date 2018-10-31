#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    vector<int> dp(n+1,1e9);
    vector<int> visi(11,0);
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        int broj=v[i];
        if(visi[broj])
            continue;
            int maxi=1e9;
            int index=-1;
            for(int j=0;j<n;j++)
            {
                if(j>0)
                    dp[j]=min(dp[j],dp[j-1]+1);
                if(j<n-1)
                    dp[j]=min(dp[j],dp[j+1]+1);
                if(v[j]==broj)
                {
                    if(dp[j]<maxi)
                    {
                        maxi=dp[j];
                        index=j;
                    }
                }
            }
            for(int j=n-1;j>=0;j--)
            {
                if(j>0)
                    dp[j]=min(dp[j],dp[j-1]+1);
                if(j<n-1)
                    dp[j]=min(dp[j],dp[j+1]+1);
  
                if(v[j]==broj)
                {
                    if(dp[j]<maxi)
                    {
                        maxi=dp[j];
                        index=j;
                    }
                }
            }
        for(int j=0;j<n;j++)
        {
            if(abs(j-index)<=m&&v[j]==broj)
                dp[j]=min(dp[j],maxi+(int)abs(j-index));
            else if(v[j]==broj)
                dp[j]=min(maxi+m,dp[j]);
            if(j+1<n)
                dp[j+1]=min(dp[j+1],dp[j]+1);
            if(j-1>=0)
                dp[j-1]=min(dp[j-1],dp[j]+1);
        }
        visi[broj]=true;
    }
  
    cout<<dp[n-1]<<endl;
    return 0;
}