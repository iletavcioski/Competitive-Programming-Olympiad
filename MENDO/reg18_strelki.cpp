#include <cstdio>
#include <vector>
using namespace std;
struct node
{
    int ty,br;
};
vector<int> p(300002,-1);
int dsu(int x)
{
    if(x==-2)
        return -2;
    else if(p[x]==-1)
        return x;
    else
        return dsu(p[x]);
}
void dsu1(int x,int y)
{
    if(x<0)
        return;
    else
    {
        if(x==y)
            return;
        int a=p[x];
        p[x]=y;
        dsu1(a,y);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    vector<int> v;
    vector<node> qu;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        a--;
        v.push_back(a);
    }
    int q;
    scanf("%d",&q);
    vector<int> vc=v;
    for(int i=0;i<q;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        b--;
        node g;
        g.ty=a,g.br=b;
        if(a==2)
        {
            vc[b]=-1;
        }
        qu.push_back(g);
    }
    for(int i=0;i<n;i++)
    {
        if(vc[i]!=-1)
        {
            int a=i;
            int b=dsu(vc[i]);
            if(a!=b&&a>=0&&b>=0)
            {
                p[a]=b;
                if(vc[i]!=b)
                {
                    dsu1(vc[i],b);
                }
            }
            else if(b==-2)
            {
                p[b]=-2;
                p[a]=-2;
                dsu1(vc[i],-2);
            }
            else if(a>=0&&b>=0)
            {
                if(a==b)
                {
                    p[b]=-2;
                    p[a]=-2;
                    dsu1(vc[i],-2);
                }
            }
        }
    }
    vector<int> vkraj;
    for(int i=q-1;i>=0;i--)
    {
        if(qu[i].ty==2)
        {
            int a=qu[i].br;
            int b=dsu(v[qu[i].br]);
            if(a!=b&&a>=0&&b>=0)
            {
                p[a]=b;
                if(v[qu[i].br]!=b)
                {
                    dsu1(v[qu[i].br],b);
                }
            }
            else if(b==-2)
            {
                p[b]=-2;
                p[a]=-2;
                dsu1(v[qu[i].br],-2);
            }
            else if(a>=0&&b>=0)
            {
                if(a==b)
                {
                    p[b]=-2;
                    p[a]=-2;
                    dsu1(v[qu[i].br],-2);
                }
            }
        }
        else
        {
            int a=dsu(qu[i].br);
            vkraj.push_back(dsu(qu[i].br));
            dsu1(qu[i].br,a);
        }
    }
    for(int i=vkraj.size()-1;i>=0;i--)
    {
        if(vkraj[i]==-2)
            printf("CIKLUS\n");
        else
            printf("%d\n",vkraj[i]+1);
    }
    return 0;
}