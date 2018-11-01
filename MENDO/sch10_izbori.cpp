#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    int b;
    cin>>b;
    vector<int> v;
    for(int i=1;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int brojac=0;
     
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    while(b<=v[0])
    {
        b++;
        v[0]--;
        brojac++;
        sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    }
    cout<<brojac<<endl;
    return 0;
}