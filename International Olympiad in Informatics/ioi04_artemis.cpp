#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int x[20005];
int y[20005];
int levo[20005];
int desno[20005];
struct node
{
    int x,y,in;
};
bool compare(const node &a, const node &b)
{
    return a.x<b.x;
}
int main()
{
    int n;
    cin>>n;
    int t;
    cin>>t;
    vector<node> v;
    vector<int> vx,vy;
    for(int i=0;i<n;i++)    
    {
        cin>>x[i]>>y[i];
        vx.push_back(x[i]);
        vy.push_back(y[i]);
    }
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    for(int i=0;i<n;i++)
    {
        node g;
        g.in=i+1;
        g.x=(int)(lower_bound(vx.begin(),vx.end(),x[i])-vx.begin());
        g.y=(int)(lower_bound(vy.begin(),vy.end(),y[i])-vy.begin());
        x[i]=g.x;
        y[i]=g.y;
        v.push_back(g);
    }
    sort(v.begin(),v.end(),compare);
    vector<int> index(n+1,0);
    for(int i=0;i<n;i++)
    {
        y[i]=v[i].y;
        index[i]=v[i].in;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(y[j]>y[i])
                desno[i]++;
            if(y[j]<y[i])
                levo[i]++;
        }
    }
    int mini=1e9;
    int minix=-1;
    int miniy=-1;
    for(int i=0;i<n;i++)
    {
        int os=0;
        vector<int> pod(20005,0);
        for(int j=0;j<i;j++)
            pod[y[j]]++;
        for(int j=1;j<=n;j++)
            pod[j]+=pod[j-1];
        for(int j=i+1;j<n;j++)
        {
            if(y[j]<y[i])
            {
                os++;
                continue;
            }
            int br=j+1-os-desno[j]-pod[y[j]];
            if(br>=t&&br<mini)
            {
                mini=br;
                minix=i,miniy=j;
            }
            if(mini==t)
                break;
        }
        os=0;
        for(int j=i+1;j<n;j++)
        {
            if(y[j]>y[i])
            {
                os++;
                continue;
            }
            int br=j+1-os-levo[j]-pod[n]+pod[y[j]];
            if(br>=t&&br<mini)
            {
                mini=br;
                minix=i,miniy=j;
            }
            if(mini==t)
                break;
        }
        if(mini==t)
            break;
    }
    
    
    cout<<index[minix]<<" "<<index[miniy]<<endl;
    return 0;
}