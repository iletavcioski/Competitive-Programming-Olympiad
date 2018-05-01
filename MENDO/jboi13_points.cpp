#include <iostream>
#include <vector>
using namespace std;
int main()
{
    const int mod=123456789;
    int n,rastojanie,a,a1,pocetna,zbir=0;
    vector<int> dp(10001,1);
    cin>>n;
    cin>>a;
    pocetna=a;
    for(int i=2;i<=n;i++)
    {
        cin>>a1;
        if(a>a1) 
        {
            zbir+=(a-a1);
        }
        a=a1;
    }
    rastojanie=pocetna-zbir;
    if(rastojanie<0)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=2;i<=n+1;i++)
    {
       for(int j=1;j<=rastojanie;j++)
       {
            dp[j]=(dp[j]+dp[j-1])%mod;
       }
    }
    cout<<dp[rastojanie]<<endl;
    return 0;
}