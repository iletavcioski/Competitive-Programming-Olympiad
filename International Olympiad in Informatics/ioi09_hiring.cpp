#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
struct node 
{
    double s,q,r;
    int i;
};
bool compare(const node &x,const node &y)
{
    if(x.r==y.r)
        return x.q<y.q;
    return x.r<y.r;
}
int main()
{
    int n;
    cin>>n;
    ll w;
    cin>>w;
    vector<node> v;
    for(int i=0;i<n;i++)
    {
        node g;
        g.i=i+1;
        cin>>g.s>>g.q;
        g.r=g.s/g.q;
        v.push_back(g);
    }
    sort(v.begin(),v.end(),compare);
    priority_queue<int> pq;
    priority_queue<pair<int,int> > pq1;
    pair<int,double> maxi=make_pair(0,-1e18);
    int maxx=0;
    ll brojac=0;
    for(int i=0;i<n;i++)
    {
        pq.push(v[i].q);
        brojac+=v[i].q;
        while(brojac*v[i].s>w*v[i].q)
        {
            brojac-=pq.top();
            pq.pop();
        }
        pair<int,double> a=make_pair(pq.size(),(double)(-1.0*brojac*v[i].s/v[i].q));
        if(a>maxi)
        {
            maxi=a;
            maxx=i;
        }
    }
    cout<<maxi.first<<endl;
    brojac=0;
    for(int i=0;i<=maxx;i++)
    {
        pq1.push(make_pair(v[i].q,v[i].i));
        brojac+=v[i].q;
        while(brojac*v[i].s>w*v[i].q)
        {
            brojac-=pq1.top().first;
            pq1.pop();
        }
    }
    while(!pq1.empty())
    {
        cout<<pq1.top().second<<endl;
        pq1.pop();
    }
    return 0;
}