#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<pair<int,double> > >v;
    vector<pair<int,double> >vecc;
    v.insert(v.begin(),505,vecc);
    vector<int> x;
    vector<int> y;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        x.push_back(a);
        y.push_back(b);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(i!=j)
            {
                double dist=(pow((x[i]-x[j]),2.00)+pow((y[i]-y[j]),2.00));
                if(dist<=100.000000000000000)
                {
                    double d=sqrt(dist);
                    v[i].push_back(make_pair(j,d));
                    v[j].push_back(make_pair(i,d));
                }
            }
        }
    }
    queue<int> qi;
    qi.push(0);
    vector<double> dp(505,999999999.999);
    queue<double> qs;
    qs.push(0.0);
    dp[0]=0.0;
    while(!qi.empty())
    {
        int topi=qi.front();
        qi.pop();
        double tops=qs.front();
        qs.pop();
        for(int i=0;i<v[topi].size();i++)
        {
            if((tops+v[topi][i].second)<dp[v[topi][i].first])
            {
                dp[v[topi][i].first]=(tops+v[topi][i].second);
                qi.push(v[topi][i].first);
                qs.push((tops+v[topi][i].second));
            }
        }
    }
    cout<<fixed<<setprecision(8);
    cout<<dp[n-1]<<endl;
    return 0;
}