#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a!=i+1)
        {
            v.push_back(abs(a-(i+1)));
        }
    }
    vector<int> vkraj;
    for(int i=1;i<=n;i++)
    {
        bool k=true;
        for(int j=0;j<v.size();j++)
        {
            if(v[j]%i!=0)
            {
                k=false;
                break;
            }
        }
        if(k)
            vkraj.push_back(i);
    }
    cout<<vkraj.size()<<endl;
    for(int i=0;i<vkraj.size();i++)
    {
        cout<<vkraj[i];
        if(i!=n-1)
            cout<<" ";
    }
    cout<<endl;
    return 0;
}