#include <iostream>
#include <vector>
using namespace std;
int st[2000000];
int vk[500000];
int I,J;
void build(int l,int r,int p)
{
    if(l==r)
    {
        st[p]=vk[l];
        return;
    }
    build(l,(l+r)/2,2*p);
    build((l+r)/2+1,r,2*p+1);
    st[p]=min(st[2*p],st[2*p+1]);
}
int query(int l,int r,int p)
{
    if(l>=I&&r<=J)
    {
        return st[p];
    }
    if(l>J||r<I)
        return 1e9;
    return min(query(l,(l+r)/2,2*p),query((l+r)/2+1,r,2*p+1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin>>n;
    int half=n/2+(n%2);
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int brojac=0;
    for(int i=0;i<half;i++)
    {
        brojac+=v[i];
    }
    vk[0]=brojac;
    int poc=0,kraj=half-1;
    int maxi=0;
    while(1)
    {
        vk[poc]=brojac;
        brojac-=v[poc];
        kraj++;
        poc++;
        if(kraj==n)
            kraj=0;
        brojac+=v[kraj];
        if(poc==n)
            poc=0;
        if(poc==0)
            break;
    }
    build(0,n-1,1);
    for(int i=0;i<n;i++)
    {
        int br1=1000000000;
        int br2=1000000000;
        I=i-half+1;
        if(I<0)
        {
            I=n+I;
            J=n-1;
            br1=query(0,n-1,1);
            I=0,J=i;
            br2=query(0,n-1,1);
        }
        else
        {
            I=i-half+1;
            J=i;
            br1=query(0,n-1,1);
        }
        maxi=max(maxi,min(br1,br2));
    }
    cout<<maxi<<endl;
    return 0;
}