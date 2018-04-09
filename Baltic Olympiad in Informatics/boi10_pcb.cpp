#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    multiset<int> s;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++) 
    {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) 
    {
        multiset<int>::iterator it=s.upper_bound(v[i].second);
        if(it!=s.begin())
        { 
            s.erase(--it);
        }
        s.insert(v[i].second);
    }
    cout<<s.size()<<endl;
    return 0;
}