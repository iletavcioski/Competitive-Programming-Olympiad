#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    deque<int> d;
    for(int i=0;i<n;i++)
    {
        int bb;
        cin>>bb;
        v.push_back(bb);
    }
    int i=0;
    int brojac=0;
    sort(v.begin(),v.end());
    while(brojac!=n)
    {
        d.push_back(v[i]);
        brojac++;
        if(brojac==n)
            break;
        i++;
        d.push_front(v[i]);
        brojac++;
        if(brojac==n)
            break;
        i++;
    }
    int maxi=0;
    for(int i=0;i<d.size()-1;i++)
    maxi=max(maxi,abs(d[i]-d[i+1]));
    cout<<maxi<<endl;
    return 0;
}