#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v1,v2;
    for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        v1.push_back(a*60+b);
        v2.push_back(c*60+d);
        if(v1[i]>=v2[i])
            v2[i]+=(24*60);
    }
    for(int i=0;i<n;i++)
        v1.push_back(v1[i]+(24*60));
    for(int i=0;i<n;i++)
        v2.push_back(v2[i]+(24*60));
    int dp[505][505];
    for(int i=0;i<505;i++)
    {
        for(int j=0;j<505;j++)
            dp[i][j]=0;
    }
    for(int i=0;i<v1.size();i++)
    {
        for(int j=0;j<v1.size();j++)
        {
            if(v1[j]>=v2[i])
                dp[i][j]=(v2[i]-v1[i]);
        }
    }
    int maxi=0;
    for(int j=0;j<v1.size();j++)
    {
        for(int i=0;i<v1.size();i++)
        {
            for(int k=0;k<v1.size();k++)
            {
                if(dp[i][j]&&dp[j][k])
                {
                    dp[i][k]=max(dp[i][k],(dp[i][j]+dp[j][k]));
                }
            }
        }
    }
     
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,dp[i][i+n]);
    }
    cout<<maxi<<endl;
    return 0;
}