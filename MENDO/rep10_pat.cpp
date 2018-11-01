#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<pair<int,int> > a,b;
int m,k;
int dp[201][201][2];
int pocetok[201][201][2];
void funkcija1(int x,int y,int vreme,int mini)
{
    if(x>m)
        return;
    vreme=max(vreme,a[x-1].first);
    pocetok[x][y][0]=vreme;
    dp[x][y][0]=min(dp[x][y][0],max(vreme+a[x-1].second,mini));
    funkcija1(x+1,y,vreme+10,dp[x][y][0]+10);
}
void funkcija2(int x,int y,int vreme,int mini)
{
    if(y>k)
        return;
    vreme=max(vreme,b[y-1].first);
    pocetok[x][y][1]=vreme;
    dp[x][y][1]=min(dp[x][y][1],max(vreme+b[y-1].second,mini));
    funkcija2(x,y+1,vreme+10,dp[x][y][1]+10);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        int bb,g;
        cin>>bb>>g;
        if(c=='A')
        a.push_back(make_pair(bb,g));
        else
        b.push_back(make_pair(bb,g));
    }
    memset(dp,1e9+1,sizeof(dp));
    memset(pocetok,1e9+1,sizeof(pocetok));
    m=a.size();
    k=b.size();
    dp[1][0][0]=a[0].first+a[0].second;
    dp[0][1][1]=b[0].first+b[0].second;
    pocetok[1][0][0]=a[0].first;
    pocetok[0][1][1]=b[0].first;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(i==0&&j==0)
                continue;
            funkcija1(i+1,j,pocetok[i][j][0]+10,dp[i][j][0]+10);
            funkcija1(i+1,j,dp[i][j][1],0);
            funkcija2(i,j+1,pocetok[i][j][1]+10,dp[i][j][1]+10);
            funkcija2(i,j+1,dp[i][j][0],0);
        }
    }
    cout<<min(dp[m][k][0],dp[m][k][1])<<endl;
    return 0;
}