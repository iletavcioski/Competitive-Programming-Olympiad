#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int v[100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        ll bb=min(a,b);
        ll kk=(ll)(2);
        bb*=kk;
        cout<<bb<<endl;
    }
    return 0;
}