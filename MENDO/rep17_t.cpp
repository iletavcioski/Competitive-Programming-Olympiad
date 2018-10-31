#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<ll> v;
    ll k;
    cin>>k;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        v.push_back(a);
    }
    int l=0,r=0;
    ll brojac=0;
    int maxi=0;
    while(l!=n&&r!=n)
    {
        brojac+=v[l];
        if(brojac<=k)
            maxi=max(maxi,l-r+1);
        while(brojac>k&&r!=n)
        {
            brojac-=v[r];
            r++;
        }
        l++;
    }
    cout<<maxi<<endl;
    return 0;
}