#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    ll k;
    cin>>k;
    vector<ll> v;
    int p=n/2;
    int p1=n-p;
    vector<ll> vc;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        v.push_back(a);
    }
    ll res=0;
    for(int i=1;i<(1<<p);i++)
    {
        ll brojac=0;
        for(int j=0;j<p;j++)
        {
            if(i&(1<<j))
            {
                brojac+=v[j];
            }
        }
        if(brojac<=k)
        {
            vc.push_back(brojac);
            res++;
        }
    }
    sort(vc.begin(),vc.end());
    for(int i=1;i<(1<<p1);i++)
    {
        ll brojac=0;
        for(int j=0;j<p1;j++)
        {
            if(i&(1<<j))
            {
                brojac+=v[j+p];
            }
        }
        if(brojac<=k)
        {
            res++;
            res+=(upper_bound(vc.begin(),vc.end(),k-brojac)-vc.begin());
        }
    }
    res++;
    cout<<res<<endl;
}