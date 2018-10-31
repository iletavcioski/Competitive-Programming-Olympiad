#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll broj; 
    int k;
    cin>>broj>>k;
        
     ll x=1;
    for (ll i=broj+1; i>0; i+=x)
    {
        int sum=0;
        for (ll y=1; y<=i; y*=10)
        {
            if ((i/y)%10 == 7)
               sum++;
        }
        if ((i/x) % 10 ==7)
           x*=10;
        if (sum >= k)
        {
                cout<<i<<endl;
                break;
        }
            
    }
    return 0;
}