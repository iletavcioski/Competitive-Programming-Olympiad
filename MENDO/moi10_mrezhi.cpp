#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Izbor
{
    int a,b;
    int vrska;
};
bool const operator <(const Izbor &x,const Izbor &y)
{
    if(x.vrska>y.vrska)
        return true;
    return false;
}
int n;
int graf[101][101];
void floydwarshal()
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                graf[i][j]=min(graf[i][j],graf[i][k]+graf[k][j]);
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    vector<int> vkraj;
    for(int tt=0;tt<t;tt++)
    {
        int k;
        cin>>n>>k;
        priority_queue<Izbor> qi;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int a;
                cin>>a;
                Izbor g;
                g.a=i;
                g.b=j;
                g.vrska=a;
                qi.push(g);
            }
        }
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)
                graf[i][j]=1000;
        }
        while(!qi.empty())
        {
            Izbor g=qi.top();
            qi.pop();
            if(graf[g.a][g.b]==g.vrska)
            {
                continue;
            }
            if(graf[g.a][g.b]<g.vrska||k==0)
            {
                vkraj.push_back(tt+1);
                break;
            }
            if(graf[g.a][g.b]>g.vrska)
            {
                graf[g.a][g.b]=g.vrska;
                graf[g.b][g.a]=g.vrska;
                k--;
                floydwarshal();
 
            }
        }
    }
    cout<<vkraj.size()<<endl;
    for(int i=0;i<vkraj.size();i++)
        cout<<vkraj[i]<<endl;
    return 0;
}