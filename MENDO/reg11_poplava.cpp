#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    int zbir=0;
    ll brojac=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(b,a));
        zbir+=a;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        brojac=max(brojac,(ll)(zbir*v[i].first));
        zbir-=v[i].second;
    }
    cout<<brojac<<endl;
    return 0;
}