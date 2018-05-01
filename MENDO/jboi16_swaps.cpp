#include <iostream>
#include <vector>
using namespace std;
int dp[2002][5005];
void dfs(int ii,int mask)
{
    for(int i=0;i<=4095;i++)
    {
        int pp=i;
        int brojac=0;
        int brojac1=0;
        int brojac2=0;
        for(int j=0;j<12;j++)
        {
            if((mask&(1<<j))!=(pp&(1<<j)))
                brojac++;
            if(mask&(1<<j))
                brojac1++;
            if(pp&(1<<j))
                brojac2++;
        }
        if(brojac1==brojac2)
        dp[ii][i]=brojac/2;
    }
}
int main()
{
     
    for(int i=0;i<2002;i++)
    {
        for(int j=0;j<=4095;j++)
        {
            dp[i][j]=9999999;
        }
    }
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        int bitmask=v[i];
        dp[i][bitmask]=0;
        dfs(i,bitmask);
        if(i!=0){
        int mini=9999999;
        for(int j=0;j<=4095;j++)
        {
 
         
            mini=min(dp[i-1][j],mini);
            dp[i][j]+=mini;
             
        }
        }
         
    }
    int mini=99999;
    for(int j=0;j<=4095;j++)
        mini=min(dp[n-1][j],mini);
     
    cout<<mini<<endl;
    return 0;
}