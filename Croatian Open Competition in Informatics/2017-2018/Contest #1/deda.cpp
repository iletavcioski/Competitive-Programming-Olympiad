#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
int st[530001];
int I,val,J;
void update(int l,int r,int p)
{
    if(l==I&&r==I)
    {
        st[p]=val;
        return;
    }
    if(l>I||r<I)
        return;
    update(l,(l+r)/2,2*p);
    update((l+r)/2+1,r,2*p+1);
    st[p]=min(st[2*p],st[2*p+1]);
    return;
}
int query(int l,int r,int p)
{
    if(l>=I&&r<=J)
        return st[p];
    if(l>J||r<I)
        return 1e9+1;
    return min(query(l,(l+r)/2,2*p),query((l+r)/2+1,r,2*p+1));
}
int main()
{
    for(int i=0;i<=530000;i++)
        st[i]=1e9+1;
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=0;i<q;i++)
    {
        char a;
        scanf(" %c",&a);
        if(a=='M')
        {
            int x,y;
            scanf("%d %d",&x,&y);
            y--;
            I=y;
            val=x;
            update(0,n-1,1);
        }
        else
        {
            int x,y;
            scanf("%d %d",&x,&y);
            y--;
            I=y,J=n-1;
            if(query(0,n-1,1)>x)
                printf("%d\n",-1);
            else
            {
                int ll=y,rr=n-1;
                int b=0;
                while(ll<rr)
                {
                    int mid=(ll+rr)/2;
                    I=ll;
                    J=mid;
                    if(query(0,n-1,1)<=x)
                        rr=mid;
                    else
                        ll=mid+1;
                }
                printf("%d\n",(ll+rr)/2+1);
            }
        }
    }
    
  return 0;
}