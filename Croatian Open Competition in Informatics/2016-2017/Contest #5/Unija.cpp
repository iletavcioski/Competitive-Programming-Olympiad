#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
typedef  long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<pair<ll,ll> >v;
    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        b/=2;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int i=0;
    ll maxi=0;
    ll prethoden=0;
    ll brojac=0;
    while(i<n)
    {
        if(v[i].second>maxi)
        {
            brojac+=((v[i].second-maxi)*v[i].first);
            maxi=v[i].second;
                
        }
        i++;
    }
    brojac*=2;
    cout<<brojac<<endl;
    return 0;
}