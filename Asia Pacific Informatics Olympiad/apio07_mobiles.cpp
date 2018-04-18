#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int inf = 1e9;
vector<vector<int> > v;
vector<int> p(100004,0);
vector<int> c(100004,0);
vector<int> h(100004,0);
bool kraj=false;
void dfs(int x)
{
    if(kraj)
    {
        p[x]=inf;
        return;
    }
        int l=v[x][0];
        int r=v[x][1];
        int lh,rh,lc,rc,lp,rp;
        if(l==-1)
        {
            lh=1;
            lp=0;
            lc=0;
        }
        else
        {
            dfs(l);
            lh=h[l];
            lp=p[l];
            lc=c[l];
        }
        if(r==-1)
        {
            rh=1;
            rp=0;
            rc=0;
        }
        else
        {
            dfs(r);
            rh=h[r];
            rp=p[r];
            rc=c[r];
        }
        h[x]=max(lh,rh)+1;
        c[x]=max(lc,rc);
        if(lh!=rh)
        {
            c[x]=inf;
        }
        if(abs(lh-rh)>=2)
        {
            p[x]=inf,c[x]=inf,kraj=true;
            return;
        }
        p[x]=c[x];
        if(lh>rh)
        {
            p[x]=min(p[x],lp+rc);
        }
        else if(lh<rh)
        {
            p[x]=min(p[x],lc+rp+1);
        }
        else if(lh==rh)
        {
            p[x]=min(p[x],min(lp+rc+1,lc+rp));
        }
        return;
}
int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    v.insert(v.begin(),n+3,vec);
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[i].push_back(a);
        v[i].push_back(b);
    }
    dfs(1);
    if(p[1]>=inf)
        cout<<-1<<endl;
    else
        cout<<p[1]<<endl;
    return 0;
}
