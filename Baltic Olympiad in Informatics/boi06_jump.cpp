#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string sum(string a,string b)
{
    if(a.size()>b.size())
        swap(a,b);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    while(a.size()<b.size())
    {
        a+='0';
    }
    string ss="";
    int prenos=0;
    for(int i=0;i<a.size();i++)
    {
        int br1=a[i]-'0';
        int br2=b[i]-'0';
        int kr=br1+br2+prenos;
        ss+=((kr%10)+'0');
        prenos=kr/10;
    }
    if(prenos)
        ss+=(prenos+'0');
    reverse(ss.begin(),ss.end());
    return ss;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin>>n;
    int m=n;
    string dp[150][150];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j]="0";
        }
    }
    dp[0][0]="1";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int a;
            cin>>a;
            if(!a)
                continue;
            if(i+a<n)
                dp[i+a][j]=sum(dp[i+a][j],dp[i][j]);
            if(j+a<m)
                dp[i][j+a]=sum(dp[i][j+a],dp[i][j]);
        }
    }
    cout<<dp[n-1][m-1]<<endl;
    return 0;
}