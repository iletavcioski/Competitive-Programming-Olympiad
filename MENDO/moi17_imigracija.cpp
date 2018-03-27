#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
typedef long long ll;
using namespace std;
int segtree[4000002];
int I,J,vrednost;
struct node
{
    int vid;
    int x;
    int y;
    int y1;
    int val;
    int index;
};
bool const operator <(const node& a,const node& b)
{
    if(a.x==b.x)
        return a.vid<b.vid;
    else
        return a.x<b.x;
}
void update(int l,int r,int p)
{
    if(l>I||r<I)
        return;
    if(l==r)
    {
        segtree[p]+=vrednost;
        return;
    }
    update(l,(l+r)/2,2*p);
    update((l+r)/2+1,r,2*p+1);
    segtree[p]=segtree[2*p]+segtree[2*p+1];
}
int query(int l,int r,int p)
{
    if(l>=I&&r<=J)
        return segtree[p];
    if(l>J||r<I)
        return 0;
    return (query(l,(l+r)/2,2*p)+query((l+r)/2+1,r,2*p+1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int b=0;
    set<int> ss;
    vector<node> v;
    node g;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        ss.insert(a);
        ss.insert(b);
        g.vid=2;
        g.x=a;
        g.y=b;
        g.y1=0;
        g.val=c;
        g.index=-1;
        v.push_back(g);
    }
    map<int,int> m;
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        ss.insert(a);
        ss.insert(b);
        ss.insert(c);
        ss.insert(d);
        g.vid=1;
        g.x=a;
        g.y=b;
        g.y1=d;
        g.index=i;
        g.val=0;
        v.push_back(g);
        g.vid=3;
        g.x=c;
        g.y=b;
        g.y1=d;
        g.index=i;
        g.val=0;
        v.push_back(g);
    }
    for(set<int>::iterator it=ss.begin();it!=ss.end();it++)
    {
        m[(*it)]=b;
        b++;
    }
    for(int i=0;i<v.size();i++)
    {
        v[i].x=m[v[i].x];
        v[i].y=m[v[i].y];
        v[i].y1=m[v[i].y1];
    }
    sort(v.begin(),v.end());
    b--;
    vector<int> vk(q+1,0);
    vector<int> vk1(q+1,0);
    for(int i=0;i<v.size();i++)
    {
        if(v[i].vid==2)
        {
            I=v[i].y;
            vrednost=v[i].val;
            update(0,b,1);
        }
        else if(v[i].vid==1)
        {
                I=v[i].y;
                J=v[i].y1;
                vk1[v[i].index]=query(0,b,1);
        }
        else
        {
            I=v[i].y;
            J=v[i].y1;
            vk[v[i].index]=query(0,b,1)-vk1[v[i].index];
        }
    }
    for(int i=0;i<q;i++)
    {
        cout<<vk[i]<<endl;
    }
    return 0;
}