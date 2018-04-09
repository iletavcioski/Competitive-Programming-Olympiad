#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin>>n;
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    ll brojac=0;
    for(int i=0;i<n;i++)
    {
        int l=i,r=n-1;
        int maxi=i;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(v[i]>=(v[mid]*0.9))
            {
                maxi=max(maxi,mid);
                l=mid+1;
            }
            else
                r=mid-1;
        }
        brojac+=(maxi-i);
    }
    cout<<brojac<<endl;
    return 0;
}