#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int n,m;
short dp[10000][2048];
int c[10000];
void sortiraj(short* b,short* e) 
{
    for(short* i=b;i<e;i++)
    {
        c[*i]++;
    }
    int brojac=0;
    for(int i=0;i<10000;i++)
    {
        while(c[i])
        {
            c[i]--;
            b[brojac]=i;
            brojac++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    memset(c,0,sizeof(c));
    for(int i=0;i<n;i++)
    {
        string ss;
        cin>>ss;
        for(int j=0;j<m;j++)
        {
            if(ss[j]=='D')
                dp[i][j]=1;
            else
                dp[i][j]=0;
            if(i&&dp[i][j])
                dp[i][j]+=dp[i-1][j];
        }
    }
    int brojac=0;
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<m;j++)
        {
            c[dp[i][j]]++;
        }
        int brojce=0;
        for(int j=0;j<10000;j++)
        {
            while(c[j])
            {
                c[j]--;
                dp[i][brojce]=j;
                brojce++;
            }
        }
        for(int j=0;j<m;j++) 
        {
            brojac=max(brojac,((m-j)*dp[i][j]));
        }
    }
    cout<<brojac<<endl;
    return 0;
}