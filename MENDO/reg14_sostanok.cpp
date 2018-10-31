#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v1,v2;
    vector<int> dp(n+1,0);
    dp[n-1]=1;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v1.push_back(a);
        v2.push_back(b);
    }
    for(int i=n-2;i>=0;i--)
    {
        int j=i+1;
        while(j<n)
        {
            if(v1[i]+v2[i]<v1[j])
                break;
            dp[i]+=dp[j];
            j+=dp[j];
        }
        dp[i]++;
    }
    for(int i=0;i<n;i++)
        cout<<dp[i]<<endl;
    return 0;
}