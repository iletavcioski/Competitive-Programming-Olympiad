#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll z;
    cin>>z;
    ll c;
    cin>>c;
    ll de=1;
    for(ll i=0;i<c-1;i++)
    {
        de*=10;
    }
    ll brojac=0;
    for(ll i=0;i<c-1;i++)
    {
         
        for(ll k=1;k<=9;k++)
        {
            ll zb=z;
            ll dk=de*k;
            while(zb>0)
            {
                zb-=dk;
                if(dk/(ll)10==0)
                    break;
                dk/=(ll)10;
            }
            if(dk/10!=0||zb<0)
            {
                brojac+=de*(ll)(k-1);
                dk=de*(ll)(k-1);
                while(1)
                {
                    z-=dk;
                    if(dk/10==0)
                        break;
                    dk/=10;
                }
                break;
            }
            else if(k==(ll)9)
            {
                brojac+=de*k;
                dk=de*k;
                while(1)
                {
                    z-=dk;
                    if(dk/10==0)
                        break;
                    dk/=10;
                }
            }
 
        }
        de/=10;
    }
    cout<<(ll)(brojac+z)<<endl;
    return 0;
}