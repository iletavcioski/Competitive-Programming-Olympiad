#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<iomanip>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    vector<double> v;
    int m;
    cin>>m;
    for(int i=0;i<n;i++)
    {
        double a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int k=n/3;
    double brojac=0.0;
    double t=(double)m/100;
    for(int i=0;i<n;i++)
    {
        if(i<k)
        brojac+=(v[i]-(v[i]*t));
        else
            brojac+=v[i];
 
    }
    cout<<fixed<<setprecision(2);
    cout<<brojac<<endl;
    return 0;
}