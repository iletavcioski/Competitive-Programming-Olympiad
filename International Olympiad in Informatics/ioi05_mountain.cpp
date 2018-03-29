#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll lazy[6000006];
ll segsum[6000006];
ll prefixsum[6000006];
int levo[6000006];
int desno[6000006];
bool imalazy[6000006];
int pp=0;
void init()
{
    pp=1;
}
void dodaj(int p)
{
    if(!levo[p])
    {
        pp++;
        levo[p]=pp;
    }
    if(!desno[p])
    {
        pp++;
        desno[p]=pp;
    }
}
void propagation(int p,int l,int r)
{
    if(!imalazy[p])
        return;
    imalazy[p]=false;
    if(l==r)
        return;
    imalazy[levo[p]]=true;
    imalazy[desno[p]]=true;
    lazy[levo[p]]=lazy[p];
    lazy[desno[p]]=lazy[p];
    segsum[levo[p]]=lazy[p]*(((l+r)/2)-l+1);
    segsum[desno[p]]=lazy[p]*(r-((l+r)/2));
    prefixsum[levo[p]]=max(segsum[levo[p]],0ll);
    prefixsum[desno[p]]=max(segsum[desno[p]],0ll);
}
void update(int l,int r,int p,int i,int j,ll val)
{
    if(l>j||r<i)
        return;
    if(l>=i&&r<=j)
    {
        imalazy[p]=true;
        lazy[p]=val;
        segsum[p]=1ll*(r-l+1)*val;
        prefixsum[p]=max(segsum[p],0ll);
        return;
    }
    dodaj(p);
    propagation(p,l,r);
    update(l,(l+r)/2,levo[p],i,j,val);
    update((l+r)/2+1,r,desno[p],i,j,val);
    segsum[p]=segsum[levo[p]]+segsum[desno[p]];
    prefixsum[p]=max(prefixsum[levo[p]],segsum[levo[p]]+prefixsum[desno[p]]);
}
int query(int l,int r,int p,ll val)
{
    if(l==r)
        return l;
    dodaj(p);
    propagation(p,l,r);
    if(prefixsum[levo[p]]>val)
    {
        query(l,(l+r)/2,levo[p],val);
    }
    else
    {
        query((l+r)/2+1,r,desno[p],val-segsum[levo[p]]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    init();
    int n;
    cin>>n;
    while(1)
    {
        char ss;
        cin>>ss;
        if(ss=='E')
            return 0;
        if(ss=='I')
        {
            int a,b;
            ll kk;
            cin>>a>>b>>kk;
            update(1,n,1,a,b,kk);
        }
        else
        {
            ll a;
            cin>>a;
            if(prefixsum[1]<=a)
                cout<<n<<endl;
            else
            cout<<query(1,n,1,a)-1<<endl;
        }
    }
    return 0;
}