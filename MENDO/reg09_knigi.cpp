#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int brojac=0;
    for(int i=0;i<v.size();i+=m)
        brojac+=v[i]*2;
    cout<<brojac<<endl;
    return 0;
}