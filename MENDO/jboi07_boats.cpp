#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
struct Izbor
{
    ll l;
    ll p;
};
bool compare( Izbor x, Izbor y)
{
    return x.p<y.p;
}
  
int main()
{
    int n;
    cin>>n;
    int maxi;
    int pa;
    int t;
    int l;
    vector<Izbor> v;
    Izbor g;
    for(int i=0;i<n;i++)
    {
        cin>>g.l>>g.p;
        v.push_back(g);
    }
    sort(v.begin(),v.end(),compare);
    maxi=1;
    pa=v[0].p;
    for(int i=1;i<n;i++)
    {
        if(v[i].p>=pa)
        {
            l=pa;
            pa=max(v[i].p,pa+v[i].l);
            maxi++;
        }
        else
        {
            t=max(v[i].p,l+v[i].l);
            if(t<pa)
                pa=t;
        }
    }
    cout<<maxi<<endl;
    return 0;
}