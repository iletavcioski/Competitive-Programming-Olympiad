#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    ll grupi=(n-1)/6;
    ll res=grupi%1000000;
    res=((res+1)*res)%1000000;
    res=(res*3)%1000000;
    int agg=n%6;
    if(agg==0)
        agg=6;
    for(int i=0;i<agg;i++)
        res+=(grupi+1);
    if(n%6==0)
        res++;
    else
        res%=1000000;
    cout<<res<<endl;
    return 0;
}