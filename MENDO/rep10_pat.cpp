#include <iostream>
#include <vector>
using namespace std;
int dp[202][202][2];
int pocetok[202][202][2];
vector<pair<int,int> > v1,v2;
int N,M;
void fun1(int i,int j,int pocetno_vreme,int vreme)
{
    if(i>N)
        return;
    pocetno_vreme=max(pocetno_vreme,v1[i-1].first);
    pocetok[i][j][0]=pocetno_vreme;
    dp[i][j][0]=min(dp[i][j][0],max(pocetno_vreme+v1[i-1].second,vreme));
    fun1(i+1,j,pocetok[i][j][0]+10,dp[i][j][0]+10);
}
void fun2(int i,int j,int pocetno_vreme,int vreme)
{
    if(j>M)
        return;
    pocetno_vreme=max(pocetno_vreme,v2[j-1].first);
    pocetok[i][j][1]=pocetno_vreme;
    dp[i][j][1]=min(dp[i][j][1],max(pocetno_vreme+v2[j-1].second,vreme));
    fun2(i,j+1,pocetok[i][j][1]+10,dp[i][j][1]+10);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        int a,b;
        cin>>a>>b;
        if(c=='A')
            v1.push_back(make_pair(a,b));
        else
            v2.push_back(make_pair(a,b));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j][0]=dp[i][j][1]=1000000000;
        }
    }
    N=v1.size();
    M=v2.size();
    dp[0][1][1]=v2[0].first+v2[0].second;
    dp[1][0][0]=v1[0].first+v1[0].second;
    pocetok[0][1][1]=v2[0].first;
    pocetok[1][0][0]=v1[0].first;
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=M;j++)
        {
            if(i==0&&j==0)
                continue;
            fun1(i+1,j,pocetok[i][j][0]+10,dp[i][j][0]+10);
            fun1(i+1,j,dp[i][j][1],0);
            fun2(i,j+1,pocetok[i][j][1]+10,dp[i][j][1]+10);
            fun2(i,j+1,dp[i][j][0],0);
        }
    }
    cout<<min(dp[N][M][0],dp[N][M][1])<<endl;
    return 0;
}