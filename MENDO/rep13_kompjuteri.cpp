#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll res=k-n;
    ll brojac=0;
    while(1)
    {
        if(k/2>=n){
         if(k%2==1){
             k--;
             brojac++;
         }
        k/=2;
        brojac++;
        }
        else
            break;
    }
    brojac+=(((k-n)/2)+((k-n)%2));
    cout<<brojac<<endl;
}