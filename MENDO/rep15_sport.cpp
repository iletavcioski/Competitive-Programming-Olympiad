#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
int dp[202][5];
string s1,s2;
int rek(int x,int broj)
{
    if(dp[x][broj]==-1)
    {
        dp[x][broj]=999999;
        if(s1[x-1]=='P'&&s2[x-1]=='P')
        {
            dp[x][broj]=rek(x-1,broj)+1;
        }
        else if(s1[x-1]=='S'&&s2[x-1]=='S')
        {
            dp[x][broj]=rek(x-1,broj);
        }
        else if(s1[x-1]=='S'&&s2[x-1]=='P')
        {
            dp[x][broj]=min(rek(x-1,1)+(broj==0)+(broj==2),rek(x-1,3)+(broj==0)+(broj!=3));
        }
        else
        {
            dp[x][broj]=min(rek(x-1,2)+(broj==0)+(broj==1),rek(x-1,4)+(broj==0)+(broj!=4));
        }
    }
    return dp[x][broj];
}
int main()
{
    cin>>s1>>s2;
    int brojac=0;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]=='P'&&s2[i]=='P')
            brojac++;
    }
    if(brojac==s1.size())
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<202;i++)
    {
        for(int j=0;j<5;j++)
            dp[i][j]=-1;
    }
    for(int i=0;i<5;i++)
    {
        dp[0][i]=0;
    }
    cout<<rek(s1.size(),0)<<endl;
    return 0;
}