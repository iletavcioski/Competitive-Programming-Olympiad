#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<deque>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    vector<ll> v;
    ll zbir=0;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        v.push_back(a);
        zbir+=a;
    }
    ll broj1=0;
    ll broj2=zbir;
    for(int i=0;i<n;i++)
    {
        broj2-=v[i];
        broj2-=broj1;
        if(broj1==broj2)
        {
            cout<<i+1<<endl;
            return 0;
        }
        broj1+=v[i];
        broj2=zbir;
    }
    cout<<-1<<endl;
    return 0;
}