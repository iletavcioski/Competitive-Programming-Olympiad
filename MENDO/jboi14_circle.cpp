#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;
struct krug
{
    double x;
    double y;
    double suma;
};
bool compare( const krug & t, const krug & d)
{
    if(t.y<d.y)
        return true;
    else if(t.y==d.y)
        return false;
    else
        return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    vector<krug> v;
    krug g;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            
    cin>>g.x;
    cin>>g.y;
    g.suma=g.x+g.y;
    v.push_back(g);
    }
    double miin=10000000.00;
    double p;
    double k;
    sort(v.begin(),v.end(),compare);
     miin=min(sqrt(pow((v[0].x-v[n-1].x),2.00)+pow((v[0].y-v[n-1].y),2.00)),sqrt(pow((v[1].x-v[n-1].x),2.00)+pow((v[1].y-v[n-1].y),2.00)));
    for(int i=1;i<v.size()-1;i++)
    {
        p=min(sqrt(pow((v[i].x-v[i+1].x),2.00)+pow((v[i].y-v[i+1].y),2.00)),sqrt(pow((v[i-1].x-v[i].x),2.00)+pow((v[i-1].y-v[i].y),2.00)));
        k=min(p,sqrt(pow((v[i-1].x-v[i+1].x),2.00)+pow((v[i-1].y-v[i+1].y),2.00)));
        if(k<miin)
        {
            miin=k;
        }
    }
    cout<<fixed<<setprecision(2);
    cout<<miin<<endl;
    return 0;
}