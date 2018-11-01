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
    ll n;
    cin>>n;
    ll brojac=0;
    for(ll i=0;i<=n;i++)
    {
        for(ll j=i;j<=n;j++)
        {
           brojac+=(i+j);
        }
    }
    cout<<brojac<<endl;
    return 0;
}