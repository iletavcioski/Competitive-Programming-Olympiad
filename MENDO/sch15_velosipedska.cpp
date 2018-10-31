#include<iostream>
using namespace std;
int m,k,n;
int xi[101],ri[101],ci[101];
int dp[101][1001];
bool iskoristeno[101][1001];
int osvetleno[10001];
int rek(int i,int b)
{
    int so=0;
    int bez=0;
    int osv=ri[i]*2;
    if(xi[i]+ri[i]>m)
    {
        osv-=(xi[i]+ri[i]-m);
    }
    if(xi[i]-ri[i]<0)
    {
        osv-=(ri[i]-xi[i]);
    }
    if(b<=0)
        return 0;
    if(dp[i][b]!=-1)
        return dp[i][b];
    if(b>=ci[i])
    {
        so=rek(i-1,b-ci[i])+osv;
    }
    bez=rek(i-1,b);
    if(so>bez)
    {
        iskoristeno[i][b]=true;
        dp[i][b]=so;
    }
    else
    {
        dp[i][b]=bez;
    }
    return dp[i][b];
}
int main()
{
    cin>>m>>k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>xi[i]>>ci[i]>>ri[i];
    }
    for(int i=0;i<101;i++)
    {
        for(int j=0;j<1001;j++)
        {
            dp[i][j]=-1;
            iskoristeno[i][j]=false;
        }
    }
    for(int i=0;i<10001;i++)
    {
        osvetleno[i]=0;
    }
    cout<<rek(n-1,k)<<" ";
    for(int i=n-1;i>=0;i--)
    {
        if(iskoristeno[i][k])
        {
            int pocetok=max(0,xi[i]-ri[i]);
            int kraj=min(m-1,xi[i]+ri[i]-1);
            for(int j=pocetok;j<=kraj;j++)
                osvetleno[j]=1;
            k-=ci[i];
        }
    }
    int maxi=0;
    if(!osvetleno[0])
        osvetleno[0]=1;
    for(int i=1;i<m;i++)
    {
        if(!osvetleno[i])
        {
            osvetleno[i]=osvetleno[i-1]+1;
            maxi=max(maxi,osvetleno[i]);
        }
        else
        {
            osvetleno[i]=0;
        }
    }
    cout<<maxi<<endl;
    return 0;
}