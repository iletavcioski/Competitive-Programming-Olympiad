#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v1,v2;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(b>a)
            swap(a,b);
        v1.push_back(a);
        v2.push_back(b);
         
    }
    static int dp[2][1001];
    memset(dp,0,sizeof(dp));
    dp[0][0]=v2[0];
    dp[1][0]=v1[0];
 
    for(int i=1;i<n;i++)
    {
        dp[0][i]=max(dp[0][i-1]+abs(v1[i-1]-v1[i])+v2[i],dp[1][i-1]+abs(v2[i-1]-v1[i])+v2[i]);
        dp[1][i]=max(dp[0][i-1]+abs(v1[i-1]-v2[i])+v1[i],dp[1][i-1]+abs(v2[i-1]-v2[i])+v1[i]);
    }
    cout<<max(dp[0][n-1],dp[1][n-1])<<endl;
    return 0;
}