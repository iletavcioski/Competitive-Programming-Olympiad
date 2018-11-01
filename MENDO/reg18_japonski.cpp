#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n,m;
    cin>>n>>m;
    vector<pair<int,ll> > v;
    for(int i=0;i<n;i++){
        int a;
        ll b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    ll brojac=0;
    ll p=0;
    for(int i=0;i<n;i++)
    {
        //cout<<p<<endl;
        if(v[i].second>p)
            brojac+=(v[i].second-p),p=v[i].second;
        else if(v[i].second<p)
            p=v[i].second;
    }
    cout<<brojac<<endl;
    return 0;
}