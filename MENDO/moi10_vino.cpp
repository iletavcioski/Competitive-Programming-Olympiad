#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<int> ima,kupi,prodaj;
ll n,h,k,brojac=0,maxi=9999999999,brojce;
vector<pair<ll,ll> > a,b;
ll seg[1<<16+2];
int roa;
void rec(int i,int m,int cur,int val)
{
    if (i==m)
        return;
    rec(i+1,m,cur,val);
    if(m==n/2)
        a.push_back(make_pair(cur+kupi[i],val+prodaj[i]));
    else
        b.push_back(make_pair(cur+kupi[i],val+prodaj[i]));
    rec(i+1,m,cur+kupi[i],val+prodaj[i]);
}
bool compare(const pair<int,int>&a,const pair<int,int> &b)
{
    if(a.second<b.second)
        return true;
    if(a.second==b.second&&a.first<b.first)
        return true;
    return false;
}
void binary_search(int i,int l,int r)
{
    int mid=(l+r)/2;
    if(a[i].second+b[mid].second>=k)
    {
            brojce=seg[mid]+a[i].first;
            if(l!=r-1)
                binary_search(i,l,mid);
    }
    else if(r!=l+1)
    {
        binary_search(i,mid,r);
    }
}
int main()
{
    cin>>n>>h>>k;
    int brojac1=0;
    for(int i=0;i<h;i++)
    {
        int a;
        cin>>a;
        ima.push_back(a-1);
    }
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        kupi.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        prodaj.push_back(a);
        brojac1+=a;
    }
    if(brojac1<k)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=0;i<h;i++)
        brojac+=kupi[ima[i]];
    rec(0,n/2,0,0);
    rec(n/2,n,0,0);
    a.push_back(make_pair(0,0));
    b.push_back(make_pair(0,0));
    sort(b.begin(),b.end(),compare);
    seg[b.size()-1]=b[b.size()-1].first;
    for(int i=b.size()-2;i>=0;i--)
        seg[i]=min(seg[i+1],(ll)b[i].first);
    for(int i=0;i<a.size();i++)
    {
        brojce=9999999999;
        binary_search(i,0,(int)b.size());
        if(brojce!=9999999999)
            maxi=min(brojce,maxi);
    }
    cout<<max((ll)0,maxi-brojac)<<endl;
    return 0;
}