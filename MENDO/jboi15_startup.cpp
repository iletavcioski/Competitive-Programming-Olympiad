#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    vector<ll> v;
    vector<ll> dp(n+1,0);
    ll maxi=1e9;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        if(i==0)
            dp[i]=a;
        else
            dp[i]=dp[i-1]+a;
        v.push_back(a);
        maxi=min(maxi,dp[i]);
    }
    int j=n-1;
    ll brojac=0;
    while(j>=0)
    {
        while(j>=0&&maxi<0)
        {
            maxi+=v[j];
            j--;
            if(maxi>=0)
                brojac++;
            if(j<0)
                break;
        }
        while(v[j]>=0&&j>=0)
        {
            brojac++;
            j--;
            if(j<0)
                break;
        }
        if(j<0)
            break;
        maxi=v[j];
        j--;
        if(j<0)
            break;
    }
    cout<<brojac<<endl;
    return 0;
}