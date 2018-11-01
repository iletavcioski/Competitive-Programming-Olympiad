#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<pair<int,pair<int,int> > > v;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,make_pair(b,i)));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int maxi=0;
    int brojac;
    for(int i=0;i<k;i++)
    {
        if(maxi<v[i].second.first)
        {
            maxi=v[i].second.first;
            brojac=v[i].second.second;
        }
    }
    cout<<brojac+1<<endl;
    return 0;
}