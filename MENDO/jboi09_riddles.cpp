#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,k;
vector<int> a(100001),v(100001);
bool mozi(int n)
{
    vector<int> v;
    v=a;
    sort(v.begin(),v.begin()+n);
    int brojac=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]<=k)
        {
            if(v[i]>(brojac+1))
                return false;
            brojac+=v[i];
            if(brojac>=k)
                return true;
        }
    }
    return false;
}
int binary_search()
{
    int mini=n+1;
    int l=0;
    int r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(mozi(mid)){
            r=mid-1;
            mini=min(mini,mid);
        }
        else
            l=mid+1;
    }
    if(mini>n)
        return -1;
    else
        return mini;
}
int main()
{
    int t;
    cin>>t;
    for(int tt=0;tt<t;tt++)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            int b;
            cin>>b;
            a[i]=b;
        }
        cout<<binary_search()<<endl;
    }
    return 0;
}