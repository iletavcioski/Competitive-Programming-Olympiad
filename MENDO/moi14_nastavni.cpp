#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
string s1,s2;
int mod=750083;
pair<int,int> dp[1001][1001];
int n;
int m;
pair<int,int>  rek(int i,int j)
{
    if(dp[i][j].first!=-1)
        return dp[i][j];
 
    if(i==n||j==m)
    {
        dp[i][j]=make_pair((n-i)+(m-j),1);
        return dp[i][j];
    }
    if(s1[i]==s2[j])
    {
        pair<int,int> k=rek(i+1,j+1);
        k.first++;
        dp[i][j]=k;
        return dp[i][j];
    }
    else
    {
        pair<int,int> k1=rek(i+1,j);
        pair<int,int> k2=rek(i,j+1);
        pair<int,int> k;
        if(k1.first==k2.first)
            k.first=k1.first,k.second=(k1.second+k2.second)%mod;
        else
        {
            if(k1.first<k2.first)
                k=k1;
            else
                k=k2;
        }
        k.first++;
        dp[i][j]=k;
        return dp[i][j];
    }
}
int main()
{
    cin>>s1>>s2;
    n=s1.size();
    m=s2.size();
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=make_pair(-1,-1);
        }
    }
    cout<<rek(0,0).second<<endl;
    return 0;
}