#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    ll b,j;
    cin>>b>>j;
    if(b>j)
        swap(b,j);
        ll brojac=0;
    for(ll i=1;i*i<=b;i++)
    {
        int k=b/i;
        if(b%i==0&&j%i==0)
            brojac++;
        if(b%k==0&&j%k==0&&i!=k)
        brojac++;
    }
     
    cout<<brojac<<endl;
    return 0;
}