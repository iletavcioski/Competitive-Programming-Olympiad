#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin>>n;
    vector<int> v;
    vector<ll> dp(n+1,1);
    vector<ll> dpmax(n+1,0);

    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        v.push_back(a);
        dpmax[i]=a;
        if(i)
            dpmax[i]=max(dpmax[i],dpmax[i-1]);
    }
    ll brojac=1;
    ll maxi=0;
    for(int i=n-1;i>=0;i--)
    {
        int a;
        if(i==0)
            a=0;
        else
            a=dpmax[i-1];
        for(int j=1;j<v[i];j++)
        {
            brojac+=dp[max(a,j)];
            brojac%=mod;
        }
        for(int j=1;j<=i;j++)
        {
            dp[j]=1LL*j*dp[j]+dp[j+1];
            dp[j]%=mod;
        }
    }
    cout<<brojac<<endl;
    return 0;
}