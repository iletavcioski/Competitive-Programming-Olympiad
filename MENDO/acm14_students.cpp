#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int tt=0;tt<t;tt++)
    {
        int n,m;
        cin>>n;
        int x[20002];
        int y[20002];
        double x1=0.0;
        double y1=0.0;
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
            x1+=x[i];
        }
        cin>>m;
        for(int i=0;i<m;i++)
            cin>>y[i],y1+=y[i];
        x1/=n;
        y1/=m;
        int brojac=0;
        for(int i=0;i<n;i++)
        {
            if((double)x[i]>y1&&(double)x[i]<x1)
                brojac++;
        }
        for(int i=0;i<m;i++)
        {
            if((double)y[i]>x1&&(double)y[i]<y1)
                brojac++;
        }
        cout<<brojac<<endl;
    }
    return 0;
}