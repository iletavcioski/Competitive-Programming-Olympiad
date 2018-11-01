#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
#include<map>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int i=0;
    vector<pair<int,int> >v;
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    int bb=0;
    ll brojac=0;
    while(bb<n)
    {
        if(v[i].second>0)
        {
            v[i].second--;
            brojac+=v[i].first;
            if(v[i].second==0)
                i++;
            bb++;
        }
    }
    cout<<brojac<<endl;
    return 0;
}