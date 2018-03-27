#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin>>n;
    vector<ll> v;
    vector<int> vis(n+1,0);
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        v.push_back(a);
    }
    ll brojac=0;
    for(int i=0;i<n-1;i++)
    {
        brojac+=max(v[i],v[i+1]);
    }
    cout<<brojac<<endl;
    return 0;
}