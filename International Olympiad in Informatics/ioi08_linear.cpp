#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
ll dp[2][5][5][5];
int main()
{
    int n;
    ll mod;
    cin>>n>>mod;
    string s;
    cin>>s;
    vector<int> A(n+1,0);
    vector<int> U(n+1,0);
    vector<int> D(n+1,0);
    A[0]=2;
    U[0]=2;
    D[0]=2;
    for(int i=1;i<=n;i++)
    {
        A[i]=A[i-1];
        if(s[i-1]=='L')
            A[i]--;
        else
            A[i]++;
        U[i]=max(U[i-1],A[i]);
        D[i]=min(D[i-1],A[i]);
    }
    int a=0,b=1;
    for(int i=0;i<5;i++)
    {
        for(int j=max(0,i-2);j<=i;j++)
        {
            for(int k=j;k<=i;k++)
            {
                    dp[0][j][i][k]=1;
            }
        }
    }
    ll brojac=0;
    for(int i=n;i>=1;i--)
    {
        swap(a,b);
        for(int u=0;u<5;u++)
        {
            for(int d=max(0,u-2);d<=u;d++)
            {
                for(int x=d;x<=u;x++)
                {
                    dp[a][d][u][x]=0;
                    if(x>0)
                        dp[a][d][u][x]+=dp[b][min(d,x-1)][u][x-1];
                    if(x<4)
                        dp[a][d][u][x]+=dp[b][d][max(u,x+1)][x+1];
                    dp[a][d][u][x]%=mod;
                }
            }
        }
        if(s[i-1]=='P')
        {
            int x=A[i-1]-1;
            int u=max(U[i-1],x);
            int d=min(D[i-1],x);
            if(d<0||u-d>2)
                continue;
            brojac+=dp[b][d][u][x];
            brojac%=mod;
        }
    }
    brojac++;
    brojac%=mod;
    cout<<brojac<<endl;
    return 0;
}
/*
5
7
PLPPL

*/