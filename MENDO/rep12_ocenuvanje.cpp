#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    ll k;
    cin>>k;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    ll l=0;
    ll r=1e18;
    while(l<=r)
    {
        ll mid=(l+r+1)/2;
        ll brojac=0;
        for(int i=0;i<n;i++)
        {
            brojac+=mid/v[i];
            if(brojac>=k)
                break;
        }
        if(brojac>=k)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<l<<endl;
    return 0;
}