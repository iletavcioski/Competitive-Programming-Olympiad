#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m;
    cin>>n>>m;
    ll meseci;
    cin>>meseci;
    vector<pair<ll,ll> > vek;
    int mm;
    cin>>mm;
    set<pair<ll,ll> > yy;
    for(int i=0;i<mm;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        vek.push_back(make_pair(a,b));
        yy.insert(make_pair((max(a-meseci,(ll)0)),(ll)0));
        yy.insert(make_pair((min(a+meseci,n-1)),(ll)1));
    }
    vector<pair<ll,ll> > y;
    for(set<pair<ll,ll> >::iterator it=yy.begin();it!=yy.end();it++)
        y.push_back(*it);
    sort(y.begin(),y.end());
    ll brojac=0;
    for(int i=0;i<y.size()-1;i++)
    {
         
        ll a=y[i].first;
        ll b=y[i+1].first;
        ll aa=y[i].second;
        ll bb=y[i+1].second;
        vector<pair<ll,ll> > x;
        for(int j=0;j<vek.size();j++)
        {
             
            ll a1=max(vek[j].first-meseci,(ll)0);
            ll b1=min(vek[j].first+meseci,n-1);
            if((a1==a&&b1>=b)){
                x.push_back(make_pair(max(vek[j].second-meseci,(ll)0),min(vek[j].second+meseci,m-1)));
            }
            else if((a1<a&&b1==b)){
                x.push_back(make_pair(max(vek[j].second-meseci,(ll)0),min(vek[j].second+meseci,m-1)));
            }
            else if((a1<a&&b1>b)){
             
                x.push_back(make_pair(max(vek[j].second-meseci,(ll)0),min(vek[j].second+meseci,m-1)));
            }
        }
        sort(x.begin(),x.end());
        a+=aa;
        b+=bb;
        if(x.size()==0)
            continue;
        ll l=x[0].first;
        ll r=x[0].second;
        for(int j=1;j<x.size();j++)
        {
            if(x[j].first<=min(r+1,m-1))
            {
                r=max(r,x[j].second);
            }
            else
            {
                 
                brojac+=(ll)((ll)(r-l+1)*(ll)(b-a));
                l=x[j].first;
                r=x[j].second;
            }
        }
     
        brojac+=(ll)((ll)(r-l+1)*(ll)(b-a));
    }
    cout<<brojac<<endl;
    return 0;
}