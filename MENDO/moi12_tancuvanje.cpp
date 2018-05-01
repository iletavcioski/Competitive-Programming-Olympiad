#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
struct Izbor
{
    int raz;
    int a;
    int b;
};
bool operator <(const Izbor &x,const Izbor &y)
{
    if(x.raz==y.raz)
        return x.a>y.b;
    else
        return x.raz>y.raz;
}
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    vector<int> vv;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vv.push_back(a);
    }
    priority_queue<Izbor> qi;
    for(int i=0;i<n-1;i++)
    {
        if(vv[i]!=vv[i+1])
        {
            Izbor g;
            g.raz=abs(v[i]-v[i+1]);
            g.a=i;
            g.b=i+1;
            qi.push(g);
        }
    }
    bool visi[100001];
    vector<int> v1,v2;
    for(int i=0;i<n;i++)
        visi[i]=false;
 
    while(!qi.empty())
    {
        Izbor g=qi.top();
        qi.pop();
        int a1=g.a;
        int b1=g.b;
        if(!visi[a1]&&!visi[b1])
        {
        v1.push_back(a1+1);
        v2.push_back(b1+1);
            visi[a1]=true;
            visi[b1]=true;
            int aa=-1,bb=-1;
             
            for(int i=a1;i>=0;i--)
            {
                if(!visi[i])
                {
                    aa=i;
                    break;
                }
            }
            for(int i=b1;i<n;i++)
            {
                if(!visi[i])
                {
                    bb=i;
                    break;
                }
            }
            if(aa!=-1&&bb!=-1)
            {
                if(vv[aa]!=vv[bb]){
                Izbor c;
                c.a=aa;
                c.b=bb;
                c.raz=abs(v[aa]-v[bb]);
                qi.push(c);
                }
            }
        }
        else if(visi[b1])
        {
            int bb=-1;
            int aa=a1;
            for(int i=b1;i<n;i++)
            {
                if(!visi[i])
                {
                    bb=i;
                    break;
                }
            }
            if(bb!=-1)
            {
                if(vv[aa]!=vv[bb])
                {
                    Izbor c;
                    c.a=aa;
                    c.b=bb;
                    c.raz=abs(v[aa]-v[bb]);
                    qi.push(c);
                }
            }
        }
        else if(visi[a1])
        {
            int aa=-1;
            int bb=b1;
            for(int i=a1;i>=0;i--)
            {
                if(!visi[i])
                {
                    aa=i;
                    break;
                }
            }
            if(aa!=-1)
            {
                if(vv[aa]!=vv[bb])
                {
                    Izbor c;
                    c.a=aa;
                    c.b=bb;
                    c.raz=abs(v[aa]-v[bb]);
                    qi.push(c);
                }
            }
        }
    }
    cout<<v1.size()<<endl;
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" "<<v2[i]<<endl;
    }
    return 0;
}