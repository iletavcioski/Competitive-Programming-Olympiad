#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mini;
    int maxi;
    cin>>mini>>maxi;
    int zbir=0;
    vector<int> v;
    for(int i=0;i<n;i++){
        int bb;
        cin>>bb;
        v.push_back(bb);
        zbir+=bb;
    }
    if(maxi*n<zbir||zbir<mini*n)
    {
        cout<<-1<<endl;
        return 0;
    }
    sort(v.begin(),v.end());
    int brojac=0;
    int nadpotrebno=0;
    int podpotrebno=0;
    int slobodnonad=0;
    int slobodnopod=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>maxi)
        {
            nadpotrebno+=v[i]-maxi;
        }
        if(v[i]<mini)
        {
            podpotrebno+=mini-v[i];
        }
    }
    cout<<max(nadpotrebno,podpotrebno)<<endl;
    return 0;
}