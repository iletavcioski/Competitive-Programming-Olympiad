#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
    int l,r;
    int ind;
}queries[330001];
int v[330003];
int vv[1000001];
int block=555;
int ans[1000001];
bool compare (const node &x,const node &y)
{
    if(x.l/block!=y.l/block)
        return x.l/block<y.l/block;
    return x.r<y.r;
}
int brojac;
void add(int x)
{
    vv[v[x]]++;
    if(vv[v[x]]==1)
        brojac++;
}
void remove(int x)
{
    vv[v[x]]--;
     if(vv[v[x]]==0)
        brojac--;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    int currL=0,currR=0;
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d %d",&queries[i].l,&queries[i].r);
        queries[i].l--;
        queries[i].r--;
        queries[i].ind=i;
    }
    sort(queries,queries+q,compare);
    brojac=0;
    for(int i=0;i<q;i++)
    {
        int L=queries[i].l;
        int R=queries[i].r;
        while(currL<L)
        {
            remove(currL);
            currL++;
        }
        while(currL>L)
        {
            add(currL-1);
            currL--;
        }
        while(currR>R+1)
        {
            remove(currR-1);
            currR--;
        }
        while(currR<=R)
        {
            add(currR);
            currR++;
        }
        ans[queries[i].ind]=brojac;
    }
    for(int i=0;i<q;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
} 