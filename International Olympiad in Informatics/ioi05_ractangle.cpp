#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
int main()
{
    ll n,m;
    string ss;
    while(1)
    {
        cin>>n>>m;

        if(n<m)
        {
            swap(n,m);
            ss="H";
        }
        else
        {
            ss="V";
        }
        ll x=m;
        while(x<n)
        {
            x*=2;
            x++;
        }
        x--;
        x/=2;
        
        cout<<ss<<" "<<x<<endl;
        if(n==1||m==1)
            break;
    }
    cout<<"-1 -1"<<endl;
}