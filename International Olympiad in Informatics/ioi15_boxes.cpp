#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,k,l;
    cin>>n>>k>>l;
     ll dp1[10000003];
     ll dp2[10000003];
     ll v[10000003];
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    dp1[0]=0;
    dp2[0]=0;
    for(ll i=1;i<=n;i++)
    {
        if(i-k>0)
            dp1[i]=dp1[i-k]+2*v[i-1];
        else
            dp1[i]=2*v[i-1];
    }

    for(ll i=n;i>=1;i--)
    {
        if(i+k<=n)
            dp2[i]=dp2[i+k]+2*(l-v[i-1]);
        else
            dp2[i]=2*(l-v[i-1]);
    }
    ll brojac=1e18+42;
    for(ll i=0;i<n;i++)
    {
        brojac=min(brojac,(ll)(dp1[i]+dp2[i+1]));
    }
    brojac=min(brojac,(dp1[n]+dp2[0]));
    for(ll i=0;i<=n;i++)
    {
        ll a;
        if(i+k+1==n+1)
            a=0;
        else
            a=i+k+1;
        brojac=min(brojac,(ll)(l+dp1[i]+dp2[a]));
    }
    if(k>=n)
    {
        brojac=min(brojac,(ll)l);
    }
    cout<<brojac<<endl;
    return 0;
}