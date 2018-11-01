#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    vector<int> vk(100000,0);
    v.push_back(2);
    for(int i=3;i<=100000;i++)
    {
        bool cc=true;
        for(int j=2;j<=sqrt((double)i);j++)
        {
            if(i%j==0){
                cc=false;
                break;
            }
        }
        if(cc)
            v.push_back(i);
    }
 
    for(int i=0;i<v.size();i++)
    {
        while(1)
        {
            if(n%v[i]==0)
            {
                vk[v[i]]++;
                n/=v[i];
            }
            else
                break;
        }
    }
    bool cc=false;
    for(int i=0;i<vk.size();i++)
    {
         
        if(vk[i])
        {
            if(cc)
            cout<<"*("<<i<<"^"<<vk[i]<<")";
            else
                cc=true,cout<<"("<<i<<"^"<<vk[i]<<")";
        }
    }
    cout<<endl;
    return 0;
}