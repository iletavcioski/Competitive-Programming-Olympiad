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
    vector<int> v1,v2,v3(1000001,-1);
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v1.push_back(a);
        v2.push_back(a);
        v3[a]=i;
    }
    sort(v2.begin(),v2.end());
    for(int i=0;i<k;i++)
    {
        swap(v1[v3[v2[i]]],v1[v3[v2[v2.size()-i-1]]]);
    }
    cout<<v1[0];
    if(v1.size()>0)
    {
        for(int i=1;i<v1.size();i++)
            cout<<" "<<v1[i];
    }
    cout<<endl;
    return 0;
}