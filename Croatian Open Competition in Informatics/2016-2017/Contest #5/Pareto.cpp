#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
typedef long double ll;
int main()
{
	ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll brojac=0;
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        v.push_back(a);
        brojac+=a;
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int broj=0;
    double d1;
    double d2;
    double maxi=-1;
    ll broj1=0;
    for(int i=0;i<v.size();i++)
    {
        broj1+=v[i];
        broj++;
        double dd=(double)broj/(double)n;
        double ddd=(ll)broj1/(ll)brojac;
        if(maxi<abs(ddd-dd))
        {
            maxi=abs(ddd-dd);
            d1=dd;
            d2=ddd;
        }
    }
    d1*=100;
    d2*=100;
    cout<<fixed<<setprecision(14);
    cout<<d1<<endl;
    cout<<fixed<<setprecision(14);
    cout<<d2<<endl;
 
    return 0;
}