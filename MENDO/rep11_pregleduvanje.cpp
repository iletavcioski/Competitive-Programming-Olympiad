#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    ll maxi=99999999999;
    int brojac=-1;
    for(int i=1;i<=1000;i++){
    int t=n/i;
    if(n%i!=0)
        t++;
       if(maxi>((((i*(i-1))/2)*k)+t))
       {
           maxi=((((i*(i-1))/2)*k)+t);
           brojac=i;
       }
    }
    cout<<brojac<<endl;
    return 0;
}