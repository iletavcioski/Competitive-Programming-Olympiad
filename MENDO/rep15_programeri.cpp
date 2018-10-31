#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
        m[a]++;
    }
    long long brojac=0;
    for(int i=0;i<v.size();i++)
    {
        if(k==0)
            brojac+=m[v[i]]-1;
        else{
        brojac+=m[v[i]-k];
        brojac+=m[v[i]+k];
        }
    }
    cout<<brojac/2<<endl;
    return 0;
}