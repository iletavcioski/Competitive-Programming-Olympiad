#include <iostream>
#include <cmath>
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef long double ld;
ld v[2000002];
ld segtree[2000002];
ld lazy[2000002];
ll segmnozi[2000002];
int x[500005];
int y[500005];
int segmaxi[2000002];
void build2(int l,int r,int p)
{
    if(l==r)
    {
        segmnozi[p]=x[l];
        return;
    }
    build2(l,(l+r)/2,2*p);
    build2((l+r)/2+1,r,2*p+1);
    segmnozi[p]=segmnozi[2*p]*segmnozi[2*p+1]%mod;
}
void build1(int l,int r,int p)
{
    if(l==r)
    {
        segtree[p]=v[l];
        segmaxi[p]=l;
        return;
    }
    build1(l,(l+r)/2,2*p);
    build1((l+r)/2+1,r,2*p+1);
    if(segtree[2*p]>segtree[2*p+1])
    {
        segtree[p]=segtree[2*p];
        segmaxi[p]=segmaxi[2*p];
    }
    else
    {
        segtree[p]=segtree[2*p+1];
        segmaxi[p]=segmaxi[2*p+1];
    }
}
void update1(int l,int r,int p,int i,int j,ld val)
{
    if(l>=i&&r<=j)
    {
        segtree[p]+=val;
        lazy[p]+=val;
        return;
    }
	if(l>j||r<i)
    return;
    if(lazy[p]!=0)
    {
        lazy[2*p]+=lazy[p];
        lazy[2*p+1]+=lazy[p];
        segtree[2*p]+=lazy[p];
        segtree[2*p+1]+=lazy[p];
		lazy[p]=0;
    }
    
    update1(l,(l+r)/2,2*p,i,j,val);
    update1((l+r)/2+1,r,2*p+1,i,j,val);
    if(segtree[2*p]>segtree[2*p+1])
    {
        segtree[p]=segtree[2*p];
        segmaxi[p]=segmaxi[2*p];
    }
    else
    {
        segtree[p]=segtree[2*p+1];
        segmaxi[p]=segmaxi[2*p+1];
    }
}
void update2(int l,int r,int p,int i)
{
    if(l==i&&r==i)
    {
        segmnozi[p]=x[l];
        return;
    }
    if(l>i||r<i)
    return;
    update2(l,(l+r)/2,2*p,i);
    update2((l+r)/2+1,r,2*p+1,i);
    segmnozi[p]=segmnozi[2*p]*segmnozi[2*p+1]%mod;
}
ll query2(int l,int r,int p,int i,int j)
{
    if(l>j||r<i)
    {
        return 1;
    }
    if(l>=i&&r<=j)
    {
        return segmnozi[p];
    }
    return query2(l,(l+r)/2,2*p,i,j)*query2((l+r)/2+1,r,2*p+1,i,j)%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>y[i];
    }
    v[0]=log((ld)x[0]);
    for(int i=1;i<n;i++)
    {
        v[i]=v[i-1];
        v[i]+=log((ld)x[i]);
    }
    for(int i=0;i<n;i++)
    {
        v[i]+=log((ld)y[i]);
    }
    build1(0,n-1,1);
    build2(0,n-1,1);
    cout<<query2(0,n-1,1,0,segmaxi[1])*y[segmaxi[1]]%mod<<endl;
    int q;
    cin>>q;
    for(int qq=0;qq<q;qq++)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            int b;
            cin>>b;
            int c;
            cin>>c;
            ld raz=log((ld)c)-log((ld)x[b]);
            x[b]=c;
            update1(0,n-1,1,b,n-1,raz);
            update2(0,n-1,1,b);
            cout<<query2(0,n-1,1,0,segmaxi[1])*y[segmaxi[1]]%mod<<endl;
        }
        else
        {
            int b;
            cin>>b;
            int c;
            cin>>c;
            ld raz=log((ld)c)-log((ld)y[b]);
            y[b]=c;
            update1(0,n-1,1,b,b,raz);
            cout<<query2(0,n-1,1,0,segmaxi[1])*y[segmaxi[1]]%mod<<endl;
        }
    }
    return 0;
}